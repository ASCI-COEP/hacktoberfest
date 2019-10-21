#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int length) {
	int i;
	for(i = 0; i < length / 2; i++) {
		if(str[i] != str[length -1 -i])
			return 0;
	}
	return 1;
}
int main() {
	char str[100];
	int length;
	scanf("%s", str);
	length = strlen(str);
	isPalindrome(str, length) ? printf("True\n") : printf("False\n");
	return 0;
}