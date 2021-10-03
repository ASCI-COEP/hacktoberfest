#include <bits/stdc++.h>
using namespace std;

class Calender{
	public :
		int month, year;

		Calender(int mo, int yr){
			month = mo;
			year = yr;
		}

		// Calender(){

		// }
		void Print_Month(){
			PrintMonth(month, year);
		}
		int GetDays(int month, int year){
			if( month == 2){
				if((year % 400==0) || (year % 4 == 0 && year % 100 != 0))	
					return 29;
				else	
					return 28;
			}
			
			else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12)	
				return 31;
			else 		
				return 30;
		} 

	int MonthStartsOn(int mnth, int yr){
		return 6;
	}

	void PrintMonth(int mnth, int yr){
		int date = MonthStartsOn(mnth, yr), i, j, k;
		int days = GetDays(mnth, yr);
		char c = ' ';
		cout << "Mon" << " " << "Tue" << " " << "Wed" << " " << "Thu" << " " << "Fri" << " " << "Sat" << " " << "Sun" << endl;
		k = 1;
		for(i = 0; i < 7; i ++){
			if(i < date){
				cout << c << c << c << c;
			}
			else{
				cout << k++ << c << c << c;
			}
		}

		cout << endl;
		k = 8 - date;
		while(k < 10){
			for(i = 0; i < 7; i ++){
				if(k > 9)
					break;
				cout << k << c << c << c; 
				k ++;
			}
			if(i == 7)
				cout << endl;
		}
		while(i != 7){
			cout << k << c << c;
			k ++;
			i ++;
		}
		cout << endl;
		while(k <= days){
			for(i = 0; i < 7; i ++){
				if(k > days)
					break;
				cout << k << c << c;
				k ++;
			}
			cout << endl;
		}
	}
};


int main(){
	Calender c;
	c.PrintMonth(7, 2020);

	return 0;
}