#include<iostream>
using namespace std;
int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
    for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
return K[n][W];
}

int main()
{
    int i, n, val[20], wt[20], W;
    cout<<"Enter number of items:";
    cin>>n;
    cout<<"Enter value and weight of items:\n";
    for(i = 0;i < n; ++i){
    	cin>>val[i];
    	cin>>wt[i];
    }
    cout<<"Enter size of knapsack:";
    cin>>W;
    cout<<knapSack(W, wt, val, n);
    return 0;
}
