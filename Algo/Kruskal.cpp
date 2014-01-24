/*
	(c) Aidarbek  Suleymenov 2014
		First algorithm in 2014 :)
	This algorithm finds the maximum cost of the shortest way
*/
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, pair<int,int> > edges[1000];
int n,m;
int g[1000][1000];
int tree_id[1000];

/*////////////////// -----------DSU--------------------*/
int parent[10000];//Parent of the i-th node of the set
int   size[10000];//Size of the i-th set 
void make_set(int v)
{	
	/*Create a new set*/
	parent[v] = v;
	size[v]   = 1;
}
int find_set(int v)
{
	/*Returns the root of the set*/
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
	/*Union set*/
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
/*//////////////////*/



int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int a,b,c;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		edges[i].first         = c;
		edges[i].second.first  = a;
		edges[i].second.second = b;
	}
	sort(edges,edges+m);
	int mx = -9999999;
	for(int i=1;i<=m;i++) make_set(i);
	for(int i=0;i<m;i++)
	{
		c = edges[i].first;
		a = edges[i].second.first;
		b = edges[i].second.second;
		if(find_set(a)!=find_set(b))
		{
			mx = max(mx,c);
			union_set(a,b);
		} 
	}   
	cout<<mx<<endl;
	return 0;
}