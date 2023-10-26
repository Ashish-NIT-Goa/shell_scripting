#include <stdio.h>
#include <stdlib.h>
#include <string.h> //not completed
#include <stdbool.h>
typedef struct Process
{
    float CPB;
    int id;
    float wait_time;
    float turn_around;
    int status;
    int flag;
    float arrival;
    float completion_time;
} process;

typedef struct ready_queue
{
    int f, r, N;
    process **arr;
} que;

process *Sort(process *p, int n)
{
    process *temp;
    temp = (process *)malloc(sizeof(process) * n);
    for (int i = 0; i < n; i++)
    {
        (temp + i)->CPB = (p + i)->CPB;
        (temp + i)->arrival = (p + i)->arrival;
        (temp + i)->id = (p + i)->id;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((temp + i)->arrival < (temp + j)->arrival)
            {
                int x = (temp + i)->id;
                (temp + i)->id = (temp + j)->id;
                (temp + j)->id = x;

                float t = (temp + i)->CPB;
                (temp + i)->CPB = (temp + j)->CPB;
                (temp + j)->CPB = t;
                float z = (temp + i)->arrival;
                (temp + i)->arrival = (temp + j)->arrival;
                (temp + j)->arrival = z;
            }
        }
    }
    return temp;
}

// queue insert from end pop from front
void enqueue(que *q, process *val)
{
    printf("Queue befor pushing :%d \n", val->id);
    if (q->r != -1 && q->r < q->N)
    {
        for (int i = 0; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]->id);
        }
    }
    if (q->r <= q->N)
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
    printf("Pushed %d\n", q->arr[q->r]->id);
}

process *dequeue(que *q)
{

    process *temp = malloc(sizeof(process *));
    temp = q->arr[0];
    printf("Popping -> %d\n", temp->id);
    for (int i = 0; i < q->r; i++)
    {
        q->arr[i] = q->arr[i + 1];
    }
    q->r = q->r - 1;
    return temp;
}

void Set_Status(process *p, int n, float elapse)
{
    for (int i = 0; i < n; i++)
    {
        if ((p + i)->arrival <= elapse && (p + i)->flag == 0)
        {
            (p + i)->status = 1;
            (p + i)->flag = 1;
        }
    }
}

int All_Status(process *p, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (p + i)->status;
    }
    return s;
}

bool exists(que *q, process *p)
{
    bool t = false;
    for (int i = 0; i <= q->r; i++)
    {
        if (q->arr[i]->id == p->id)
        {
            t = true;
        }
    }
    return t;
}

float Avg_Wait_Time(process *p, int n, float q)
{
    int c = 0;
    que *Queue = malloc(sizeof(que));
    Queue->f = 0;
    Queue->r = -1;
    Queue->N = n + 1;
    Queue->arr = malloc(sizeof(process *) * Queue->N);
    float *tmp = (float *)malloc(sizeof(float) * n);
    for (int i = 0; i < n; i++)
    {
        tmp[i] = (p + i)->CPB;
    }
    float total_wait = 0;
    float time_elapsed = 0;
    Set_Status(p, n, time_elapsed);
    enqueue(Queue, p);
    process *temp = malloc(sizeof(process *));
    while (All_Status(p, n) != 0)
    {
        int c = 0;
        temp = dequeue(Queue);
        float x = temp->CPB - q;
        if (x <= 0)
        {
            temp->status = 0;
            time_elapsed += temp->CPB;
            printf("%d run for %.2f total time elapsed after run %.2f\n", temp->id, temp->CPB, time_elapsed);
            temp->CPB = 0;
            temp->completion_time = time_elapsed;
        }
        else
        {
            temp->CPB -= q;
            time_elapsed += q;
            printf("%d run for %.2f total time elapsed after run %.2f\n", temp->id, q, time_elapsed);
        }
        Set_Status(p, n, time_elapsed);
        for (int i = 0; i < n; i++)
        {
            if (temp->id != (p + i)->id && (p + i)->status == 1)
            {
                if (Queue->r != -1)
                {
                    for (int j = 0; j <= Queue->r; j++)
                    {
                        if (!exists(Queue, (p + i)))
                        {
                            printf("in 2 for %d\n", (p + i)->id);
                            printf(" %d <-> %d\n", Queue->arr[j]->id, (p + i)->id);
                            enqueue(Queue, (p + i));
                        }
                    }
                }
                else
                {
                    printf("in 3\n");
                    enqueue(Queue, (p + i));
                }
            }
        }

        if (temp->status != 0 )
        {
            printf("in 4 for %d\n", temp->id);
            enqueue(Queue, temp);
        }
    }

    for (int i = 0; i < n; i++)
    {
        (p + i)->turn_around = (p + i)->completion_time - (p + i)->arrival;
    }
    for (int i = 0; i < n; i++)
    {
        (p + i)->wait_time = (p + i)->turn_around - tmp[i];
        total_wait += (p + i)->wait_time;
        printf("P%d-> Ct->%.2f Tat-%.2f-> Wt-%.2f\n", (p + i)->id, (p + i)->completion_time, (p + i)->turn_around, (p + i)->wait_time);
    }

    return total_wait / n;
}
float Avg_Turn_Around(process *p, int n)
{
    float total_turn_around = 0;
    for (int i = 0; i < n; i++)
    {
        total_turn_around += (p + i)->turn_around;
    }
    return total_turn_around / n;
}

int main()
{
    int n;
    float q;
    printf("Enter no.of Processes:\n");
    scanf("%d", &n);
    process *p = (process *)malloc(sizeof(process) * n);
    for (int i = 0; i < n; i++)
    {
        (p + i)->id = i + 1;
        printf("Enter CPU burst  for P%d:", i + 1);
        scanf("%f", &(p + i)->CPB);
        printf("Enter arrival  for P%d:", i + 1);
        scanf("%f", &(p + i)->arrival);
        fflush(stdin);
    }
    printf("Enter Time Quantum:");
    scanf("%f", &q);
    fflush(stdin);
    p = Sort(p, n);

    float x = Avg_Wait_Time(p, n, q);
    printf("Avg Wait:%.2f\n", x);
    float y = Avg_Turn_Around(p, n);
    printf("Avg Turn Around:%.2f", y);
    return 0;
}