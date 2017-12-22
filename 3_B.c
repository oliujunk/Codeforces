#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    int capacity;
    int inputIndex;
}VehicleSt;

//冒泡，降序
void Sort(VehicleSt *array, int length)
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

int main(void)
{

    int n, v, i;
    int j=0, k=0;
    int numOfKayak=0,  numOfCatamaran=0;
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

    Sort(vehicleKayak, j);
    Sort(vehicleCatamaran, k);

    int maxCapacity = 0;

    for(i=0,j=0,k=0; v>0;)
    {
        if(j<numOfKayak && (vehicleKayak[j].capacity >= vehicleCatamaran[k].capacity || k>=numOfCatamaran || v == 1))
        {
            memcpy(&vehicle[i], &vehicleKayak[j], sizeof(VehicleSt));
            maxCapacity += vehicleKayak[j].capacity;
            i++;
            j++;
            v--;
        }
        else if(v>=2 && k<numOfCatamaran && (vehicleCatamaran[k].capacity >= vehicleKayak[j].capacity + vehicleKayak[j+1].capacity || j+1>=numOfKayak))
        {
            memcpy(&vehicle[i], &vehicleCatamaran[k], sizeof(VehicleSt));
            maxCapacity += vehicleCatamaran[k].capacity;
            k++;
            i++;
            v -= 2;
        }
        else if(v>=2)
        {
            memcpy(&vehicle[i], &vehicleKayak[j], sizeof(VehicleSt));
            memcpy(&vehicle[i+1], &vehicleKayak[j+1], sizeof(VehicleSt));
            maxCapacity = maxCapacity + vehicleKayak[j].capacity + vehicleKayak[j+1].capacity;
            i += 2;
            j += 2;
            v -= 2;
        }
    }

    printf("%d\n", maxCapacity);
    for(j=0; j<i-1; j++)
        printf("%d ", vehicle[j].inputIndex);
    printf("%d\n", vehicle[i-1].inputIndex);

    return 0;
}
