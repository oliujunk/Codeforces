#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int leftCost;
    int rightCost;
    int DCost;
    int inputIndex;
} QuestionMaskSt;

typedef struct Node
{
    struct Node *pLast;
    QuestionMaskSt data;
    struct Node *pNext;
} NODE, *PNODE;

void insertList(PNODE list, PNODE node);

int main(void)
{
    char inputArray[50001];
    freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%s", inputArray);

    int i = 0;
    long long minCost = 0;
    int count = 0;
    PNODE list = (PNODE)malloc(sizeof(NODE));   //创建一个头结点，头结点不存放数据
    list->pNext = NULL;
    for (i = 0; i < strlen(inputArray); i++)
    {
        if (inputArray[i] == '(')
            count++;
        else if (inputArray[i] == ')')
            count--;
        else
        {
            PNODE p = (PNODE)malloc(sizeof(NODE));
            p->pNext = NULL;
            scanf("%d %d", &p->data.leftCost, &p->data.rightCost);
            p->data.DCost = p->data.rightCost - p->data.leftCost;
            p->data.inputIndex = i;
            inputArray[i] = ')';
            count--;
            minCost += p->data.rightCost;
            insertList(list, p);
            free(p);
        }

        if (count < 0)
        {
            // inputArray[costArray[k].inputIndex] = '(';
            // minCost -= costArray[k].DCost;
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
void insertList(PNODE list, PNODE node)
{
    PNODE addNode = (PNODE)malloc(sizeof(NODE));
    addNode = node;
    PNODE tempNode = list;
    while(tempNode->pNext != NULL)
    {
        if(addNode->data.DCost >= tempNode->data.DCost)
        {
            tempNode->pLast = addNode;
            addNode->pNext = tempNode;
            return;
        }
        else
        {
            tempNode = tempNode->pNext;
        }
    }
    tempNode->pNext = addNode;
}