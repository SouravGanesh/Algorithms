#include <iostream>
using namespace std;
int main()
{
    int i,j,a[10][10],frt=0,rear=0,n,indegree[10],queu[10],x;
;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;

    cout<<"enter the adjacency matrix"<<endl;
    for(i=0;i<n;i++)
        indegree[i]=0;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
          {

           cin>>a[i][j];
           if(a[i][j]==1)
           indegree[j]++;
          }
    }
    for(i=0;i<n;i++)
    { cout<<"in["<<i<<"]="<<indegree[i]<<endl;
        if(indegree[i]==0)
        { queu[rear++]=i;

        }
    }
    cout<<"topological sort:"<<endl;
     while(frt!=rear)
     { x=queu[frt++];
       cout<<x<<" ";
       for(j=0;j<n;j++)
       {
           if(a[x][j]==1)
           {
               a[x][j]=0;
               indegree[j]--;
               if(indegree[j]==0)
               {
                   queu[rear++]=j;
               }
           }
       }

     }

    return 0;
}
