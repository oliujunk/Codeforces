#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[33];
    int sameNameNum;
} NameSt;

int main(void)
{
    int n;
    int i, j, k;
    //freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    NameSt nameArray[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        k = i;
        scanf("%s", nameArray[i].name);
        for (j = 0; j < i; j++)
        {
            if (strcmp(nameArray[i].name, nameArray[j].name) == 0)
            {
                nameArray[j].sameNameNum++;
                n--;
                i--;
                printf("%s%d\n", nameArray[j].name, nameArray[j].sameNameNum);
                break;
            }
        }
        if (i == k)
            printf("OK\n");
    }
    return 0;
}