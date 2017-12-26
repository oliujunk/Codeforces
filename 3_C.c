#include <stdio.h>

int main(void)
{
    char matrix[3][4];
    int i, j;
    int numOfX=0, numOf0=0;
    for(i=0; i<3; i++)
    {
        scanf("%s", matrix[i]);
        for(j=0; j<3; j++)
        {
            if(matrix[i][j] == 'X')
                numOfX++;
            else if(matrix[i][j] == '0')
                numOf0++;
        }
    }

    if(numOfX<=2 && numOf0<=2)
    {
        if(numOfX-numOf0 == 1)
            printf("second\n");
        else if(numOfX-numOf0 == 0)
            printf("first\n");
        else
            printf("illegal\n");

        return 0;
    }
    else
    {
        if(matrix[0][1] != '.'
           && ((matrix[0][1] == matrix[0][0] && matrix[0][1] == matrix[0][2])
           || (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1])))
        {
            if(matrix[0][1] == 'X')
            {
                if(numOfX-numOf0 == 1)
                    printf("the first player won\n");
                else
                    printf("illegal\n");
            }
            else
            {
                if(numOfX-numOf0 == 0)
                    printf("the second player won\n");
                else
                    printf("illegal\n");
            }
            return 0;
        }

        if(matrix[1][0] != '.'
           && ((matrix[1][0] == matrix[0][0] && matrix[1][0] == matrix[2][0])
           || (matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2])))
        {
            if(matrix[1][0] == 'X')
            {
                if(numOfX-numOf0 == 1)
                    printf("the first player won\n");
                else
                    printf("illegal\n");
            }
            else
            {
                if(numOfX-numOf0 == 0)
                    printf("the second player won\n");
                else
                    printf("illegal\n");
            }
            return 0;
        }
        if(matrix[1][2] != '.'
           && ((matrix[1][2] == matrix[0][2] && matrix[1][2] == matrix[2][2])
           || (matrix[1][2] == matrix[1][0] && matrix[1][2] == matrix[1][1])))
        {
            if(matrix[1][2] == 'X')
            {
                if(numOfX-numOf0 == 1)
                    printf("the first player won\n");
                else
                    printf("illegal\n");
            }
            else
            {
                if(numOfX-numOf0 == 0)
                    printf("the second player won\n");
                else
                    printf("illegal\n");
            }
            return 0;
        }
        if(matrix[2][1] != '.'
           && ((matrix[2][1] == matrix[2][0] && matrix[2][1] == matrix[2][2])
           || (matrix[2][1] == matrix[0][1] && matrix[2][1] == matrix[1][1])))
        {
            if(matrix[2][1] == 'X')
            {
                if(numOfX-numOf0 == 1)
                    printf("the first player won\n");
                else
                    printf("illegal\n");
            }
            else
            {
                if(numOfX-numOf0 == 0)
                    printf("the second player won\n");
                else
                    printf("illegal\n");
            }
            return 0;
        }
        if(matrix[1][1] != '.'
           && ((matrix[1][1] == matrix[0][0] && matrix[1][1] == matrix[2][2])
           || (matrix[1][1] == matrix[0][2] && matrix[1][1] == matrix[2][0])))
        {
            if(matrix[1][1] == 'X')
            {
                if(numOfX-numOf0 == 1)
                    printf("the first player won\n");
                else
                    printf("illegal\n");
            }
            else
            {
                if(numOfX-numOf0 == 0)
                    printf("the second player won\n");
                else
                    printf("illegal\n");
            }
            return 0;
        }
        else
        {
            if(numOfX==5 && numOf0 == 4)
                printf("draw\n");
            else if(numOfX-numOf0 == 1)
                printf("second\n");
            else if(numOfX-numOf0 == 0)
                printf("first\n");
            else
                printf("illegal\n");

            return 0;
        }
    }

    return 0;
}
