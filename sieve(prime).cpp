vector<int> prime;
void sieve(){
	
	//complexity: O(nlog(logn))
	
	int N=(int)1e6;
	vector<bool> isp(N,false);
	
	for(int z=2;z<=N;z++)
	{
		if(!isp[z])
		{
			prime.pb(z);
			if(z*z>N)	continue;
			
			for(int j=z*z;j<=N;j+=z)	// <--- modified
				isp[j]=true;
		}
	}
}
