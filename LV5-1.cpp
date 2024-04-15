#include<stdio.h>
#include<math.h>

typedef struct tocka{
	int x;
	int y;
	int z;
}TOCKA;

typedef struct trokut{
	TOCKA *t1;
	TOCKA *t2;
	TOCKA *t3;
}TROKUT;

void unesiTocke(TOCKA *p, int n){
	for(int i=0;i<n;i++){
		printf("Unesi koordinate za %d tocku: ",i);
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
	}
}

void unesiTrokute(TROKUT *t, TOCKA *p, int m){
	int ind1,ind2,ind3;
	for(int i=0;i<m;i++){
		printf("Unesi indekse tocaka za %d. trokut: ",i+1);
		scanf("%d %d %d",&ind1,&ind2,&ind3);
		t[i].t1=&p[ind1];
		t[i].t2=&p[ind2];
		t[i].t3=&p[ind3];
	}
}


float pronadjiNajveciOpseg(TROKUT *t, int m){
	float max_opseg=0,str12,str23,str31;
	for(int i=0;i<m;i++){
		str12=sqrt(pow(t[i].t2->x-t[i].t1->x,2)+pow(t[i].t2->y-t[i].t1->y,2)+pow(t[i].t2->z-t[i].t1->z,2));
		str23=sqrt(pow(t[i].t3->x-t[i].t2->x,2)+pow(t[i].t3->y-t[i].t2->y,2)+pow(t[i].t3->z-t[i].t2->z,2));
		str31=sqrt(pow(t[i].t3->x-t[i].t1->x,2)+pow(t[i].t3->y-t[i].t1->y,2)+pow(t[i].t3->z-t[i].t1->z,2));
		if(max_opseg<(str12+str23+str31)){
			max_opseg=str12+str23+str31;
		}
	}
	return max_opseg;
}

int main()
{
	int n,m;
	scanf("%d",&n); //broj tocaka
	scanf("%d",&m); //broj trokuta
	
	TOCKA tocke[10];
	TROKUT trokuti[10];
	
	unesiTocke(tocke,n);
	unesiTrokute(trokuti,tocke,m);
	
	float opseg=pronadjiNajveciOpseg(trokuti,m);
	
	printf("REZULTATI:\n");
	printf("%.2f",opseg);

	return 0;
}
