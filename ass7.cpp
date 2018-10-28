/*
Assignment No:: 7
Title :: Represent any real world graph using adjacency list /adjacency matrix find minimum spanning
		tree using Kruskal’s algorithm.
Name :: Sachin B. Aher
Roll No. :: 3174521		Class:: SE-B-IT		Batch:B3
*/
/*---CODE---*/
#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;
class kruskals
{
  struct node
  {
    int v1,v2;  
	int weight;  
  };
  
  struct node store[MAX],path[MAX];
  int parent[MAX];
  int pn,nv,ne;
  
  public:
     kruskals()
     {
       pn=0;
       for(int x=1;x<MAX;x++)
       {
          parent[x]=x;
       }
     }
     
     void create()
     {
       cout<<"\nEnter number of vertices:\t";
       cin>>nv;
       cout<<"\nEnter number of edges:\t";
       cin>>ne;
       cout<<"\nEnter all source and destination vertices with their weights\n";
        for(int i=0;i<ne;i++)
        {
           cin>>store[i].v1>>store[i].v2>>store[i].weight;
        }
      }
      
     void sort()
     {
        node temp;
	for(int i=0;i<ne-1;i++)
  	{
    	  for(int j=0;j<ne-i-1;j++)
	  {
	    if(store[j].weight>store[j+1].weight) 
	    {
	       temp=store[j];
	       store[j]=store[j+1];
	       store[j+1]=temp;
            }
	  }
  	}
     }
      
     void kAlgo()
     {
       sort();
       pn=0;
       int x=0;
       while(pn<nv-1)
       {
         int a=find(store[x].v1);  
         int b=find(store[x].v2);
         if(a!=b)
         {
           path[pn++]=store[x];
           unionC(a,b);
         }
         x++;
       }  
     }
     
     int find(int x)
     {
        if(parent[x]!=x)
        {
           parent[x]=find(parent[x]);
        }
        
        else
           return parent[x];
     }
     
     void unionC(int i,int j)
     {
        parent[j]=i;
     }
     
     void print()
     {
        int cost=0;
        cout<<"\nSpanning Tree\n";
        for(int i=0;i<nv-1;i++)
        {
          cout<<"\n"<<path[i].v1<<"\t"<<path[i].v2<<"\t"<<path[i].weight;
          cost=cost+path[i].weight;
        }
        
        cout<<"\nTotal Cost of minimum spanning tree is:\t"<<cost<<"\n";
     }
};

 int main()
{
  kruskals ks;
  ks.create();
  ks.kAlgo();
  ks.print();
}
/*---OUTPUT---*/
/*

*/    
       
