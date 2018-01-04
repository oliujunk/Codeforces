#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int DCost;
    int inputIndex;
} QuestionMaskSt;

// typedef struct Node
// {
//     QuestionMaskSt data;
//     struct Node *pNext;
// } NODE, *PNODE;

// void insertList(PNODE list, QuestionMaskSt data);
// QuestionMaskSt deleteNode(PNODE list);
void insertArray(QuestionMaskSt *costArray, QuestionMaskSt cost);
QuestionMaskSt deleteOneCost(QuestionMaskSt *costArray);

int last = 0;

int main(void)
{
    char inputArray[50001];
    QuestionMaskSt costArray[50001];
    //freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    //freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%s", inputArray);

    int i = 0;
    long long minCost = 0;
    int count = 0;
    int leftCost, rightCost;
    // PNODE list = (PNODE)malloc(sizeof(NODE)); //创建一个头结点，头结点不存放数据
    // list->data.DCost = 2147483637;
    // list->pNext = NULL;
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
            //insertList(list, cost);
            insertArray(costArray, cost);
        }

        if (count < 0)
        {
            cost = deleteOneCost(costArray);
            if(cost.inputIndex == -1)
                break;
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

/*
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
//使用链表会超时
*/

void insertArray(QuestionMaskSt *costArray, QuestionMaskSt cost)
{
    int r = last;
    if (r == 0)
        costArray[r] = cost;
    else
    {
        while (costArray[(r - 1) / 2].DCost < cost.DCost && r > 0)
        {
            costArray[r] = costArray[(r - 1) / 2];
            r = (r - 1) / 2;
        }
        costArray[r] = cost;
    }
    last++;
}

QuestionMaskSt deleteOneCost(QuestionMaskSt *costArray)
{
    int r = 0;
    QuestionMaskSt data, temp;
    if(last == 0)
    {
        data.inputIndex = -1;
        return data;
    }
    data = costArray[0];
    costArray[0] = costArray[last - 1];
    last--;
    while ((costArray[r].DCost < costArray[2 * r + 1].DCost && (2 * r + 1) < last) || (costArray[r].DCost < costArray[2 * r + 2].DCost && (2 * r + 2) < last))
    {
        if (2 * r + 2 < last && costArray[2 * r + 1].DCost < costArray[2 * r + 2].DCost)
        {
            temp = costArray[2 * r + 2];
            costArray[2 * r + 2] = costArray[r];
            costArray[r] = temp;
            r = 2 * r + 2;
        }
        else
        {
            temp = costArray[2 * r + 1];
            costArray[2 * r + 1] = costArray[r];
            costArray[r] = temp;
            r = 2 * r + 1;
        }
    }

    return data;
}
