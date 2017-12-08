lli Prim(int start){
	/* MST with complexity O((V+E)logV) */
	
	typedef pair<int,int> T;

	lli minCost = 0;
	priority_queue<T, vector<T>, greater<T> > pq;
	bool vis[V+1];

	pq.push({0,start});
	while(!pq.empty()){

		//select the edge with min weight
		T p = pq.top(); pq.pop();
		int x = p.S;

		//checking for cycle
		if(vis[x])
			continue;

		vis[x]=true;
		minCost += p.F;

		for(int i=0;i<graph[x].size();i++){
			T z = graph[x][i];
			if(!vis[z.F])
				pq.push({z.S,z.F});
		}
	}

	return minCost;
}
