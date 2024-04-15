#include<stdio.h>
int main()
{
	int A[3][4], B[3][4];
	int i=0, j=0;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
		{
			scanf("%d",&A[i][j]);
			B[3-i][4-j]=A[i][j];
		}
			
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",B[i][j]);
		printf("\n");
	}
	return 0;
}
