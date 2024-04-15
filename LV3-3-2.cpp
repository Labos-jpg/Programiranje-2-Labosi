#include<stdio.h>
#include<stdlib.h>

int** f(int **, int, int,int);

int main(){
	
	int n,m;
	do{
		scanf("%d",&n);
	} while(!(n>=2 && n<=10));
	do{
		scanf("%d",&m);
	} while(!(m>=2 && m<=10));
	
	int k;
	scanf("%d",&k);
	
	int polje[10][10];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&polje[i][j]);
		}
	}
	
	int *pok[10]={NULL};
	
	for(int i=0;i<n;i++){
		*(pok+i)=&polje[i][0];
	}
	
	int **pokazivac=NULL;
	
	pokazivac=f(pok,n,m,k);
	
	if(pokazivac==NULL) return 1;
	
	printf("REZULTATI:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",*(*(pokazivac+i)+j));
		}
		printf("\n");
	}
	
	return 0;
}

int** f(int **p, int n, int m,int k){
	int** poku=NULL;
	
	poku=(int**)calloc(n,sizeof(int*));
	
	if(poku== NULL){
		return NULL;
	}
	
	for(int i=0;i<n;i++){
		*(poku+i)=(int*)calloc(m,sizeof(int));
		
		if(*(poku+i)==NULL) return NULL;
	}
	
	int br;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			br=*(*(p+i)+j);
			*(*(poku+i)+j)=k*br;
		}
	}
	
	return poku;
}
