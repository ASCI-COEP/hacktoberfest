#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
/*Write a program which reads a file and counts the no. of occurrences of every word in it. */
int main(int argc, char *argv[])	{
	int fd, i = 0, j = 0, cnt = 0, word_cnt = 0;
	char ch;
	char tofind[20], arr[20];
	fd = open(argv[1], O_RDONLY | S_IRUSR | S_IWUSR);
	if (fd == -1)	{
		errno = EINVAL;
		perror("");
		return errno;
	}		
	while(read(fd, &ch, 1)){
		cnt++;
		tofind[i] = ch;
		i++;
		if (ch == ' ' || ch == '\n' || ch == '\t'){
			tofind[i] = '\0';
			lseek(fd, 0, SEEK_SET);
			while(read(fd, &ch, 1)){
				arr[j] = ch;
				j++;
				if (ch == ' ' || ch == '\n' || ch == '\t'){
					arr[j] = '\0';
					if(!strcmp(tofind,arr))
					word_cnt++;
					j = 0;	
					i = 0;
				}
				
			}
			printf("%s occured %d times\n",tofind,word_cnt);
			word_cnt = 0;
		}
		lseek(fd, cnt, SEEK_SET);
	}
	return 0;	
}
