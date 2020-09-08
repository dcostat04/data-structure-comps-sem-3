
#include <stdio.h>
#include<conio.h>
#include<string.h>
#define max 10
int top=-1;
int stk[max];
void push(char c)
{
    if (top ==(max-1))
    printf("stack overflow\n");
    else
    {
        top=top+1;
        stk[top]=c;
    }
}
char pop()
{
    if (top==-1)
    printf("stack underflow\n");
    else
    return(stk[top--]);
}
void main()
{
    char expe[max],temp;
    int i,flag=1;
    printf("enter an expression\n");
    gets(expe);
    for (i=0;i<strlen(expe);i++)
    {
        if (expe[i]=='('||expe[i]=='{'||expe[i]=='[')
         push(expe[i]);
        if(expe[i]==')'|| expe[i]=='}'||expe[i]==']')
         if(top==-1)
             flag=0;
        else
        {
            temp=pop();
            if(expe[i]==')'&&(temp=='{'||temp=='['))
              flag=0;
             if(expe[i]=='}'&&(temp=='('||temp=='['))
              flag=0;
            if(expe[i]==']'&&(temp=='('||temp=='{'))
             flag=0;
              
        }
    }
    if(top>=0)
      flag=0;
    if (flag==1)
    printf("valid expression\n");
    else
    printf("invalid expression\n");
    
    
}

