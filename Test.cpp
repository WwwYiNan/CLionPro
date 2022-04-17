#include<stdio.h>
#include<malloc.h>


#define MAXLEN  100
typedef struct xznode {
    int m;       // 系数
    int n;       // 指数
} datatype;

typedef struct {
    datatype data[MAXLEN];
    int last;
} SeqList;

SeqList *InitSeqList() {
//@@1
    SeqList *L;
    L = new SeqList;
    L->last = -1;
    return L;
//@@1
}

int InsSeqList(SeqList *L, int i, datatype x) {
//@@2
    int j;
    for (j = L->last; j >= i; j++) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i] = x;
    L->last++;
//@@2 
}

int CreatSeqList(SeqList *L) {
//@@3
    int n, m, i = 0;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        L->data[i].n = n;
        L->data[i].m = m;
        i++;
    }
    L->last = i - 1;
//@@3
}

int LenSeqList(SeqList *L) {
//@@4
    return L->last;
//@@4
}

int Add_Seq(SeqList *A, SeqList *B, SeqList *C) {
//@@5
    int i = 0, j = 0, k = 0;
    while (1) {
        if (i > LenSeqList(A) && j > LenSeqList(B))
            break;
        if (i > LenSeqList(A) && j <= LenSeqList(B)) {
            InsSeqList(C, k, B->data[j]);
            k++;
            j++;
        }
        if (i <= LenSeqList(A) && j > LenSeqList(B)) {
            InsSeqList(C, k, A->data[i]);
            k++;
            i++;
        }
        if (i <= LenSeqList(A) && j <= LenSeqList(B)) {
            if (A->data[i].n > B->data[j].n) {
                InsSeqList(C, k, A->data[i]);
                k++;
                i++;
            }
            if (A->data[i].n < B->data[j].n) {
                InsSeqList(C, k, B->data[j]);
                k++;
                j++;
            }
            if (A->data[i].n == B->data[j].n) {
                C->data[k].m = A->data[i].m + B->data[j].m;
                if (C->data[k].m == 0) continue;
                else {
                    InsSeqList(C, k, A->data[i]);
                    k++;
                    i++;
                    j++;
                }

            }
        }
    }
//@@5
}

int ShowSeqList(SeqList *L) {
//@@6
    int i;
    for (i = 0; i <= LenSeqList(L); i++) {
        printf("%d %d\n", L->data[i].m, L->data[i].n);
    }
//@@6
}

int main() {
    SeqList *L1, *L2, *L3;

    L1 = InitSeqList();    //初始化三个空表
    L2 = InitSeqList();
    L3 = InitSeqList();

    CreatSeqList(L1);    //创建两个顺序表
    CreatSeqList(L2);

    Add_Seq(L1, L2, L3);   //L1 L2相加之后结果放入L3
    ShowSeqList(L3);
    return 0;
} 