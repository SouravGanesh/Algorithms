#include <iostream>
using namespace std;

int main()
{int cost[10][10],i,j,k,n;
 cout<<"Enter the number of nodes"<<endl;
 cin>>n;
 cout<<"Enter the cost matrix"<<endl;
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
        cin>>cost[i][j];
 }
 for(k=0;k<n;k++)
 {
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             cost[i][j]=min(cost[i][j] , (cost[i][k]+cost[k][j]));
         }
     }
 }
 cout<<"The least cost paths from one vertex to every other vertex is:"<<endl<<endl;
 for(i=0;i<n;i++)
 {
     for(j=0;j<n;j++)
        {
           if(i!=j)
            {
                cout<<i<<"--->"<<j<<"==="<<cost[i][j]<<endl;
            }
        }
 }

 return 0;
}


