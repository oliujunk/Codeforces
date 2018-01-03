#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int DCost;
    int inputIndex;
} QuestionMaskSt;

typedef struct Node
{
    QuestionMaskSt data;
    struct Node *pNext;
} NODE, *PNODE;

void insertList(PNODE list, QuestionMaskSt data);
QuestionMaskSt deleteNode(PNODE list);

int main(void)
{
    char inputArray[50001];
    freopen("C:\\Users\\XPH\\Desktop\\input2.txt", "r", stdin);
    freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%s", inputArray);

    int i = 0;
    long long minCost = 0;
    int count = 0;
    int leftCost, rightCost;
    PNODE list = (PNODE)malloc(sizeof(NODE));   //创建一个头结点，头结点不存放数据
    list->data.DCost = 2147483637;
    list->pNext = NULL;
    QuestionMaskSt cost;
    for (i = 0; i < strlen(inputArray); i++)
    {
        if (inputArray[i] == '(')
            count++;
        else if (inputArray[i] == ')')
            count--;
        else
        {
            scanf("%d %d", &leftCost, &rightCost);
            cost.DCost = rightCost - leftCost;
            cost.inputIndex = i;
            inputArray[i] = ')';
            count--;
            minCost += rightCost;
            insertList(list, cost);
        }

        if (count < 0)
        {
            cost = deleteNode(list);
            inputArray[cost.inputIndex] = '(';
            minCost -= cost.DCost;
            count += 2;
        }
    }

    if (count != 0)
        printf("%d\n", -1);
    else
        printf("%I64d\n%s\n", minCost, inputArray);

    return 0;
}

//按降序插入链表
void insertList(PNODE list, QuestionMaskSt data)
{
    PNODE p, q;
    p = list;
    while(p != NULL && p->pNext != NULL && data.DCost < p->pNext->data.DCost)
    {
        p = p->pNext;
    }
    q = (PNODE)malloc(sizeof(NODE));
    q->data = data;
    q->pNext = p->pNext;
    p->pNext = q;
}

QuestionMaskSt deleteNode(PNODE list)
{
    QuestionMaskSt data;
    data = list->pNext->data;
    list->pNext = list->pNext->pNext;
    return data;
}