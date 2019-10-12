#include<stdio.h>

typedef struct node {
	struct node* previous;
	int data;
	struct node* next;
}node;

typedef struct Integer {
	node *head;
	node *tail;
	int noOfDigits;
}Integer;
	
void initInteger(Integer *a);

/* Initialize the "Integer" type data structure.
 * You may interpret an "empty" Integer to be the value 0.
 */

void addDigit(Integer *a, char c); 

  /* Appends one digit to an existing Integer data type.
 * E.g. if the Integer a was 1234 and the function was called as
 * addDigit(Integer *a, char c); where c='5'
 * then Integer a becomes 12345.
 * Ignore the request if c is not a digit.  
 */

Integer createIntegerFromString(char *str);

 /* Create and return an Integer from a string.
 * 'str' may contain non-digits, in that case you should
 * process 'str' upto the first non-digit. E.g. if
 * 'str' was  123ab45 then the Integer returned will be 123
 * if 'str' was "abhijit" then the Integer returned will be 0
 */

Integer addIntegers(Integer a, Integer b);

/* This function adds two Integers a and b, and returns the sum as Integer */

Integer subtractIntegers(Integer a, Integer b);

  /* This function substracts two Integers a and b, and returns the difference as Integer. Here a must be bigger than b (as Integer is non-zero). If a is smaller than b, then you can return an Integer with value 0 */

void printInteger(Integer a);

/* Print an Integer (just the sequence of digits, nothing else) with a \n in the end  */

void destroyInteger(Integer *a);
/* Destroys an Integer, i.e. deallocates all malloced memory
 * for the Integer and reInitiatizes it */
