#include<iostream>
#include<conio.h>
using namespace std;

/*
 The function takes argument a,n and s..a is an integer array and n is the size of the array..
 s is used to store the sum during the recursion process
 
 

for a[]={1,2,3,4}..it works as follows:
 sum(a,4,0) = sum(a,3,4)
          =sum(a,2,7)
          =sum(a,1,9)
		   
          = sum(a,0,10)
          = 10
*/


/* Base case: n=0
   Recurrence Relation: f(a,n,s) = f(a,n-1,s1)  where n>0, s1=s+a[n-1]
*/            
int sum(int a[],int n, int s) {    
    // Basic Case to stop the recursion
if (n==0)  {
        return s;
    } else {
        s = s + a[n-1];  //variable to keep the elements sum
        n--;
        return sum(a,n, s); //returning sum to print it.
    }
}
int main()
{
	int n;
	cout<<"\nEnter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter the array elements:\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"\n\nThe sum of array elements is "<<sum(a,n,0);
	getch();
	return 0;
	
}
