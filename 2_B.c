#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, n;
    scanf("%d", &n);
    int **matrix = malloc(sizeof(int)*n);
    char *trace = malloc(sizeof(char)*(n-1)*2+1);
    memset(trace, '\0', sizeof(char)*(n-1)*2+1 );
    for(i=0; i<n; i++)
        matrix[i] = malloc(sizeof(int)*n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d", &matrix[i][j]);

    int countZero;

    for(i=0; i<(n-1)*2; i++)
    {
        if(matrix[0][0] == 0 || matrix[n-1][n-1] == 0)
        {
            countZero = 1;
            for(j=0; j<n-1; j++)
                *(trace+j) = 'D';
            for(j=n-1; j<(n-1)*2; j++)
                *(trace+j) = 'R';
            break;
        }
        else
        {

        }
    }

    printf("%d\n", sizeof(char));
    printf("%s\n", trace);


    for(i=0; i<n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
