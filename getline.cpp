#include<bits/stdc++.h>

#define sync_off std::ios_base::sync_with_stdio(false); cin.tie(NULL);
#define li long int
#define lli long long int
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n)	 scanf("%d",&n)
#define sii(n,m) scanf("%d%d",&n,&m)
#define sli(n)	 scanf("%ld",&n)
#define slli(n)  scanf("%lld",&n)
#define sf(n)	 scanf("%f",&n)
#define sstr(s)  scanf("%s",s)

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
	//reading the string
	string s;
	getline(cin,s);
	
	cout<<s;
	
	//spliting the string
	string sub;
	istringstream iss(s);
	vector<string> v;
	
	while(getline(iss,sub,' '))
		v.pb(sub);

	return 0;
}

