#include<iostream>
#include<conio.h>
using namespace std;
/*The function is called recursively until n is equal to 1..functions calls are stacked 
on top of each other..topmost being when n=1 followed by n=2,3,4 and so on..but in this case n is printed
before calling the function recursively..thus the order is descending*/

/* Base case: n=1
Recurrence Relation: f(n)=f(n-1) , n>1
*/
void descending_natural(int n)
{
	cout<<n<<"\n";
	if(n>1)
	descending_natural(n-1);
	return;
}
int main()
{
	int n;
	cout<<"\nEnter the value of n: ";
	cin>>n;
	descending_natural(n);
	getch();
	return 0;
}
