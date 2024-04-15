#include<stdio.h>
#include<stdlib.h>

int najveci(int**, int, int);

int main(){
	
	int n,m;
	do{
		scanf("%d",&n);
	} while(!(n>=2 && n<=5));
	do{
		scanf("%d",&m);
	} while(!(m>=2 && m<=8));
	
	int polje[5][8];
	
	int *pok[5]={NULL};
	
	for(int i=0;i<n;i++){
		*(pok+i)=&polje[i][0];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&polje[i][j]);
		}
	}
	
	printf("REZULTATI:\n");
	printf("%d",najveci(pok,n,m));
	
	return 0;
}

int najveci(int **p, int n, int m){
	int max=-1000;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(max<*(*(p+i)+j)) max=*(*(p+i)+j);
		}
	}
	
	return max;
}


