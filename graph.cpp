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
};
