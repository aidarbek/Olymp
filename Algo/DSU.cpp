#include <iostream>
using namespace std;
int parent[10000];
int   size[10000];
void make_set(int v)
{	
	parent[v] = v;
	size[v]   = 1;
}
int find_set(int v)
{
	if(v==parent[v])
	{
		return v;
	}
	else
	{
		return parent[v] = find_set(parent[v]);
	}
}
void union_set(int a,int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a!=b)
	{
		if(size[a]<size[b])
		{
			swap(a,b);
		}
		parent[b] = a;
		size[a]+=size[b];
	}
}
int main()
{
	int n;
	cin>>n;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		make_set(x);
	}
	int q;
	cin>>q;
	int y;
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		union_set(x,y);
	}
	int m;
	cin>>m;
	m = find_set(m);
	cout<<size[m];
	return 0;
}