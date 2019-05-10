#include<iostream>
using namespace std;
int c[10][10],ne=1,parent[10];

int finds(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}

int uni(int i,int j)
{
    while(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
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

    while(ne<n)
    {
        for(i=0,mini=9999;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(c[i][j]<mini)
                {
                    mini=c[i][j];
                    a=u=i;
                    b=v=j;

                }
            }
        }
            u=finds(u);
            v=finds(v);
            if(uni(u,v))
                {
                    cout<<"\nedge"<<ne++<<":("<<a<<"-->"<<b<<")"<<"cost:"<<mini<<endl;
                    minicost+=mini;

                }
    c[a][b]=c[b][a]=9999;
    }
    cout<<minicost;
    return 0;
}
