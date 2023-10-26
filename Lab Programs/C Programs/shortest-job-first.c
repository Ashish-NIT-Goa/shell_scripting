#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Process
{
    float CPB;
    float wait_time;
    float turn_around;
}process;

process *Sort(process *p,int n)
{
    process *temp;
    temp = (process*)malloc(sizeof(process)*n);
    for(int i=0;i<n;i++)
    {
        (temp+i)->CPB = (p+i)->CPB;
        (temp+i)->wait_time = (p+i)->wait_time;
        (temp+i)->turn_around = (p+i)->turn_around;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((temp+i)->CPB < (temp+j)->CPB)
            {
                float t = (temp+i)->CPB;
                (temp+i)->CPB = (temp+j)->CPB;
                (temp+j)->CPB=t;
            }
        }
    }
    return temp;
}

float Avg_Wait_Time(process *p,int n)
{
    float total_wait=0;
    float time_elapsed = 0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {   
          (p+i)->wait_time=0;
          time_elapsed=(p+i)->CPB;
          total_wait=(p+i)->wait_time;
        }
        else 
        {
            (p+i)->wait_time=time_elapsed;
            time_elapsed+=(p+i)->CPB;
            total_wait+=(p+i)->wait_time;
        }
    }
    return total_wait/n;
}

float Avg_Turn_Around(process *p,int n)
{
    float total_turn_around=0;
    for(int i=0;i<n;i++)
    {
        (p+i)->turn_around=(p+i)->CPB+(p+i)->wait_time;
        total_turn_around+=(p+i)->turn_around;
    }
    return total_turn_around/n;
}

int main()
{
    int n;
    printf("Enter no.of Processes:\n");
    scanf("%d",&n);
    process *p = (process*)malloc(sizeof(process)*n);
    for( int i=0;i<n;i++)
    {
        printf("Enter CPU burst  for P%d:",i+1);
        scanf("%f",&(p+i)->CPB);
        fflush(stdin);
    }
    p = Sort(p,n);
    float x = Avg_Wait_Time(p,n);
    printf("Avg Wait:%.2f\n",x);
    float y = Avg_Turn_Around(p,n);
    printf("Avg Turn Around:%.2f",y);
    return 0;
}