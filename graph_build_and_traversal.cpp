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
class Graph
{
	int V;
	list<int> *adj;

	public : 
    
	Graph(int V); //constructor
	void dfsUtil(int s , bool visited[]); //helper function to for dfs

	void addEdge(int u , int v);
	void DFS(int s);   //for depth first search
	void BFS(int s);   //for breadth first search

};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u , int v)
{
	adj[u].push_back(v); //in case of undirected graph adj[v].push_back(u); would also be added
}

void Graph::dfsUtil(int s , bool visited[])
{
	cout<<s<<" ";
	visited[s]=true;
    list<int>::iterator it;
	for(it = adj[s].begin(); it != adj[s].end() ; it++)
	{
		if(!visited[*it]){
			dfsUtil(*it , visited);
		}
	}
}

void Graph::DFS(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
	dfsUtil(s , visited);
}

void Graph::BFS(int s)
{
	bool visited[V]={false};
	list<int>queue;
  
	queue.push_back(s);

	while(!queue.empty())
	{
		int top = queue.front();
		queue.pop_front();
		visited[top]=true;
        
        cout<<top<<" ";
        for(auto it = adj[top].begin() ; it != adj[top].end() ; it++)
        	if(!visited[*it])
        		queue.push_back(*it);
	}
}

int main()
{
	c_s();
	Graph g(4);
	 g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout<<"depth first traversal of a graph starting from 2nd node\n";
    g.DFS(2);

    cout<<"\ndepth first traversal of a graph starting from 2nd node\n";
    g.BFS(2);
    
}

