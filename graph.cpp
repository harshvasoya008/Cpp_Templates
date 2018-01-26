class Graph{
	typedef int T;
	
	int V,E;
	vector<T> *graph;
	
	public:
	void build(int _v,int _e){
		V=_v;
		E=_e;
		graph = new vector<T>[V+1];
		for(int i=1;i<=E;i++){
			int a,b;
			sii(a,b);
			graph[a].pb(b);
			graph[b].pb(a);
		}
	}

	void dfs(int u){
		vis[u]=true;
		
		for(int i=0;i<graph[u].size();i++){
			int z = graph[u][i];
			if(!vis[z])
				dfs(vis,z);
		}
	}
};
