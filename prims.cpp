#include<bits/stdc++.h>
using namespace std;

void c_s()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	   freopen("input2.txt","r",stdin);
	   freopen("output2.txt","w",stdout);
	#endif
}


int pickMinWeightVertex(int *weight , bool *visited , int V )
{
	int mini=INT_MAX,ind;
	for(int i=0;i<V;i++) 
		if(!visited[i] && weight[i] < mini)
		{
			mini = weight[i];
			ind  = i;
		}
		return ind;
}

void prims(int **edges , int V , int E)
{
	bool *visited = new bool[V];
    int  *parent = new int[V];
    int *weight = new int[V];

    for(int i=0;i<V;i++)
    {
    	visited[i] = false;
    	parent[i] = -1;
    	weight[i] = INT_MAX;
    }
    weight[0] = 0;

    for(int i=0;i<V-1;i++)
    {
       int u = pickMinWeightVertex(weight , visited ,  V);
       visited[u] = true;

       for(int j=0;j<V;j++)
       {
       	 if( !visited[j] && edges[u][j] != INT_MAX)
       	 {
       	 	if( weight[u] + edges[u][j] < weight[j] )
       	 	{
       	 		weight[j] = edges[u][j];
       	 		parent[j] = u;
       	 	}
       	 }
       }
    }
    
    for(int i=1;i<V;i++)
    	if(parent[i] < weight[i])
    	cout<<parent[i]<<"->"<<i<<" "<<weight[i]<<endl;
        else
        cout<<i<<"->"<<parent[i]<<" "<<weight[i]<<endl;

}

int main()
{
	c_s();
    
    int V,E;
    cin>>V>>E;
	
	int **edges = new int*[V];
    
    for(int i=0;i<V;i++)
    {
    	edges[i] = new int[V];
    	for(int j=0;j<V;j++)
    		edges[i][j] = INT_MAX;
    }

	for(int i=0;i<E;i++)
    {
    	int x,y,z; cin>>x>>y>>z;
    	edges[x][y] = z;
    	edges[y][x] = z;
    }

    prims(edges , V , E);
    
    for(int i=0;i<V;i++)
    	delete [] edges[i];
    delete [] edges;
}