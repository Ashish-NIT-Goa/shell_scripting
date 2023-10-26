#include<stdio.h>

int main(){
    int n,R;
    printf("Enter the number of Processes and Resources: ");
    scanf("%d %d",&n,&R);

    int fin[n], res[R], alloc[n][R], max[n][R], need[n][R], req[R];
    int ans[n], index;
    int flag;
    index = 0;

    for(int i=0;i<n;i++) fin[i] = 0;

    printf("Enter the no. of available instances of each resource: ");
    for(int i=0;i<R;i++) scanf("%d",&res[i]);

    printf("Enter the no. of allocated resources to each process: ");
    for(int i=0;i<n;i++){
        printf("P%d: ",i);
        for(int j=0;j<R;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the maximum claim of each process: ");
    for(int i=0;i<n;i++){
        printf("P%d: ",i);
        for(int j=0;j<R;j++){
            scanf("%d",&max[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<R;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int p;
    printf("Which process wants to request resources? ");
    scanf("%d",&p);

    printf("Enter the no. of instances requested by the process P%d: ",p);
    for(int i=0;i<R;i++){
        scanf("%d",&req[i]);

        if(req[i] > need[p][i]){
            printf("Error! Process has exceeded its maximum claim!\n");
            return 0;
        }

        if(req[i] > res[i]){
            printf("Error! Process has exceeded the available resources!\n");
            return 0;
        }

        res[i] -= req[i];
        alloc[p][i] += req[i];
        need[p][i] -= req[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fin[j]==0){
                flag = 0;
                for(int k=0;k<R;k++){
                    if(need[j][k] > res[k]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    fin[j] = 1;
                    ans[index++] = j;
                    for(int k=0;k<R;k++){
                        res[k] += alloc[j][k];
                        alloc[j][k] = 0;
                    }
                }
            }
        }
    }

    flag = 1;

    for(int i=0;i<n;i++){
        if(fin[i] == 0){
            flag = 0;
            printf("Deadlock detected!!\n");
            break;
        }
    }

    if(flag == 1){
        printf("Safe Sequence: ");
        for(int i=0;i<n;i++) printf("P%d ",ans[i]);
        printf("\n");
    }

    return 0;
}