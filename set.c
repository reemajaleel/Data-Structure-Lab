#include<stdio.h>
struct bit
{
unsigned char x:1;
};
int uset[]={1,2,3,4,5,6,7,8,9},size=9;
void main()
{
void readset(struct bit[],int);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersect(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[9]={0};
struct bit b[9]={0};
struct bit c[9]={0};
int n,m;
printf("Enter size of set A : ");
scanf("%d",&n);
readset(a,n);
printf("Enter size of set B : ");
scanf("%d",&m);
readset(b,m);
printf("Set A : ");
printset(a);
printf("Set B : ");
printset(b);
unionset(a,b,c);
printf("AUB=");
printset(c);
intersect(a,b,c);
printf("AIB=");
printset(c);
difference(a,b,c);
printf("A-B=");
printset(c);
}
void readset(struct bit a[],int n) //function to read a bit and store as bit string
{
int i,x,k;
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++)
{
scanf("%d",&x);
for(k=0;k<size;k++)
{
if(x==uset[k]) //if x is member of uset
{
a[k].x=1; //set 1 corresponding to x on a[]
break;
}
}
}
}
void printset(struct bit a[]) //function to print a set from bit string representation
{
int k;
printf("{");
for(k=0;k<size;k++)
{
if(a[k].x==(unsigned char)1)
{
printf("%d,",uset[k]);
}
}
printf("\b}\n");
return;
}
void unionset(struct bit a[],struct bit b[],struct bit c[]) //function to find union of two sets
{
int k;
for(k=0;k<size;k++)
{
c[k].x=a[k].x | b[k].x;
}
return;
}
void intersect(struct bit a[],struct bit b[],struct bit c[]) //function to find intersect of two sets
{
int k;
for(k=0;k<size;k++)
{
c[k].x=a[k].x & b[k].x;
}
return;
}
void difference(struct bit a[],struct bit b[],struct bit c[]) //function to find difference of two sets
{
int k;
for(k=0;k<size;k++)
{
c[k].x=a[k].x &! b[k].x;
}
return;
}
