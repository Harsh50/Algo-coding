#include<iostream>
#include<conio.h>
using namespace std;
/*
  The function uses 2 arguments..n which the number to be checked and k which is initially
  n/2 and then reduced by 1 in each subsequent function call 
  
  
  Base case: There are three base cases:
             1) k=1
             2) n<=1
             3) n is divisble by k
  Recurrence relation: f(n,k) = f(n, k-1) where k is not equal to 1, n>1, n is not divisible by k
  
 */            
bool isprime(int n,int k)
{
	if(k==1)   //if k becomes 1 then n is prime
	return true;
	if(n<=1)
	return false;
	if(n%k==0)     // checking if n is divisible by k
	return false;
	else
	isprime(n,k-1);
}
int main()
{
	int n;
	cout<<"\nEnter a number: ";
	cin>>n;
	if(isprime(n,n/2))
	cout<<"\n\nIt is a prime number. ";
	else
	cout<<"\n\nIt is not a prime number ";
	
	getch();
	return 0;
}

