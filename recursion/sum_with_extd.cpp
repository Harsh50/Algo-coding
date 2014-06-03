#include<iostream>
#include<conio.h>
using namespace std;

/*The function uses two arguments.. one is the number that is passed and the second is used to store
the sum during the recursion process*/

/* Base case: n=0

   Recurrence Relation : f(n,s) = f(n1,s1) , n>0,where n1=n/10 and s1=s+n%10
   
*/   


int sum(int n, int s) {    
    // Base Case to stop the recursion
if (n== 0)  {
        return s;
    } else {
        s= s + n % 10;  //variable to keep the digits sum
        n= n/10;
        return sum(n, s); //returning sum to print it.
    }
}

int main()
{
	int n;
	cout<<"\n\nEnter the number: ";
	cin>>n;
	cout<<"\n\nThe sum of the digits is "<<sum(n,0);
	getch();
	return 0;
	
}
