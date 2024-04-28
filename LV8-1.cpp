#include<stdio.h>
#include<stdlib.h>

typedef struct Clanovi{
	char prezime[30];
	char ime[20];
	int sifra;
	char adresa[30];
	int tel;
}CLANOVI;

int main(){
	int odabir=0;
	FILE *pf;
	int i=0;
	int n=0;
	CLANOVI Clanovi[10];
	
	while(odabir!=4){
		printf("Unesite broj za odabir: "); scanf("%d",&odabir);
		switch(odabir){
		case 1:
			pf=fopen("Clanovi.txt","w");
			if(pf==NULL){
				printf("Greska: nije moguce kreirati datoteku clanovi.txt\n");
				exit(-1);
				return 1;
			}
			fclose(pf);
			break;
		case 2:
			pf=fopen("Clanovi.txt","r");
			if(pf==NULL){
				printf("Greska: nije moguce otvoriti datoteku clanovi.txt\n");
				exit(-1);
				return 1;
			}
			else{
				rewind(pf);
				for(i=0;i<n;i++){
					fread(&Clanovi[i],sizeof(CLANOVI),1,pf);
					printf("Clan %d: %s %s\n",i+1,Clanovi[i].ime,Clanovi[i].prezime);
				}
			}
			fclose(pf);
			break;
		case 3:
			printf("Koliko clanova unosite: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("\nPodaci od %d clana: ",i+1);
				printf("\nIme: "); scanf("%s",Clanovi[i].ime);
				printf("\nPrezime: "); scanf("%s",Clanovi[i].prezime);
				printf("\nAdresa: "); scanf("%s",Clanovi[i].adresa);
				printf("\nTel.: "); scanf("%d",&Clanovi[i].adresa);
				printf("\nSifra: "); scanf("%d",&Clanovi[i].adresa);
				fwrite(&Clanovi[i],sizeof(CLANOVI),1,pf);
			}
			fclose(pf);
			break;
		}
	}
	
	return 0;
}

