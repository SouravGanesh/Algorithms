#include <iostream>
using namespace std;
int minimum(int dest[], int visit[], int n)
{
    int mini = 9999, i;
    for (i = 0; i < n; i++)
    {
        if (visit[i] == 0 && dest[i] < mini)
            mini = i;
    }
    return mini;
}
int main()
{
    int n, cost[10][10], p[10], dest[10], i, j, source, visit[10], u, var;
    cout << "enter  the number of vertices" << endl;
    cin >> n;
    cout << "enter the cost matrix" << endl;
    for (i = 0; i < n; i++)
    {
        visit[i] = 0;
        for (j = 0; j < n; j++)
            cin >> cost[i][j];

    }
    cout << "enter the  source vertex" << endl;
    cin >> source;
    visit[source] = 1;
    for (i = 0; i < n; i++)
    {
        p[i] = source;
        dest[i] = cost[source][i];
    }
    for (i = 0; i < n - 1; i++)
    {
        u = minimum(dest, visit, n);
        var = u;
        cout << dest[u] << "  ";
        while (var != source)
        {
            cout << var << "<--";
            var = p[var];
        }
        cout << source << endl;
        visit[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (visit[j] == 0 && dest[u] + cost[u][j] < dest[j])
            {
                dest[j] = dest[u] + cost[u][j];
                p[j] = u;
            }
        }
    }
    return 0;
}
