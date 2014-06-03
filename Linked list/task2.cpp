#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Node{
	char name[20];
	int age;
	char occ[20];
	char loc[20];
	char gender;
	Node *next;
	public:
	  Node(){next=NULL;
	  }
		void setData(char *Name,int Age,char *Occ, char *Loc, char Gender){
		
		 strcpy(name,Name);
		 age=Age;
		 strcpy(occ,Occ);
		 strcpy(loc,Loc);
		 gender=Gender;
		}
		void setNext(Node *anext){
		next=anext;
		}
		char *retName(){return name;
		}
		
		int retage(){return age;
		}
		char *retloc(){return loc;
		}
		char *retocc(){return occ;
		}
		char retgen(){return gender;}
		
		
		Node *Next(){return next;
		}
		
		
};

	





//print the contents of the list
void print(Node *head)
{
	Node *tmp=head; 
	int i=1;
	if(tmp==NULL)
	{
		cout<<"\n\tEMPTY"<<endl;
		return;
	}
   else{
   	do{
   	   cout<<"\n\t"<<i<<". Name: ";
   	   puts(tmp->retName());
   	   cout<<"\n\t   Age: "<<tmp->retage();
   	   cout<<"\n\n\t   Occupation: ";
   	   puts(tmp->retocc());
   	   cout<<"\n\t   Location: ";
   	   puts(tmp->retloc());
   	   cout<<"\n\t   Gender: ";
   	   if(tmp->retgen()=='m')
   	   cout<<"Male";
   	   else
   	   cout<<"Female";
   	   
   		cout<<"\n\n";
   		i++;
   		tmp=tmp->Next();
   		
   	}while(tmp!=NULL);
   	
   }
}
//append a node to a linked list
void add_user(Node **head)
{
   char n[20],l[20],occ[20],g;
   int a;
    cout<<"\n\t*******  ADDING USER  **********";
    
	cout<<"\n\n\tName: ";
	fflush(stdin);
	gets(n);                        //tried gets() and getline() but they didnt work
	cout<<"\n\tAge: ";
	cin>>a;
	cout<<"\n\tOccupation: ";
	fflush(stdin);
	cin.getline(occ,20);
	cout<<"\n\tLocation: ";
	fflush(stdin);
	cin.getline(l,20);
	cout<<"\n\tGender(M/F): ";
	cin>>g;
	while(!(g=='m' || g=='f' || g=='M' ||g=='F'))
	{
	cout<<"Invalid gender!!Enter again";
	cin>>g;
	}
	
	
	Node *newNode=new Node();
	newNode->setData(n,a,occ,l,g);
	newNode->setNext(NULL);
	Node *tmp=*head;
	if((tmp)==NULL)
	{
		*head=newNode;
		
	}
	else
	{
		while(((tmp)->Next())!=NULL)
		{
			tmp=(tmp)->Next();
		}
		(tmp)->setNext(newNode);
	cout<<"\n\tUser added succesfully!!";	
}
cout<<"\n\tUser added succesfully!!\n";

}
void assign(Node *temp1,Node *temp2) //To copy data from one node to another
{
 
 
 (temp1)->setData((temp2)->retName(),(temp2)->retage(),(temp2)->retocc(),(temp2)->retloc(),(temp2)->retgen());

}
void sort_users(Node *head)
{
 
 
 Node *temp=new Node(); 
	Node *tmp=head;
	if(tmp==NULL)
	{
		cout<<"\n\tEMPTY"<<endl;
		return;
	}
   else{
   int counter=0;
   while(tmp)
   {
   tmp=tmp->Next();
   counter++;
   }
   tmp=head;
   for(int j=0;j<counter;j++)
   {
      while(tmp->Next())
      {
      	Node *temp1=tmp->Next();
      	char *s1=tmp->retName();
      	char *s2=temp1->retName();
         if(strcmp(s1,s2)>0)
         {
         	
         assign(temp,tmp);
         assign(tmp,temp1);
         assign(temp1,temp);
         tmp=tmp->Next();
         }
         else
         {
         
         tmp=tmp->Next();}
      }
      tmp=head;
   }
   
   
   }
   
}


void del_user(Node *ptr){

    
	
	Node *temp  = ptr->Next();
    assign(ptr,temp);
    ptr->setNext(temp->Next());
    free(temp);
    cout<<"\n\n\tThe list after deletion is: \n";
    
	
}

void del_ptr(Node *head)
{
	if(!head){
	cout<<"\n\n\tThe list is empty!!";
	return;
}
	char n[20],l[20],occ[20],g;
   int a;
cout<<"\n\tEnter the details of the user to be deleted:\n ";
	cout<<"\n\tName: ";
	cin>>n;
	cout<<"\n\n\tAge: ";
	cin>>a;
	cout<<"\n\n\tOccupation: ";
	cin>>occ;
	cout<<"\n\n\tLocation: ";
	cin>>l;
	cout<<"\n\n\tGender(M/F): ";
	cin>>g;
	while(!(g=='m' || g=='f' || g=='M' ||g=='F'))
	{
	cout<<"\n\n\tInvalid gender!!Enter again: ";
	cin>>g;
	}
	Node *tmp=head;
	int flag=0;
	Node *ptr=new Node();
	while(tmp)
	{
		if((strcmp(tmp->retName(),n)==0)&&(strcmp(tmp->retloc(),l)==0)&&(strcmp(tmp->retocc(),occ)==0)&&(tmp->retage()==a)&&(tmp->retgen()==g))
		{
		flag=1;
	    ptr=tmp;
		break;}
	    tmp=tmp->Next();
	}
	if(ptr->Next()==NULL)
	{
		tmp=head;
		Node *del;
		while(tmp)
		{
			if(tmp->Next()==ptr)
			del=tmp;
			tmp=tmp->Next();
			
		}
		del->setNext(NULL);
		free(ptr);
		return;
	}
	if(flag)
	del_user(ptr);
	else
	{
		cout<<"\n\n\tThe entered user was not found!!";
		return;
	}
	
	
}
void sort(int *a,int n) //To sort an integer array..used to array of ages so as to find median age
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-i-2;j>=0;j--)
		{
			if(*(a+j)>(*(a+j+1)))
			{
				int temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
			}
		}
	}
}
void median_age(Node *head)
{
		Node *tmp=head;
	if(tmp==NULL)
	{
		cout<<"\n\n\tThe list is empty!!"<<endl;
		return;
	}
   else{
   int counter=0;
   while(tmp)
   {
   	counter++;
   tmp=tmp->Next();
   
   }
   
   tmp=head;
   int *a=(int *)malloc(counter*sizeof(int));
   int i=0;
   while(tmp)
   {
   	*(a+i)=tmp->retage();
   	i++;
   	tmp=tmp->Next();
   }
   sort(a,counter);
   if(counter%2!=0)
   cout<<"\n\n\tThe median age is "<<*(a+(counter-1)/2)<<"\n";
   else
   {
   	float median= ((*(a+(counter)/2))+(*(a+(counter-2)/2)))/2.0;
   	cout<<"\n\n\tThe median age is "<<median<<"\n";
   }
	
}
}
void average_age(Node *head)
{
	Node *tmp=head;
	float avg,sum=0;
	int counter=0;
	if(tmp==NULL)
	{
		cout<<"\n\n\tThe list is empty!!";
		return;
	}
	while(tmp)
	{
		sum+=tmp->retage();
		counter++;
		tmp=tmp->Next();
	} 
	avg=sum/counter;
	cout<<"\n\n\tThe average age is "<<avg;
	
}
void max_occupation(Node *head)
{
	Node *tmp=head;
	Node *temp=head;
	if(tmp==NULL)
	{
		cout<<"\n\n\tThe list is empty!!";
		return;
	}
	
	int max=1,counter=0;
	while(tmp)
	{
		
		counter++;
		tmp=tmp->Next();
		
	} 
	tmp=head;
    int i=0;
    char *s[20];
    int a[counter];
    for(int j=0;j<counter;j++)
    a[j]=0;                  //array a and s ar used to ensure that if two occupations are present equal number of times ,both will be printed
    	
    	while(tmp)
    	{ *(s+i)=tmp->retocc();
    		while(temp)
    		{
    			if(strcmpi(*(s+i),temp->retocc())==0)
    			++a[i];
    			temp=temp->Next();
    		}
    		temp=head;
    		if(a[i]>max)
    		{
    		max=a[i];
    		
    	    }
    	    i++;
    		tmp=tmp->Next();
    		
    	}
    	cout<<"\n\n\tOccupation that most users have :";
    	for(int i=0;i<counter;i++)
    	{
    	int flag=1;	
		if(a[i]==max)
		{
			
			for(int j=0;j<i;j++)    //this loop is to make sure a occupation is printed ony one time
			{if(strcmp(*(s+i),*(s+j))==0)
			{
			
			 flag=0;break;
			 }
			 }
			if(flag){
			
	    	cout<<" "<<*(s+i);
	    	cout<<"\n\t";}
        }
}
}

void max_location(Node *head) //Same logic as max_occupation
{
	Node *tmp=head;
	Node *temp=head;
	if(tmp==NULL)
	{
		cout<<"\n\n\tThe list is empty!!";
		return;
	}
	
	int max=1,counter=0;
	while(tmp)
	{
		
		counter++;
		tmp=tmp->Next();
		
	} 
	tmp=head;
    int i=0;
    char *s[20];
    int a[counter];
    for(int j=0;j<counter;j++)
    a[j]=0;
    	
    	while(tmp)
    	{ *(s+i)=tmp->retloc();
    		while(temp)
    		{
    			if(strcmpi(*(s+i),temp->retloc())==0)
    			++a[i];
    			temp=temp->Next();
    		}
    		temp=head;
    		if(a[i]>max)
    		{
    		max=a[i];
    		
    	    }
    	    i++;
    		tmp=tmp->Next();
    		
    	}
    	cout<<"\n\n\tPlace where most users live: ";
    	for(int i=0;i<counter;i++)
    	{
    	int flag=1;	
		if(a[i]==max)
		{
			
			for(int j=0;j<i;j++)         //this loop is to make sure a location is printed ony one time
			{if(strcmp(*(s+i),*(s+j))==0){
			
			 flag=0;break;}
			 }
			if(flag)
			{
	    	cout<<"\n\n\t"<<*(s+i);
	    	
	       }
        }
}
}
void suggest_friends(Node *head, char *s)
{
	Node *tmp=head;
	Node *ptr;
	int flag=0;
	while(tmp)
	{
		if(strcmpi(tmp->retName(),s)==0){
		
		ptr=tmp;
		flag=1;
		break;
	   }
	   tmp=tmp->Next();
	}
	if(!flag){
	cout<<"\n\n\tUser not found!!"; return;
    }
    cout<<"\n\n\tSuggested Friends:";
    tmp=head;
    while(tmp)
    { if(tmp!=ptr)
       {
    
    	if((strcmp(tmp->retloc(),ptr->retloc())==0 || strcmp(tmp->retocc(),ptr->retocc())==0) && abs(tmp->retage()-ptr->retage())<=15)
    	cout<<"\n\n\t"<<tmp->retName();
      }
    	tmp=tmp->Next();
    }
    
}
void reverse(Node **head)
{
    if(*head==NULL)
	return;
    Node **prev,**current,**next;
    Node *tmp=((*head)->Next());
    next=&tmp;
    Node *temp=new Node();
    prev=&(temp);
    current=head;
    *prev =NULL;
  while(*current!=NULL)
  {
 	*next=(*current)->Next();
 	(*current)->setNext(*prev);
 	(*prev)=(*current);
 	(*current)=(*next);
  }
 *head=*prev;
cout<<"\n\n";
cout<<"\n\tThe list after reversing is: \n";
 print(*head);
}
void segregate_age(Node *head)
{
	Node *tmp=head;
	Node *temp=new Node();
	while(tmp)
	{
		if((tmp->retage())%2==0 && tmp->Next())
		{ 
		  temp=tmp->Next();
		  while(temp)
		  {
		  	if((temp->retage())%2!=0)
		  	{
		  		Node *swap=new Node();
		  		assign(swap,temp);
		  		assign(temp,tmp);
		  		assign(tmp,swap);
		  		break;
		  	}
		  	temp=temp->Next();
		  }
			
		}
	  tmp=tmp->Next();	
	}
  cout<<"\n\tThe list after segregation is :\n";	
}	


Node *head=NULL;	
int main()
{ 

int choice;
char c;
do{
cout<<"\n\t*****************   MENU   *******************"
    <<"\n\n\t1. Add a user\n\n"
    <<"\t2. Sort users based on their names\n\n"
    <<"\t3. Delete a user\n\n"
    <<"\t4. Find the median age of the users\n\n"
    <<"\t5. Find the average age of the users\n\n"
    
    <<"\t6. Find the occupation of most users\n\n"
    <<"\t7. Find the location where most users live\n\n"
    <<"\t8. Suggest friends to a particular user\n\n"
    <<"\t9. Reverse the list\n\n"
    <<"\t10. Segregate users based on their age\n\n"
    <<"\n\n\tEnter your choice: ";
cin>>choice;
switch(choice)
{
	case 1: system("cls");
	       add_user(&head);
	       cout<<"\n\n\tThe list after addition is:\n";
	       print(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	case 2: system("cls");
	       sort_users(head);
	       cout<<"\n\n\tThe list after sorting users based on names is:\n";
	       print(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	case 3: system("cls");
	       del_ptr(head);
	       print(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
    case 4: system("cls");
	       median_age(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	case 5: system("cls");
	      average_age(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	
	case 6: system("cls");
	       max_occupation(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
    case 7: system("cls");
	       max_location(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	case 8: system("cls");
	        char s[20];
	        cout<<"\n\n\tEnter the user's name to suggest friends to: ";
	        cin>>s;
	       suggest_friends(head,s);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
    case 9: system("cls");
	       reverse(&head);
	       
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
	case 10: system("cls");
	       segregate_age(head);
	       print(head);
	       cout<<"\nDo you want to go back to the main menu(Y/N)? ";
	       cin>>c;
	       break;
   default:cout<<"\n\n\tInvalid choice!!";
           	   		   	   		   	   	   	   		   	          
}    

}while(c=='y'||c=='Y');


return 0;
getch();
	
}
