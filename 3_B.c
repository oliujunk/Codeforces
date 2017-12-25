#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    int capacity;
    int inputIndex;
}VehicleSt;

//冒泡排序，降序
void bubbleSort(VehicleSt *array, int length)
{
    int  i, j;
    VehicleSt temp;
    for(j=0; j<length-1; j++)
    {
        for(i=0; i < length-j-1; i++)
        {
            if(array[i].capacity < array[i+1].capacity)
            {
                memcpy(&temp, &array[i], sizeof(VehicleSt));
                memcpy(&array[i], &array[i+1], sizeof(VehicleSt));
                memcpy(&array[i+1], &temp, sizeof(VehicleSt));
            }
        }
    }
}
//快速排序，降序
void quickSort(VehicleSt *a, int left, int right)
{
    if(left >= right)
        return;

    int i = left;
    int j = right;
	VehicleSt temp;
	memcpy(&temp, &a[left], sizeof(VehicleSt));
    while(i < j)
    {
        while(i < j && temp.capacity >= a[j].capacity)
            j--;

		memcpy(&a[i], &a[j], sizeof(VehicleSt));
        while(i < j && temp.capacity <= a[i].capacity)
            i++;

		memcpy(&a[j], &a[i], sizeof(VehicleSt));
    }

	memcpy(&a[i], &temp, sizeof(VehicleSt));
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}


int main(void)
{
    int n, v, i;
    int j=0, k=0;
    int numOfKayak=0,  numOfCatamaran=0;
//    freopen("C:\\Users\\XPH\\Desktop\\input2.txt", "r", stdin);
//    freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%d %d", &n, &v);
    VehicleSt *vehicle = (VehicleSt *)malloc(sizeof(VehicleSt)*n);
    VehicleSt *vehicleKayak = (VehicleSt *)malloc(sizeof(VehicleSt)*n);
    VehicleSt *vehicleCatamaran = (VehicleSt *)malloc(sizeof(VehicleSt)*n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &(vehicle[i].type), &(vehicle[i].capacity));
        vehicle[i].inputIndex = i + 1;
        if(vehicle[i].type == 1)
        {
            numOfKayak++;
            memcpy(&vehicleKayak[j++], &vehicle[i], sizeof(VehicleSt));
        }
        else
        {
            numOfCatamaran++;
            memcpy(&vehicleCatamaran[k++], &vehicle[i], sizeof(VehicleSt));
        }
    }

//    bubbleSort(vehicleKayak, j);
//    bubbleSort(vehicleCatamaran, k);

    quickSort(vehicleKayak, 0, j-1);
    quickSort(vehicleCatamaran, 0, k-1);

    unsigned int maxCapacity = 0;

    for(i=0,j=0,k=0; v>0 && j<=numOfKayak && k<=numOfCatamaran;)
    {
        if(j<numOfKayak
            && (v == 1
                || k>=numOfCatamaran
                || vehicleKayak[j].capacity >= vehicleCatamaran[k].capacity
                || (j+1<numOfKayak && vehicleKayak[j].capacity + vehicleKayak[j+1].capacity > vehicleCatamaran[k].capacity)))
        {
            memcpy(&vehicle[i], &vehicleKayak[j], sizeof(VehicleSt));
            maxCapacity += vehicleKayak[j].capacity;
            i++;
            j++;
            v--;
        }
        else if(v>=2 && k<numOfCatamaran && (j+1>=numOfKayak || j>=numOfKayak || vehicleCatamaran[k].capacity >= vehicleKayak[j].capacity + vehicleKayak[j+1].capacity))
        {
            memcpy(&vehicle[i], &vehicleCatamaran[k], sizeof(VehicleSt));
            maxCapacity += vehicleCatamaran[k].capacity;
            k++;
            i++;
            v -= 2;
        }
        else
        {
            break;
        }
    }

    if(maxCapacity>0)
    {
        printf("%u\n", maxCapacity);
        for(j=0; j<i-1; j++)
            printf("%d ", vehicle[j].inputIndex);
        printf("%d\n", vehicle[i-1].inputIndex);
    }
    else
    {
        printf("%u\n", maxCapacity);
        printf("\n");
    }

    free(vehicle);
    free(vehicleKayak);
    free(vehicleCatamaran);

    return 0;
}
