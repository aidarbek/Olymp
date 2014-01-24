#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <string.h>
#include <string>
#define MAXN 10000
using namespace std;
int              a[MAXN][MAXN];
int              n;
string           s;
map<string, int> m1;
bool             u[MAXN][MAXN];
int 			 d[MAXN];
int pow1(int x,int y)
{
	if(y==1) return x;
	if(y==0) return 1;
	else
	{
		int ans = 1;
		for(int i=1;i<=y;i++)
		{
			ans*=x;
		}
		return ans;
	}
}
int to_int(string s)
{
	int ans = 0;
	int counter = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans += (s[i]-'0') * pow1(10,counter);
		counter++;
	}
	return ans;
}
int main()
{
	freopen("squirell.in","r",stdin);
	freopen("squirell.out","w",stdout);
	int val;
	int it = 0;	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string num;
		cin>>s;
		for(int j=0;j<s.size();j++)
		{
			if(int(s[j])>=48 && int(s[j])<=57 )
			{
				num = s.substr(j);
				s = s.substr(0,j);
				break;
			}
		}             
		val = 0;
		val = to_int(num);              
		
		if(!m1[s]) it = i;
		else it = m1[s];
		m1[s]      = it;
			
		if(val<=MAXN)
		{
			u[it][val] = 1;
		}
	}                             
	int m;
	cin>>m;
	string s1;
	for(int i=1;i<=m;i++)
	{
		cin>>s1;
		int index = m1[s1];
		int res   = 0;

		if(index!=0)
		{   
			for(int i=1;i<=MAXN;i++)
			{
				if(u[index][i]==0)
				{
					u[index][i]=1;
					res = i;
					break; 
				}
			}
			cout<<res<<endl;
		}
		else
		{   
			n++;
			m1[s1]   = n;
			u[n][1] = 1;
			cout<<1<<endl;
		}
	}    
	return 0;
}
