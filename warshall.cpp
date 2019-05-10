#include <iostream>
using namespace std;

int main()
{int adj[10][10],i,j,k,n,flag=0;
 cout<<"Enter the number of nodes"<<endl;
 cin>>n;
 cout<<"Enter the adjacency matrix"<<endl;
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
        cin>>adj[i][j];
 }
 for(k=0;k<n;k++)
{
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             adj[i][j]=(adj[i][j] or (adj[i][k] and adj[k][j]));
         }
     }
 }
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
        {
            cout<<adj[i][j];

           //if(adj[i][j]!=1)
             //   flag=1;
        }
        cout<<endl;
 }
 /*if(flag==0)
    cout<<"There is a path from every node to every other node"<<endl;
 else
    cout<<"There is no path from every node to every other node"<<endl;
 */return 0;
}
