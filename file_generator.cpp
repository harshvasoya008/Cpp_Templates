#include<bits/stdc++.h>

#define sync_off std::ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n)	 scanf("%d",&n)
#define sii(n,m) scanf("%d%d",&n,&m)
#define slli(n)  scanf("%lld",&n)
#define forn(i,a,b) for(int i=a;i<b;i++)

using namespace std;
int main()
{
	string path="F:/_My Hub/C++ Programming/CLion/Morgan Stanley/input.txt";
	
	ofstream myfile;
	myfile.open(path);
	
	srand(time(NULL));
	
	// <---------------------------->
	
	int N=5;
	myfile<<N<<"\n";
	
	forn(i,0,N)
		myfile<<rand()%10<<" ";
	myfile<<"\n";
	
	for(int i=0;i<N;i++){
		int x = rand()%3;
		myfile << x <<" ";
	}
	myfile<<"\n";
	
	forn(i,0,N){
		int x = rand()%3;
		myfile<<x<<" ";
	}
	myfile<<"\n";
	
	// <---------------------------->

	myfile.close();
	
	printf("File generated successfully.");
	return 0;
}

