#include<stdio.h>
#include<conio.h>
#include<string.h>
int top=-1,index=0,pos=0,len;
char symbol,temp,infix[20],stack[20],postfix[20];
void push(char symbol);
char pop();
char pred(char symbol);
void infixtopostfix();
void main()
{
    printf("Enter the infix expression:");
    scanf("%s",infix);
    infixtopostfix();
    printf("Infix expression:\n%s",infix);
    printf("\nPostfix expression:\n%s",postfix);
    getch();
}
void infixtopostfix()
{
    len=strlen(infix);
    push('#');
    while(index<len)
    {
        symbol=infix[index];
        switch(symbol)
        {
            case '(':push(symbol);
                    break;
            case ')':temp=pop();
                    while(temp!='(')
                    {
                         postfix[pos]=temp;
                         pos++;
                         temp=pop();
                    }
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':while(pred(stack[top])>=pred(symbol))
                    {
                        temp=pop();
                        postfix[pos++]=temp;
                    }
                    push(symbol);
                    break;
            default:postfix[pos++]=symbol;
        }
        index++;
    }
    while(top>0)
    {
        temp=pop();
        postfix[pos++]=temp;
    }
}
void push(char symbol)
{
    top=top+1;
    stack[top]=symbol;
}
char pop()
{
    char symbol;
    symbol=stack[top];
    top=top-1;
    return(symbol);
}
char pred(char symbol)
{
    int p;
    switch(symbol)
    {
        case '^':p=100;
                break;
        case '*':
        case '/':p=80;
                break;
        case '+':
        case '-':p=60;
                break;
        case '(':p=40;
                break;
        case '#':p=20;
                break;
    }
    return(p);
}
