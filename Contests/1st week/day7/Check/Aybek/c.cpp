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

const int N=500001;

int point(int q[],int f,int len){
	int l=1,r=len,re=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(q[mid]<f){
			re=max(re,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	return (q[re+1]==f?re+1:re);
}

int a[N],b[N],c[N],d[N],e[N],h[N];
int al=0,bl=0,cl=0,dl=0,el=0,hl=0;
int n,p,res=0;

int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n>>p;
	inc(i,1,n){
		int s,f;
		cin>>s>>f;
		if(s==1){
		   int j=point(a,f,al);
//		   cout<<s<<":"<<f<<"   "<<j<<" "<<al<<"   "<<res<<endl;
			res+=al-j;
		   al=j;
			if(a[j]!=f){
				a[++al]=f;
				res++;
			}
		}
		if(s==2){
		   int j=point(b,f,bl);
//		   cout<<s<<":"<<f<<"   "<<j<<" "<<bl<<"   "<<res<<endl;
			res+=bl-j;
		   bl=j;
			if(b[j]!=f){
				b[++bl]=f;
				res++;
			}
		}
		if(s==3){
		   int j=point(c,f,cl);
			res+=cl-j;
		   cl=j;
			if(c[j]!=f){
				c[++cl]=f;
				res++;
	   	}
		}
		if(s==4){
		   int j=point(d,f,dl);
			res+=dl-j;
		   dl=j;
			if(d[j]!=f){
				d[++dl]=f;
				res++;
			}
		}
		if(s==5){
		   int j=point(e,f,el);
			res+=el-j;
		   el=j;
			if(e[j]!=f){
				e[++el]=f;
				res++;
	   	}
		}
		if(s==6){
		   int j=point(h,f,hl);
			res+=hl-j;
		   hl=j;
			if(h[j]!=f){
				h[++hl]=f;
				res++;
			}
		}
	}	       
	cout<<res;
return 0;
}
