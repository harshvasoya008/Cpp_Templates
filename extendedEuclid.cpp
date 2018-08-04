pair<int,int> extendedEuclid(int a,int b){

	//complexity: O(log(max(a,b)))
	
	if(!b)
		return {1,0};

	pair<int,int> p = extendedEuclid(b,a%b);
	return {p.S, p.F-(a/b)*p.S};
}