#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
int main() {
	stack t;
	int flag = 1, i = 0;
	init(&t);
	char currop;
	char *s = "{ 2 + 4 * [ 3 / 2]} ";
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
				}
				break;
			case ']':
				if(!isEmpty(&t)) {
					if(pop(&t) != '[') {
						flag = 0;
						break;
					}
				}
				break;
			case '}':
				if(!isEmpty(&t)) {
					if(pop(&t) != '{') {
						flag = 0;
						break;
					}
				}
				break;
		}
		i++;
	}
	if(flag && isEmpty(&t)){
		printf("Balanced Parenthesis\n");
	}else {
		printf("Unbalanced Parenthesis\n");
	}
	return 0;
}
