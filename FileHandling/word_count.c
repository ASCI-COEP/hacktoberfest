#include<stdio.h>
#include<errno.h>
#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		perror("file not found\n");
		return errno;
	}

	char c;
	int state = OUT;
	c = fgetc(fp);
	int nw,nc,nl;
	nw = nc = nl = 0;

	while( (c = fgetc(fp) )!= EOF){
		nc++;
		
		if(c == '\n')
			nl++;
			
		if(c == ' ' || c == '\t' || c == '\n'){
			state = OUT;
		}
		else if(state == OUT){
			state = IN;
			nw++;
		}
	}

	printf("no of characters = %d\nno of words = %d\nno of lines = %d\n",nc,nw,nl);
	return 0;
}
