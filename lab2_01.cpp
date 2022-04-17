#include "SqStack.h"

//文件中实现删除顺序栈st中指定值元素x
void DelAllX(SqStack &st,ElemType x)
{
  SqStack s1,s2;
  InitStack(s1);
  InitStack(s2);
  ElemType e;
  while(Pop(st,e))
      if(e != x)
          Push(s1,e);
  while(Pop(s1,e))
      Push(s2,e);
  st = s2;
}

void PrintS(SqStack st)
{
    while(st.top != -1)
    {
        printf("%3d",st.data[st.top]);
        st.top --;
    }
}

int main()
{
    SqStack  st;
    InitStack(st);
    Push(st,3);
    Push(st,3);
    Push(st,3);
    Push(st,4);
    Push(st,4);
    Push(st,5);
    PrintS(st);
    printf("\n");
    DelAllX(st,4);
    PrintS(st);
    return 0;
}