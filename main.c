/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<ctype.h> 
#include <conio.h>
#include<string.h>
#define max 100                
float s[max];
int top = -1;
float post(char ch[]);
void push(float s[],float val)      
{
 if (top ==(max-1))
    printf("stack overflow\n");
    else
    {
        
        top=top+1;
        s[top]=val;
    }
}
float pop(float s[])
{
    float val=-1;
	if (top==-1)
    printf("stack underflow\n");
    else
    {
        val=s[top];
        top--;
    }
  return(val);
}
int main()
{
	float val;
	char ch[100];
	printf("\nEnter a postfix expression: ");
	gets(ch);
	val= post(ch);
	printf("\nvalue of postfix expression= %f",val);
	getch();
	return 0;
}	
float post(char ch[])
{
    int i=0;
    float a,b,result;
    while(ch[i]!=0)
    {
		if(isdigit(ch[i]))
		{
			push(s,(float)(ch[i]-'0'));
		}
		else 
		{
			b = pop(s);
			a = pop(s);
			
			switch(ch[i])
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '%': result = (int)a % (int)b;
					  break;	  
			}
			
			push(s,result);
		}		
	    i++;
	}
	return(result);
}	

