/* esegui.c  
   a causa dell'uso di strerror_r, usato in printerror.h,
   compilare con -D_POSIX_C_SOURCE >= 200112L
*/


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>  /* shm_* stuff, and mmap() */
#include <sys/stat.h>
#include <signal.h>
#include <sys/time.h>	/* timeval{} for select() */
#include <time.h>	/* timespec{} for pselect() */
#include <string.h>     /* per strerror_r  and  memset */
#include <limits.h>	/* for OPEN_MAX */
#include <errno.h>
#include <sys/wait.h>
#include "printerror.h"
#include <fcntl.h>     /* flags for shm_open */
#include <sys/types.h> /* ftruncate() */
/* Posix IPC object name [system dependant] */
#define SHMOBJ_PATH         "/foo1423"
/* maximum length of the content of the message */
#define SHARED_SEGMENT_SIZE 512
/*int esegui(  ) 
{
	

}*/


/* servono due parametri: path+nome del programma 
   e nome del programma da eseguire
*/
int main( int argc, char* argv[] ) {
	
	pid_t pid;
	int shmfd, rc;
	int ret, status;
	int shared_seg_size = SHARED_SEGMENT_SIZE;
	char *shared_msg;      /* the pointer to the shared segment */
	shmfd = shm_open(SHMOBJ_PATH, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
	if (shmfd < 0)
	{
		perror("In shm_open()");
		exit(1);
   	 }
   	 fprintf(stdout, "Created shared memory object %s\n", SHMOBJ_PATH);
	/* adjusting mapped file size (make room for the whole segment to map) */
    	rc = ftruncate(shmfd, shared_seg_size);
    	if (rc != 0)
	{
		perror("ftruncate() failed");
		exit(1);
    	}
	/* requesting the shared segment */    
    	shared_msg = (char *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
    	if (shared_msg == NULL)
	{
		perror("In mmap()");
		exit(1);
    	}
    	fprintf(stdout, "Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);
	memset(shared_msg, (int)'B', shared_seg_size );
	/*rc=esegui(  );*/
	
	
	pid=fork();	/* il padre fa la prima fork */
	if(pid<0)
	{
		int myerrno=errno;
		fprintf(stderr, "fork() failed: error %d\n", myerrno );
		fflush(stderr);
		exit(1);
		
}
	else if(pid==0) /* il figlio esegue il comando script.sh */
	{
		
		sleep(60);
		int shared_seg_size = SHARED_SEGMENT_SIZE;
		char *shared_msg;      /* the pointer to the shared segment */
		   
		 /* creating the shared memory object 
		  notare che qui non ho messo i flag O_CREAT | O_EXCL
		  che ho usatoper creare ex-novo l'oggetto nel writer
		 */
		 shmfd = shm_open(SHMOBJ_PATH, O_RDWR, S_IRWXU | S_IRWXG);
		 if (shmfd < 0)
		{
			perror("In shm_open()");
			exit(1);
		}
	    	printf("Opened shared memory object %s\n", SHMOBJ_PATH);
		shared_msg = (char *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
	    	if (shared_msg == NULL)
		{
			perror("In mmap()");
			exit(1);
	    	}
	    	printf("Shared memory segment allocated correctly (%d bytes).\n", shared_seg_size);
		memset(shared_msg, (int)'K', shared_seg_size );
		exit(0);

	}
	else 
	{
		pid_t pidpadre;

		/* il padre aspetta la terminazione del figlio */
  		do {
			pidpadre = waitpid ( pid, &status, 0 /*WNOHANG*/ );
		} while( (pidpadre<0) && (errno==EINTR) );
		if(pidpadre<0)	
		{
			PrintErrnoAndExit ( "waitpid" );
			exit(3);
		}
                else if( pidpadre==0 )
		{ 	/* puo' accadere solo se ho usato WNOHANG */
                        printf("il processo figlio non e' ancora terminato");
                }
		else {
			if(WIFEXITED(status))
			{ /* figlio terminato normalmente */
				rc = WEXITSTATUS(status);
				printf("figlio restituisce status %d\n", rc );
				fflush(stdout);
				shared_msg = (char *)mmap(NULL, shared_seg_size, PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
				printf("The content of the shared memory is: %s\n", shared_msg );
			}
			else {
				printf("figlio termina in modo anormale con codice d'errore %d\n",rc );
				fflush(stdout);
			}
		}
		exit(0);

	}
	return(0);
}
