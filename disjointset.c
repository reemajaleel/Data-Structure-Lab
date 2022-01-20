#include<stdio.h>
#include<stdlib.h>


typedef struct		//structure to represent an object of a set in linked representation
{			
int value;			
struct rep*repptr;
struct node*next;
} node;

typedef struct		//structure to represent header node of linked representation of set
{
node*head;			
node*tail;
} rep;

typedef struct		//structure to store key and set representation
{
int key;
rep*repptr;			
struct nodaddr*next;
} nodaddr;

nodaddr*node=0;			//list to store keys and set representation

void main()
{
void makeset();			//initialising functions
rep*find(int);
void unionset(int,int);

makeset(10);
makeset(20);
makeset(30);
makeset(40);
printf("find(10)=%x\n",find(10));
printf("find(20)=%x\n",find(20));
printf("find(30)=%x\n",find(30));
printf("find(40)=%x\n",find(40));

unionset(10,20);
printf("\nAfter union of 10 and 20 \nfind(20)=%x\n",find(20));
unionset(30,40);
printf("\nAfter union of 30 and 40 \nfind(40)=%x\n",find(40));
unionset(20,40);
printf("\nAfter union of 20 and 40 \nfind(40)=%x\n",find(40));
}


void makeset(int a)		//function to create a set for an object
{
nodaddr*t=(nodaddr*)malloc(sizeof(nodaddr));	//create set reference
rep*newset=(rep*)malloc(sizeof(rep));		//create new set
newset->head=(node*)malloc(sizeof(node));	//initialise head and tail
newset->tail=newset->head;			
newset->head->value=a;				//fill values
newset->head->repptr=newset;			//to store set representation pointer and key as linked
newset->head->next=0;
t->repptr=newset;
t->key=a;
t->next=ndr;
ndr=t;
}


rep*find(int x)					//function to return pointer of representation of set containing x
{
nodaddr*t=ndr;
while(t!=0 && t->key!=x)
t=t->next;
return t->repptr;
}
void unionset(int key1,int key2)		//function to find union of two sets corresponding to objects given
{
rep*set1,*set2;
nodaddr*t=ndr;
node*t1;
set1=find(key1);
set2=find(key2);
while(t!=0)
{
if(t->repptr==set2)		//change representative pointer of set containing key 2 to that of key key 1
t->repptr=set1;
t=t->next;
}
t1=set2->head;			//changing header pointer of objects of set 2 to set 1
while(t1!=0)
{
t1->repptr=set1;
t1=t1->next;
}
set1->tail->next=set2->head;	//set the tail of set 1 to set 2 
set1->tail=set2->tail;		//while conditions runs only where set 1 and set 2 are different
free(set2);
}
