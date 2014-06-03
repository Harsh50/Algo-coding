#include<iostream>
#include<conio.h>

using namespace std;
/*The function is called recursively until n is equal to 1..function calls are stacked 
on top of each other..topmost being when n=1 followed by n=2,3,4 and so on..thus first n=1 is printed..
followed by completion of other functions..as a result natural numbers upto n are printed in ascending
order*/


/* Base case: n=1
Recurrence Relation: f(n)=f(n-1)   , n>1
*/
void ascending_natural(int n)
{
	if(n>1)
	{
		ascending_natural(n-1);
		
	}
	cout<<n<<"\n";
	return;
	
	
}
int main()
{
	int n;
	cout<<"\nEnter the value of n: ";
	cin>>n;
	ascending_natural(n);
	getch();
	return 0;
}
