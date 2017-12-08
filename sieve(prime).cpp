void sieve(vector<int> &prime){
	
	//complexity: O(nlog(logn))
	
	int N=(int)1e6;
	bool *isp=new bool[N]();
	
	for(int z=2;z<=N;z++)
	{
		if(!isp[z])
		{
			prime.pb(z);
			if(z*z>N)	continue;
			
			for(int j=2*z;j<=N;j+=z)
				isp[j]=true;
		}
	}
}
