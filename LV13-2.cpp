#include<stdio.h>

#define indeks(dg,gg) ((dg+gg)/2)

void loadArray(int A[]){
	FILE *fp=NULL;
	fp=fopen("in.txt","r");
	for(int i=0;i<500;i++){
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

void selectionSort (int a[], int n) {
    int i, j, min;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (a[j] < a[min]) 
                min = j;
        swap(&a[i], &a[min]);
    }
}

int binSearch(int A[], int x, int length, int *brk){
	int dg, gg, s;
	dg = 0;
	gg = length-1;
	while (dg<=gg) {
		s = indeks(dg,gg);
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
	int polje[500];
	loadArray(polje);
	selectionSort(polje,500);
	
	int broj;
	do{
		scanf("%d",&broj);
	}while(!(broj>=1 && broj<=1000));
	
	//printf("%d",indeks(50,50));
	
	int res,brk=0;
	res=binSearch(polje,broj,500,&brk);
	printf("REZULTATI:\n");
	if(res!=(-1)){
		printf("Broj je nadjen.");
	}
	else printf("Broj nije nadjen.");
	
	return 0;
}

