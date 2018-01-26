class SqrtDecomposition{
	
	int *A;
	int *block;
	int N;
	int BLK_SIZE;
	int total_blocks;
	
	public:

	void init(int *_a, int n){
		A = _a;
		N = n;
		BLK_SIZE = sqrt(N);
		total_blocks = ceil(sqrt(N));

		block = new int[total_blocks];
		forn(i,0,total_blocks){
			block[i] = 0;
			int curr = i*BLK_SIZE;
			forn(j,0,BLK_SIZE){
				if(curr+j<N)
					block[i] += A[curr+j];
				else
					break;
			}
		}
	}

	void update(int idx, int val){
		int blk_num = idx/BLK_SIZE;
		block[blk_num] += (val - A[idx]);
		A[idx] = val;
	}

	int query(int L, int R){
		int sum = 0;
		int i = L;
		while (i<R && i%BLK_SIZE!=0){
			// traversing first block in range
			sum += A[i];
			i++;
		}
		while (i+BLK_SIZE <= R){
			// traversing completely overlapped blocks in range
			sum += block[i/BLK_SIZE];
			i += BLK_SIZE;
		}
		while (i<=R){
			// traversing last block in range
			sum += A[i];
			i++;
		}
		return sum;
	}
};