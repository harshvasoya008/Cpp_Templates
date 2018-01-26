vector<int> prime;
unordered_map<int,int> *fac;
void sieve(int N){	
	bool *isp=new bool[N]();
	memset(isp,false,N);

	for(int z=2;z<=N;z++)
	{
		if(!isp[z])
		{
			prime.pb(z);
			fac[z][z] = 1;
			
			for(int j=2*z;j<=N;j+=z){
				isp[j]=true;
				
				int num=j;
				int exp=0;
				while(num%z==0)
					exp++, num=num/z;
				
				fac[j][z] = exp;
			}
		}
	}
}
