#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* next;
}*top;

struct node* push(struct node* top)
{

  struct node* new_node,*ptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);

  if(top==NULL)
  {
    top=new_node;
    new_node->next=NULL;
  }
  else
  {
  ptr=top;
  new_node->next=ptr;
  top=new_node;
  }
  return top;
}

struct node* pop(struct node* top)
{

  if(top==NULL)
  {
    printf("Stack is underflow\n");
  }
  else
  {
  struct node *ptr,*preptr;
  preptr=top;
  ptr=preptr->next;
  top=ptr;
  printf("%d was popped\n",preptr->data);
  free(preptr);
  }
  return top;
}

void peek(struct node* top)
{
  if(top==NULL)
  {
    printf("Stack is underflow\n");
  }
  else
  {
  printf("Element at the top of the stack is : %d \n", top->data);
  }
}

void display(struct node* top)
{
  if(top==NULL)
  {
    printf("Stack is underflow\n");
  }
  else
{
  struct node *tempnode;
  tempnode=top;
  printf("Elements in the Stack are:\n");
  while(tempnode!=NULL)
  {
    printf("%d ->\n",tempnode->data);
    tempnode=tempnode->next;
  }
}
}

int main()
{

	int option;
	do
	{
		printf("-------------MENU-------------\n");
		printf("1)push \n");
		printf("2)pop \n");
		printf("3.PEEK \n");
		printf("4)Display the queue \n");
		printf("5.EXIT \n");
		printf("Enter an option \n");
		scanf("%d",&option);

		switch(option)
		{
			case 1:
			top=push(top);
			break;
			case 2:
			top=pop(top);
			break;
			case 3:
			peek(top);
			break;
			case 4:
			display(top);
			break;
			case 5:
			exit(0);
			break;
			default:
			printf("Invalid input\n");
		}
	}while(1);
	return 0;
}
