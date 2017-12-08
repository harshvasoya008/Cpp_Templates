void factorise(map<int,int> &Map, vector<int> &prime, int n){
	int num=n;
	for(int i=0;prime[i]<=num;i++){
    	
		int j = lower_bound(all(prime),num)-prime.begin();
    	if(j!=prime.size() && prime[j]==num){
    		Map[num]=1;
    		return;
		}
		
		int p=prime[i];
		if(num%p==0){
			int exp=0;
			while(num%p==0)
				exp++, num=num/p;
			Map[p]=exp;
		}
	}	
}
