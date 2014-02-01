#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
#define MAXN 25000000
using namespace std;
long long int     h[MAXN];
long long int    pw[10000];
map<long long, bool>   m1;
vector<long long> ar;
int    n;
string s;
long long int p = 997;
bool used[MAXN];
long long get_hash(int i,int j)
{
	return h[j]-h[i-1]*pw[j-i+1];
} 
int main()
{
	freopen("Bekzhan.in","r",stdin);
	freopen("Bekzhan.out","w",stdout);
	cin>>s;
	double t = clock();
	n = s.size();
	pw[0] = 1;
	for(int i=1;i<=n;i++)
	{
		pw[i] = pw[i-1]*p;
	}
	for (int i=1; i<=n; ++i)
	{
		h[i] = h[i-1] * p + (s[i-1]-'a'+1);
		//h[i] = h[i-1]  + pw[i]*(s[i-1]-'a'+1);
	}
	long long b,ans=0;
	set<int> ans1; 
	for(int i=1;i<=n;i++)
	{
		//cerr<<h[i]<<endl;
		for(int j=i;j<=n;j++)
		{
			//cout<<get_hash(i,j)<<endl;
			b = get_hash(i,j);
			//cerr<<i<<" "<<j<<"-"<<b<<endl;
			//ar.push_back(b);	
			//ans1.insert(b);
			if(!m1[b])
			{
			 ans++;
			 m1[b] = 1;
			}
		}
	}
	/*cerr<<ar.size();
	vector<long long> ans1;
	for(int i=0;i<ar.size();i++)
	{
		for(int j=i+1;j<ar.size();j++)
		{
			if(ar[i]==ar[j] && i!=j)
			{
				used[j] = 1;
			}
		}
		if(!used[i]) 
			ans1.push_back(i);
	}    */
	//cerr<<"Finished in: "<<(clock()*1.0-t)/CLOCKS_PER_SEC;
	cout<<ans<<" ";
	return 0;
}                  