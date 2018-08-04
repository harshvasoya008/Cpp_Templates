int LongestIncreasingSubsequence(int a[], int n){
	if(n==0)
		return 0;

	int tail[n];
	int len=1;

	tail[0] = a[0];
	for(int i=1;i<n;i++){
		int idx = upper_bound(tail,tail+len,a[i]) - tail;
		
		// // Use in case of repeating numbers
		// int idx = lower_bound(tail,tail+len,a[i]) - tail;
		
		if(idx == len)
			tail[len++] = a[i];
		else
			tail[idx] = a[i];
	}

	return len;
}