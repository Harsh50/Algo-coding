#include<iostream>
#include<conio.h>
using namespace std;
/* The function takes argument n..till n is not equal to zero..it calls itself recursively with
parameter n/10

for n=465..it works as follows:
 sum(4) = 5 + sum(46)
        = 5 + 6 +sum(4)
        =11 + 4 +sum(0)
        =11+4+0
        =15
*/

/* Base case: n=0

   Recurrence Relation: f(n) = f(n/10) + n%10  , n is not equal to zero
           
*/       
int sum(int n)
{
	if(n!=0)
    return (n%10+sum(n/10));
    else
    return 0;
}
int main()
{
	int n;
	cout<<"\nEnter the number: ";
	cin>>n;
	cout<<"\n\nThe sum of the digits is "<<sum(n);
	getch();
	return 0;
}

