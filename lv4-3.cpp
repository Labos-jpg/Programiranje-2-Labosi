#include<stdio.h>
#include<stdlib.h>
int main()
{
	float min=10, max=0, polje[12], suma=0;
	int i=0, n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f",&polje[i]);
		suma=suma+abs(polje[i]);
	}
	for(i=0;i<n;i++)
	{
		if(polje[i]<0) polje[i]=suma;
		printf("%.2f ",polje[i]);
	}
	return 0;
}
