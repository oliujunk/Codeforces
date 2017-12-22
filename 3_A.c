#include <stdio.h>
#include <string.h>

int main(void)
{
    int start[2], end[2];

    char tempArray[2][3];
    scanf("%s", tempArray[0]);
    scanf("%s", tempArray[1]);

    start[0] = tempArray[0][0] - 'a';
    start[1] = tempArray[0][1] - '1';

    end[0] = tempArray[1][0] - 'a';
    end[1] = tempArray[1][1] - '1';

    int i;
    int flag1, flag2;
    int x, y;
    if(start[0] < end[0])
    {
        flag1 = 1;
        x = end[0] - start[0];
    }
    else
    {
        flag1 = 0;
        x = start[0] - end[0];
    }

    if(start[1] < end[1])
    {
        flag2 = 1;
        y = end[1] - start[1];
    }
    else
    {
        flag2 = 0;
        y = start[1] - end[1];
    }

    int step = x > y ? x : y;

    printf("%d\n", step);

    if(flag1 == 1 && flag2 == 1)
    {
        strcpy(tempArray[0], "RU");
        strcpy(tempArray[1], x>y?"R":"U");
    }
    else if(flag1 == 1 && flag2 == 0)
    {
        strcpy(tempArray[0], "RD");
        strcpy(tempArray[1], x>y?"R":"D");
    }
    else if(flag1 == 0 && flag2 == 1)
    {
        strcpy(tempArray[0], "LU");
        strcpy(tempArray[1], x>y?"L":"U");
    }
    else if(flag1 == 0 && flag2 == 0)
    {
        strcpy(tempArray[0], "LD");
        strcpy(tempArray[1], x>y?"L":"D");
    }

    for(i=0; i<(x > y ? y : x); i++)
        printf("%s\n", tempArray[0]);
    for(i=step - (x > y ? y : x); i>0; i--)
        printf("%s\n", tempArray[1]);


    return 0;
}
