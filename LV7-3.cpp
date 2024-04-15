#include<stdio.h>

void cpy(FILE*, FILE*);

int main(){
	FILE *pf1=NULL;
	FILE *pf2=NULL;
	pf1=fopen("Prva.txt","r");
	pf2=fopen("Druga.txt","w");
	
	if(pf1==NULL){
		printf("Nijesmo mogli otvorit datoteku.");
		return 1;
	}
	else{
		cpy(pf1,pf2);
		fclose(pf1);
		fclose(pf2);
	}
	return 0;
}

void cpy(FILE *fpulaz, FILE* fpizlaz){
	int c;
	while((c=getc(fpulaz))!=EOF){
		if(c>='a' && c<='z'){
			c=c+'A'-'a';
		}
		putc(c,fpizlaz);
	}
}

