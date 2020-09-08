
#include <stdio.h>
#include<ctype.h> 
#include <conio.h>
#include<string.h>
#define max 100                
char s[max];
int top = -1;
void push(char element)      
{
 if (top ==(max-1))
    printf("stack overflow\n");
    else
    {
        top=top+1;
        s[++top]=element;
    }
}
char pop()
{
	if (top==-1)
    printf("stack underflow\n");
    else
  return(s[top--]);
}
int priority(char element){
	switch (element)
	{
	case '(':
	return 1;
	
	case '+':
	case '-':
	return 2;
	
	case '*':
	case '/':
	return 3;
	}
}
 
int main()
{
	char infix[50],postfix[50],ch,element;
	int i=0,k=0;
	printf("enter infix expression\n");
	gets(infix);
	while((ch = infix[i++])!='\0'){
		if(ch=='(')
		push(ch);
		else if(isalnum(ch))
		postfix[k++]=ch;
		else if(ch==')'){
			while(s[top]!='(')
			{
			postfix[k++]=pop();
			}
			element=pop();                    
		}
		else
		{
			while(priority(s[top])>=priority(ch))   
			postfix[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#'){
		postfix[k++]=pop();
	}
	postfix[k]='\0';
	printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n", infix, postfix);
	return 0;
}
