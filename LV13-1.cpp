#include<stdio.h>

enum TJEDAN {ponedjeljak=1,utorak,srijeda,cetvrtak,petak,subota,nedjelja};

int main(){
	enum TJEDAN dan;
	scanf("%d",&dan);
	
	if(dan==subota || dan==nedjelja)
		printf("Vikeeend!");
	else
		printf("Radis jos %d dana do vikenda.",subota-dan);
	
	return 0;
}


