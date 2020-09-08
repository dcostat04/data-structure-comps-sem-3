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
  //new_node->next=start;              //ONLY CHANGE IN CLL COMPARED TO SLL, HERE WE CANNOT USE THE COMMENTED LINE BECOS START IS NULL
  if(start==NULL)                     //INSTEAD WE INITIALIZE NEW_NODE->NEXT TWICE
  {
    new_node->next=new_node;          //THIS HERE IS NOT START BECOS START IS NULL
    start=new_node;
  }
  else
  {
    ptr=start;
    while(ptr->next!=start)
    {
      ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->next=start;
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
  printf("Elements in the CLL are:\n");
  while(tempnode->next!=start)
  {
    printf("%d ->\n",tempnode->data);
    tempnode=tempnode->next;
  }
  printf("%d ->\n",tempnode->data); //THIS IS BECOS IF ONLY ONE NODE IS CREATED IT MUST BE DISPLAYED WHICH CANNOT BE DONE INSIDE THE LOOP
}                                       //ALSO BECOS LOOP STOPS AT LAST NODE

struct node* insertbeg(struct node* start)
{
  struct node* new_node,*ptr,*last;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  ptr=start;  //THE FIRST NODE BEFORE INSERTING AT BEGINNING
  last=start;
  while(last->next!=start)    //TO FIND THE LAST NODE
  {
    last=last->next;
  }
  new_node->next=ptr;
  start=new_node;
  last->next=start;   //WE HAVE TO CHANGE LAST TOO IF START CHANGES THIS DOES NOT CHANGE AUTOMATICALLY
  return start;
}

struct node* insertend(struct node* start)
{
  struct node* new_node,*ptr;
  new_node=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data\n");
  scanf("%d",&new_node->data);
  new_node->next=start;       //next becomes start instead of NULL
  if(start==NULL)
  {
    start=new_node;
    new_node->next=start;
  }
  else
  {
  ptr=start;
  while(ptr->next!=start)
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
  printf("Enter the data before which you want to enter\n");
  scanf("%d",&num);
  ptr=start;
  while(ptr->data!=num)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  if(ptr==start)  //INSERTING BEFORE FIRST NODE
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
  printf("Enter the data after which you want to enter\n");
  scanf("%d",&num);


  preptr=start;
  while(preptr->data!=num)
  {
    preptr=preptr->next;
  }
  if(preptr->next==start)
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
  struct node *ptr,*preptr,*last;
  last=start;
  while(last->next!=start)
  {
    last=last->next;
  }
  preptr=start;
  ptr=preptr->next;
  start=ptr;
  last->next=start;
  free(preptr);
  return start;
}

struct node* deleteend(struct node* start)
{
  struct node *ptr,*preptr;
  ptr=start;
  while (ptr->next!=start)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=start;
  free(ptr);
  return start;
}

struct node* deletebefore(struct node* start)
{
  int data;
  struct node *ptr,*preptr,*afptr;

  printf("Enter the data before which you want to delete\n");
  scanf("%d",&data);

  //printf("before while\n");
  afptr=start;
  while(afptr->data!=data)
  {
    preptr=ptr;
    ptr=afptr;
    afptr=afptr->next;
  }
  if(afptr==start)
    {
      printf("There is no node before the first node \n");
      return start;
    }
  if(ptr==start)
  {
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

  printf("Enter the data after which you want to delete\n");
  scanf("%d",&data);


  preptr=start;
  while(preptr->data!=data)
  {
    preptr=preptr->next;
  }
  if(preptr->next==start)
    {
      printf("There is no node after the last node \n");
      return start;
    }
  ptr=preptr->next;
  if(ptr->next==start)
  {
    return deleteend(start);
  }
  afptr=ptr->next;
  preptr->next=afptr;
  free(ptr);
  return start;
}

struct node* deletenode(struct node* start)
{
  struct node *preptr,*afptr,*ptr;
  printf("Enter the node data that you want to delete\n");
  scanf("%d",&num);
  afptr=ptr=start;
  while(ptr->data!=num)
  {
    preptr=ptr;
    ptr=afptr;
    afptr=afptr->next;
  }
  if(ptr==start)
    {
      return deletebeg(start);
    }
  if(ptr->next==start)
    {
      return deleteend(start);
    }
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
    if(ptr==start)
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

int main()
{
  int option;

  do
  {
    printf("MENU\n");
    printf("1) CREATE A CLL\n");
    printf("2) DISPLAY\n");
    printf("3) INSERT AT THE BEGINNING\n");
    printf("4) INSERT AT THE END\n");
    printf("5) INSERT  BEFORE THE GIVEN NODE\n");
    printf("6) INSERT  AFTER THE GIVEN NODE\n");
    printf("7) DELETE AT THE BEGINNING\n");
    printf("8) DELETE AT THE END\n");
    printf("9) DELETE BEFORE THE GIVEN NODE\n");
    printf("10)DELETE AFTER THE GIVEN NODE\n");
    printf("11)DELETE THE GIVEN NODE\n");
    printf("12)SEARCH THE GIVEN NODE\n");
    printf("13)EXIT\n");
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
        start=deletenode(start);
        break;
      case 12:
        search(start);
        break;
    }

  }while(option!=13);

  return 0;
}
