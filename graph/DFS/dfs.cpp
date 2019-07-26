/**enter node and connected edge
6 7
enter connected edge
1 2
1 3
2 4
2 5
3 5
5 6
4 6
enter source and destination path
1 5**/
#include<bits/stdc++.h>
using namespace std;
int graph[100][100],visited[100];
int path[100];



int main()
{

    int node,edge;
   cout<< "enter node and connected edge" << endl;
   cin>>node>>edge;
   cout << "enter connected edge" <<endl;
    while(edge--)
    {
        int u,v; /// 1------2
        cin >>u>>v;
        graph[u][v]=graph[v][u]=1; /// 1-----2 cost 1 and 2------1 cost 1
    }
int source,destination;
    cout << "enter source and destination path" << endl;
    cin>>source>>destination;
    for(int i=1;i<=100;i++) path[i] = -1;
    stack<int>S;
    S.push(source);
    visited[source]=1;
    while(!S.empty())
    {
        int u=S.top();
        S.pop();
        for(int i=1;i<=node;i++)
        {///graph[u][i]==1 means 2 node have a connection and not visited
            if( graph[u][i]==1 &&visited[i]==0)
            {
                S.push(i);
                visited[i] = 1;
                path[i] = u;
            }
        }
    }
    int ans[100],c=0;
    /// j = distance -> d not = -1 cz array initialize by -1
    ///j = path[j] go to index no j = path[distance]
/** index   1 2 3 4 5 6[create an array name path]
    path = -1 1 1 2 2 4 **/
    for(int j = destination;j!=-1;j=path[j]) // d=6
    {
        //cout << path[j] << " ";
        ans[c++] = j; /// insert index number in ans
    }
    cout << "bfs path : ";
    for(int i=c-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
}
