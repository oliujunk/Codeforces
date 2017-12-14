#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int n;
    char inArray[15] = {0};
    char outArray[15] = {0};
    char temp[15] = {0};
    char *p1, *p2;
    int Col;
    int i, j;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", inArray);
        p1 = strstr(inArray, "R");
        p2 = strstr(inArray, "C");
        int temp1 = p2 - p1 - 1;
        if(p1 != NULL && p2 != NULL && (p2-p1) > 1 && *(p1+1) <= '9' && *(p1+1) >= '0')
        {
            i = 0;
            j = 0;
            Col = atoi(p2+1);
            for(;;)
            {
                if(Col <= 26)
                {
                    temp[i++] = 'A' + (Col%26==0?26:Col%26) - 1;
                    break;
                }
                else
                {
                    temp[i++] = 'A' + (Col%26==0?26:Col%26) - 1;
                    if(Col%26==0)
                        Col = Col/26-1;
                    else
                        Col = Col/26;
                }
            }
            for(; i>0; i--)
            {
                outArray[j++] = temp[i-1];
            }
            for(;temp1>0; temp1--)
            {
                outArray[j++] = inArray[++i];
            }

            printf("%s\n", outArray);

            memset(outArray, 0, sizeof(outArray));
            memset(temp, 0, sizeof(temp));
        }
        else
        {
            i = 0;
            j = 0;
            float temp2 = 0;
            for(i=0; inArray[i] <= 'Z' && inArray[i] >= 'A'; i++)
                ;
            p1 = &inArray[i];

            for(j=0; j<i; j++)
                temp2 += pow(26, i-j-1)*(inArray[j] - 'A' + 1);
            i = 0;
            outArray[i++] = 'R';
            for(i=1; (outArray[i++] = *(p1++)) != 0;)
                ;
            outArray[--i] = 'C';
            sprintf(temp, "%.0f", temp2);
            strcat(outArray, temp);

            printf("%s\n", outArray);

            memset(outArray, 0, sizeof(outArray));
            memset(temp, 0, sizeof(temp));
        }
    }
    return 0;
}
