#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int a[100001];
int n;
int main()
{	
	deque<int> d;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(d.size()==0) {d.push_back(a[i]);continue;}
		else
		{
			if(d.back() > a[i])
			{
				d.push_back(a[i]);
				continue;
			}
			if(d.front() >a[i])
			{
				d.push_front(a[i]);
				continue;
			}
		}
	}
	cout<<d.size()<<endl;
	while(!d.empty())
	{
		cout<<d.front()<<" ";
		d.pop_front();
	}
	return 0;
}