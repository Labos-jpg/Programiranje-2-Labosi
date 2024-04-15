#include<stdio.h>

int main(){
	FILE *pfdat= NULL;
	FILE *pfstu= NULL;
	pfdat=fopen("Dat.txt","r");
	pfstu=fopen("Studenti.txt","w");
	int n;
	char ime[20];
	char prezime[30];
	if(pfdat==NULL){
		printf("Datoteka se ne moze otvoriti.\n");
		return 1;
	}
	else{
		fscanf(pfdat,"%d",&n);
	}
	if(pfstu==NULL){
		printf("Datoteka se ne moze otvoriti.\n");
		return 1;
	}
	else{
		for(int i=0;i<n;i++){
		scanf("%19s",ime);
		scanf("%29s",prezime);
		fprintf(pfstu,"%s %s\n",ime,prezime);
		}
	}
	fclose(pfdat);
	fclose(pfstu);
	return 0;
}

