void dfs(int u){
	stack<int> st;
	st.push(u);
	vis[u]=true;

	while(!st.empty()){
		int x=st.top(); st.pop();
		
		for(int i=0;i<graph[x].size();i++){
			int z=graph[x][i];
			if(!vis[z]){
				vis[z]=true;
				st.push(z);
			}
		}
	}
}

