#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void BubbleSort(int A[], int n)
{
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1-i; j++)
            if(A[j+1] < A[j])
                swap(A[j+1],A[j]);
}
int main()
{
    long const N = 1000000;
    int A[N];
    srand((unsigned)time(NULL));
    for(int i=0; i<N; i++)
        A[i] = rand();
    clock_t start, finish, total_time;
    start = clock()/CLOCKS_PER_SEC;
    cout<<"start"<<endl;
    BubbleSort(A, N);
    cout<<"end"<<endl;
    finish = clock()/CLOCKS_PER_SEC;
    total_time = finish - start;
    cout<<"Total time is: "<<total_time<<endl;
    cout<<endl;
    return 0;
}
