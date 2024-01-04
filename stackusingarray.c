#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
void main()
{
int n,ch;
do
{
printf("\n1.push\n2.pop\n3.display\n4.exit");
printf("\nenter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("enter the element to insert: ");
scanf("%d",&n);
push(n);
break;
}
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("exiting");
break;
default:
printf("enter a valid choice");
};
}
while(ch!=4);
}
struct node
{
int data;
struct node*link;
}*top,*top1,*temp;
void push(int n)
{
if(top==NULL)
{
top=(struct node*)malloc(1*sizeof(struct node));
top->link=NULL;
top->data=n;
}
else
{
temp=(struct node*)malloc(1*sizeof(struct node));
temp->link=top;
temp->data=n;
top=temp;
}
}
void pop()
{
top1=top;
if(top1==NULL)
{
printf("empty");
}
else
{
top1=top->link;
printf("popped element %d\n",top->data);
free(top);
top=top1;
}
}
void display()
{
top1=top;
if(top1==NULL)
{
printf("empty");
}
else
{
while(top1!=NULL)
{
printf("%d->",top1->data);
top1=top1->link;
}
}
}
