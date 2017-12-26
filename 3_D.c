#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputArray[50001];
    scanf("%s", inputArray);

    int i=0, j=0;
    int numOfQuestioMark = 0;
    for(i=0; i<strlen(inputArray); i++)
        if(inputArray[i] == '?')
            numOfQuestioMark++;

    int **costArray = (int **)malloc(sizeof(int)*numOfQuestioMark);
    for(i=0; i<numOfQuestioMark; i++)
    {
        costArray[i] = (int *)malloc(sizeof(int)*3);
        scanf("%d %d", &costArray[i][0], &costArray[i][1]);
    }

    for(i=0; i<strlen(inputArray); i++)
        if(inputArray[i] == '?')
            costArray[j++][2] = i;

    return 0;
}
