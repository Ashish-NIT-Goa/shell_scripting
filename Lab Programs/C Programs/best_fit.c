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
    int assigned;
    bool status;
} pro;

void Best_Fit(seg *s_arr, pro *p_arr, int s, int p)
{
    int IF = 0;
    int oldif;
    int newif;
    int ob = 0;
    int nb = 0;
    int c;
    for (int i = 0; i < p; i++)
    {
        c = 0;
        for (int j = 0; j < s; j++)
        {
            if (((p_arr + i)->size <= (s_arr + j)->size) && !(s_arr + j)->alloc)
            {

                if (c == 0)
                {
                    oldif = (s_arr + j)->size - (p_arr + i)->size;
                    ob = j;
                    (p_arr + i)->assigned = ob;
                    c = 1;
                }

                nb = j;
                newif = (s_arr + j)->size - (p_arr + i)->size;
                if (oldif <= newif)
                {
                    oldif = oldif;
                    ob = ob;
                    (p_arr + i)->assigned = ob;
                    (s_arr + nb)->alloc = false;
                    (s_arr + ob)->alloc = true;
                }
                else
                {
                    oldif = newif;
                    (s_arr + ob)->alloc = false;
                    ob = nb;
                    (s_arr + nb)->alloc = true;
                    (p_arr + i)->assigned = nb;
                }
                (p_arr + i)->status = true;
            }
        }
        IF += oldif;
    }

    printf("\n");
    for (int i = 0; i < s; i++)
    {
        if (!(s_arr + i)->alloc)
        {
            printf("B%d not allocated\n",i);
            IF += (s_arr + i)->size;
        }
    }

    printf("\nProcess allocated\n");

    for (int i = 0; i < p; i++)
    {
        if ((p_arr + i)->status)
        {
            printf("P%d - B%d \n", i, (p_arr + i)->assigned);
        }
    }

    printf("\nThe total internal fragmentation is: %d", IF);
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
    Best_Fit(segm, p, no_s, no_p);

    return 0;
}