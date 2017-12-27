#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *pNext;
}NODE, *PNODE;

typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, char val);
int empty(PSTACK pS);
int pop(PSTACK pS, char *pVal);
int clear(PSTACK pS);
int quickSort(int **a, int left, int right);

int main(void)
{
    char inputArray[50001];
    char inputTempArray[50001];
    freopen("C:\\Users\\XPH\\Desktop\\input2.txt", "r", stdin);
    scanf("%s", inputArray);

    memcpy(inputTempArray, inputArray, sizeof(inputArray));

    int i=0, j=0;
    int numOfQuestioMark = 0;
    int minCost = 0;
    for(i=0; i<strlen(inputArray); i++)
        if(inputArray[i] == '?')
            numOfQuestioMark++;

    int **costArray = (int **)malloc(sizeof(int)*numOfQuestioMark);
    int **costTempArray = (int **)malloc(sizeof(int)*numOfQuestioMark);
    for(i=0; i<numOfQuestioMark; i++)
    {
        costArray[i] = (int *)malloc(sizeof(int)*4);
        costTempArray[i] = (int *)malloc(sizeof(int)*4);
        scanf("%d %d", &costArray[i][0], &costArray[i][1]);
        costArray[i][2] = costArray[i][1] - costArray[i][0];
    }

    memcpy(costTempArray, costArray, sizeof(costArray));
    for(i=0; i<strlen(inputArray); i++)
    {
        if(inputArray[i] == '?')
        {
            inputTempArray[i] = ')';
            costArray[j++][3] = i;
            minCost += costArray[j-1][1];
        }
    }

    int count = 0;

    for(j=0; j<numOfQuestioMark; j++)
    {
        for(i=0; i<costArray[j][3]; i++)
        {
            if(inputTempArray[i] == '(')
                count++;
            else
                count--;
            
            if(count < 0)
            {
                memcpy(costTempArray, costArray, sizeof(costArray));
                quickSort(costTempArray, 0, j);
                inputTempArray[costTempArray[0][3]] = '(';
                minCost -= costTempArray[0][2];
                break;
            }
        }
    }

    free(costArray);
    for(i=0; i<numOfQuestioMark; i++)
        free(costArray[i]);

    return 0;
}


void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop)
    {
        printf("动态内存分配失败\n");
        exit(-1);
    }
    else
    {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}

void push(PSTACK pS, char val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

int empty(PSTACK pS)
{
    if(pS->pTop == pS->pBottom)
        return 1;
    else
        return 0;
}

int pop(PSTACK pS, char *pVal)
{
    if(empty(pS))
        return 0;
    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return 0;
    }
}

int clear(PSTACK pS)
{
    if(empty(pS))
        return 0;
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while(p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom; 
    }
}

//快速排序，降序
int quickSort(int **a, int left, int right)
{
    if(left >= right)
        return a[0][2];

    int i = left;
    int j = right;
	int temp[4];
	memcpy(&temp, a[left], sizeof(int)*4);
    while(i < j)
    {
        while(i < j && temp[2] >= a[j][2])
            j--;

		memcpy(a[i], a[j], sizeof(int)*4);
        while(i < j && temp[2] <= a[i][2])
            i++;

		memcpy(a[j], a[i], sizeof(int)*4);
    }

	memcpy(a[i], &temp, sizeof(int)*4);
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}
