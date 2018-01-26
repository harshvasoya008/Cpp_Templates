class FenwickTree{
	/* Binary-Indexed Tree (BIT) */

	typedef int T;
	T *BIT;
	int MAX;
	
	public:
	void build(int n){
		MAX=n+1;
		BIT = new T[MAX];
		for(int i=0;i<MAX;i++)
			BIT[i]=0;
	}
	
	void update(int x,int val){
		while(x<MAX){
			BIT[x] += val;
			x += x&-x;
		}
	}
	
	T query(int x){
		int sum=0;
		while(x>0){
			sum += BIT[x];
			x -= x&-x;
		}
		return sum;
	}
};

lli getInvCount(int a[],int b[],int n){
	sort(b,b+n);

	// converting a[] into sort-indexed array
	int arr[n];
	forn(i,0,n){
		arr[i] = lower_bound(b,b+n,a[i]) - b + 1; 	// 1-indexed
	}
	
	FenwickTree fw;
	fw.build(n);

	lli invcnt = 0;
	for(int i=n-1;i>=0;i--){
		invcnt += (lli)fw.query(arr[i]-1);
		fw.update(arr[i],1);
	}

	return invcnt;
}