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


void dijkstra(vector<list<pair<int,int>>> graph , int V , int s)
{
   bool visited[V] = {false};  // Mark all visited false
   int dist[V];

   priority_queue< pair<int,int> , vector<pair<int,int>> , greater<> > pq; 
   //priority_queue to store min distance with the corresponding pair.It is a min heap
   
   for(int i=0;i<V;i++){
       dist[i] = INT_MAX;   // initialize all distance to infinity , if it is source then 0
       if(i == s) 
         dist[i] = 0;
       pq.push({dist[i],i});  // push all pairs into priority queue
   }
   
   for(int i=0;i<V-1;i++)   // Run through V-1 becoz for last node all adjacent vertex will be visited
   {
     pair<int,int> top = pq.top();  // get min dist with its key from pq
     pq.pop();
     int d = top.first;     // min distance       
     int ind = top.second;  // corresponding vertex to min distance
     visited[ind] = true;   // mark visited true

     for(auto j = graph[ind].begin() ; j != graph[ind].end() ; j++)  // traverse all adjacent node , 
                                                                    // note list contains pairs made of ajacent vertex and ite weight
     {
        // Below is Dijkstra's algo process
        int vertex = j->first;
        int weigh = j->second;

        if(!visited[vertex])
        {
            if( dist[ind] + weigh < dist[vertex])
                dist[vertex] = dist[ind] + weigh;
        }
     }
   }
    

    for(int i=0;i<V;i++)
        cout<<s<<"->"<<i<<" = "<<dist[i]<<endl;  // printing distance from source to other vertices

}

int main()
{
	c_s();
    
    int V,E;
    cin>>V>>E;

    vector< list< pair<int,int> > >graph(V);

    for(int i=0;i<E;i++)
    {
        int x,y,weight;
        cin>>x>>y>>weight;
        graph[x].push_back(make_pair(y,weight));
    }

    dijkstra(graph , V , 0);
}

