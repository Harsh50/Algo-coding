#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
void permute(char str[],char per[],int len,int last,int index)
{   
	int i;
	for(i=0;i<len;i++)
	{
		per[index]=str[i];
		if(index==last)
		{ 
		per[last+1]='\0';
		
		cout<<per<<"\n\n";
	}
		else
		permute(str,per,len,last,index+1);
	}
}
void permute1(char str[],char per[],int len,int last,int index)
{   
	int i;
	
	for(i=0;i<len;i++)
	{
		
		
		per[index]=str[i];
		if(index==last)
		{ 
		per[last+1]='\0';
		for(int k=0;k<=last;k++)
		{
			for(int j=0;j<=last;j++)
			{
			
			if(per[k]==per[j] && k!=j)
			{
			
			return;
		   }
	}
		}
		cout<<per<<"\n\n";
	}
		else
		permute1(str,per,len,last,index+1);
	}
}
int main()
{
	
	int n,len;
	cin>>n;
	cout<<"\nEnter the number of special symbols: ";
	cin>>len;
	char *str=(char *)malloc(len*sizeof(char));
	cin>>str;
	
	
	char *per=(char *)malloc((n+1)*sizeof(char));
	permute1(str,per,len,n-1,0);
	getch();
}
