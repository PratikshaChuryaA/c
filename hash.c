#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define m 5
int a[10],l;
void init_hashtable()
{
int i;
for(i=0;i<m;i++)//m is hash size
a[i]=0;
}
void display()
{
int i;
printf("******Hash table ******\n");
printf("Locat :");
for(i=0;i<m;i++)//print location
{
printf(" %d\t",i);
}
printf("\n");
printf("Value :");
for(i=0;i<m;i++)//print the values
{
printf(" %d\t",a[i]);
}
}
int compute_hashvalue(int k)
{
return k%m;
}
void main()
{
int i,k,ch,c=0;
init_hashtable();//initialize hash values to 0
display();// display the hash table
printf("\n1.Insert key\n2.Resolve collision-Linear Probing\n3.Exit \n");
while(1)
{
printf("\nEnter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the key k which is a four digit integer: ");
scanf("%d",&k);
l=compute_hashvalue(k);
printf("\nThe item is: %d \nThe position is: %d\n",k,l);
if(a[l]!=0)//detect collision
{
printf("!!! COLLISION HAS OCCURED !!!\n");
break;
}
else
{
a[l]=k;
display();
}
break;
case 2:
c=0;
while(a[l]!=0 && c<m)
{
l=(l+1)%m;
c++;//find empty slot using linear probing
}
if(c==m)//insert if empty slot found
{
printf("Hash table full \n");
}
else
{
a[l]=k;
display();
}
break;
case 3:exit(0);
break;
default: printf("WRONG CHOICE \n");
break;
}
}
}
