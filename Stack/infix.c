#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int j = 0;				//declare global j so that it can be used to represent the index  of 
						//line in every recursive call given when there is a bracket

typedef struct node {		//defining single structure with union for both  
	union A{				//operator and operand stacks as well as temperoroy node
		char op;
		int num;
	}A;
	struct node *next;
}node;

char showoptr1(node **top) {
	if(*top != NULL)
		return (*top)->A.op;
	return 0;
}

char showoptr2(node **top) {
	//if((*top) != NULL)
		if((*top)->next != NULL)
			return (*top)->next->A.op;
	return 0;
}



void startstack(node **top) {		//initiaize both stacks to NULL
	*top = NULL;
}

void pushopnd(node **top, int no) {
	node *temp = NULL;								//declare temperory node pointer to hold the value and then point it to top
	temp = (node*)malloc(sizeof(node));
	temp->A.num = no;								//push an operand to the operand stack whenever found
	//printf("pushed sum=%d\n",temp->A.num);
	temp->next = *top;
	*top = temp;
}

/*
int pop(stack *s) {
    node *tmp = *s;
    int val = (*s)->val;
    *s = (*s)->next;
    free(tmp);
    return val;
}
*/

int popopnd(node **top) {				//pop the top operand from the operand stack
	//printf("1");
	node *temp;
	temp = *top;
	int no = temp->A.num;
	//printf("popped number=%d\n",no);
	*top = (*top)->next;
	temp->next = NULL;					
	free(temp);						//free the not necessary space now pointed by temp
	return no;
}

int isempty(node **top){
	if((*top) == NULL) {
		return 1;
	}
	else 
	return 0;
}

void pushoptr(node **top, char opt) {		//push the operator to the operator stack
	node *temp = NULL;
	temp = (node*)malloc(sizeof(node));
	temp->A.op = opt;
	//printf("pushed optr=%c\n",temp->A.op);
	temp->next = *top;
	*top = temp;
	//printf("%c   %c\n", temp->A.op, (*top)->A.op);
}

char popoptr(node **top) {			//pop the top  operator from operator stack
	node *temp = NULL;
	char opt = (*top)->A.op;
	temp = *top;
	*top = (*top)->next;
	temp->next = NULL;
	//free(temp);
	return opt;
}


	node *topopnd;			//declare global stack variables 
	node *topoptr;			//so that they can be used in any function
	//printf("1");

/*
typedef struct opnd{
	int num;
	struct opnd *next;
}opnd;

typedef struct optr{
	char op;
	struct optr *next;
}optr;
*/

void readstring(char *line) {			//function to read the expression as char string
	int i = 0;
	char ch;
	line[i++] = '0';
	line[i++] = '+';
	while((ch = getc(stdin)) != '\n'){
		//printf("1");
		line[i++] = ch;
	}
	if(ch == ')' || ch == ')'){
	}	
	line[i++] = ' ';			//add an extra space as the program wasnt working in the 
	line[i] = '\0';				//case of 5*(-5) i.e where the string ends with a bracket
	//return i;
}


int optrprec(char curroptr, char prevoptr) {			//to check operator precedence
	if((prevoptr == '+' || prevoptr == '-') && (curroptr == '*' || curroptr == '/'))	//dont pop the previous operator only if 
		return 0;																//the previous operator is + or -, and current operator is * or / 
	return 1;
}

int infixeval(char *line, int len) {		//main fuction to solve the infix and also the function called recursively in case of brackets
	
	int sum = 0, a, b, res, x = 0, end = 0;
	char currchar, exp;		//, sh1, sh2, tempop;
	
	while(j <= len) {					//loop runs until the char string ends
		//printf("KJSDGFJ\nlen = %d\n", len);
		currchar = line[j++];
		//printf("current char = %c\t j = %d\n", currchar, j);
		
		switch(currchar) {					//switch to seperate operands and operators into their stacks and ignore spaces
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				sum = sum * 10 + (int)currchar - '0';
				//printf("sum=%d\n",sum);
				//printf("j= %d\n", j);
				if(j == len || line[j] == ')'){			//at the end of the string
					//printf("last number=%d\n", sum);
					pushopnd(&topopnd, sum);
				}
				break;
				
			case '+': case '-': case '*': case '/':
				pushopnd(&topopnd, sum);		//if the current operator is operator then push the operand formed in sum
				//printf("number=%d\n",sum);
				sum = 0;
				if(isempty(&topoptr)){		//for empty operator stack always push the operator
					x++;
					pushoptr(&topoptr, currchar);
					//printf("%c\n",topoptr->A.op);
				}
				else if(optrprec(currchar, topoptr->A.op) && x){		//check the precidence and if it satisfies the condition in optrprec funtion
					exp = popoptr(&topoptr);							//then pop the previous optr and also pop top 2 opnds and solve them
					pushoptr(&topoptr, currchar);						//and push the result to the operand stack
					//printf("popped-operator=%c\n",exp);
					if(!isempty(&topopnd))
						b = popopnd(&topopnd);
					if(!isempty(&topopnd))
						a = popopnd(&topopnd);
					//printf("a=%d  b=%d",a,b);
					
					switch(exp) {
						case '+':
							res = a + b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '-':
							res = a - b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '*':
							res = a * b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '/':
							res = a / b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
					}
					/*
					printf("123");
					while(optrprec(sh1 = showoptr1(&topoptr), sh2 = showoptr2(&topoptr))){
						printf("123");
						tempop = popoptr(&topoptr);
						printf("123");
						exp = popoptr(&topoptr);
						printf("123");
						pushoptr(&topoptr, tempop);
						printf("123");
						switch(exp) {
						case '+':
							res = a + b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '-':
							res = a - b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '*':
							res = a * b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						case '/':
							res = a / b;
							pushopnd(&topopnd, res);
							//printf("res=%d\n",res);
							break;
						}
					}		*/
				}
							
				else{											//if the precedence funtion fails then directly push to the optr stack
					pushoptr(&topoptr, currchar);
					x++;
					//printf("pushopter%c\n",currchar);
				}
				break;
				
			case ' ':  case '\t':						//ignore the spaces
				if(j == len || line[j] == ')'){			//if the last char is space them push the operand to the stack held in sum
					//printf("last number=%d\n", sum);
					pushopnd(&topopnd, sum);
				}
				break;

			case  '(': 							//if found ( then call infixeval recursively and return the result 
				//printf("BRACKET-START\n");	//form the expressioon present in the complete backet
				//printf("	%d\n", j);
				sum = infixeval(line, len);
				//printf("SUM = %d\n", sum);
				a = popopnd(&topopnd);
				//printf("not useful pop=%d", a);
				//pushopnd(&topopnd, res);
				break;
			case ')':							//to show that the bracket has ended but as our while loop runs for entire line, 
				end = 1;						//we need to explicitly end the switch here
				//printf("BRACKET ENDS NEXT\n");
				break;
		}
		//printf("sum outside=%d\n", sum);
		
		if(end){
			//printf("end in if = %d\n", end);
			break;									//we break the loop here when ) is encountered
		}
	}
	
	//printf("%d", isempty(topoptr));
			//printf("%d::%c", topopnd->A.num, topoptr->A.op);	
	//printf("end = %d\nx= %d\n", end, x);	
	while(!isempty(&topoptr) && x) {			//if the line is traced completely with precedence then the rest operations are
		x--;									//performed here until the *operator* stack is empty 
		b = popopnd(&topopnd);					//(as operand stack wont be empty since result is stored in it
		a = popopnd(&topopnd);
		exp = popoptr(&topoptr);
		//printf("%d::", res);
		switch(exp) {
			case '+':
				res = a + b;
				pushopnd(&topopnd, res);
				break;
			case '-':
				res = a - b;
				pushopnd(&topopnd, res);
				break;
			case '*':
				res = a * b;
				pushopnd(&topopnd, res);
				break;
			case '/':
				res = a / b;
				pushopnd(&topopnd, res);
				break;
		}
	}
	//printf("return: %d\n", res);
	return res;							//retrun the result for the function
}	





int main() {
	char *line;
		//	//printf("1");
	line = (char*)malloc(50);
	readstring(line);
   // fgets(line, 50, stdin); 
 
	startstack(&topopnd);
	startstack(&topoptr);
	int result = infixeval(line, strlen(line));
			//printf("1");
	printf("%d\n", result);
		//	//printf("1");
	free(line);
	return 0;
}
