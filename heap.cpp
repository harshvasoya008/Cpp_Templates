class Heap{
    typedef int T;
    T *arr;
    int MAX;
    int n;

    public:
    Heap(int _n){
        MAX = _n;
        arr = new T[MAX];
        n = 0;
    }

    int left(int i){ return 2*i+1; }
    int right(int i){ return 2*i+2; }
    int parent(int i){ return (i-1)/2; }
    int getTop(){ return (n ? arr[0] : -1); }

    // '<' for minHeap, '>' for maxHeap
    bool check(T &a, T &b){ return a < b; }

    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int top = i;

        if(l < n && !check(arr[top],arr[l]))
            top = l;
        if(r < n && !check(arr[top],arr[r]))
            top = r;

        if(top != i){
            swap(arr[top], arr[i]);
            heapify(top);
        }
    }

    T pop(){
        T top = arr[0];
        n--;

        if(!n)
            return top;

        arr[0] = arr[n];
        heapify(0);

        return top;
    }

    void push(T x){
        if(n == MAX){
            cout<<"Error: Heap full\n";
            return;
        }

        arr[n++] = x;
        int i = n-1;

        while(i>0 && !check(arr[parent(i)], arr[i])){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void print(){
        cout<<"[";
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<"]\n";
    }
};