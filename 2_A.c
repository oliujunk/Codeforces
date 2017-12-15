#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int i = 0;
    struct nameSorceSt {
        char name[33];
        int sorce;
    };

    struct nameSorceSt nameSorce[1000] = {{0, 0}};

    char nameTemp[33];
    int sorceTemp;
    int emptyIndex = 0;
    int maxArray[100] = {0};
    int maxNum = 0;
    int maxSorce = 0;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s %d", nameTemp, &sorceTemp);
        for(i=0; i<emptyIndex; i++)
        {
            if(strcmp(nameSorce[i].name, nameTemp) == 0)
            {
                nameSorce[i].sorce += sorceTemp;
                break;
            }
        }
        if(i == emptyIndex)
        {
            strcpy(nameSorce[i].name, nameTemp);
            nameSorce[i].sorce = sorceTemp;
            emptyIndex++;
        }
    }

    maxSorce = nameSorce[0].sorce;

    for(i=0; i<emptyIndex; i++)
    {
        if(nameSorce[i].sorce > maxSorce)
        {
            maxSorce = nameSorce[i].sorce;
            maxNum = 1;
            memset(maxArray, 0, sizeof(maxArray));
            maxArray[0] = i;
        }
        else if(nameSorce[i].sorce == maxSorce)
        {
            maxArray[maxNum] = i;
            maxNum++;
        }
    }
    strcpy(nameTemp, nameSorce[maxArray[0]].name);
    for(i=1; i<maxNum; i++)
        if(strcmp(nameTemp, nameSorce[maxArray[i]].name) >= 0)
            strcpy(nameTemp, nameSorce[maxArray[i]].name);
    printf("%s\n", nameTemp);

    return 0;
}
