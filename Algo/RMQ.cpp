#include <iostream>
#define INF 100000
using namespace std;
int n;
int t[10000];
int a[10000];
int sz;
void build(int node)
{                  	
	if(node <= sz-1)
	{
		build(node*2);
		build(node*2+1);
		t[node] = max(t[node*2],t[node*2+1]);
	}
}
void update(int v,int x)
{
	t[v+sz-1] = x;
	v=(v+sz-1)/2;
	while(v>=1)
	{
		
		t[v] = max(t[v*2],t[v*2+1]);
		
		v/=2;		
	}
}
int res = -99999;
void minimum(int l, int r)
{
	if(l%2==1)
	{
		res = max(res, t[l]);
		l++;
	}		
	if(r%2==0)
	{
		res = max(res,t[r]);
		r--;
	}
	if(l==r)
	{
		res = max(res,t[r]);
	}
	else if(l>r) res = res;
	else
	{
		minimum(l/2,r/2);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	sz = 1;
	cin>>n;
	int inf = 100000;
	while(sz<n)  sz*=2;
	for(int i=0;i<=sz+n;i++)
	{
		t[i] = inf;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t[sz+i-1];
	}
	build(1);
	
	update(1,100);
	
	res = -9999999;
	minimum(2,4);
	cout<<res<<endl;

	for(int i=1;i<=sz+n-1;i++)
	{
		cout<<t[i]<<" ";
	} 
	return 0;
}