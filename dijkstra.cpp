void Dijkstra(int src,int n){
	
	/* Complexity: O(ElogV) */
	
	int dist[n+1];
	bool vis[n+1];
	int parent[n+1];
	
	forn(i,0,n+1)
		dist[i]=INF, vis[i]=false, parent=-1;
	
	/*private class comp{
		public:
		bool operator() (const int &lhs, const int &rhs)const{
			return dist[lhs] > dist[rhs];
		}
	};*/
	
	typedef pair<int,int> T;
	priority_queue<T, vector<T>, greater<T>> pq;
	
	dist[src]=0;
	pq.push({0,src});
	
	while(!pq.empty()){
		int u = pq.top().S; pq.pop();
		if(vis[u])
			continue;
		
		vis[u]=true;
				
		for(pair<int,int> p : graph[u]){
			int v = p.F;
			int w = p.S;
			
			if(!vis[v] && dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				pq.push({dist[v],v});
				// parent[v] = u;			// To store the shortest path 
			}
		}
	}
	
	for(int i=0;i<n+1;i++)
		printf("%d: %d\n",i,dist[i]);
}
