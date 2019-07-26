
/*
1 -- apply only unicost graph
2 -- need 2 array visit[] , cost[]
3 -- use queue


step:
1 : push source node
2 : check queue is empty/not
3 : if not empty -> pop queue front -> visit adjacency node + push in queue
4 : update cost
*/



/**
1\
|  \
|    \
2      3
| \     |
|  \    |
|   4   |
|   /\  |
|  /  \ |
5 /    \6

node edge
6 7
1 2
1 3
2 4
2 5
4 5
4 6
3 6
1 6
cost: 2
path: 1 3 6
------------xx-----------------

1-----3
     /|
    / |
   /  |
 2/   |
|\    |
| \   |
|  \  |
4   \ 5-----6

6 6
1 3
3 2
3 5
2 4
2 5
5 6
**/

/// 1 source to 1 node distance + path
#include<bits/stdc++.h>
using namespace std;

int graph[100][100],visited[100],cost[100];
int path[100];

struct node
{
    int u,w;
};

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin >>u>>v;
        graph[u][v]=graph[v][u]=1;
    }
    int s,d;
    cin>>s>>d;
    for(int i=1;i<=100;i++) path[i] = -1;
    queue<node>Q;
    Q.push({s,0});
    visited[s]=1;
    cost[s]=0;
    while(Q.size()!=0)
    {
        int u=Q.front().u, w = Q.front().w;
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[u][i]==1 && visited[i]==0)
            {
                Q.push({i,w+1});
                visited[i] = 1;
                cost[i] = w+1;
                path[i] = u;
            }
        }
    }
    cout << "distance : " << cost[d] << endl;
    int ans[100],c=0;

    // j = distance -> d not = -1 cz array initialize by -1
    //j = path[j] go to index no j = path[distance]
    /*      1 2 3 4 5 6
    path = -1 1 1 2 2 3
    start j = 6 -> j !=-1 then j = 3(cz element of index 6 is 3)
    */
    for(int j = d;j!=-1;j=path[j]) // d=6
    {
        cout << j << endl;
        ans[c++] = j; // insert index number of array like 6 3 1
    }
    cout << "path : ";
    for(int i=c-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
}



-----------------------xxx----------------------
/// 1 source to all node distance + path

#include<bits/stdc++.h>
using namespace std;

int graph[100][100],color[100],dist[100];
int path[100];

struct node
{
    int u,w;
};

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin >>u>>v;
        graph[u][v]=graph[v][u]=1;
    }
    int s,d;
    cin>>s;
    for(int i=1;i<=100;i++) path[i] = -1;
    queue<node>Q;


    for(int i=1;i<=n;i++){
            d = i;
    Q.push({s,0});
    color[s]=1;
    dist[s]=0;
    while(Q.size()!=0)
    {
        int u=Q.front().u, w = Q.front().w;
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[u][i]==1 && color[i]==0)
            {
                Q.push({i,w+1});
                color[i] = 1;
                dist[i] = w+1;
                path[i] = u;
            }
        }
    }
      cout <<"source : "<< s << "  destination : "<< d <<  "  distance : " << dist[d]<<endl;
    int ans[100],c=0;
    for(int j = d;j!=-1;j=path[j])
    {
        ans[c++] = j;
    }
    cout << "path : ";
    for(int i=c-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    }
}
/*6 7
1 2
1 3
2 4
2 5
4 5
 6 4
3 6

1 6
*/
-----------xx-------------
/// char input

#include<bits/stdc++.h>
using namespace std;

char graph[100] [100], color[100];
char path[100];
int dist[100];

struct  node
{
    char u;
    int w;
};

int main()

{
    //freopen("input.txt","r",stdin);
    int n,m;
    char s,d;
    cin>>n>>m;
    //cin>>s>>d;
    for(int i=1;i<=m;i++)
    {
        char u,v;
        cin >> u>>v;
        graph[u][v]=graph[v][u]='1';
    }
    //int s,d;
    cin>> s>>d;
    queue<node>Q;
    for(char i='a';i<='z';i++) path[i]='1';
    Q.push({s,0});
        color[s]='1';
    while(Q.size()!=0)
    {
        char u=Q.front().u;
        int w=Q.front().w;
        Q.pop();
        for(int i='a';i<='z';i++)
        {
            if(graph[u][i]=='1'&&color[i]!='1')
            {
                Q.push({i,w+1});
                color[i]='1';
                dist[i]=w+1;
                path[i] = u;

            }
        }
    }
    cout<< dist[d]<<endl;

     /*stack<char> Stack;
    Stack.push(d);
    while(1)
    {
        Stack.push(parent[d]);
        d = parent[d];
        if(d==s) break;
    }

    while(!Stack.empty())
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }*/


    char  ans[100];
    int c=0;
    for(char j = d;j!='1';j=path[j])
    {
        ans[c++] = j;
    }
    cout << "path : ";
    for(int i=c-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
6 7
a c
a b
b e
b d
c f
d e
d f

a f
*/

/// cycle detect if directed
#include<bits/stdc++.h>
using namespace std;

int graph[100] [100], color[100],dist[100],path[100];
struct  node
{
    int u,w;
};

int main()

{
    //freopen("input.txt","r",stdin);
    int n,m;
    int s,d;
    cin>>n>>m;
    //cin>>s>>d;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u>>v;
        graph[u][v]=1;
    }
    //int s,d;
    cin>> s>>d;
    queue<node>Q;
    for(int i=1;i<=100;i++) path[i] = -1;
    Q.push({s,0});
        color[s]=1;
    while(Q.size()!=0)
    {
        int u=Q.front().u;
        int w=Q.front().w;
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(graph[u][i]==1&&color[i]==1)
            {
                cout<<"cycle "<<u<<"-"<<i<<endl;
            }

            if(graph[u][i]==1&&color[i]==0)
            {
                Q.push({i,w+1});
                color[i]=1;
                dist[i]=w+1;
                path[i] = u;

            }
        }
    }
    cout<< dist[d]<<endl;


    int ans[100],c=0;
    for(int j = d;j!=-1;j=path[j])
    {
        ans[c++] = j;
    }
    cout << "path : ";
    for(int i=c-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
/*6 7
1 2
1 3
2 4
2 5
4 5
 6 4
3 6

1 6
*/

