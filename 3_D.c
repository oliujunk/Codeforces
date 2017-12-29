#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define INT_MAX 2147483647
// #define INT_MIN (-INT_MAX - 1)

int quickSort(int **a, int left, int right);
void insertSort(int **array, int first, int last);

int main(void)
{
    char inputArray[50001];
    freopen("C:\\Users\\XPH\\Desktop\\input2.txt", "r", stdin);
    freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%s", inputArray);

    int i = 0, j = 0, k = 0;
    int questionMask = 0;
    for (i = 0; i < strlen(inputArray); i++)
        if (inputArray[i] == '?')
            questionMask++;

    int **costArray = (int **)malloc(sizeof(int **) * questionMask);
    for (i = 0; i < questionMask; i++)
    {
        costArray[i] = (int *)malloc(sizeof(int *) * 4);
        scanf("%d %d", &costArray[i][0], &costArray[i][1]);
        costArray[i][2] = costArray[i][1] - costArray[i][0];
    }

    long long minCost = 0;
    for (i = 0; i < strlen(inputArray); i++)
    {
        if (inputArray[i] == '?')
        {
            costArray[j][3] = i;
            inputArray[i] = ')';
            minCost += costArray[j++][1];
        }
    }

    int count = 0;

    for (i = 0; i < strlen(inputArray); i++)
    {
        if (inputArray[i] == '(')
        {
            count++;
        }
        else if (inputArray[i] == ')')
        {
            count--;
        }

        if (count < 0)
        {
            for (j = k; j < questionMask; j++)
            {
                if (costArray[j][3] == i)
                    break;
                if (costArray[j][3] > i)
                {
                    j--;
                    break;
                }
            }
            if (j == questionMask)
                j--;
            //quickSort(costArray, k, j);
            insertSort(costArray, k, j);
            inputArray[costArray[k][3]] = '(';
            minCost -= costArray[k][2];
            count += 2;
            //costArray[0][2] = INT_MIN;
            k++;
        }
    }
    if (count != 0)
        printf("%d\n", -1);
    else
    {
        printf("%I64d\n", minCost);
        printf("%s\n", inputArray);
    }

    return 0;
}

//快速排序，降序
int quickSort(int **a, int left, int right)
{
    if (left >= right)
        return a[0][2];

    int i = left;
    int j = right;
    int temp[4];
    memcpy(&temp, a[left], sizeof(int) * 4);
    while (i < j)
    {
        while (i < j && temp[2] >= a[j][2])
            j--;

        memcpy(a[i], a[j], sizeof(int) * 4);
        while (i < j && temp[2] <= a[i][2])
            i++;

        memcpy(a[j], a[i], sizeof(int) * 4);
    }

    memcpy(a[i], &temp, sizeof(int) * 4);
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

//插入排序，降序
void insertSort(int **array, int first, int last)
{
    int i, j;
    int temp[4];
    for (i = first + 1; i <= last; i++)
    {
        memcpy(&temp, array[i], sizeof(int) * 4);
        j = i - 1;
        while (j >= first && array[j][2] < temp[2])
        {
            memcpy(array[j + 1], array[j], sizeof(int) * 4);
            j--;
        }
        if (j != i - 1)
            memcpy(array[j + 1], temp, sizeof(int) * 4);
    }
}

// //折半插入排序
// void insertSort2(Elemtype A[], int n)
// {
//     int i, j, low, high, mid;
//     for (i = 2; i <= n; i++)
//     {
//         A[0] = A[i];
//         low = 1;
//         high = i - 1; //设置折半查找的范围，从1到i-1,A[0]用来暂存元素
//         while (low <= high)
//         {
//             mid = (low + high) / 2;
//             if (A[mid].key > A[0].key)
//                 high = mid - 1; //查找左半子表
//             else
//                 low = mid + 1; //查找右半子表
//         }

//         for (j = i - 1; j >= high + 1; --j)
//             A[j + 1] = A[j]; //统一向后移动元素，空出插入位置
//         A[high + 1] = A[0];  //插入操作
//     }
// }