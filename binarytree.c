#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left;
struct node*right;
};
struct node*root=(struct node*)0;
void main()
{
void insert(int);
struct node*search(struct node*,int);
void delete(int);
void inorder(struct node*);
int c,d,s,k;
do
{
printf("1.insert\n");
printf("2.search\n");
printf("3.delete\n");
printf("4.display\n");
printf("5.exit\n");
printf("enter your choice :\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("enter data to insert:\n");
scanf("%d",&d);
insert(d);
break;
case 2:
printf("enter data to search:\n");
scanf("%d",&s);
search(root,s);
break;
case 3:
printf("enter data to delete:\n");
scanf("%d",&k);
delete(k);
break;
case 4:
printf("display the data:\n");
inorder(root);
break;
case 5:
printf("exiting...\n");
exit(0);
}
}
while(1);
}
void insert(int x)
{
//create a new node
struct node*t,*t1,*t2;
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->left=t->right=0;
if(root==0) //case of empty tree
{
root=t;
}
else
{
t1=root;
while(t1!=0 && t1->data!=x) //condition to avoid inserting same node
{
t2=t1; //for remembering the parent node
if(x>t1->data)
t1=t1->right;
else
t1=t1->left;
}
if(t1 !=0 && x==t1->data)
printf("duplicate data not allowed\n");
else //actual insertion code block
{
if(x>t2->data) //case of new data greater than parent
t2->right=t;
else //case of new data lower than parent
t2->left=t;
}
}
}

void inorder(struct node*t)
{
if(t!=0)
{
inorder(t->left);
printf("%d\n",t->data);
inorder(t->right);
}
}
//function for searching
struct node*search(struct node*root,int a)
{
if(root==0) //case of empty tree
printf("not found\n");
else if(root->data==a)
{
printf("item found\n");
}
else
{
if(a>root->data) //case of right subtree
return search(root->right,a);

else                                     //case of left subtree
return search(root->left,a);
}
}
//function to delete a node
void delete(int item)
{
struct node*t1,*t2,*t3,*sucpar,*suc;
t1=root;
//loop to find the node to be deleted
while(t1!=0 && t1->data!=item)
{
t2=t1;
if(item>t1->data)
t1=t1->right;
else
t1=t1->left;
}
//after the loop t1 points to the node to be deleted
//t2 points to the parent of the node to be deleted
//t1==0 implies not found
if(t1==0)
printf("not found\n");
else //element found case
{
if(t1->right==0 && t1->left==0) //case of leaf node
{
if(t1!=root)
{
if(t2->data>item)
t2->left=0;
else
t2->right=0;
}
else
root=0;
}
else if(t1->left==0 || t1->right==0)
{
if(t1!=root)
{
if(item>t2->data) //case of deleting node on the right side of parent
t2->right=t1->left==0?t1->right:t1->left;
else //case of deleting node on the left side of parent
t2->left=t1->left==0?t1->right:t1->left;
}
else
{
if(root->right!=0)
root=root->right;
else
root=root->left;
}
}
else
{
//case of two child
//inorder successor will be left extreme of right subtree
sucpar=t1;
suc=t1->right;
while(suc->left!=0)
{
sucpar=suc;
suc=suc->left;
}
//copy the inorder successor to the node to be deleted
t1->data=suc->data;
//next step is to add link to inorder successor parents
//for that we need to find it is left or right
if(suc->data<sucpar->data)
{
sucpar->left=suc->right;
}
else
sucpar->right=suc->right;
t1=suc;
}
free(t1); //common removal for all cases
printf("Item deleted...\n");
}
}
