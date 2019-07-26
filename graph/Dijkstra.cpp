
/*
8 14
0 1 4
0 7 8
1 2 8
1 7 11
2 8 2
8 6 6
7 8 7
7 6 1
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
0 8


*/

#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

const int MAX_SIZE = 1000;
const int INF = 1e9;

vector<int> graph[MAX_SIZE],cost[MAX_SIZE];
int dist[MAX_SIZE],node,edge;

bool visit[MAX_SIZE];

void initialize()
{
    for(int i=1;i<=node;i++)
    {
        visit[i] = 0;
        dist[i] = INF;
        graph[i].clear();
        cost[i].clear();
    }
}

void createGraph()
{
    cin >> node >> edge;
    initialize();
    int x,y,c;
    for(int i=0;i<edge;i++)
    {
        cin >> x>>y>>c;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x].push_back(c);
        cost[y].push_back(c);
    }
}
void dijkstra(int source)
{
    dist[source] = 0;
    while( 1 )
    {
        int current_node = -1;
        for( int i = 0 ; i <= node ; i++ )
        {
            if( visit[i] == 0 && ( current_node == -1 || dist[current_node] > dist[i]))
            {
                current_node = i;
            }
        }
        cout << "current node" << current_node << endl;
        if( current_node == -1 ) break;
        visit[current_node] = 1;
        int sz = graph[current_node].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current_node][i];
            if( visit[nxt] ) continue;
            int cc = cost[current_node][i];
            if( dist[nxt] > dist[current_node] + cc )
            {
                dist[nxt] = dist[current_node] + cc;
            }
        }
    }

    for( int i = 0 ; i <= node ; i++ )
    {
        printf("from %d to %d:: minimum cost:: %d\n", source , i , dist[i] );
    }
}
int main()
{
    createGraph();
    dijkstra(0);
    return 0;
}

/*
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int u , w ; // u is the road number and w is the total cost needed to reach u from source
};

class cmp{
    public :
    bool operator () (node &a,node &b){
        if(a.w>b.w) return true; else return false; // Sorted in ascending order according to cost
    }
};
vector <int> graph[100+10],cost[100+10];
int Dijkstra(int N,int s,int d){
    bool visited[100+10] ;
    for(int i=1;i<=100;i++) visited[i]=false;
    priority_queue <node,vector<node>,cmp> Q;
    node n;
    n.u=s;n.w=0;
    Q.push(n);
    while(Q.size()!=0)
    {
        n = Q.top();
        Q.pop();
        int u = n.u, w = n.w;
        if(visited[u]) continue;
        visited[u] = true;
        if(u==d) return w;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(visited[v]== false){
                n.u = v;
                n.w = w+cost[u][i];
                Q.push(n);
            }
    }

    }
    return -1;
}
int main(){
    int node,edge;
    scanf("%d%d",&node,&edge);

    while(edge--){
        int u , v , w; // from node u to v is cost w
        scanf("%d%d%d",&u,&v,&w);
        graph[u].push_back(v);
        cost[u].push_back(w);

    }
    int source,dest;
    scanf("%d%d",&source,&dest);
    printf("%d\n",Dijkstra(node,source,dest));
    return 0;

}
*/
