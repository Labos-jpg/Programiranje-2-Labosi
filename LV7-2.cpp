#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *pf= NULL;
	pf=fopen("in.txt","r");
	
	FILE *pfout=NULL;
	pfout=fopen("out.txt","w");
	
	int n,m;

	if(pf==NULL){
		printf("Datoteka se ne moze otvoriti.\n");
		return 1;
	}
	else{
		fscanf(pf,"%d %d",&n, &m);
		fclose(pf);
	}
	
	//float a[10][10]; moze i ovo al sad bum dinamicko zauzet jer ce vjv tak trazit
	float **a=NULL;
	a=(float**)malloc(n*sizeof(float*));
	for(int i=0;i<n;i++){
		a[i]=(float*)malloc(m*sizeof(float));
		if(a[i]==NULL) return 1;
	}
	
	
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%f",&a[i][j]);
		}
	}
	
	if(pfout==NULL){
		printf("Datoteka se ne moze otvoriti.\n");
		return 1;
	}
	else{
		for(i=0;i<n-1;i++){
			for(j=1;j<m;j++){
				fprintf(pfout,"%.2f\t",a[i][j]);
			}
			fprintf(pfout,"\n");
		}
		fclose(pfout);
	}
	
	for(i=0;i<n-1;i++){
		for(j=1;j<m;j++){
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
	
	return 0;
}

