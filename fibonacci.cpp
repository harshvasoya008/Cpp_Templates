namespace Fib{
	
	void multiply(lli F[2][2], lli M[2][2])
	{
		lli x =  (F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD;
		lli y =  (F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD;
		lli z =  (F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD;
		lli w =  (F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD;
		
		F[0][0] = x%MOD;
		F[0][1] = y%MOD;
		F[1][0] = z%MOD;
		F[1][1] = w%MOD;
	}
	 
	void power(lli F[2][2], lli n)
	{
		if( n == 0 || n == 1)
		  return;
		lli M[2][2] = {{1,1},{1,0}};
		
		power(F, n/2);
		multiply(F, F);
		
		if (n%2 != 0)
			multiply(F, M);
	}
	 
	lli getfib(lli n)
	{
		lli F[2][2] = {{1,1},{1,0}};
	  	if (n == 0)
	    	return 0;
	  	power(F, n-1);
	  	return F[0][0];
	}
}

