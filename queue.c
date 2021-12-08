#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=0,rear=0;
int q[size];
int flag;
void main()
{
void insert(int);
int delete();
int search(int);
int c,d,k;
do
{
printf("1.insert\n");
printf("2.delete\n");
printf("3.search\n");
printf("4.exit\n");
printf("enter your option\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("enter the value to insert:\n");
scanf("%d",&d);
insert(d);
break;
case 2:
d=delete();
if(flag==1)
{
printf("the deleted item is:%d\n",d);
}
break;
case 3:
printf("enter the value to search:\n");
scanf("%d",&d);
k=search(d);
if(k==0)
printf("item not found\n");
break;
case 4:
printf("exit\n");
exit(0);
}
}
while(1);
}
void insert(int x)
{
int t;
t=(rear+1)%size;
if(front==t)
{
printf("quene is full");
return;
}
else
{
rear=t;
q[rear]=x;
printf("item inserted\n");
}
}
int delete()
{
int r;
if(front==rear)
{
flag=0;
printf("quene is empty\n");
}
else
{
front=(front+1)%size;
flag=1;
return q[front];
}
}
int search(int item)
{
int f,r;
f=front;
r=rear;
while(f!=r)
{
f=(f+1)%size;
if(q[f]==item)
{
printf("item found\n");
return 1;
}
}
return 0;
}
