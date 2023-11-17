#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*link;
}
*top,*top1,*temp;
void push(int element)
{
if(top == NULL)
{
top=(struct node*)malloc(1*sizeof(struct node));
top->link=NULL;
top->data=element;
}
else
{
temp=(struct node*)malloc(1*sizeof(struct node));
temp->link=top;
temp->data=element;
top=temp;
}
}
void pop()
{
top1=top;
if(top1 == NULL)
{
printf("Empty");
}
else
{
top1=top->link;
printf("%d",top->data);
free(top);
top=top1;
}
}
void display()
{
top1=top;
if(top1 == NULL)
{
printf("Empty");
}
else
{
while(top1 !=NULL)
{
printf("->%d",top1->data);
top1=top1->link;
}
}
}
void main()
{
int ch,num;
do
{
printf("Which function you want: \n\n1.Push \n2.Pop \n3.Display \n4.Exit");
scanf("%d",&ch);
switch(ch)
{
  case 1:
        printf("Enter the number:\n");
        scanf("%d",&num);
        push(num);
        break;
  case 2:
        pop();
        break;
  case 3:
        display();
        break;
   case 4:
        printf("Exited");
        break;
   default:
    printf("Invalid Choice");
    break;
    }
    }while(ch != 4);
    }
