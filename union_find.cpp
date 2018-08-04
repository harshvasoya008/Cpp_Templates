class Union_Find{
	
	int *parent;
	int *subsize;

	public:
	void init(int n){
		parent = new int[n];
		subsize = new int[n];
		for(int i=0;i<n;i++)
			parent[i] = i, subsize[i] = 1;
	}

	int findroot(int x){
		while(parent[x]!=x){
			x = parent[x] = parent[parent[x]];		// grand-parent step method

			/* Equivalent to:
				parent[x] = parent[parent[x]];
				x = parent[x];

				--> Takes O(logn) steps to reach root
			*/
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
};
