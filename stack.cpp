#include "stdio.h"
#include "string.h"

#define MaxSize 100
typedef struct Stack
{
    int top;
    char str[MaxSize];
}Stack;

int main()
{
    int len,i,mid,next;
    char str[100];
    Stack S;
    S.top = 0;
    gets(str);
    len = strlen(str);
    mid = len/2;
    for(i=0;i<mid;i++)
    {
        S.str[S.top] = str[i];
        S.top ++;
    }
    if(len % 2!=0)
    {
        next = mid +1;
    }else{
        next = mid;
    }
    while(S.top != 0)
    {
        if(S.str[S.top -1] == str[next])
        {
            S.top --;
            next ++;
        }
        else
        {
            break;
        }
    }
    if(S.top == 0)
        printf("是回文\n");
    else
        printf("不是回文\n");
    return 0;
}
