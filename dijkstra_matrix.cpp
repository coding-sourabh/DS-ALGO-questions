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

int minVertex(int dist[] , bool visited[] , int V)
{
	int minIndex = -1,min_distance = INT_MAX;

	for(int i=0;i<V;i++)
		if(!visited[i] && (minIndex == -1 || dist[i] < min_distance) ){
			minIndex = i;
			min_distance = dist[i];
		}
	return minIndex;
}

void dijkstra(int **g , int V , int s)
{
	bool visited[V] = {false};
	int dist[V];
	for(int i=0;i<V;i++)  // initialize distance to infinity
		dist[i] = INT_MAX;
    
    dist[s] = 0; // initialize distance of source from source 0
  
    for(int i=0;i<V-1;i++) // V-1 becoz for last vertex all vertices will be already viseted
    {
    	int ind = minVertex(dist , visited , V);
    	visited[ind] = true; // mark min vertex as visited
        
        for(int j=0;j<V;j++)   //update all adjacent vertex distance if possible
        {
        	if(g[ind][j] > 0)  //means there is an edge
        	{
        		if( dist[ind] + g[ind][j] < dist[j]) // smallest path possible through i vertex to jth vertex
        		{
        			dist[j] =  dist[ind] + g[ind][j];
        		}
        	}
        }

    } 

    for(int i=0;i<V;i++)
    	cout<<s<<"->"<<i<<" = "<<dist[i]<<endl;
}

int main()
{
	c_s();
   
    int  V,E;
    // cin>>V>>E;
    cout<<"Enter number of vertices & edges\n"; cin>>V>>E;
    int** g = new int*[V];
    
    cout<<"Enter the weights for edges\n";
    
    for(int i=0;i<V;i++){
    	g[i] = new int[V];
    	for(int j=0;j<V;j++)
    		g[i][j] = 0;
    }
    
    
    int u,v,weight;
    for(int i=0;i<E;i++)
    {
       cin>>u>>v>>weight;
       g[u][v] = weight;
       g[v][u] = weight;
    } 
    
    dijkstra(g,V,0); // prints shortest path from source(here 0) to all other vertices.
    
    for(int i=0;i<V;i++)
    	delete [] g[i];
    delete [] g;

    cout<<"ho hoyy";
}

