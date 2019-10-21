#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"q.h"
#include<unistd.h>
#include<fcntl.h>


int main(int argc, char *argv[]){
	queue q1;
	init(&q1);
	data new;
	int count = 0;
	while(scanf("%s %lld",new.name,&new.mob) != -1){
		nq(&q1,new);
		count++;
	}
	data temp;
	FILE *fd = fopen(argv[1],"r+");
	if(fd == NULL){
		return -199;
	}
	//for(int i = 0 ; i  < count ; i++)
	while(!isEmpty(&q1))
	{
		temp = dq(&q1);
		fprintf(fd,"%s,%lld\n",temp.name,temp.mob);
		//puts(temp.name);
		//printf("%lld\n",temp.mob);
	}
	fclose(fd);
	return 0;
}
