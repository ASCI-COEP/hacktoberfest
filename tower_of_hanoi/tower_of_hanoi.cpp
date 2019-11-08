#include<iostream>
using namespace std;
void TOH(int d,char tower1, char tower2, char tower3)
{
	if(d==1)  //base case
	{
		cout<<"\nShift top disk from tower "<<tower1<<" to tower "<<tower2;
		return ;
	}
	TOH(d-1, tower1 , tower3, tower2);  //recursive function call
	cout<<"\nshift top disk from tower "<<tower1<<" to tower "<<tower2;
	TOH(d-1,tower3,tower2,tower1); //recursive function call
}
// tower1 is the source and tower2 is the destination and tower3 is the intermediate.
int main()
{
	int disk;
	cout<<"enter the no. of disks:  ";
	cin>>disk;
	if(disk<1)
		cout<<"\nthere are no disks to shift.";
	else
		cout<<"there are "<<disk<<" disks in tower 1\n";
	
	TOH(disk,'1','2','3');
	cout<<endl<<disk<<" disks in tower 1 are shifted to tower 2\n";
	return 0;
}
