class SegTree{
	typedef int stt;
	typedef int arr;
	
	int MAX;
	stt *tree;
	int *lazy;
	arr *A;
	
	public:
	
	void init(arr *_A,int n){
		MAX = 4*n;
		tree = new stt[MAX];
		lazy = new int[MAX];
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
		lazy[node] = 0;
	}
	
	void updateRange(int node, int start, int end, int l, int r, int val) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node]; 
			if (start != end) {
				lazy[node * 2] += lazy[node];
				lazy[node * 2 + 1] += lazy[node];
			}
			lazy[node] = 0;
		}

		if (start > end || start > r || end < l) 
			return;
		
		if (start >= l && end <= r) {
			tree[node] += (end - start + 1) * val;
			if (start != end) {
				lazy[node * 2] += val;
				lazy[node * 2 + 1] += val;
			}
			return;
		}
		
		int mid = (start + end) / 2;
		updateRange(node*2, start, mid, l, r, val); 
		updateRange(node*2 + 1, mid + 1, end, l, r, val); 
		tree[node] = tree[node*2] + tree[node*2 + 1]; 
	}

	int queryRange(int node, int start, int end, int l, int r) {
		if (start > end || start > r || end < l)
			return 0;

		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node]; 
			if (start != end) {
				lazy[node * 2] += lazy[node]; 
				lazy[node * 2 + 1] += lazy[node]; 
			}
			lazy[node] = 0; 
		}

		if (start >= l && end <= r) 
			return tree[node];
		
		int mid = (start + end) / 2;
		int p1 = queryRange(node * 2, start, mid, l, r); 
		int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r); 
		return (p1 + p2);
	}
};
