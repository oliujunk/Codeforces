#include <stdio.h>
#include <math.h>

#define DOUBLE(a) ((a)*(a))

int coordinate[3][2];
int r[3];

//get point A, B , C, require point D. |AD|/r1 == |BD|/r2 == |CD|/r3
double getDeviation(double x, double y)
{
    int i;
    double tempArray[3];
    double ret = 0;
    for(i=0; i<3; i++)
        tempArray[i] = sqrt(DOUBLE(coordinate[i][0]-x) + DOUBLE(coordinate[i][1]-y))/r[i];

    for(i=0; i<3; i++)
        ret += DOUBLE(tempArray[i] - tempArray[(i+1)%3]);

    return ret;
}

int main(void)
{
    double requiredCoordinate[2] = {0};
    int i;
    for(i=0; i<3; i++)
    {
        scanf("%d %d %d", &coordinate[i][0], &coordinate[i][1], &r[i]);
        requiredCoordinate[0] += coordinate[i][0]/3.0;
        requiredCoordinate[1] += coordinate[i][1]/3.0;  //从该点开始逐次逼近结果
    }

    double temp;
    double step;
    for(step=1; step>0.000001; )
    {
        temp = getDeviation(requiredCoordinate[0], requiredCoordinate[1]);

        if(getDeviation(requiredCoordinate[0]+step, requiredCoordinate[1]) < temp)
            requiredCoordinate[0] += step;
        else if(getDeviation(requiredCoordinate[0]-step, requiredCoordinate[1]) < temp)
            requiredCoordinate[0] -= step;
        else if(getDeviation(requiredCoordinate[0], requiredCoordinate[1]+step) < temp)
            requiredCoordinate[1] += step;
        else if(getDeviation(requiredCoordinate[0], requiredCoordinate[1]-step) < temp)
            requiredCoordinate[1] -= step;
        else
            step = step * 0.7;

        if(getDeviation(requiredCoordinate[0], requiredCoordinate[1]) < 0.000001)
        {
            printf("%.5lf %.5lf\n", requiredCoordinate[0], requiredCoordinate[1]);
            return 0;
        }
    }

    return 0;
}
