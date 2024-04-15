#include<stdio.h>

int main(){

	int br_mj;

	do{
		scanf("%d",&br_mj);
		if(br_mj<1 || br_mj>12) printf("Nekorektan broj mjeseca.");
	} while(!(br_mj>=1 && br_mj<=12));

	char *mjeseci[12]={"sijecanj","veljaca","ozujak","travanj","svibanj"
	,"lipanj","srpanj","kolovoz","rujan","listopad","studeni","prosinac"};

	printf("REZULTATI:\n");
	printf("%s",*(mjeseci+br_mj-1));

	return 0;
}
