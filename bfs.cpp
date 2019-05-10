#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	cout<<"Enter number of nodes : ";
	int n; cin>>n;
	int a[n][n];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	}
	cout<<"Enter starting node : (0-N-1) : ";
	int s;
	cin>>s;
	int os = s;
	int visited[n];
	memset(visited,0,n*sizeof(int));
	int q[n];
	int front = -1;
	int rear = 0 ;
	int count = 0 ;
	visited[s] = 1;
	count++;
	while(count!=n)
	{
		cout<<s;
		for(int i=0; i<n; i++)
			if(!visited[i]&&a[s][i])
			{
				q[rear++] = i;
				visited[i] = 1;
				count++;
			}
		s = q[++front];
	}
	while(front!=rear)
		cout<<q[front++] ;
}
