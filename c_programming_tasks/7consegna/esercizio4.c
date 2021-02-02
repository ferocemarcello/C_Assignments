#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char**frase;
    int a,z,k,fine;    
    //alloco e controllo spazio per la frase
    if (!(frase=(char**)malloc(sizeof(char*))))
    {
    	exit(1);//uscita dal programma con errore
    } 
    //alloco e controllo spazio per la prima parola
    if (!(frase[0]=(char*)malloc(sizeof(char))))
    {
    	exit(1);//uscita dal programma con errore
    }     
    printf("Digita una frase\n");
    //inizio il ciclo per scorrere tutte le parole(il controllo è stabilito sul valore della variabile intero fine
    for(a=0;fine!=1;a++)//a è l'indicatore parola(riga della matrice)
	{
        //inizializzo fine a zero
        fine=0;    
        if(a>0)
		{
            //alloco spazio per un altra parola
            if(!(frase=(char**)realloc(frase,(a+1)*sizeof(char*))))
            {
            	exit(1);//uscita dal programma con errore
            } 
            //alloco alla parola successiva una dimensione di un carattere
            frase[a]=(char*)malloc(sizeof(char));
        }
        for(z=0;fine==0;z++)
		{  
            if(z>0)
			{      
                //alloco spazio per un altro carattere successivo al primo
                if (!(frase[a]=(char*)realloc(frase[a],(z+1)*sizeof(char))))
                {
                	exit(1);//uscita dal programma con errore
                }    
            }
            //acquisisco il carattere con la funzione getchar()
            *(frase[a]+z)=getchar();//questo è la prima istruzione che il compilatore esegue
									//(legge il valore del primo carattere e lo assegna alla prima lettera della prima parola          
            //se il carattere è un invio o uno spazio
            if(*(frase[a]+z)=='\n'||(int)(*(frase[a]+z))==32)
			{
                //se il carattere è l'invio
                if(*(frase[a]+z)=='\n')
				{
                    //sostituisco il carattere presente con lo spazio(che servirà per poi invertirlo) e esco dal ciclo
                    *(frase[a]+z)=' ';
                    fine=1;//condizione che il for principale non rispetta
                }
                else
				{
					//cambio la condizione di fine ciclo per iniziare a allocare una nuova parola
                    fine=2;//condizione che il for annidato non rispetta
                }
                //alloco un altro elemento per contenere il carattere terminatore di stringa '\0'
                z++;
                if(!(frase[a]=(char*)realloc(frase[a],(z+1)*sizeof(char))))
                {
                	exit(1);//uscita dal programma con errore
                }
                *(frase[a]+z) = '\0';
            }    
        }              
    }
    printf("\nla frase e':\n");
    for(z=0;z<a;z++)
	{
        printf("%s",*(frase+z));            
    }
    printf("\n\nla frase al contrario e':\n");
    for(z=a-1;z!=-1;z--)
	{        
        printf("%s",*(frase+z));
    }
    printf("\n\n");
    //Dealloco la memoria
    for(z=0;z<a-1;z++)
    {
    	free(frase[z]);
	}
    free(frase);
    system("pause");
    return 0;
}
