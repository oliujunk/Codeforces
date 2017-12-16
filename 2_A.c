#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    int i = 0, j = 0, k = 0;
    struct nameSorceSt {
        char name[33];
        int sorce;
    };

    struct nameSorceSt nameSorce[1000] = {{0, 0}};
    struct nameSorceSt nameSorce2[1000] = {{0, 0}};

    struct maxSorceSt {
        int maxNameIndex;
        int maxIndex;
    };

    int emptyIndex = 0;
    struct maxSorceSt maxSorceArray[100] = {{0, 0}};
    int maxNum = 0;
    int maxSorce = 0;

    scanf("%d", &n);

    m = n;

    while(n--)
    {
        scanf("%s %d", nameSorce[m-n-1].name, &(nameSorce[m-n-1].sorce));
        memcpy(&nameSorce2[m-n-1], &nameSorce[m-n-1], sizeof(nameSorce[m-n-1]));
        for(i=0; i<emptyIndex; i++)
        {
            if(strcmp(nameSorce[i].name, nameSorce[m-n-1].name) == 0)
            {
                nameSorce[i].sorce += nameSorce[m-n-1].sorce;
                break;
            }
        }
        if(i == emptyIndex)
        {
            strcpy(nameSorce[i].name, nameSorce[m-n-1].name);
            nameSorce[i].sorce = nameSorce[m-n-1].sorce;
            emptyIndex++;
        }
    }//计算出每个人的最终得分

    maxSorce = nameSorce[0].sorce;

    for(i=0; i<emptyIndex; i++)
    {
        if(nameSorce[i].sorce > maxSorce)
        {
            maxSorce = nameSorce[i].sorce;
            maxNum = 1;
            memset(maxSorceArray, 0, sizeof(maxSorceArray));
            maxSorceArray[0].maxNameIndex = i;
        }
        else if(nameSorce[i].sorce == maxSorce)
        {
            maxSorceArray[maxNum].maxNameIndex = i;
            maxNum++;
        }
    }//计算出最高分，并统计出得到最高分人的位置

//    for(j=0; j<maxNum; j++)
//    {
//        for(i=m-1; i>=0; i--)
//        {
//            if(strcmp(nameSorce[i].name, nameSorce[maxSorceArray[j].maxNameIndex].name) == 0)
//            {
//                maxSorceArray[j].maxIndex = i;
//                break;
//            }
//        }
//    }//计算出最高分最后一次结算的位置

    int tempSorce;

    for(n=0; n<m; n++)
    {
        for(i=0; i<maxNum; i++)
        {
            if(strcmp(nameSorce2[n].name, nameSorce[maxSorceArray[i].maxNameIndex].name) == 0)
            {
                maxSorceArray[i].maxIndex += nameSorce2[n].sorce;
                if(maxSorceArray[i].maxIndex >= maxSorce)
                {
                    printf("%s\n", nameSorce2[n].name);
                    return 0;
                }
                break;
            }
        }
    }

    return 0;
}
