class SegTree{
	typedef int stt;
	typedef int arr;
	
	int MAX;
	stt *tree;
	arr *A;
	
	public:
	
	void init(arr *_A,int n){
		MAX = 4*n;
		tree = new stt[MAX];
		A=_A;
		build(1,0,n-1);
	}
	
	void build(int node, int start, int end) {
		if (start == end) {
			tree[node] = A[start];
		} else {
			int mid = (start + end) / 2;
			build(2 * node, start, mid);
			build(2 * node + 1, mid + 1, end);
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}

	void update(int node, int start, int end, int idx, long val) {
		if (start == end) {
			tree[node] += val;
			A[idx] += val;
		} else {
			int mid = (start + end) / 2;
			if (idx <= mid)
				update(2 * node, start, mid, idx, val);
			else
				update(2 * node + 1, mid + 1, end, idx, val);
			
			tree[node] = tree[2 * node] + tree[2 * node + 1];
		}
	}

	int query(int node, int start, int end, int l, int r) {
		if (r < start || end < l)
			return 0;
		
		if (l <= start && end <= r)
			return tree[node];
		
		int mid = (start + end) / 2;
		int p1 = query(2 * node, start, mid, l, r);
		int p2 = query(2 * node + 1, mid + 1, end, l, r);
		return (p1 + p2);
	}
};
