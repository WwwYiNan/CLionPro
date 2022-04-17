#include "SqQueue.h"


//删除循环队列中所有奇数数字
void DelOddNum(SqQueue &sq) {
    SqQueue s1;
    InitQueue(s1);
    ElemType e;
    while (sq.front != sq.rear) {
        if (DeQueue(sq, e))
            if (e % 2 == 0)
                EnQueue(s1, e);
    }
    sq = s1;
}

void PrintQue(SqQueue sq)
{
    while(sq.front != sq.rear)
    {
//        printf("%3d",sq.data[sq.front-1]);

        printf("%3d",sq.data[sq.front+1]);
        sq.front++;
    }

}


int main() {
    SqQueue sq;
    InitQueue(sq);
    EnQueue(sq, 3);
    EnQueue(sq, 4);
    EnQueue(sq, 4);
    EnQueue(sq, 5);
    EnQueue(sq, 6);
    EnQueue(sq, 8);
    EnQueue(sq, 9);
    EnQueue(sq, 88);
    PrintQue(sq);
    printf("\n");
    DelOddNum(sq);
    PrintQue(sq);
    return 0;
}