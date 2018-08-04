template<class T>
void LongestCommonSubsequence(T a[],T b[],int n,int m){

	int lcs[n+1][m+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0)
				lcs[i][j] = 0;

			else if(a[i-1]==b[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];		

			else
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
	}

	cout<<"Length of LCS: "<<lcs[n][m]<<"\n";
	
	vector<T> seq;
	int i=n,j=m;
	while(i>0 && j>0){
		if(a[i-1]==b[j-1]){
			seq.push_back(a[i-1]);
			i--, j--;
		}
		else if(lcs[i-1][j] > lcs[i][j-1])
			i--;
		else
			j--;
	}

	reverse(all(seq));
	cout<<"LCS: ";
	for(T x: seq)
		cout<<x<<" ";
	cout<<"\n";

}
