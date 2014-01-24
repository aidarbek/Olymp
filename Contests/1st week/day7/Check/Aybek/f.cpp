#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>

#define S second
#define F first
#define ll long long
#define eps 1e-9
#define mkp make_pair
#define pb push_back
#define ull unsigned long long
#define inc(i,x,n) for(int i=(int)x;i<=(int)n;i++)
#define dec(i,n,x) for(int i=(int)n;i>=(int)x;i--)
#define sz size

using namespace std;

const int inf=1000000000; // default 1e9

double Time()
{
  return double(clock())/double(CLOCKS_PER_SEC);
}

const int N=100001;

int n,q,com,l,r,x;
ll a[N],b[N];

int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n>>q;
	inc(i,1,n){
		cin>>a[i];
	}
	inc(i,1,q){
		cin>>com;
		if(com==1){
			cin>>l>>r>>x;
			inc(j,l,r) a[j]=x;
		}
		else if(com==2){
			cin>>l>>r>>x;
			int e=1;
			inc(j,l,r){
				a[j]+=e*x;
				e++;
			}
		}
		else if(com==3){
			cin>>l>>x;
			int sz=0;
			inc(j,l,n){
				b[++sz]=a[j];
			}
			a[l]=x;
			inc(j,1,sz){
				a[l+j]=b[j];
			}
			n=max(l,n+1);
		}
		else{
			cin>>l>>r;
			ll sum=0;
		   inc(j,l,r) sum+=a[j]*1ll;
		   cout<<sum<<endl;
		}
	}
return 0;
}
