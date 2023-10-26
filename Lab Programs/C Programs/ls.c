#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

//we must give whole path from the root(mnt)
int main(int argc,char **argv)
{
    
    DIR *dp =opendir(argv[1]);
    struct dirent *link =readdir(dp);
    while(link!=NULL)
    {
        printf("length-%d type-%d name-%s \n",link->d_reclen,link->d_type,link->d_name);
        link = readdir(dp);
    }
    int c = closedir(dp);
    if(c==0)
    {
        printf("Closed succesfully!!\n");
    }
    return 0;
}