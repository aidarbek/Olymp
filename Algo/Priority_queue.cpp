#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	priority_queue<int> q;
	int n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		q.push(x);
	}
	cout<<q.top();
	return 0;
}
