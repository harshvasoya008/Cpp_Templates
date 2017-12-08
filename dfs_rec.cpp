void dfs(int u){
	vis[u]=true;
	
	for(int i=0;i<graph[u].size();i++){
		int z = graph[u][i];
		if(!vis[z])
			dfs(vis,z);
	}
}
