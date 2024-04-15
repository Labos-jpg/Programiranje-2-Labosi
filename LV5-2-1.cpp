#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct artikl{
	char naziv[5];
	float cijena;
	int kol;
}ARTIKL;


void unesiPodatkeRacuna(ARTIKL *a, int n){
	for(int i=0;i<n;i++){
		getchar();
		printf("Unesi %d. artikl:\n",i+1);
		printf("IME:");
		fgets(a[i].naziv,50,stdin);
		getchar();
		printf("CIJENA:");
		scanf("%f",&a[i].cijena);
		printf("KOL:");
		scanf("%d",&a[i].kol);
	}
}

void ispisRacuna(char k[], char p[],ARTIKL *a, int n){
	printf("REZULTATI:\n");
	printf("Kupac: %s",k);
	printf("Prodavac: %s",p);
	for(int i=0;i<n;i++){
		printf("IME: %s\t",a[i].naziv);
		printf("CIJENA: %.2f\t",a[i].cijena);
		printf("KOL: %d\t",a[i].kol);
	}
}


int main(){
	ARTIKL artikli[10];
	int n;
	char kupac[50],prodavac[50];
	printf("Unesi ime kupca: ");
	fgets(kupac,50,stdin);
	printf("Unesi ime prodavaca: ");
	fgets(prodavac,50,stdin);
	scanf("%d",&n);
	
	unesiPodatkeRacuna(artikli, n);
	ispisRacuna(kupac,prodavac,artikli,n);
	
	return 0;
}
