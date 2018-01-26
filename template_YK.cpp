#include <bits/stdc++.h>

#define LOCAL 0

#define lli long long int
#define llu unsigned long long int
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define slli(n) scanf("%lld",&n);
#define ss(n) scanf("%s",n);

const long double EPS = 1e-10;
const int MOD = 1000000007ll;
const int mod1 = 1000000009ll;
const int mod2 = 1100000009ll;
int INF = (int)1e9;
lli INFINF = (lli)1e18;
int debug = 0;
long double PI = acos(-1.0);

using namespace std;

int bit_count(lli _x){lli _ret=0;while(_x){if(_x%2==1)_ret++;_x/=2;}return _ret;}
int bit(lli _mask,int _i){return (_mask&(1ll<<_i))==0?0:1;}
int powermod(lli _a,lli _b,int _m=MOD){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
int add(int a,int b,int m=MOD){int x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
int sub(int a,int b,int m=MOD){int x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
int mul(int a,int b,int m=MOD){lli x=a*1ll*b;x%=m;while(x<0)x+=m;return (int)x;}
int ldtoint(ld x){return (int)(x+0.5);}lli ldtolli(ld x){return (lli)(x+0.5);}

template<class T1,class T2>ostream&operator<<(ostream& os,const pair<T1,T2>&p){os<<"["<<p.first<<","<<p.second<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,const vector<T>&v){os << "[";bool first=true;for (T it:v){if (!first)os<<", ";first = false;os<<it;}os<<"]";return os;}
template<class T>ostream&operator<<(ostream& os,set<T>&v){os<<"[";bool first=true;for (T it:v){if(!first)os<<", ";first=false;os<<it;}os<<"]";return os;}
template<class T1,class T2>ostream&operator<<(ostream& os,map<T1,T2>&v){os<<"[";bool first=true;for(pair<T1,T2> it:v){if(!first)os<<", ";first=false;os<<"("<<it.F<<","<<it.S<<")";}os<<"]";return os;}

struct Segtree{
    typedef int stt;
    static const int MAXN = 2000010;
    stt Segtree[4*MAXN];

    stt MergeSegTree(stt a,stt b){
        return a + b;
    }

    void BuildSegTree(int s,int e,int idx){
        if(s==e)
            Segtree[idx] = 0;
        else{
            int mid = (s+e)>>1;
            BuildSegTree(s,mid,2*idx+1);
            BuildSegTree(mid+1,e,2*idx+2);
            Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
        }
    }

    void UpdateSegTree(int s,int e,int x,stt y,int idx){
        if(s==e){
            Segtree[idx] += y;
            return;
        }
        int mid = (s+e)>>1;
        if(x<=mid)
            UpdateSegTree(s,mid,x,y,2*idx+1);
        else
            UpdateSegTree(mid+1,e,x,y,2*idx+2);
        Segtree[idx] = MergeSegTree(Segtree[2*idx+1],Segtree[2*idx+2]);
    }

    stt QuerySegTree(int s,int e,int x,int y,int idx){
        if(s==x && e==y)
            return Segtree[idx];
        int mid = (s+e)>>1;
        if(y<=mid)
            return QuerySegTree(s,mid,x,y,2*idx+1);
        if(x>mid)
            return QuerySegTree(mid+1,e,x,y,2*idx+2);
        return MergeSegTree(QuerySegTree(s,mid,x,mid,2*idx+1),QuerySegTree(mid+1,e,mid+1,y,2*idx+2));
	}
};

int N,K;
Segtree stt;

int main()
{
if(LOCAL){
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    debug = 1;
}
    srand (time(NULL));

    cin>>N>>K;
    stt.BuildSegTree(1,2*N,0);

    int curr = 1;
    int tot = 1;
    for(int i=1;i<=N;i++){
        int next = curr + K;
        int sum = stt.QuerySegTree(1,2*N,curr+1,next-1,0);

        stt.UpdateSegTree(1,2*N,curr,1,0);
        stt.UpdateSegTree(1,2*N,curr+N,1,0);

        stt.UpdateSegTree(1,2*N,next,1,0);
        if(next > N)
            stt.UpdateSegTree(1,2*N,next - N,1,0);
        else
            stt.UpdateSegTree(1,2*N,next + N,1,0);

        tot += sum + 1;
        cout<<tot<<" ";

        if(next > N)
            next -= N;
        curr = next;
    }

    return 0;
}
