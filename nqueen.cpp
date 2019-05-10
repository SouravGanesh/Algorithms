#include <iostream>
#include<stdlib.h>
using namespace std;
int a[100];
int place(int pos)
{int i;
for(i=0;i<pos;i++)
{
    if(a[pos]==a[i] or (abs(a[pos]-a[i])==abs(pos-i)))
        return 0;
}
return 1;

}
void printval(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[j]==i)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
void placequeens(int n)
{
    int k=0,sol=1;
    a[k]=0;
    while(k!=-1)
    { while(a[k]<n and place(k)==0)
       {
           a[k]++;
       }
       if(a[k]<n)
       {
           if(k==n-1)
           {cout<<"solution"<<sol<<endl;
               sol++;
               printval(n);
               a[k]++;
           }
           else
           {
               k++;a[k]=0;
           }
       }
       else
       {
           k--;
           a[k]++;
       }
    }
}

int main()
{
    int n;
    cout<<"enter the number of queens"<<endl;
    cin>>n;
    if(n<=3)
        cout<<"cannot place "<<n<<" queens in "<<n<<"*"<<n<<" chess board"<<endl;
    else
        placequeens(n);
    return 0;
}
