#include<iostream>
using namespace std;
int a[10][10],v[10],n;
void dfs(int source)
{
    cout<<source<<" ";
    v[source]=1;
    for(int i=0;i<n;i++)
    {

        if(a[source][i]==1 && v[i]!=1)
        {
            dfs(i);
        }
    }
}
int main()
{
    int s;
    cout<<"Enter the no. of nodes\n";
    cin>>n;
    cout<<"Enter the matrix\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         cin>>a[i][j];
    cout<<"Enter the source\n";
    cin>>s;
    cout<<"DFS: ";
    dfs(s);
}
