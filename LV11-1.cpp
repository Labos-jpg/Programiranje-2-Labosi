#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateArray(int A[],int n){
	FILE *fp=NULL;
	fp=fopen("in1.txt","w");
	for(int i=0;i<n;i++){
		fprintf(fp,"%d ",(rand()%1000+1));
	}
	fclose(fp);
}

void loadArray(int A[],int n){
	FILE *fp=NULL;
	fp=fopen("in1.txt","r");
	for(int i=0;i<n;i++){
		fscanf(fp,"%d ",&A[i]);
	}
	fclose(fp);
}

int sekvSearch(int A[], int x, int length, int *brk){
	for(int i=0;i<length;i++){
		(*brk)++;
		if(A[i]==x){
			return i;
		}
	}
	return -1;
}

int main(){
	srand((unsigned)time(NULL));
	int polje[500],brk=0,br,n,res;
	//generateArray(polje,500);
	loadArray(polje,500);
	
	printf("Upisi broj koji zelis pronaci: ");
	scanf("%d",&br);
	n=sizeof(polje)/sizeof(int);
	
	res=sekvSearch(polje,br,n,&brk);
	printf("REZULTATI:\n");
	if(res!=(-1)) printf("Broj %d je pronadjnen nakon %d koraka.",br,brk);
	else printf("Broj %d nije pronadjen.",br);
	
	return 0;
}

