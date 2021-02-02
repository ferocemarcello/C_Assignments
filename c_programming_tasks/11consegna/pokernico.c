#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#define nshuffle 3
#define ch_tr 191
#define ch_bl 192
#define ch_br 217
#define ch_tl 218
#define ch_v 179
#define ch_o 196
#define ch_bm 193
#define ch_tm 194

// stato 1:ok, 0:esce, -1:ko
typedef struct {int puntimano; int mano[5]; int bilancio; char*nome; int stato; int puntata;} player;
typedef struct {int carta[52];int testa;int ncarte;} s_mazzo;

void creamazzo(s_mazzo*mazzo){
    int i;
    for (i=0;i<52;i++) mazzo->carta[i]=i;
    mazzo->testa=0;
    mazzo->ncarte=52;}

void mescolamazzo(s_mazzo*mazzo){
    int i,j,k,tmp;
    for (i=0;i<nshuffle;i++){
        for(j=0;j<mazzo->ncarte;j++){
            do k=rand()%mazzo->ncarte;
            while (k==j);
            tmp=mazzo->carta[(mazzo->testa+j)%mazzo->ncarte];
            mazzo->carta[(mazzo->testa+j)%mazzo->ncarte]=mazzo->carta[(mazzo->testa+k)%mazzo->ncarte];
            mazzo->carta[(mazzo->testa+k)%mazzo->ncarte]=tmp;}}}

void daicarte(int*mano,s_mazzo*mazzo){
    int i;
    for (i=0;i<5;i++)
        if (mano[i]==-1){
            mano[i]=mazzo->carta[mazzo->testa];
            mazzo->ncarte--;
            mazzo->testa=(mazzo->testa+1)%52;}}

void lasciacarta(int idcarta,int*mano,s_mazzo*mazzo){
    mazzo->carta[(mazzo->testa+mazzo->ncarte)%52]=mano[idcarta];
    mano[idcarta]=-1;
    mazzo->ncarte++;}

char semecarta(int carta){
    return 3+carta/13;}

char valorecarta(int carta){
    switch (carta%13){
        case 0: return 'A';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
        default: return carta%13;}}

int puntipervalore(int carta){
    carta=carta%13;
    if (carta==0) return 65;
    else return carta*5;}

int puntiperseme(int carta){
    return 4-carta/13;}

int puntimano(int*mano){
    int i,j,min,tmp;
    for (i=0;i<4;i++){
        for (j=i+1;j<5;j++)
            if (j==i+1||puntipervalore(mano[min])>puntipervalore(mano[j])) min=j;
        if (puntipervalore(mano[min])<puntipervalore(mano[i])){
            tmp=mano[min];
            mano[min]=mano[i];
            mano[i]=tmp;}}
    //controllo poker
    if (mano[0]%13==mano[3]%13||mano[1]%13==mano[4]%13)
        return 704+puntipervalore(mano[1]);
    // controllo colore
    if (mano[0]/13==mano[1]/13&&mano[1]/13==mano[2]/13&&mano[2]/13==mano[3]/13&&mano[3]/13==mano[4]/13){
        tmp=0;
        return 600+puntiperseme(mano[0])+tmp;}
    // controllo full
    min=-1;
    if (mano[0]%13==mano[1]%13&&mano[2]%13==mano[4]%13) min=2;
    if (mano[0]%13==mano[2]%13&&mano[3]%13==mano[4]%13) min=0;
    if (min!=-1){
        for (i=min;i<min+3;i++)
            if (tmp<puntiperseme(mano[i]))
                tmp=puntiperseme(mano[i]);
        return 500+tmp+puntipervalore(mano[2]);}
    //controllo scala
    min=0;
    for (i=0;i<5;i++) if ((1+mano[i]%13)%13==mano[(i+1)%5]%13) min++;
    if (min==4){
        j=tmp=0;
        for(i=0;i<5;i++)
            if (j<puntipervalore(mano[i])){
                j=puntipervalore(mano[i]);
                tmp=puntiperseme(mano[i]);}
        return 400+j+tmp;}
    // controllo tris
    min=-1;
    for (i=0;i<3&&min==-1;i++) if (mano[i]%13==mano[i+2]%13) min=i;
    if (min!=-1){
        tmp=0;
        for(i=min;i<3;i++) if (tmp<puntiperseme(mano[i])) tmp=puntiperseme(mano[i]);
        return 300+tmp+puntipervalore(mano[min]);}
    // controllo doppia coppia e coppia
    min=tmp=-1;
    for (i=0;i<4;i++)
        if (mano[i]%13==mano[i+1]%13){
            if (min!=-1) tmp=min;
            min=i;}
    if (tmp!=-1){// doppia coppia
        if (puntipervalore(mano[min])>puntipervalore(mano[tmp])) j=min;
        else j=tmp;
        if (puntiperseme(mano[j])>puntiperseme(mano[j+1])) return 200+puntipervalore(mano[j])+puntiperseme(mano[j]);
        else return 200+puntipervalore(mano[j])+puntiperseme(mano[j+1]);}
    if (min!=-1){ // coppia
        if (puntiperseme(mano[min])>puntiperseme(mano[min+1])) return 100+puntipervalore(mano[min])+puntiperseme(mano[min]);
        else return 100+puntipervalore(mano[min])+puntiperseme(mano[min+1]);}
    if (mano[0]%13==0) return 65+puntiperseme(mano[0]);
    else return puntipervalore(mano[4])+puntiperseme(mano[4]);}

void printbilanci(player*giocatori,int nplayers){
    int i;
    for (i=0;i<nplayers;i++)
        if (giocatori[i].stato!=-1) printf("%s: %d$\n",giocatori[i].nome,giocatori[i].bilancio);}

void printmano(int*mano){
    int i;
    char seme,valore;
    putchar(ch_tl);
    for (i=0;i<4;i++) printf("%c%c%c",ch_o,ch_o,ch_tm);
    for (i=0;i<6;i++) putchar(ch_o);
    printf("%c\n",ch_tr);
    for (i=0;i<5;i++){
        valore=valorecarta(mano[i]);
        if (valore<10) printf("%c%-2d",ch_v,valore+1);
        else printf("%c%c ",ch_v,valore);}
    if (valore<10) printf("  %2d%c\n",valore+1,ch_v);
    else printf("   %c%c\n",valore,ch_v);
    for (i=0;i<5;i++) {
        seme=semecarta(mano[i]);
        printf("%c%c ",ch_v,seme);}
    printf("   %c%c\n",seme,ch_v);
    putchar(ch_bl);
    for (i=0;i<4;i++) printf("%c%c%c",ch_o,ch_o,ch_bm);
    for (i=0;i<6;i++) putchar(ch_o);
    printf("%c\n",ch_br);}

int main(){
    system("chcp 65001");
    srand(time(NULL));
    int nplayers=4,bilanciobase=250,i,j,idmazziere=0,piatto=0,ultimapuntata=0,idrilancio=0,choice,winner;
    s_mazzo mazzo;
    player*giocatori;
    player*curplayer;
    creamazzo(&mazzo);
    int cartescelte[5];
    char ch;
    char tmpstr[51];
    do{
        system("cls");
        printf("Questo programma simula una partita a poker.\nUsa i tasti [+] e [-] per selezionare le opzioni, [invio] per confermare.\n");
        printf("Quanti giocatori devono partecipare? %c %d %s",nplayers>2?'-':' ',nplayers,nplayers<6?"+\n":"\n");
        do ch=getch();
        while (ch!='+'&&ch!='-'&&ch!=13);
        if (ch=='+'&&nplayers<6) nplayers++;
        if (ch=='-'&&nplayers>2) nplayers--;}
    while (ch!=13);
    giocatori=(player*)malloc(nplayers*sizeof(player));
    if (giocatori==NULL){
        printf("Errore! Memoria insufficiente.");
        getch();
        return -1;}
    do{
        system("cls");
        printf("Tutti i giocatori partono con la stessa somma di denaro, se arrivi a 0 prima degli avversari hai perso.\n");
        printf("Con quale somma devono partire i giocatori?\n%c%d%s",bilanciobase>50?'-':' ',bilanciobase,bilanciobase<1000?"+\n":"\n");
        do ch=getch();
        while (ch!='+'&&ch!='-'&&ch!=13);
        if (ch=='+'&&bilanciobase<1000) bilanciobase+=50;
        if (ch=='-'&&bilanciobase>50) bilanciobase-=50;}
    while (ch!=13);
    do{
        printf("Come ti chiami? (max 50 caratteri)\n");
        fgets(tmpstr,50,stdin);
        if (tmpstr[strlen(tmpstr)-1]=='\n') tmpstr[strlen(tmpstr)-1]='\0';}
    while (strlen(tmpstr)==0);
    giocatori[0].nome=(char*)malloc((strlen(tmpstr)+1)*sizeof(char));
    if (giocatori[0].nome==NULL){
        printf("Errore! Memoria insufficiente.");
        getch();
        return -1;}
    strcpy(giocatori[0].nome,tmpstr);
    giocatori[0].bilancio=bilanciobase;
    giocatori[0].stato=1;
    for (i=0;i<5;i++) giocatori[0].mano[i]=-1;
    for (i=1;i<nplayers;i++){
        do{
            printf("Inserisci il nome del giocatore %d: ",i+1);
            fgets(tmpstr,50,stdin);
            if (tmpstr[strlen(tmpstr)-1]=='\n') tmpstr[strlen(tmpstr)-1]='\0';}
        while (strlen(tmpstr)==0);
        giocatori[i].nome=(char*)malloc((strlen(tmpstr)+1)*sizeof(char));
        if (giocatori[i].nome==NULL){
            printf("Errore! Memoria insufficiente.");
            getch();
            return -1;}
        strcpy(giocatori[i].nome,tmpstr);
        giocatori[i].bilancio=bilanciobase;
        giocatori[i].stato=1;
        for (j=0;j<5;j++) giocatori[i].mano[j]=-1;}
    do{
        system("cls");
        printf("Il mazziere per questa mano e' %s\n",giocatori[idmazziere].nome);
        mescolamazzo(&mazzo);
        printf("Il mazziere mescola il mazzo e distribuisce le carte...\n");
        for (i=0;i<nplayers;i++)
            if (giocatori[(idmazziere+i)%nplayers].stato!=-1){
                daicarte(giocatori[(idmazziere+i)%nplayers].mano,&mazzo);
                giocatori[(idmazziere+i)%nplayers].bilancio-=5;
                piatto+=5;}
        printf("Ogni giocatore lascia sul piatto 5$\n\n");
        printbilanci(giocatori,nplayers);
        puts("");
        for (i=0;i<nplayers;i++){
            if ((idmazziere+i)%nplayers!=0){
                curplayer=giocatori+((idmazziere+i)%nplayers);
                if (curplayer->stato==1){
                    printf("%s guarda le sue carte...\n",curplayer->nome);
                    curplayer->puntimano=puntimano(curplayer->mano);
                    if (curplayer->puntimano<300){
                        j=rand()%4;
                        if (j==4){
                            printf("%s lascia!\n",curplayer->nome);
                            curplayer->stato=0;}
                        else{
                            printf("%s cambia %d cart%c.\n",curplayer->nome,j+1,j>0?'e':'a');
                            for(;j>=0;j--) lasciacarta(j,curplayer->mano,&mazzo);
                            daicarte(curplayer->mano,&mazzo);
                            curplayer->puntimano=puntimano(curplayer->mano);}}
                    if (curplayer->stato!=0){
                        if (ultimapuntata==0){
                            curplayer->puntata=10+rand()%10;
                            if (curplayer->bilancio>curplayer->puntimano*curplayer->puntata/100)
                                curplayer->puntata=curplayer->puntimano*curplayer->puntata/100;
                            else curplayer->puntata=curplayer->bilancio;
                            curplayer->bilancio-=curplayer->puntata;
                            ultimapuntata=curplayer->puntata;
                            piatto+=curplayer->puntata;
                            printf("%s punta %d$",curplayer->nome,curplayer->puntata);}
                        else{
                            if (curplayer->puntimano>400&&curplayer->bilancio>2*ultimapuntata){
                                curplayer->puntata=2*ultimapuntata;
                                ultimapuntata=curplayer->puntata;
                                idrilancio=i;
                                printf("%s rilancia! La puntata cresce a %d$",curplayer->nome,ultimapuntata);}
                            else{
                                if (ultimapuntata>curplayer->bilancio){
                                    printf("%s mette tutti i suoi soldi nel piatto.",curplayer->nome);
                                    curplayer->puntata=curplayer->bilancio;}
                                else{
                                    curplayer->puntata=ultimapuntata;
                                    printf("%s vede.",curplayer->nome);}}
                            curplayer->bilancio-=curplayer->puntata;
                            piatto+=curplayer->puntata;}
                        printf(" (piatto: %d$)\n",piatto);}}
                getch();}
            else{
                if (giocatori[0].stato==1){
                    if (giocatori[0].bilancio==0){
                        printf("E' il tuo turno! Ma non hai piu' soldi per puntare... Non ti resta che lasciare.");
                        getch();
                        giocatori[0].stato=0;}
                    else{
                        printf("E' il tuo turno! Premi un tasto per guardare le tue carte...\n");
                        getch();
                        choice=5;
                        giocatori[0].puntimano=puntimano(giocatori[0].mano);
                        for (j=0;j<5;j++) cartescelte[j]=0;
                        do{
                            system("cls");
                            printf("Se desideri cambiare le tue carte selezionale ora (tasti [+] e [-], massimo 4).\n");
                            printf(" %c  %c  %c  %c     %c\n",cartescelte[0]?'X':' ',cartescelte[1]?'X':' ',cartescelte[2]?'X':' ',cartescelte[3]?'X':' ',cartescelte[4]?'X':' ');
                            printmano(giocatori[0].mano);
                            printf(" %c  %c  %c  %c     %c\n\n",choice==0?'^':' ',choice==1?'^':' ',choice==2?'^':' ',choice==3?'^':' ',choice==4?'^':' ');
                            printf(" %c %s\n %c Lascia\n",choice==5?'>':' ',giocatori[0].bilancio>ultimapuntata?"Fai la tua puntata":"All in",choice==6?'>':' ');
                            do ch=getch();
                            while (ch!='+'&&ch!='-'&&ch!=13);
                            if (ch=='+') choice=(choice+1)%7;
                            if (ch=='-') choice=(choice+6)%7;
                            if (ch==13&&choice!=5&&choice!=6){
                                cartescelte[choice]=!cartescelte[choice];
                                if (cartescelte[0]&&cartescelte[1]&&cartescelte[2]&&cartescelte[3]&&cartescelte[4])
                                    cartescelte[choice]=!cartescelte[choice];}}
                        while (!(ch==13&&(choice==5||choice==6)));
                        if (choice==6) giocatori[0].stato=0;
                        else {
                            for (j=0;j<5;j++)
                                if (cartescelte[j])
                                    lasciacarta(j,giocatori[0].mano,&mazzo);
                            daicarte(giocatori[0].mano,&mazzo);
                            giocatori[0].puntimano=puntimano(giocatori[0].mano);
                            if (giocatori[0].bilancio<ultimapuntata){
                                printf("Metti tutti i tuoi soldi nel piatto... Premi un tasto e buona fortuna!\n");
                                getch();
                                piatto+=giocatori[0].bilancio;
                                giocatori[0].bilancio=0;}
                            else {
                                if (ultimapuntata==0) giocatori[0].puntata=1;
                                else giocatori[0].puntata=ultimapuntata;
                                do{
                                    system("cls");
                                    printf("Scegli quanto puntare. (Suggerimento: tieni premuto i tasti [+] e [-] per aumentare o diminuire rapidamente.\n");
                                    printmano(giocatori[0].mano);
                                    printf("Piatto: %d$\n%s %d$",piatto,ultimapuntata==0?"Punti":giocatori[0].puntata==ultimapuntata?"Vedi:":"Rilanci a",giocatori[0].puntata);
                                    printf("   (%s %c)\n",giocatori[0].puntata==ultimapuntata?"":"-",giocatori[0].puntata==giocatori[0].bilancio?'\b':'+');
                                    do ch=getch();
                                    while (ch!='+'&&ch!='-'&&ch!=13);
                                    if (ch=='+'&&giocatori[0].bilancio>giocatori[0].puntata) giocatori[0].puntata++;
                                    if (ch=='-'&&giocatori[0].puntata>ultimapuntata&&giocatori[0].puntata>1) giocatori[0].puntata--;}
                                while (ch!=13);
                                piatto+=giocatori[0].puntata;
                                if (ultimapuntata!=0&&giocatori[0].puntata>ultimapuntata) idrilancio=i;
                                ultimapuntata=giocatori[0].puntata;
                                giocatori[0].bilancio-=ultimapuntata;}}}}}}
        if (idrilancio!=-1){
            for (i=0;i<idrilancio;i++)
                if (giocatori[(idmazziere+i)%nplayers].stato==1){
                    if ((idmazziere+i)%nplayers!=0){
                        curplayer=giocatori+(idmazziere+i)%nplayers;
                        if (curplayer->bilancio==0){
                            printf("%s non ha abbastanza denaro, lascia.\n",curplayer->nome);
                            curplayer->stato=0;}
                        else{
                            printf("%s deve scegliere se vedere o meno...\n",curplayer->nome);
                            if (rand()%2){
                                if (curplayer->bilancio>=ultimapuntata-curplayer->puntata){
                                    piatto+=ultimapuntata-curplayer->puntata;
                                    printf("%s vede, e deposita sul piatto i restanti %d$\nPiatto: %d$\n",curplayer->nome,ultimapuntata-curplayer->puntata,piatto);
                                    curplayer->bilancio=ultimapuntata-curplayer->puntata;
                                    curplayer->puntata=ultimapuntata;}
                                else {
                                    piatto+=curplayer->bilancio;
                                    curplayer->puntata+=curplayer->bilancio;
                                    curplayer->bilancio=0;
                                    printf("%s mette nel piatto tutti i soldi che gli restano.\nPiatto: %d$\n",curplayer->nome,piatto);}}
                            else {
                                printf("%s lascia.\n",curplayer->nome);
                                curplayer->stato=0;}}
                        getch();}
                    else {
                        if (giocatori[0].bilancio!=0){
                            printf("Tocca a te... Premi un tasto quando sei pronto a scegliere.");
                            getch();
                            choice=0;
                            do{
                                system("cls");
                                printf("Avevi puntato %d$, ma %s ha rilanciato e ora devi mettere altri %d$ nel piatto.\n",giocatori[0].puntata,giocatori[(idmazziere+idrilancio)%nplayers].nome,ultimapuntata-giocatori[0].puntata);
                                printf(" %c Lascia %s Vedi %c\n",choice==0?'>':' ',choice==0?"< ":" >",choice==0?' ':'<');
                                do ch=getch();
                                while (ch!='+'&&ch!='-'&&ch!=13);
                                if (ch=='+'||ch=='-') choice=!choice;}
                            while (ch!=13);
                            if (choice==0) giocatori[0].stato=0;
                            else {
                                if (giocatori[0].bilancio>ultimapuntata-giocatori[0].puntata){
                                    giocatori[0].bilancio-=ultimapuntata-giocatori[0].puntata;
                                    piatto+=ultimapuntata-giocatori[0].puntata;
                                    printf("Metti nel piatto altri %d$, ora il piatto contiene %d$\n",ultimapuntata-giocatori[0].puntata,piatto);
                                    giocatori[0].puntata=ultimapuntata-giocatori[0].puntata;}
                                else{
                                    piatto+=giocatori[0].bilancio;
                                    giocatori[0].puntata+=giocatori[0].bilancio;
                                    giocatori[0].bilancio=0;
                                    printf("Metti tutto quello che ti resta nel piatto... Buona fortuna!\nOra il piatto ha %d$\n",piatto);}}}
                        else{
                            printf("Non hai abbastanza denaro, premi un tasto per lasciare.\n");
                            giocatori[0].stato=0;
                            getch();}}}
            idrilancio=-1;}
        printf("E' il momento di scoprire le carte...\n");
        winner=-1;
        for (i=0;i<nplayers;i++){
            curplayer=giocatori+(idmazziere+i)%nplayers;
            if (curplayer->stato==1){
                printf("\n%s scopre le sue carte:\n",curplayer->nome);
                curplayer->puntimano=puntimano(curplayer->mano);
                printmano(curplayer->mano);
                if (winner==-1||giocatori[winner].puntimano<curplayer->puntimano)
                    winner=(idmazziere+i)%nplayers;}}
        if (winner==0) printf("\nSembra che tu abbia la mano migliore!\nPrendi tutto il piatto.\n",giocatori[0].nome);
        else printf("\nSembra che %s abbia la mano migliore!\n%s prende tutto il piatto.\n",giocatori[winner].nome,giocatori[winner].nome);
        giocatori[winner].bilancio+=piatto;
        piatto=ultimapuntata=0;
        for (i=0;i<nplayers;i++){
            if (giocatori[i].stato!=-1){
                if (giocatori[i].bilancio<=0) {
                    printf("%s eliminato.\n",giocatori[i].nome);
                    giocatori[i].stato=-1;}
                else{
                    giocatori[i].stato=1;
                    for (j=0;j<5;j++) lasciacarta(j,giocatori[i].mano,&mazzo);
                    giocatori[i].puntata=0;}}}
        do idmazziere=(idmazziere+1)%nplayers;
        while (giocatori[idmazziere].stato==-1);
        j=0;
        curplayer=NULL;
        for(i=0;i<nplayers;i++)
            if (giocatori[i].stato==1){
                j++;
                curplayer=giocatori+i;}
        if (j==1) printf("%s vince!\nFine partita.\n",curplayer->nome);
        getch();}
    while(j!=1);
    for (i=0;i<nplayers;i++) free(giocatori[i].nome);
    free(giocatori);
}
