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

void swap(int *x ,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void bubbleSort(int A[], int n){
	int i,j,chg;
	for(i=0,chg=1;chg;i++){
		chg=0;
		for(j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
				chg=1;
			}
		}
	}
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

int binSearch(int A[], int x, int length, int *brk){
	int dg, gg, s;
	dg = 0;
	gg = length-1;
	while (dg<=gg) {
		s = (dg+gg)/2;
		(*brk)++;
		if (x == A[s]) {
			return s;
		}
		else if (x>A[s])
			dg = s+1;
		else if (x<A[s])
			gg = s-1;
		}
	if (dg>gg) return -1;
}

int main(){
	srand((unsigned)time(NULL));
	int polje[500],brks=0,brkb=0,n,resSek,resBin,srSekv,srBin,ukSek=0,ukBin=0,brpSek=0,brpBin=0;
	int brojevi[5];
	
	
	//generateArray(polje,500);
	loadArray(polje,500);
	
	printf("Unesi brojeve za pretragu: ");
	for(int i=0;i<5;i++){
		scanf("%d",&brojevi[i]);
	}
	
	n=sizeof(polje)/sizeof(int);
	
	bubbleSort(polje,500);

	printf("REZULTATI:\n");
	printf("Sekvencijalno:\n");
	for(int i=0;i<5;i++){
		resSek=sekvSearch(polje,brojevi[i],n,&brks);
		if(resSek!=(-1)){
			printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,brojevi[i],brks);
			ukSek+=brks;
			brks=0;
			brpSek++;
		}
		else
			printf("%d. broj %d nije pronadjen.\n",i+1,brojevi[i]);
		brks=0;
	}
	
	printf("\n\n");
	
	printf("Binarno:\n");
	for(int i=0;i<5;i++){
		resBin=binSearch(polje,brojevi[i],n,&brkb);
		if(resBin!=(-1)){
			printf("%d. broj %d je pronadjen u %d koraka.\n",i+1,brojevi[i],brkb);
			ukBin+=brkb;
			brkb=0;
			brpBin++;
		}
		else
			printf("%d. broj %d nije pronadjen.\n",i+1,brojevi[i]);
		brkb=0;
	}
	
	printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n",(float)ukSek/brpSek);
	printf("Srednji broj koraka za binarno pretrazivanje je: %.2f\n",(float)ukBin/brpBin);
	return 0;
}
