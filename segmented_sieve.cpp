void SegmentedSieve(int MAX, vector<int> &prime){
	
	// using simple sieve to generate primes upto sqrt(MAX)
	int N = floor(sqrt(MAX))+1;
	bool *isp = new bool[N+1];
	memset(isp,true,N+1);
	
	for(int i=2;i*i<N;i++){
		if(isp[i]){
			for(int j=i+i;j<N;j+=i)
				isp[j]=false;
		}
	}
	for(int i=2;i<N;i++)
		if(isp[i])
			prime.pb(i);
	free(isp);
	
	//marking the multiples of primes generated in several segments of size sqrt(MAX)
	int size = prime.size();
	int low = N;
	int high = 2*N;
	while(low < MAX){
		bool mark[N+1];
		memset(mark,true,N+1);
		
		for(int i=0;i<size;i++){
			int start = floor(low/prime[i]) * prime[i];
			if(start < low)
				start += prime[i];
				
			for(int j=start;j<high;j+=prime[i])
				mark[j-low]=false;
		}
		
		for(int i=low;i<high;i++)
			if(mark[i-low])
				prime.pb(i);
		
		low += N;
		high += N;
		if(high >= MAX)
			high = MAX;
	}			
}
