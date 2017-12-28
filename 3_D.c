#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char inputArray[10];
    freopen("C:\\Users\\XPH\\Desktop\\input2.txt", "r", stdin);
    scanf("%s", inputArray);

    int i = 0, j = 0;
    int questionMask = 0;
    for(i=0; i<strlen(inputArray); i++)
        if(inputArray[i] == '?')
            questionMask++;
    
    int **costArray = (int **)malloc(sizeof(int **)*questionMask);
    for(i=0; i<questionMask; i++)
    {
        costArray[i] = (int *)malloc(sizeof(int *)*4);
        scanf("%d %d", &costArray[i][0], &costArray[i][1]);
        costArray[i][2] = costArray[i][1] - costArray[i][0];
    }

    int minCost = 0;
    for(i=0; i<strlen(inputArray); i++)
    {
        if(inputArray[i] == '?')
        {
            costArray[j][3] = i;
            inputArray[i] = ')';
            minCost += costArray[j++][1];
        }
    }

    for(i=0; i<strlen(inputArray); i++)
    {
        
    }

    return 0;
}