#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, const char **argv){
	FILE *fp;
	int count = 0;
	char fline[100];
	char *rep = "char";
	
	fp = fopen(argv[1], "r");
	if(!fp){
		perror("Can't open file!");
		exit(1);
	}
	
	while(!feof(fp)){
		fgets(fline,100,fp);
		if(strstr(fline,rep)!=NULL){
			count++;
			printf("%s\n",fline);
		}
	}
	
	if(!count) printf("The substring %s is not present in this directory's file names.\n", rep);
	else printf("The substring %s ocured %d times in this directory's file names.\n", rep, count);
	
	return 0;
}