#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> v;
bool cmp(int l, int r) const
{
	return l>r;
}
int main()
{
	freopen( "input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	make_heap(v.begin(), v.end()), cmp;
	cout<<v.front()<<" ";
	make_heap(v.begin(), v.end());
	cout<<v.front();
	return 0;
}