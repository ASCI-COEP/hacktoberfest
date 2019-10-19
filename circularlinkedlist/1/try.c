#include "list.h"

int main(int argc, char const *argv[])
{
	list l1, l2;
	char *t;
	char *string = "hello";
	char *str2 = "hello";
	char *str3 = "hellodsfa";
	char *str4 = "hsad";
	char *str5 = "chup";
	char *str6 = "chupsad";
	init(&l1);
	init(&l2);

	insert(&l1, string, 0);
	insert(&l1, str2, 1);
	insert(&l1, str3, 2);
	insert(&l1, str5, 1);
	insert(&l2, str4, 0);
	insert(&l2, str6, 0);
	// t = traverse(&l1);
	// printf("%s\n",t );
	// t1 = traverse(&l2);
	// printf("%s\n",t1 );
	t = traverse(&l1);
	printf("str = %s\n",t );
	remDuplicate(&l1);
	t = traverse(&l1);
	printf("str = %s\n",t );

	// Interseclist(&l1,&l2);
	return 0;
}