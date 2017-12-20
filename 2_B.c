#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n;
    scanf("%d", &n);

    int ***matrix = malloc(sizeof(int)*n);
    char *trace = malloc(sizeof(char)*(n-1)*2+1);
    memset(trace, '\0', sizeof(char)*(n-1)*2+1 );
    for(i=0; i<n; i++)
    {
        matrix[i] = malloc(sizeof(int)*n);
        for(j=0; j<n; j++)
            matrix[i][j] = malloc(sizeof(int)*3);
    }

    int temp = 0;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &matrix[i][j][0]);
            matrix[i][j][1] = 0;
            matrix[i][j][2] = 0;
            temp = matrix[i][j][0];
            for(; temp>0; )
            {
                if(temp%5 == 0)
                {
                    matrix[i][j][2]++;
                    temp = temp/5;
                    continue;
                }
                if(temp%2 == 0)
                {
                    matrix[i][j][1]++;
                    temp = temp/2;
                    continue;
                }
                else
                    break;
            }
        }
    }

    int m = 0, k = 0;
    for(i=2*(n-1), j=1; i>=0; i--, j++)
    {
        if(i >= n-1)
        {
            m = n;
            for(k=0; k<j; k++)
            {
                m--;
                if((m+1 > n-1) && (i-m+1 <= n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + matrix[m][i-m+1][1];
                    matrix[m][i-m][2] = matrix[m][i-m][2] + matrix[m][i-m+1][2];
                }
                else if((m+1 <= n-1) && (i-m+1 > n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + matrix[m+1][i-m][1];
                    matrix[m][i-m][2] = matrix[m][i-m][2] + matrix[m+1][i-m][2];
                }
                else if((m+1 <= n-1) && (i-m+1 <= n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + (matrix[m+1][i-m][1] > matrix[m][i-m+1][1] ? matrix[m][i-m+1][1] : matrix[m+1][i-m][1]);
                    matrix[m][i-m][2] = matrix[m][i-m][2] + (matrix[m+1][i-m][2] > matrix[m][i-m+1][2] ? matrix[m][i-m+1][2] : matrix[m+1][i-m][2]);

                }
            }
        }
        else
        {
            m = 0;
            for(k=0; k<2*n-j; k++)
            {
                if((m+1 > n-1) && (i-m+1 <= n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + matrix[m][i-m+1][1];
                    matrix[m][i-m][2] = matrix[m][i-m][2] + matrix[m][i-m+1][2];
                }
                else if((m+1 <= n-1) && (i-m+1 > n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + matrix[m+1][i-m][1];
                    matrix[m][i-m][2] = matrix[m][i-m][2] + matrix[m+1][i-m][2];
                }
                else if((m+1 <= n-1) && (i-m+1 <= n-1))
                {
                    matrix[m][i-m][1] = matrix[m][i-m][1] + (matrix[m+1][i-m][1] > matrix[m][i-m+1][1] ? matrix[m][i-m+1][1] : matrix[m+1][i-m][1]);
                    matrix[m][i-m][2] = matrix[m][i-m][2] + (matrix[m+1][i-m][2] > matrix[m][i-m+1][2] ? matrix[m][i-m+1][2] : matrix[m+1][i-m][2]);

                }
                m++;
            }

        }
    }

    for(i=0, m=0, k=0; i<(n-1)*2; i++)
    {
        if(m>=n)
        {
            for(; i<(n-1)*2; i++)
                trace[i] = 'R';

            break;
        }
        if(k>=n)
        {
            for(; i<(n-1)*2; i++)
                trace[i] = 'D';

            break;
        }

        if(matrix[m+1][k][1] + matrix[m+1][k][2] <= matrix[m][k+1][1] + matrix[m][k+1][2])
        {
            trace[i] = 'D';
            m = m+1;
        }
        else
        {
            trace[i] = 'R';
            k = k+1;
        }
    }

    int tailingZero = 0;



    printf("%d\n", tailingZero);
    printf("%s\n", trace);

    for(i=0; i<n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
