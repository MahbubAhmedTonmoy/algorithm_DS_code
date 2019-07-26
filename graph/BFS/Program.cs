using System;

namespace BFS
{
     class Program
    {
        
        public  struct  node{
            public int u,w;
        }
   
	public static void Main()
	{
        int [,] Graph = new int[1000,1000];
        int []visited = new int[100];
        int []cost = new int [1000];
        int []path = new int[100];
        
        Console.WriteLine("input node and edge");

        string mm,nn;
        int n,m;
        nn = Console.ReadLine();
        Int32.TryParse(nn, out n);
        mm = Console.ReadLine();
        Int32.TryParse(mm, out m);
		for(int i=0;i<m;i++)
		{
           
                string uu,vv;
                int u,v;
                uu = Console.ReadLine();
                
                Int32.TryParse(uu, out u);
                vv = Console.ReadLine();
                
                Int32.TryParse(vv, out v);
                Graph[u,v] = Graph[v,u] = 1;
        
		}
        string ss,dd;int s,d;
        ss = Console.ReadLine();
		Int32.TryParse(ss, out s);
        dd = Console.ReadLine();
		
        Int32.TryParse(dd, out d);
		for(int i=1;i<=100;i++) {
			path[i] = -1;
		}
		System.Collections.Generic.Queue<node> Q = new System.Collections.Generic.Queue<node>();
		
		node Node = new node{u=s , w=0};
		Q.Enqueue(Node);
		visited[s] = 1;
		cost[s] = 0;
		while(Q.Count !=0){
			
        int u=Q.Peek().u, w = Q.Peek().w;
        Q.Dequeue();
        for(int i=1;i<=n;i++)
        {
            if(Graph[u,i]==1 && visited[i]==0)
            {
				node N = new node{u=i , w=w+1};
		        Q.Enqueue(N);
                visited[i] = 1;
                cost[i] = w+1;
                path[i] = u;
            }
        }
		}
		Console.WriteLine("distance : "+ cost[d]);
		 
		
    int[] ans= new int [100];
		int c = 0;
    for(int j = d;j!=-1;j=path[j])
    {
        ans[c++] = j;
    }
    Console.WriteLine( "path : ");
    for(int i=c-1;i>=0;i--)
    {
         Console.WriteLine( "path : ");
    }
		
		
	}
    }
}
