#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct node
{
  int data;
  struct node* next;
}*front,*rear;

struct node* insert(struct node* front)
{
  struct node* new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  new_node->next=NULL;
  if(front==NULL)
  {
    front=new_node;
    rear=new_node;
  }
  else
  {
  rear=front;
  while(rear->next!=NULL)
  {
    rear=rear->next;
  }
  rear->next=new_node;
  rear=new_node;
  }
  return front;
}

struct node* deletes(struct node* front)
{

  if(front==NULL)
  {
    printf("Queue is underflow\n");
  }
  else
  {
  struct node *ptr,*preptr;
  printf("%d was deleted\n",front->data);
  ptr=front->next;
  free(front);
  front=ptr;
  }
  return front;
}

void peek(struct node* front)
{
  if(front==NULL)
  {
    printf("Queue is underflow\n");
  }
  else
  {
  printf("Element at the front of the Queue is : %d \n", front->data);
  }
}

void display(struct node* front)
{
  if(front==NULL)
  {
    printf("Queue is underflow\n");
  }
  else
{
  struct node *tempnode;
  tempnode=front;
  printf("Elements in the Queue are:\n");
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
    printf("----------MENU----------\n");
    printf("1)Insert an element\n");
    printf("2)Delete an element\n");
    printf("3)Peek\n");
    printf("4)Display the queue\n");
    printf("5)Exit\n");
    printf("Enter an option\n");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      front=insert(front);
      break;
      case 2:
      front=deletes(front);
      break;
      case 3:
      peek(front);
      break;
      case 4:
      display(front);
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
