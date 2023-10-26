#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Process
{
    float CPB;
    float wait_time;
    float turn_around;
    int status;
    float arrival;
    float completion_time;
}process;

int All_Status(process *p,int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
      s+=(p+i)->status;
    }
    return s;
}

float Avg_Wait_Time(process *p,int n,float q)
{
    float *tmp = (float*)malloc(sizeof(float)*n);
    for(int i=0;i<n;i++)
    {
        tmp[i]=(p+i)->CPB;
    }
    float total_wait=0;
    float time_elapsed=0;
    while(All_Status(p,n)!=0)
    {
        for(int i=0;i<n;i++)
        {
            if((p+i)->status!=0)
            {
                int x = tmp[i]-q;
                if(x<=0)
                {
                    (p+i)->status=0;
                   time_elapsed+=tmp[i];
                   tmp[i]=0;
                   (p+i)->completion_time=time_elapsed;
                }
                else{
                    tmp[i]-=q;
                   time_elapsed+=q;
                }
            }
        }
    }
   
    for(int i=0;i<n;i++)
    {
        (p+i)->turn_around=(p+i)->completion_time-(p+i)->arrival;
    }
    
    for(int i=0;i<n;i++)
    {
        (p+i)->wait_time=(p+i)->turn_around-(p+i)->CPB;
        total_wait+=(p+i)->wait_time;
        printf("%d->%f\n",i,(p+i)->wait_time);
    }
    
    return total_wait/n;
}

float Avg_Turn_Around(process *p,int n)
{
    float total_turn_around=0;
    for(int i=0;i<n;i++)
    {
        total_turn_around+=(p+i)->turn_around;
    }
    return total_turn_around/n;
}

int main()
{
    int n;
    float q;
    printf("Enter no.of Processes:\n");
    scanf("%d",&n);
    process *p = (process*)malloc(sizeof(process)*n);
    for( int i=0;i<n;i++)
    {
        (p+i)->status=1;
        printf("Enter CPU burst  for P%d:",i+1);
        scanf("%f",&(p+i)->CPB);
        fflush(stdin);
    }
    printf("Enter Time Quantum:");
    scanf("%f",&q);
    float x = Avg_Wait_Time(p,n,q);
    printf("Avg Wait:%.2f\n",x);
    float y = Avg_Turn_Around(p,n);
    printf("Avg Turn Around:%.2f",y);
    return 0;
}