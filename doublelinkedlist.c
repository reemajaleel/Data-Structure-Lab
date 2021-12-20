#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left,*right;
};
struct node*start=(struct node*)0;
void main()
{
void insert(int);
void delete(int);
struct node*search(int),*t;
int data,c;
do
{
printf("1.insert\n");
printf("2.search\n");
printf("3.delete\n");
printf("4.exit\n");
printf("enter your choice\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("enter the element to insert\n");
scanf("%d",&data);
insert(data);
break;
case 2:
printf("enter the data to search\n");
scanf("%d",&data);
t=search(data);
if(t==(struct node*)0)
printf("data not found\n");
else
printf("data found\n");
break;
case 3:
printf("enter the data to delete\n");
scanf("%d",&data);
delete(data);
break;
case 4:
exit(1);
}
}
while(1);
}
//function to insert a node at beginning of doubly linked list
void insert(int data)
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
if(start==(struct node*)0)
t->left=t->right=(struct node*)0;
else
{
t->left=(struct node*)0;
t->right=start;
start->left=t;
}
start=t;
}
//search item
struct node*search(int data)
{
struct node*t=start;
while(t!=(struct node*)0 &&t->data!=data)t=t->right;
return t;
}
//delete item
void delete(int data)
{
struct node*t;
t=search(data);
if(t==0)
printf("item not found\n");
else
{
if(t==start)
if(t->right==(struct node*)0)
start=(struct node*)0;
else
{
t->right->left=t->left;
start=t->right;
}
else
if(t->right==(struct node*)0)
t->left->right=t->right;
else
{
t->left->right=t->right;
t->right->left=t->left;
}
}
free(t);
}
