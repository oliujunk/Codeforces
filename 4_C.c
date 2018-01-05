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
    int i, j;
    freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    NameSt nameArray[50000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", nameArray[i].name);
        for (j = 0; j < i; j++)
        {
            if (strcmp(nameArray[i].name, nameArray[j].name) == 0)
            {
                nameArray[j].sameNameNum++;
                n--;
                i--;
                break;
            }
        }
        if (j == i)
            printf("OK\n");
        else
            printf("%s%n\n", nameArray[i].name, nameArray[i].sameNameNum);
    }
    return 0;
}