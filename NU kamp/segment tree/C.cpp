#include <iostream>
#define INF 1000001
using namespace std;
int n;
int  t[1000000];
int t1[1000000];
int  a[100000];
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
	build(1);	
}
int res = -99999;
void maximum(int l, int r)
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
		maximum(l/2,r/2);
	}
}



void build1(int node)
{                  	
	if(node <= sz-1)
	{
		build(node*2);
		build(node*2+1);
		t1[node] = min(t1[node*2],t1[node*2+1]);
	}
}
void update1(int v,int x)
{
	t1[v+sz-1] = x;
	build1(1);	
}

int res1 = 99999;
void minimum(int l, int r)
{
	if(l%2==1)
	{
		res1 = min(res1, t[l]);
		l++;
	}		
	if(r%2==0)
	{
		res1 = min(res1,t[r]);
		r--;
	}
	if(l==r)
	{
		res1 = min(res1,t[r]);
	}
	else if(l>r) res = res;
	else
	{
		minimum(l/2,r/2);
	}
}



int main()
{
	freopen("rvq.in","r",stdin);
	freopen("rvq.out","w",stdout);
	sz = 1;
	int inf = 100000;
	n = inf;

	while(sz<n)  sz*=2;
	cout<<sz<<endl;
	
	
	for(int i=0;i<=sz+n;i++)
	{
	    	t1[i] = INF;      //minimum
	}
	for(int i=0;i<=sz+n;i++)
	{
			t[i] = -1*INF;		//maximum
	}
	
	
	/*
	for(int i=0;i<=sz+n;i++)
	{
		//cout<<" "<<t1[i];      //minimum
	}
	*/

	/*
	for(int i=0;i<=sz+n;i++)
	{
		cout<<" "<<t[i];     
	}
	*/
	
	for(int i=1;i<=n;i++)
	{
		 t[sz+i-1]  = (((i% 12345)*(i% 12345))+((i% 23456)*(i% 23456)*(i% 23456)));
 		 t1[sz+i-1] = (((i% 12345)*(i% 12345))+((i% 23456)*(i% 23456)*(i% 23456)));	

 		 cout<<t[sz+i-1]<<" ";
	}
	build(1);
	build1(1);
	int k,x,y;
	cin>>k;
	for(int i=1;i<=k;i++)
	{                                             
		cin>>x>>y;
		if(x<0)
		{
			x*=-1;
			update(x, y);
			update1(x,y);
		}
		else
		{
			res =   INF;
			res1 = -INF;
			minimum(x,y);
			maximum(x,y);
			cout<<res-res1<<endl;
		}
	}
	 
	return 0;
}