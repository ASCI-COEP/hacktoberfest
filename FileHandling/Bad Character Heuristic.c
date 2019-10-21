#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
/*Here, printf statements are used for the user to understand*/
int check(char *pat, char *buff, int i){	
	int len = strlen(pat);
	int q = len - 1, j, cnt = 0;
	char ch;
	while(q >= 0){
		if (pat[q] == buff[i]){					/*Find if pattern and text character matches*/
			q--;
			i--;
		}
		else{
			ch = buff[i];					/*return index of mismatch*/	/*mismatch occured at a character*/
			for (j = q; j >= 0; j--){
				if (ch == pat[j]){			/*Find if mismatched character occurs in pattern*/
					return cnt; 			/*Return the index of character when match found in pattern*/
				}
				else{
					cnt++;
				}
			}
			return len + (len - q -1);			/*If the character of text does not match then skip the characters till the mismatch*/
		}
	}
	printf("Match Found\n");
	return len;							/*whole pattern matched*/
}

void badch(char *pat, char *buff){
/*	Bad Character Heuristic --		
*	
*	1. Compare characters right to left.
*
*	1. If mismatch occured, search for character in pattern and return index and skip the bytes.
*
*	2. If mismatched character not in pattern, skip the bytes till the pattern moves past mismatch.
*/
	int i = 0;
	int len_p = strlen(pat);
	int len_b = strlen(buff);
	i = len_p -1;
	while(i <= len_b){ 							/*Iterate till end of file*/
		
		/*Check for pattern in substring*/
		
		i += check(pat, buff, i);
										/*Calling check function*/
		printf("Current i = %d\n",i);
	}
}

int main(){	
	char buff[] = "ABCABCsdfdAfsBCBAsdfCBsdfABfjdkggjfdkjfdsgdsjkaljcJjkddjkf";
	char pat[]  = "ABC";
	badch(pat, buff);
	printf("main End\n");
	return 0;
}
