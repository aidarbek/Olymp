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

int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n;
	k=n/5;
	n=n%5;
	while(n%3!=0&&k>0){
		k--;
		n+=5;
	}
	if(k==0&&n%3!=0) cout<<-1;
	else cout<<k+n/3;
return 0;
}
