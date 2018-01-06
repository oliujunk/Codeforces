#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int width;
    int height;
    int inputIndex;
} EnvelopeSt;

typedef struct Node
{
    EnvelopeSt data;
    struct Node *next;
} NODE;

int main(void)
{
    int n, w, h;
    int i, j = 0;
    freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    NODE *list = (NODE *)malloc(sizeof(NODE));
    list->next = NULL;
    NODE *p, *q;
    EnvelopeSt envelope;
    scanf("%d %d %d", &n, &w, &h);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &envelope.width, &envelope.height);
        if (envelope.width > w && envelope.height > h)
        {
            envelope.inputIndex = i + 1;
            p = list;
            while (p != NULL && p->next != NULL && envelope.width >= p->next->data.width)
            {
                p = p->next;
            }
            if (envelope.width == p->data.width)
            {
                if (envelope.height <= p->data.height)
                    p->data = envelope;
                continue;
            }
            if(envelope.height > p->data.height)
            {
                q = (NODE *)malloc(sizeof(NODE));
                q->data = envelope;
                q->next = p->next;
                p->next = q;
                j++;
            }
        }
    }
    printf("%d\n", j);
    p = list->next;
    for (i = 0; i < j - 1; i++)
    {
        printf("%d ", p->data.inputIndex);
        p=p->next;
    }
    printf("%d\n", p->data.inputIndex);

    return 0;
}