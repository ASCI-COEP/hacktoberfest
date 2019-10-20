#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int readline(char *arr, int n) {
	char ch;
	int count = 0;
	while((ch = getchar()) != '\n' && count < n)
		arr[count++] = ch;
	arr[count] = '\0';
	return count;
}

int isBalance(char* s) {
	stack t;
	int flag = 1, i = 0;
	init(&t);
	char currop;
	while(s[i] != '\0') {
		currop = s[i];
		switch(currop) {
			case '(' : case '[' : case '{' :
				push(&t, currop);
				break;
			case ')' :  
				if(!isEmpty(&t)) {
					if(pop(&t) != '(') {
						flag = 0;
						break;
					}
				}else{
					flag = 0;
					break;
				}
				break;
			case ']':
				if(!isEmpty(&t)) {
					if(pop(&t) != '[') {
						flag = 0;
						break;
					}
				}else{
					flag = 0;
					break;
				}
				break;
			case '}':
				if(!isEmpty(&t)) {
					if(pop(&t) != '{') {
						flag = 0;
						break;
					}
				}else {
					flag = 0;
					break;
				}
				break;
		}
		i++;
	}
	if(flag && isEmpty(&t)){
		return 1;
	}else {
		return 0;
	}

}
int main() {
	int x;
	char *s = (char*) malloc(sizeof(char) * 1024);
	while(x = readline(s, 1024)) {
		if(isBalance(s))
			printf("Expression has balanced parenthesis\n");
		else
			printf("Expression has unbalanced parenthesis\n");
	}
		return 0;
}
