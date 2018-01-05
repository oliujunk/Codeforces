#include <stdio.h>

typedef struct
{
    int minTime;
    int maxTime;
} StudyTimeSt;

int main(void)
{
    int day, sumHour;
    int i, j;
    int minSum = 0, maxSum = 0;
    StudyTimeSt studyTime[30];
    scanf("%d %d", &day, &sumHour);
    for (i = 0; i < day; i++)
    {
        scanf("%d %d", &studyTime[i].minTime, &studyTime[i].maxTime);
        minSum += studyTime[i].minTime;
        maxSum += studyTime[i].maxTime;
    }

    if (sumHour > maxSum || sumHour < minSum)
    {
        printf("NO\n");
        return 0;
    }
    else
    {
        printf("YES\n");
        for (i = 0; i < day; i++)
        {
            if(minSum + studyTime[i].maxTime - studyTime[i].minTime >= sumHour)
                break;
            else
                minSum += (studyTime[i].maxTime - studyTime[i].minTime);
        }

        if(i<day-1)
        {
            for(j=0; j<i; j++)
                printf("%d ", studyTime[j].maxTime);
            printf("%d ", studyTime[i].minTime+sumHour-minSum);
            for(j=i+1; j<day-1; j++)
                printf("%d ", studyTime[j].minTime);
            printf("%d\n", studyTime[day-1].minTime);        
        }
        else
        {
            for(j=0; j<i; j++)
                printf("%d ", studyTime[j].maxTime);
            printf("%d\n", studyTime[day-1].minTime+sumHour-minSum);
        }
        return 0;
    }
}