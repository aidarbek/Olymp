#include <iostream>
using namespace std;
int t[200000];
int sz = 1;
int a[100000];
int RSQ(int l,int r)
{
	int res = 0;
	l += sz+1;
	r += sz+1;
	cout<<l<<" "<<r<<endl;
	while(l<r)
	{
		if(l%2==1)
		{
			//res+=t[l];
			l++;
		}	
		if(r%2==0)
		{
			//res+=t[r];
			r--;
		}
		cerr<<res<<endl;       
		if(l>=r) break;
		l/=2;
		r/=2;
		//cerr<<l<<" "<<r<<endl;
	}
	if(l==r) res+=t[r];
	cerr<<res<<endl;
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int q;
	int l,r;
	cin>>n;           
	while(sz<n) 
	{
		sz*=2;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[sz+i-1] = a[i];
	}               
	
	for(int i=sz;i>=1;i--)
	{
		t[i] =  t[i*2] + t[i*2+1];
	}
	cin>>q;
	cout<<sz<<endl;
	for(int i=sz+n;i>=sz+1;i--) cout<<t[i]<<" ";
	cout<<endl;
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		cout<<RSQ(l,r)<<" ";
		cerr<<endl<<"-------------------"<<endl;
	}
	return 0;
}