#include <stdio.h>

typedef struct
{
    int minTime;
    int maxTime;
} StudyTimeSt;

int main(void)
{
    int day, sumHour;
    int i;
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
        
        return 0;
    }
}