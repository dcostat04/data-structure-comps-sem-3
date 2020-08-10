
#include<stdio.h>
#include<conio.h>
#define MAX 3
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int x)
{
	if(rear==MAX-1)
	printf("\n OVERFLOW");
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}
int dequeue()
{ int a;
	if(front==-1|| front>rear)
	{
			printf("\n UNDERFLOW");
		return -1;
	}
	else 
	{
		a=queue[front];
		front++;
		return a;
	}
		
}
int peek()
{
		if(front==-1|| front>rear)
	{
			printf("\n UNDERFLOW");
		return -1;
	}
		else{
			return queue[front];
		}
	
}
void display()
{ int i;
	if(front==-1|| front>rear)
		printf("\n UNDERFLOW");
		printf("\n Elements of queue:");
	for(i=front; i<rear+1;i++)
	{
		printf("\n%d",queue[i]);
	}	
}
int main()
{
	int choice,val,ins;
	do
	{
		printf("\n MAIN MENU \n 1.Insert an element \n 2.Delete an element \n 3.Peek \n 4.Display the queue \n 5.EXIT");
		printf("\n Enter your option:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			 printf("\n Enter the number to be inserted in the queue:");
			scanf("%d",&ins);
			enqueue(ins);
			break;
		case 2: 
			val=dequeue();
			if(val!=-1)
			printf("\n The number deleted from the queue:%d",val);
			break;
		case 3:
			val=peek();
			if(val!=-1)
			printf("\nThe first value in the queue:%d",val);
			break;
		case 4:
			display();
			break;	
		}
	} while(choice<5);
getch();
return 0;	
}



