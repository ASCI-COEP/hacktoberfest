#include<stdio.h>
#include<string.h>
struct student { 
	char name[16];
	int age;
	double marks;
};
int main(){
	int i = 0, k;
	char s[16];
	struct student info[50];
	
	while(info[i-1].age != -1){
		scanf("%s%d%lf", info[i].name, &info[i].age, &info[i].marks);
		i++;
	}
	k = --i;
	scanf("%s", s);
	for(i=0; i<k; i++)
	    if(strcmp(s, info[i].name)==0){
			printf("%s %d %.0lf", info[i].name, info[i].age, info[i].marks);
			break;
		}
	return 0;
}
		
