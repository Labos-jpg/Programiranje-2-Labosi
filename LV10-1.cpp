#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct tocka{
	float x;
	float y;
	float z;
}TOCKA;

typedef struct trokut{
	TOCKA *t1;
	TOCKA *t2;
	TOCKA *t3;
}TROKUT;

float Str(TOCKA *p1,TOCKA *p2){
	return sqrt(pow(p1->x - p2->x,2)+pow(p1->y - p2->y,2)+pow(p1->z - p2->z,2));
}

float Opseg(TROKUT t){
	return Str(t.t1,t.t2)+Str(t.t1,t.t3)+Str(t.t2,t.t3);
}

int main(){
	TOCKA *p;
	TROKUT *t;
	FILE *pf;
	pf=fopen("model.txt","r");
	
	int n,m;
	fscanf(pf,"%d %d",&n,&m);
	
	p=(TOCKA*)malloc(n*sizeof(TOCKA));
	if(p==NULL){
		printf("Error");
		return 1;
	}
	
	t=(TROKUT*)malloc(m*sizeof(TROKUT));
	if(t==NULL){
		printf("Error");
		return 1;
	}
	int ind1,ind2,ind3;
	for(int i=0;i<n;i++){
		fscanf(pf,"%f%f%f",&p[i].x,&p[i].y,&p[i].z);
		//printf("%f %f %f\n",p[i].x,p[i].y,p[i].z);
	}
	for(int i=0;i<m;i++){
		fscanf(pf,"%d%d%d",&ind1,&ind2,&ind3);
		t[i].t1=&p[ind1];
		t[i].t2=&p[ind2];
		t[i].t3=&p[ind3];
	}
	
	TROKUT *max;	
	float max_op=0;

	for(int i=0;i<m;i++){
		if(max_op<Opseg(t[i])){
			max_op=Opseg(t[i]);
			max=&t[i];
		}
	}
	
	printf("REZULTATI:\n");
	printf("Najveci opseg je %.2f od trokuta cije su koord.:\n",max_op);
	printf("(%.2f %.2f %.2f)\n",max->t1->x,max->t1->y,max->t1->z);
	printf("(%.2f %.2f %.2f)\n",max->t2->x,max->t2->y,max->t2->z);
	printf("(%.2f %.2f %.2f)\n",max->t3->x,max->t3->y,max->t3->z);
	
	
	fclose(pf);
	free(p);
	free(t);
	p=NULL;
	t=NULL;
	return 0;
}
