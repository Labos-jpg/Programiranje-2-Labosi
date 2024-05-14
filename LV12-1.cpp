#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int id;
	char *ime;
	char *prezime;
	float prosjek;
	struct student* nextNode;
}STUDENT;

void unosPodataka(STUDENT*);
float prosjekSvihStudenata(STUDENT*);
STUDENT* createSLList(void);
STUDENT* insertNewSLList(STUDENT*);
void traverseSLList(STUDENT*);
STUDENT* searchSLList(STUDENT*,int);
void deleteNodeSLList(STUDENT**,STUDENT*);

int main(){
	int brojStudenata;
	printf("Unesite broj studenata: "); scanf("%d",&brojStudenata);
	
	STUDENT* headNode=createSLList();
	
	if(headNode==NULL){
		return 1;
	}
	

	for(int i=0;i<brojStudenata-1;i++){
		headNode=insertNewSLList(headNode);
	}
	
	int trazeniStudent;
	printf("Unesi ID trazenog studenta: "); scanf("%d",&trazeniStudent);
	
	printf("REZULTATI:\n");
	traverseSLList(headNode);
	printf("Ukupan prosjek svih studenata: %.2f\n",prosjekSvihStudenata(headNode));
	STUDENT* targetNode=searchSLList(headNode,trazeniStudent);
	deleteNodeSLList(&headNode,targetNode);
	traverseSLList(headNode);
	printf("Ukupan prosjek svih studenata: %.2f\n",prosjekSvihStudenata(headNode));
	
	return 0;
}

void unosPodataka(STUDENT* pok){
	pok->ime=(char*)malloc(30*sizeof(char));
	pok->prezime=(char*)malloc(40*sizeof(char));
		
	if(pok->ime==NULL || pok->prezime==NULL){
		perror("Zauzimanje");
		return;
	}
		
	printf("Unesite id: "); scanf("%d",&pok->id);
	printf("Unesite ime: "); scanf("%s",pok->ime);
	printf("Unesite prezime: "); scanf("%s",pok->prezime);
	printf("Unesite prosjek: "); scanf("%f",&pok->prosjek);
}

float prosjekSvihStudenata(STUDENT *traverseNode){
	int br=0;
	float prosjek, suma=0;
	
	while(traverseNode){
		br++;
		suma+=traverseNode->prosjek;
		traverseNode=traverseNode->nextNode;
	}
	prosjek=(float)suma/br;
	return prosjek;
}

STUDENT* createSLList(void){
	STUDENT* headNode=(STUDENT*)calloc(1,sizeof(STUDENT));

	if(headNode==NULL){
		perror("Kreairanje");
		return NULL;
	}
		
	else{
		unosPodataka(headNode);
		headNode->nextNode=NULL;
	}
	return headNode;
}

STUDENT* insertNewSLList(STUDENT* headNode){
	
	STUDENT* newHeadNode=(STUDENT*)malloc(1*sizeof(STUDENT));
	if(newHeadNode==NULL){
		perror("Kreairanje");
		return NULL;
	}
	else{
		unosPodataka(newHeadNode);
		newHeadNode->nextNode=headNode;
	}
	
	return newHeadNode;
}

void traverseSLList(STUDENT* traverseNode){
	while(traverseNode){
		printf("ID: %d - %s %s, prosjek: %.2f\n",traverseNode->id, traverseNode->ime, traverseNode->prezime, traverseNode->prosjek);
		traverseNode=traverseNode->nextNode;
	}
}

STUDENT* searchSLList(STUDENT* traverseNode ,int criteria){
	
	if(traverseNode==NULL){
		printf("Student s trazenim ID-em nije pronadjen!");
	}
	
	while(traverseNode){
		if(traverseNode->id==criteria){
			return traverseNode;
		}
		traverseNode=traverseNode->nextNode;
	}
	
	return NULL;
}

void deleteNodeSLList(STUDENT** headNode,STUDENT* targetNode){
	
	if(targetNode==NULL){
		printf("Ne postoji ID za brisanje.\n");
		return;
	}
	
	if(*headNode==targetNode){
		*headNode=(*headNode)->nextNode;
		free(targetNode);
	}
	else{
		STUDENT* traverseNode=*headNode;
		
		while(traverseNode->nextNode){
			if(traverseNode->nextNode==targetNode){
				traverseNode->nextNode=targetNode->nextNode;
				free(targetNode);
				break;
			}
			traverseNode=traverseNode->nextNode;
		}
		
	}
}

