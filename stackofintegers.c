#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int top=-1;
int data[SIZE];
void push(int item)
{
    if(top==SIZE-1)
        printf("\n stack overflow");
    else
    {
        top=top+1;
        data[top]=item;
    }
}
void pop()
{
    if(top==-1)
        printf("\n stack underflow");
    else
    {

        printf("\n element pop is %d",data[top]);
        top=top-1;
    }
}
void display()
{

    int i;
    if(top==-1)
        printf("\n stack is empty");
    else
    {
        printf("\n stack content are \n");
        for(i=top;i>=0;i--)
            printf("%d\n",data[i]);
    }
}
int main()
{
    int ch,item;
    for(;;)
    {
        printf("\n 1.push");
        printf("\n 2.pop");
        printf("\n 3.display");
        printf("\n read choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n read element to be pushed:");
            scanf("%d",&item);
            push(item);
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            default:exit(0);
        }
    }
    return 0;
}
