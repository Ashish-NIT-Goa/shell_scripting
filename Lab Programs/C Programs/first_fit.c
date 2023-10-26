#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct segment
{
    int size;
    bool alloc;
} seg;

typedef struct process
{
    int size;
    bool status;
} pro;

void First_Fit(seg *s_arr, pro *p_arr, int s, int p)
{
    int IF = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (((p_arr + i)->size <= (s_arr + j)->size) && !(s_arr + j)->alloc && !(p_arr + i)->status)
            {
                IF += (s_arr + j)->size - (p_arr + i)->size;
                (p_arr + i)->status = true;
                (s_arr + j)->alloc = true;
            }
        }
    }

    printf("\n");
    for(int i=0;i<s;i++)
    {
        if(!(s_arr+i)->alloc)
        {
            printf("B%d not allocated\n",i);
            IF+=(s_arr+i)->size;
        }
    }

    printf("Process which are allocated are:");
    for (int i = 0; i < p; i++)
    {
        if ((p_arr + i)->status)
        {
            printf("P%d ", i);
        }
    }
    
    printf("The total internal fragmentation is: %d", IF);
}

int main()
{
    int no_s;
    printf("Enter no.of frame segements:");
    scanf("%d", &no_s);
    seg *segm = (seg *)malloc(sizeof(seg) * no_s);
    for (int i = 0; i < no_s; i++)
    {
        printf("Enter size of frame segment B%d:", i);
        scanf("%d", &(segm + i)->size);
        (segm + i)->alloc = false;
        fflush(stdin);
    }
    int no_p;
    printf("Enter no.of processes:");
    scanf("%d", &no_p);
    pro *p = malloc(sizeof(pro) * no_p);
    for (int i = 0; i < no_p; i++)
    {
        printf("Enter size of P%d:", i);
        scanf("%d", &(p + i)->size);
        (p + i)->status = false;
        fflush(stdin);
    }
    First_Fit(segm, p, no_s, no_p);

    return 0;
}