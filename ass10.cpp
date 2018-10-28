#include<iostream>
#include<stdlib.h>
#define INF 9999
#define MAX 100
using namespace std;

class graph
{
	int n,edges;
	int g[MAX][MAX];
	
      public:
      		graph()
      		{
      		}
      		void readg()
      		{
      			int i,j,e,weight;
      			cout<<"\nEnter Number of Nodes::";
      			cin>>n;
      			for(i=0;i<n;i++)
      			{
      				for(j=0;j<n;j++)
      				{
      					if(i==j)
      					{
      						g[i][j]=0;
      					}
      					else
      					{
      						g[i][j]=INF;
      					}
      				}
      			}
      			cout<<"Enter No of Edges::";
      			cin>>edges;
      			cout<<"Enter Source Destion Nodes and Wight::";
      			for(e=0;e<edges;e++)
      			{
      				cin>>i;
      				cin>>j;
      				cin>>weight;
      				g[i][j]=weight;
      				g[j][i]=weight;
      			}
      		}
      		void prims()
      		{
      			int pass,min,temp;
      			int sum=0;
      			int visited[MAX];
      			int l,m,k;
      			for(int i=0;i<n;i++)
      			{
      				visited[i]=0;
      			}
      			visited[0]=1;
      			for(pass=0;pass<n-1;pass++)
      			{
      			
      				min=999;
      				for(int i=0;i<n;i++)
      				{
      					temp=999;
      					if(visited[i]==1)
      					{
      						for(int j=0;j<n;j++)
      						{
      							if(g[i][j]<temp && visited[j]==0)
      							{
      								temp=g[i][j];
      								k=j;
      							}
      						}
      						
      					}
      					if(min>temp)
      					{
      						min=temp;
      						l=i;
      						m=k;
      					}
      				}
      			sum=sum+min;
      			visited[l]=1;
      			visited[m]=1;
      			cout<<"\nFrom"<<l<<"to"<<m<<"Weight::"<<min;
      			}
      		cout<<"\nMST Cost is::"<<sum;
      		}
};

int main()
{
	graph g1;
	g1.readg();
	g1.prims();
	return 0;
}

