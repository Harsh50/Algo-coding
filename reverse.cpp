#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
/* The arguments are the string(s),starting index(i) and end (j) of the string
It recursively calls itself till i is less than j and then starts swapping characters
at ith and jth position respectively

 for s[]="harsh" it works as follows:
  
  when base case is reached s[i]=s[j]=r
  then,
  
  "harsh" = "harsh"
          ="hsrah" 
          ="hsrah"
*/

/* Base case: i>=j
   
    Recurrence Relation: f(s,i,j) =f(s,i+1,j+1) where i<j
    
*/          

void reverse(char s[],int i,int j)
{
	if(i<j)
	reverse(s,i+1,j-1);
	else return;
	char temp;
	temp=s[i];
	s[i]=s[j];   //swapping characters at ith and  jth position
	s[j]=temp;
}

int main()
{
	char s[50];
	cout<<"\nEnter a string: ";
	cin>>s;
	reverse(s,0,strlen(s)-1);
	cout<<"\n\nThe reverse string is "<<s;
	getch();
	return 0;
}
