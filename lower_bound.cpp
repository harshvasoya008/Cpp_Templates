#include<bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
	vector<int> v = {1,2,3,5,6,6,7,10};
	vector<int>::iterator it1 = upper_bound(all(v),6);
	vector<int>::iterator it2 = lower_bound(all(v),6);
	vector<int>::iterator it3 = lower_bound(all(v),8);
	int i = upper_bound(all(v),20) - v.begin();
	cout<<*it1<<endl;
	cout<<it2-v.begin()<<endl;
	cout<<*it3<<endl;
	cout<<"*"<<i<<endl;
	
	vector<pair<int,int> > a = {{1,1},{3,2},{4,3}};
	vector<pair<int,int> >::iterator it4 = upper_bound(all(a),mp(4,4));
	cout<< it4->F <<" "<< it4->S <<endl;
	
	return 0;
}

