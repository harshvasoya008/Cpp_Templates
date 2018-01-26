pair<int,int> extendedEuclid(int a,int b){

	//complexity: O(log(max(a,b)))
	
	if(!b)
		return {1,0};

	extendedEuclid(b,a%b);
	return {y, x-(a/b)*y};
}