class Kruskal{
	/* MST with complexity O(ElogV) */

	class Edge{
		public:
		int u,v;			// end-vertices
		int w;				// weight
		
		bool operator < (const Edge &other) const {
			if(w!=other.w)
				return w < other.w;
			return u < other.u;
		}
	};
	
	vector<Edge> graph;
	int *parent;
	int *subsize;
	int V,E;
	
	public:
		void build(int _v, int _e){
			V=_v;
			E=_e;
			
			parent = new int[V+1];
			subsize = new int[V+1];
			for(int i=0;i<=V;i++)
				parent[i]=i, subsize[i]=1;
			
			for(int i=0;i<E;i++){
				Edge e;
				sii(e.u,e.v);
				si(e.w);
				
				graph.pb(e);
			}
			
			sort(all(graph));
		}
		
		int findroot(int x){
			while(parent[x]!=x){
				x = parent[x] = parent[parent[x]];		// grand-parent step method
			}
			return x;
		}
		
		void unite(int x,int y){
			int a = findroot(x);
			int b = findroot(y);
			
			if(subsize[a] < subsize[b]){		// set A added to set B
				parent[a] = parent[b];
				subsize[b] += subsize[a];
			}
			else{								// set B added to set A
				parent[b] = parent[a];
				subsize[a] += subsize[b];
			}
		}
		
		lli MST(){
			/* MST with complexity O(ElogV) */
			
			lli minCost=0;
			for(int i=0;i<E;i++){
				int u = graph[i].u;
				int v = graph[i].v;
				
				// Check if the selected edge is creating a cycle or not
		        if(findroot(u) != findroot(v))
		        {
		            minCost += graph[i].w;
		            unite(u, v);
		        }    
			}
			
			return minCost;
		}
};

