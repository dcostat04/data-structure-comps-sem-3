#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num;
struct node
{
  int data;
  struct node* next;
}*start,*new_node,*ptr;

struct node* create ( struct node* start)
{
    printf("Enter -1 to end the linked list\n");
    printf("Enter the data\n");
    scanf("%d",&num);
  while(num!=-1)
  {
  new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=num;
  new_node->next=NULL;

  if(start==NULL)
  {
    start=new_node;
  }
  else
  {
    ptr=start;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=new_node;
  }
  printf("Enter the data\n");
    scanf("%d",&num);
  }
  return start;
}

void display(struct node* start)
{
  struct node *tempnode;
  tempnode=start;
  printf("Elements in the Singly Linked List are:\n");
  while(tempnode!=NULL)
  {
    printf("%d ->\n",tempnode->data);
    tempnode=tempnode->next;
  }
}

struct node* insertbeg(struct node* start)
{
  struct node* new_node,*ptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  ptr=start;
  new_node->next=ptr;
  start=new_node;
  return start;
}

struct node* insertend(struct node* start)
{
  struct node* new_node,*ptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  new_node->next=NULL;
  if(start==NULL)
  {
    start=new_node;
  }
  else
  {
  ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=new_node;
  }
  return start;
}

struct node* insertbefore(struct node* start)
{
  int num;
  struct node *new_node,*ptr,*preptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the Number from the list before which you want to enter\n");
  scanf("%d",&num);


  ptr=start;
  while(ptr->data!=num)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  if(ptr==start)
  {
    start=insertbeg(start);
  }
  else
  {
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  preptr->next=new_node;
  new_node->next=ptr;
  }
  return start;
}

struct node* insertafter(struct node* start)
{
  int num;
  struct node *new_node,*ptr,*preptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the Number from the list after which you want to enter\n");
  scanf("%d",&num);


  preptr=start;
  while(preptr->data!=num)
  {
    preptr=preptr->next;
  }
  if(preptr==NULL)
  {
    start=insertend(start);
  }
  else
  {
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  ptr=preptr->next;
  new_node->next=ptr;
  preptr->next=new_node;
  }
  return start;
}

struct node* deletebeg(struct node* start)
{
  struct node *ptr,*preptr;
  preptr=start;
  ptr=preptr->next;
  start=ptr;
  free(preptr);
  return start;
}

struct node* deleteend(struct node* start)
{
  struct node *ptr,*preptr;
  ptr=start;
  while (ptr->next!=NULL)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=NULL;
  free(ptr);
  return start;
}

struct node* deletebefore(struct node* start)
{
  int data;
  struct node *ptr,*preptr,*afptr;

  printf("Enter the Number from the list before which you want to delete\n");
  scanf("%d",&data);


  afptr=start;
  while(afptr->data!=data)
  {
    preptr=ptr;
    ptr=afptr;
    afptr=afptr->next;
  }
  if(ptr==start)
  {
      printf(" Error: entered first number \n");
      return deletebeg(start);
  }

  preptr->next=afptr;
  free(ptr);
  return start;
  }


struct node* deleteafter(struct node* start)
{
  int data;
  struct node *ptr,*preptr,*afptr;

  printf("Enter the Number from the list after which you want to delete\n");
  scanf("%d",&data);


  preptr=start;
  while(preptr->data!=data)
  {
    preptr=preptr->next;
  }
  ptr=preptr->next;
  if(ptr->next==NULL)
  {
    return deleteend(start);
  }
  afptr=ptr->next;
  preptr->next=afptr;
  free(ptr);
  return start;
}

void search(struct node* start)
{
  int i=1,num,flag=0;
  struct node *ptr;
  printf("Enter the node that you want to search for:\n");
  scanf("%d",&num);
  ptr=start;
  while(ptr->data!=num)
  {

    ptr=ptr->next;
    i++;
    if(ptr==NULL)
    {

      flag=1;
      break;
    }

  }
  if(flag==1)
{
  printf("Node not found in the list\n");
}
else
{
  printf("Node found at position number %d in the CLL\n",i);
}
}
struct node *delete_list(struct node *start)
{
      struct node *ptr;
       if(start!=NULL)
       {
          ptr=start;
          while(ptr != NULL)
         {
            printf("\n %d is to be deleted next", ptr -> data);
           start = deletebeg(ptr);
            ptr = start;
         }
       }
return start;
}
struct node *sort_list(struct node *start)
{
   struct node *ptr1, *ptr2;
   int temp;
   ptr1 = start;
   while(ptr1 -> next != NULL)
   {
      ptr2 = ptr1 -> next;
      while(ptr2 != NULL)
      {
          if(ptr1 -> data > ptr2 -> data)
          {
            temp = ptr1 -> data;
            ptr1 -> data = ptr2 -> data;
            ptr2 -> data = temp;
          }
          ptr2 = ptr2 -> next;
      }
      ptr1 = ptr1 -> next;
    }
return start;
}




int main()
{
  int option;

  do
  {
    printf("**MENU FOR  SINGLY LINKED LIST**\n");
    printf("1)CREATE A SINGLY LINKED LIST\n");
    printf("2)DISPLAY\n");
    printf("3)INSERT AT THE BEGINNING\n");
    printf("4)INSERT AT THE END\n");
    printf("5)INSERT  BEFORE THE GIVEN NODE\n");
    printf("6)INSERT  AFTER THE GIVEN NODE\n");
    printf("7)DELETE AT THE BEGINNING\n");
    printf("8)DELETE AT THE END\n");
    printf("9)DELETE BEFORE THE GIVEN NODE\n");
    printf("10)DELETE AFTER THE GIVEN NODE\n");
    printf("11)SEARCH THE GIVEN NODE\n");
    printf("12) DELETE THE ENTIRE LIST\n");
    printf("13) SORT THE LIST\n ");
    printf("14)EXIT\n");
    printf("Enter an option\n");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
        start=create(start);
        break;
      case 2:
        display(start);
        break;
      case 3:
        start=insertbeg(start);
        break;
      case 4:
        start=insertend(start);
        break;
      case 5:
        start=insertbefore(start);
        break;
      case 6:
        start=insertafter(start);
        break;
      case 7:
        start=deletebeg(start);
        break;
      case 8:
        start=deleteend(start);
        break;
      case 9:
        start=deletebefore(start);
        break;
      case 10:
        start=deleteafter(start);
        break;
      case 11:
        search(start);
        break;
      case 12:
        start = delete_list(start);
        printf("\n LINKED LIST DELETED");
        break;
      case 13:
      start = sort_list(start);
      break;
    }

  }while(option!=14);

  return 0;
}
