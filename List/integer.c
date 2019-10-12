#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "integer.h"
#define max_int 1024
static int nodeCount = 0;

void initInteger(Integer *a) {
	a -> head = NULL;
	a -> tail = NULL;
	a -> noOfDigits = 0;
}

void addDigit(Integer *a, char c) {
	if(c - 48 < 0 || c - 48 > 9) return;
	
	node *ptr;
	if(!a -> head) {
		a -> head = (node *)malloc(sizeof(node));
		nodeCount++;
		ptr = a -> head;
		ptr -> previous = NULL;
		ptr -> data = c - 48;
		ptr -> next = NULL;
		a -> tail = ptr;
		a -> noOfDigits++;
	}
	
	else {
		node *ptr2;
		ptr = a -> tail;
		ptr -> next = (node*)malloc(sizeof(node));
		nodeCount++;
		ptr2 = ptr;
		ptr = ptr -> next;
		ptr -> previous = ptr2;
		ptr -> data = c - 48;
		ptr -> next = NULL;
		a -> tail = ptr;
		a -> noOfDigits++;
	}
}

void printInteger(Integer a) {
	node *ptr = a.head;
	while(ptr) {
		printf("%d", ptr -> data);
		ptr = ptr -> next;
	}
	printf("\n");
}

Integer createIntegerFromString(char *str) {
	int x = 0;
	Integer a;
	initInteger(&a);
	while(x < strlen(str))
		addDigit(&a, str[x++]);
	return a;
}

Integer addIntegers(Integer a, Integer b) {
	Integer c;
	initInteger(&c);
	node *ptr1, *ptr2;
	int larger, i, carry = 0, sum = 0, x, y;
	char str[max_int] = {};
	if(a.noOfDigits != b.noOfDigits)
		larger = a.noOfDigits > b.noOfDigits ? a.noOfDigits : b.noOfDigits;
	else
		larger = a.noOfDigits;
	i = larger;
	str[larger + 1] = '\0';
	ptr1 = a.tail;
	ptr2 = b.tail;
	while(larger != -1) {
		if(ptr1)
			x = ptr1 -> data;
		else
			x = 0;
		if(ptr2)
			y = ptr2 -> data;
		else
			y = 0;
			
		sum = x + y + carry;
		if(sum >= 10) {
			sum = (sum - 10) + '0';
			str[i--] = sum;
			carry = 1;
		} else {
			sum = sum + '0';
			str[i--] = sum;
			carry = 0;
		}
		if(ptr1) ptr1 = ptr1 -> previous;
		if(ptr2) ptr2 = ptr2 -> previous;
		larger--;
	}
	c = createIntegerFromString(str);
	return c;
}

Integer subtractIntegers(Integer a, Integer b) {		
	Integer c;
	initInteger(&c);
	
	if(a.noOfDigits < b.noOfDigits) {
		addDigit(&c, '0');
		return c;
	} else if(a.noOfDigits == b.noOfDigits) {
		if(a.head -> data < b.head -> data) {
			addDigit(&c, '0');
			return c;
		}
	}

	node *ptr1, *ptr2;
	int larger, i, borrow = 0, diff = 0, x, y;
	char str[max_int] = {};
	larger = a.noOfDigits;
	i = larger;
	str[larger + 1] = '\0';
	ptr1 = a.tail;
	ptr2 = b.tail;
	while(larger != -1) {
		if(ptr1)
			x = ptr1 -> data;
		else
			x = 0;
		if(ptr2)
			y = ptr2 -> data;
		else
			y = 0;
			
		diff = x - y - borrow;
		if(diff < 0) {
			diff = (x + 10) - y - borrow + '0';
			str[i--] = diff;
			borrow = 1;
		} else {
			diff += '0';
			str[i--] = diff;
			borrow = 0;
		}
		if(ptr1) ptr1 = ptr1 -> previous;
		if(ptr2) ptr2 = ptr2 -> previous;
		larger--;
	}
	c = createIntegerFromString(str);
	return c;
}

void destroyInteger(Integer *a) {
	node *ptr = a -> head, *temp;
	while(ptr) {
		temp = ptr;
		ptr = ptr -> next;
		free(temp);
	}
	printf("Integer destroyed successfully\n");
}

/*int main() {
	char str[max_int];
	Integer a, b, c;
	initInteger(&a);
	initInteger(&b);
	initInteger(&c);
			
	scanf("%s", str);
	a = createIntegerFromString(str);
	scanf("%s", str);
	b = createIntegerFromString(str);
	
	c = subtractIntegers(a, b);
	printInteger(c);
	destroyInteger(&a);
	destroyInteger(&b);
	destroyInteger(&c);
	return 0;
}*/


