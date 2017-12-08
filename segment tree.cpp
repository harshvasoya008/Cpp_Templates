class SegTree{
	typedef map<char,int> stt;
	typedef string arr;
	
	int MAX;
	stt *tree;
	arr *A;
	
	public:
	
	void init(arr *_A,int n){
		tree = new stt[MAX];
		A=_A;
	}
	
	void build(int node,int start,int end)
	{
	    if(start == end)
	    {
	        // Leaf node will have a single element
	        tree[node][A[start]]++;
	    }
	    else
	    {
	        int mid = (start + end) / 2;
	        // Recurse on the left child
	        build(2*node, start, mid);
	        // Recurse on the right child
	        build(2*node+1, mid+1, end);
	        
	        // Internal node will have the sum of both of its children
			
			stt &left = tree[2*node];
			stt &right = tree[2*node+1];
			
			for(auto& it : left)
				tree[node][it.F] += it.S;
			for(auto& it : right)
				tree[node][it.F] += it.S;
		}
	} 
	
	void update(int node, int start, int end, int idx, int val)
	{
	    if(start == end)
	    {
	        // Leaf node
	        A[idx] += val;
	        tree[node] += val;
	    }
	    else
	    {
	        int mid = (start + end) / 2;
	        if(idx <= mid)
	        {
	            // If idx is in the left child, recurse on the left child
	            update(2*node, start, mid, idx, val);
	        }
	        else
	        {
	            // if idx is in the right child, recurse on the right child
	            update(2*node+1, mid+1, end, idx, val);
	        }
	        // Internal node will have the sum of both of its children
	        tree[node] = tree[2*node] + tree[2*node+1];
	    }
	}
		
	stt& query(int l, int r, int node,int start,int end)
	{
	    if(r < start or end < l)
	    {
	        // range represented by a node is completely outside the given range
	        stt M;
	        return M;
	    }
	    if(l <= start and end <= r)
	    {
	        // range represented by a node is completely inside the given range
	        return tree[node];
	    }
	    // range represented by a node is partially inside and partially outside the given range
	    int mid = (start + end) / 2;
	    stt &ans1 = query(l,r,2*node, start, mid);
	    stt &ans2 = query(l,r,2*node+1, mid+1, end);
	    
		stt ans;
	    for(auto& it : ans1)
			ans[it.F] += it.S;
		for(auto& it : ans2)
			ans[it.F] += it.S;
	    
	    return ans;
	}
};
