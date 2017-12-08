void GPD(int gpd[],int N){
            
    fill(gpd,gpd+N,-1);
    for(int i=2;i<N;i++)
    {
        if(gpd[i]!=-1)
            continue;
            
        for(int j=i;j<N;j+=i)
            gpd[j]=i;
    }
}