#include<stdio.h>
int main()
{
	float min=10, max=0, polje[10];
	int i=0, n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%f",&polje[i]);
		if(polje[i]<=min) min=polje[i];
		if(polje[i]>=max) max=polje[i];
	}
	if(max==min) printf("%.2f",min);
	else printf("%.2f %.2f",min ,max);
	return 0;
}
