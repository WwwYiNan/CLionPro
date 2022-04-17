#include "SqStack.h"


//数制转换问题：编写一个函数 void conversion(int d,int n ),
// 完成十进制数d和其它进制数的转换，
// d=(d div n)*n+d mod n
// ( 其中:div为整除运算,mod为求余运算,d为10进制数，n表示n进制数)。
// 要求借助堆栈实现。

void PrintS(SqStack st)
{
    while(st.top != -1)
    {
        printf("%2d",st.data[st.top]);
        st.top --;
    }
}

void conversion(int d, int n) {
    SqStack sq;
    InitStack(sq);
    int j;
    while (d != 0) {
        Push(sq, d % n);
        d /= n;
    }
    while (!StackEmpty(sq)) {
        Pop(sq, j);
        switch (j) {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", j);
                break;
        }
    }
}

int main() {
    int n = 63;
    printf("%d转换为2进制数为：", n);
    conversion(n, 2);
    printf("\n%d转换为8进制数为：", n);
    conversion(n, 8);
    printf("\n%d转换为16进制数为：", n);
    conversion(n, 16);

    return 0;
}