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

int n,m;
char a[100];

int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int cur=0;
	inc(i,0,n-1) a[i]='?';
	inc(i,1,m){
		int k;
		char c;
		cin>>k>>c;
		cur+=k;
		cur%=n;
		if(a[cur]!='?'&&a[cur]!=c){
		   cout<<"!";
			exit(0);
		}
		a[cur]=c;
	}
	inc(i,1,n){
		cout<<a[cur];
		cur--;
		if(cur<0) cur+=n;
	}
return 0;
}
