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
