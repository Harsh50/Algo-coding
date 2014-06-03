#include<iostream>
#include<conio.h>
using namespace std;
/*This function moves disks from tower A to C using a spare tower B for storage

 Base case: n=1, move the only disk from tower A to C
 
 There is only one position which allows bottom most nth disk to move from A to C: when there is only
 nth disk on A..C is empty and n-1 disks are stacked on B.
 
 so, first n-1 disk problem from A to B is solved
     next nth disk is moved from A to C
     then, n-1 disk problem from B to C is solved
*/     


void move(int n,char from,
                    char to,char spare)
 {
    if(n>0)
    {
       move((n-1),from,spare,to); // moving n-1 disks from A to B

       cout<<"\t Move the Disk from Tower-"<<from      //moving nth disk from A to C
                          <<" to Tower-"<<to<<"\n";

       move((n-1),spare,to,from);     //moving n-1 disks from B to C
    }
 }
int main()
{
	int n;
	cout<<"\nEnter the number of disks: ";
	cin>>n;
	move(n,'A','C','B');
	getch();
	return 0;
	
}
