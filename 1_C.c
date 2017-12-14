#include <stdio.h>
#include <math.h>

#define M_PI		3.14159265358979323846

int main(void)
{
    double A[2], B[2], C[2];    //坐标
    double a[2], b[2], c[2];    //向量
    double cosA, cosB, cosC;    //角度余弦
    double angleA, angleB, angleC, DEG;    //角度
    int n;  //正多边形的边数
    double an, temp[3];   //边长
    double S;   //面积


    scanf("%lf %lf", &A[0], &A[1]);
    scanf("%lf %lf", &B[0], &B[1]);
    scanf("%lf %lf", &C[0], &C[1]);

    a[0] = C[0] - B[0];
    a[1] = C[1] - B[1];
    b[0] = C[0] - A[0];
    b[1] = C[1] - A[1];
    c[0] = B[0] - A[0];
    c[1] = B[1] - A[1];

    temp[0] = sqrt(a[0]*a[0] + a[1]*a[1]);
    temp[1] = sqrt(b[0]*b[0] + b[1]*b[1]);
    temp[2] = sqrt(c[0]*c[0] + c[1]*c[1]);

    if(fabs(temp[0] - temp[1]) < 0.001)
        an = temp[0];
    else if(fabs(temp[1] - temp[2]) < 0.001)
        an = temp[1];
    else
        an = temp[2];

    cosA = (b[0]*c[0] + b[1]*c[1])/(temp[1] * temp[2]);
    cosB = (a[0]*c[0] + a[1]*c[1])/(temp[0] * temp[2]);
    cosC = (b[0]*a[0] + b[1]*a[1])/(temp[1] * temp[0]);

    angleA = acos(cosA)*180/M_PI;
    angleB = acos(cosB)*180/M_PI;
    angleC = acos(cosC)*180/M_PI;

    if(fabs(angleA - angleB) < 0.001 || fabs(angleA + angleB - 180) < 0.001)
        DEG = angleC;
    else if(fabs(angleA - angleC) < 0.001 || fabs(angleA + angleC - 180) < 0.001)
        DEG = angleB;
    else if(fabs(angleC - angleB) < 0.001 || fabs(angleC + angleB - 180) < 0.001)
        DEG = angleA;

    n = 360/(180 - DEG);

    S = n/4.0*an*an*1.0/tan(M_PI/n);
    printf("%.8lf\n", S);

    return 0;
}
