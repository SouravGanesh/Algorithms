#include<iostream>
using namespace std;
int c[10][10],ne,visit[10]={0};
int main()
{
    int i,j,n,mini,minicost=0,a,b,u,v;
    cout<<"enter no of vertex";
    cin>>n;
    cout<<"enter thee weighed graph";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>c[i][j];
            if(c[i][j]==0)
            {
                c[i][j]=9999;
            }
        }
    }
    visit[0]=1;
    while(ne<n-1)
    {
        for(i=0,mini=9999;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(c[i][j]<mini && visit[i]!=0)
                {
                    mini=c[i][j];
                    a=u=i;
                    b=v=j;

                }
            }
        }
                if(visit[u]==0 ||  visit[v]==0)
                {
                    cout<<"\nedge"<<ne++<<":("<<a<<"-->"<<b<<")"<<"cost:"<<mini<<endl;
                    minicost+=mini;
                    visit[b]=1;
                }
    c[a][b]=c[b][a]=9999;
    }
    cout<<minicost;
    return 0;
}
