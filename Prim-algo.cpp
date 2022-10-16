#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 

typedef pair<int,int> pi;



void addEdge(vector<pi> adj[], int u, int v, int w){
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}


void primMST(vector<pi> adj[], int V){

	priority_queue<pi, vector<pi>, greater<pi>> minH;
	int src = 0;
	vector<bool> vis(V,false);
	vector<int> key(V,INF);
	vector<int> parent(V,-1);

	minH.push(make_pair(0,src));
	key[src]=0;

	while(!minH.empty()){

		int u = minH.top().second;
		minH.pop();

		vis[u]=true;

		for(auto e: adj[u]){
			int v = e.first;
			int w = e.second;
			if(!vis[v] && key[v] > w){

				key[v]=w;
				minH.push(make_pair(key[v],v));
				parent[v]=u;
			}
		}
	}

	for(int i=1;i<V;i++){
		cout<<parent[i]<<"-"<<i<<"\n";
	}
}


int main(){
	int V=7;
	vector<pi> adj[V];

    addEdge(adj, 3, 4, 9); 
	addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
  
    primMST(adj, V); 
  
    return 0; 
}
