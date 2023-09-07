#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char **argv)
{
FILE *f1,*f2;char ch;
f1=fopen(argv[1],"r");
f2=fopen(argv[2],"w");
if(f1==NULL || f2==NULL)
{
printf("unable to open");
}
else
{
while(!feof(f1))
{
ch=fgetc(f1);
fputc(ch,f2);
}
printf("Successfully copied contents of file-1 to file-2\n");
fclose(f1);
fclose(f2);
}
}
