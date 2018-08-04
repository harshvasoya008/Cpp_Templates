void bfs(int u){
	queue<int> q;
	hashmap<int,bool> vis;
	
	q.push(u);
	vis[u]=true;
	
	while(!q.empty()){
		int x=q.front(); q.pop();
		
		for(int i=0;i<graph[x].size();i++){
			int z=graph[x][i];
			if(!vis[z]){
				vis[z]=true;
				q.push(z);
			}
		}
	}
}
