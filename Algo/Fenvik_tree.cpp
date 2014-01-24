#include <iostream>
using namespace std;
int t[10000];
int n;
int a[1000];
int q;
int G(int k)
{
	return (k &(k+1));
}
void upd(int k, int d)
{
	//a[k]+=d;
	while(k<n)
	{
		t[k] += d;
		k = (k|(k+1));
	}
}
int sum(int l,int r)
{
	int res = 0;
	while(r>=0)
	{
		res+=t[r];
		r = G(r)-1;
		cerr<<r<<" "<<res<<endl;
	}
	
	while(l>=0) 	
	{
		res-=t[l];
		l = G(l)-1;
		cerr<<l<<" "<<res<<endl;
	}
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int l,r;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		upd(i,a[i]);
	}	
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		cout<<sum(l-2,r-1)<<endl;
	}
	return 0;
}
                    
