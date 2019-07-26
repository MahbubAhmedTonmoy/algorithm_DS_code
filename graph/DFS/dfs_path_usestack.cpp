

///only use stack to find path
/// not use any path array

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
       stack<int>s;
    stack<int>ans;
    s.push(source);
    visited[source]=1;
cout<<endl;
    cout << "DFS path:";
    while(s.size()!=0 && s.top()!= destination)
    {
        int u=s.top();
        ans.push(u);
        s.pop();

        for(int i=1;i<=node;i++)
        {///graph[u][i]==1 meansans.push(u); 2 node have a connection and not visited
            if( graph[u][i]==1 &&visited[i]==0)
            {
                s.push(i);
                visited[i] = 1;

        }

    }

     while (!ans.empty())
    {
        cout << '\t' << ans.top();
        ans.pop();
    }
}
cout << '\t'<<destination << endl;
}
