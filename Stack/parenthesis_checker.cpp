/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	unsigned int T, i;
	stack < char > st;
	string str;
	bool balanced = true;
	cin >> T;

	while(T--) {
		cin >> str;
		for(i = 0; i < str.size(); i++) {
			if(str[i] == '{' || str[i] == '[' || str[i] == '(')
					st.push(str[i]);
			else if(!st.empty() && ((str[i] == '}' && st.top() == '{') || (str[i] == ']' && st.top() == '[') ||(str[i] == ')' && st.top() == '(')))
						st.pop();
			else {
				balanced = false;
				break;
			}
			balanced = true;
		}
		if(balanced && st.empty())
			cout << "balanced" << endl;
		else
			cout << "not balanced" << endl;
		while(!st.empty())
			st.pop();
	}
	return 0;
}
