#include<iostream>
#include<conio.h>
using namespace std;

/*
 The function takes argument a and n..a is an integer array and n is the size of the array..
 
 

for a[]={1,2,3,4}..it works as follows:
 sum(a,4) = a[3]+sum(a,3)
          =a[3] + a[2] + sum(a,2)
          = a[3] + a[2] + a[1] +sum(a,1)
          =a[3] + a[2] + a[1] + a[0] + sum(a,0)
          = 4 + 3 + 2 + 1+ 0
          =10
*/

/* Base case: n=0
   Recurrence Relation: f(a,n) = a[n-1]+ f(a,n-1)  where n>0
*/            
int sum(int a[],int n)
{
	if(n>0)
	return (a[n-1]+sum(a,n-1));
	else
	return 0;
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
	cout<<"\n\nThe sum of array elements is "<<sum(a,n);
	getch();
	return 0;
	
}
