#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    if(argc < 2) {
    	errno = EINVAL;
        perror("Invalid Argument To Main\n");
        return errno;
    }
	int i, fd, n;
	struct info {
		int id;
		char name[16];
		double score;
	};
	struct info *ptr;
	scanf("%d", &n);   //User Gives Number Of Data To Be Entered
	//printf("%d",n);
	ptr = (struct info *)malloc(sizeof(struct info) *n);
	if(ptr == NULL) {
		perror("Memory Not Available\n");
		return errno;
	}
	for(i = 0; i < n; i++) {
		//printf("ID = ");
		scanf("%d", &ptr[i].id);
		//printf("NAME = ");
		scanf("%s", ptr[i].name);
		//printf("SCORE = ");
		scanf("%lf", &ptr[i].score);
	}
	fd = open(argv[1], O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	if(fd == -1) {
		perror("File Not Opened\n");
		return errno;
	}
	write(fd, &n, sizeof(n));
	for(i = 0; i < n; i++) {
		write(fd, &ptr[i].id, sizeof(ptr[i].id));
		write(fd, ptr[i].name, sizeof(ptr[i].name));
		write(fd, &ptr[i].score, sizeof(ptr[i].score));
	}
	close(fd);
	return 0;
}
