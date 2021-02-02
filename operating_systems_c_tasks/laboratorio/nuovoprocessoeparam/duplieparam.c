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
/* servono due parametri: path+nome del programma 
   e nome del programma da eseguire
*/
int main( int argc, char* argv[] ) {
	
	int i=0;
	pid_t pid;
	pid_t pidpadre;
int status;

	for(i=0;i<10;i++)
	{
		
		pid=fork();
		if(pid==0)
		{
			printf("i=%d\n",i);
			fflush(stdout);
			sleep(1);
			exit(i);
		}
	}
	for(i=0;i<10;i++)
	{
		do{
		pidpadre = waitpid ( -1, &status, 0 /*WNOHANG*/ );
		printf("status=%d\n",WEXITSTATUS(status));
	  } while( (pidpadre<0) && (errno==EINTR) );
	}	
		
	return 0;
}





