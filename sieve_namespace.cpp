namespace Sieve{
    const int MAXN = 1000010;
    int N;
    bool isp[MAXN];

    void init(int _N){
        N = _N;
        for(int i=1;i<=N;i++)
            isp[i] = true;
        isp[1]=false;
        for(int i=2;i*i<=N;i++)
            if(isp[i])
                for(int j=i+i;j<=N;j+=i)
                    isp[j] = false;
    }
}
