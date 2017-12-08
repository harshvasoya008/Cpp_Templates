void Dijkstra(int src,int n){
	
	/* Complexity: O(ElogV) */
	
	int dist[n+1];
	bool vis[n+1];
	
	forn(i,0,n+1)
		dist[i]=INF, vis[i]=false;
	
	private class comp{
		public:
		bool operator() (const int &lhs, const int &rhs)const{
			return dist[lhs] > dist[rhs];
		}
	};
	
	priority_queue<int,vector<int>,comp> pq;
	
	dist[src]=0;
	pq.push(src);
	
	while(!pq.empty()){
		int x = pq.top(); pq.pop();
		if(vis[x])
			continue;
		
		vis[x]=true;
				
		for(int i=0;i<graph[x].size();i++){
			int z = graph[x][i].F;
			int w = graph[x][i].S;
			
			if(!vis[z] && dist[x]+w < dist[z]){
				dist[z] = dist[x]+w;
				pq.push(z);
			}
		}
	}
	
	for(int i=0;i<n+1;i++)
		printf("%d: %d\n",i,dist[i]);
}
