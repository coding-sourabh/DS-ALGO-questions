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

struct edge
{
public:
	int src;
	int dest;
	int weight;
};

bool compare(edge e1 , edge e2)
{
	return e1.weight < e2.weight;
}

int find_parent(int *parent , int v)
{
	if(parent[v] == v) return v;
	else
	return find_parent(parent , parent[v]);
}

void kruskals(edge *input , int V , int E)
{
	sort(input , input+E , compare);

	edge *output = new edge[V-1];
	int i=0,count=0;

    int *parent = new int[V];
    for(int i=0 ; i<V ; i++)
    	parent[i] = i;

	while(count != V-1)
	{
       edge cur_edge = input[i];

       int src_parent = find_parent(parent , cur_edge.src);
       int dest_parent = find_parent(parent ,cur_edge.dest);

       if(src_parent != dest_parent)
       {
       	  output[count++] = cur_edge;
       	  parent[src_parent] = dest_parent;
       }
       i++;
	}

	for(int i=0;i<V-1;i++)
	{
		if(output[i].src < output[i].dest)
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		else
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
	}

}

int main()
{
	c_s();
    
    int V,E;
    cin>>V>>E;
	edge *input = new edge[E];

	for(int i=0;i<E;i++)
    {
    	int x,y,z; cin>>x>>y>>z;
    	input[i].src = x;
    	input[i].dest = y;
    	input[i].weight = z;
    }
    
    kruskals(input , V , E);

}