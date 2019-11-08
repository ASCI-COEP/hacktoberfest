#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	string lower;
	
	cout << "Enter the string: " << endl;
	getline(cin, lower);
	
	for(int i = 0; i < lower.size(); i++)
		if(lower[i] >= 97 && lower[i] <= 122)
			lower[i] = lower[i] - 32;
	
	cout << "Converted String: " << lower << endl;

	return 0;
  
}
