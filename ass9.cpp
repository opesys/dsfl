#include<iostream>
#include<stdlib.h>
#include<string.h>
#define MAX 10
using namespace std;

struct hash
{
  int roll_no;
  unsigned int cont_no;
  char name[30];
  int chain;
}rec[MAX],h;

class HashTable
{
  public:
      HashTable()
      {
         for(int i=0;i<MAX;i++)
         {
            rec[i].roll_no=0;
            rec[i].cont_no=0;
            strcpy(rec[i].name,"-");
            rec[i].chain=-1;
         }
      }
      
     // void insert();                           
      int hashing(unsigned  int h);
      void display();
      void wo_replace(hash h);
      void w_replace(hash h);
};

/*void HashTable::insert()
{
    struct hash h1;
    int i,no;
    cout<<"\nEnter a student record\n";
    cout<<"\nEnter number of students:\t";
      cin>>no;
              for(i=0;i<no;i++)
               {
                cout<<"\nName:\t";
                  cin>>h1.name;
                cout<<"\nRoll_no:\t";
                  cin>>h1.roll_no;
                cout<<"\nContact_no:\t";
                  cin>>h1.cont_no;
               }  
}*/

int HashTable::hashing(unsigned int h)
{
    return(h % MAX);
}

void HashTable::wo_replace(hash h)
{
   int i,p,k;
   p=k=hashing(h.cont_no);
    if(rec[k].cont_no==0)
    {
       rec[k].cont_no=h.cont_no;
       strcpy(rec[k].name,h.name);
       rec[k].roll_no=h.roll_no;
    }
    else
    {
       i=(k+1)%MAX;
       do
       {
          if(hashing(rec[i].cont_no)==k)
          
            p=i;
          
          if(rec[i].cont_no==0)
          {
            rec[i].cont_no=h.cont_no;
            rec[i].roll_no=h.roll_no;
            strcpy(rec[i].name,h.name);
            
              if(hashing(rec[p].cont_no==k))
              {
                rec[p].chain=i;      
              }                          
             break;
          }
           i=(i+1)%MAX;
       }while(i!=k);
       if(i==k)
       {
           cout<<"\nHash table is full\n";
       }
     }
}

void HashTable::w_replace(hash h)
{

}

void HashTable::display()
{
   cout<<"\nIndex\tName\tContact_no\tChain\n";
   for(int i=0;i<MAX;i++)
   {
      cout<<"\n";
      cout<<i<<"\t"<<rec[i].name<<"\t"<<"\t"<<rec[i].cont_no<<"\t"<<rec[i].chain<<"\n";
   }
}

int main()
{
  HashTable ht;
  struct hash h;
  int choice,n;
  do
  {
    cout<<"\n............MENU..........\n";
    cout<<"\n1.With Replacement\n2.WithOut Replacement\n3.Display\n4.Exit\nEnter your choice:\n";
      cin>>choice;
      switch(choice)
      {
        case 1:cout<<"Enter number of records to be inserted(between 0 to 10):\t";
               cin>>n;
               for(int i=0;i<n;i++)
               {
                cout<<"\nEnter Roll_no:\t";
                cin>>h.roll_no;
	        cout<<"Enter name:";
	        cin>>h.name;
	        cout<<"Enter Contact No: ";
		cin>>h.cont_no;
	        ht.w_replace(h);
	       }
	        ht.display();
	        break;
              
               
        case 2:cout<<"Enter number of records to be inserted(between 0 to 10):\t";
               cin>>n;
               for(int i=0;i<n;i++)
               {
                cout<<"\nEnter Roll_no:\t";
                cin>>h.roll_no;
	        cout<<"Enter name:";
	        cin>>h.name;
	        cout<<"Enter Contact No: ";
	        cin>>h.cont_no;
	        ht.wo_replace(h);
	       }
	       ht.display();
	       break;
               
         case 3:ht.display();
                break;
                
         case 4:exit(0);
         
         default:cout<<"\n...........INVALID CHOICE...........\n";
      }
  }while(choice!=4);
}
