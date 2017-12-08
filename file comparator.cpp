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
#define sf(n)	 scanf("%f",&n)

const int mod = 10000009;
const lli MOD = 1000000007;
int DEBUG = 0;

using namespace std;

lli powermod(lli _a,lli _b,lli _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;if(x<0)x+=m;return x;}


int main()
{
	ifstream file1,file2;
	file1.open("F:/output.txt",ios::binary);
	file2.open("F:/output2.txt",ios::binary);
	
//---------- compare two files line by line ------------------//
	char str1[256], str2[256];
	int j = 0;
	while(!file1.eof())
	{
		file1.getline(str1,256);
		file2.getline(str2,256);
		j++;
		if(strcmp(str1,str2) != 0)
		{
			cout<<"line no: ";
			cout << j << "-the strings are not equal" << "\n";
//			cout << "   " << str1 << "\n";
//			cout << "   " << str2 << "\n";
		}
	}
	
	return 0;
}
