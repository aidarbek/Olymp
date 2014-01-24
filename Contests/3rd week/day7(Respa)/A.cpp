#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#define INF 1000000
using namespace std;
int n,m,k;
int a[INF];
int b[INF];
int w[INF];//Weight's of the subjects
int p[INF];//Power of the "zaklinaniya"
char c[INF];
char buffer[INF];
int r[INF];
int x;
int num;
vector< int > s[INF]; //Subjects of the i'th magic
map<int,int> was;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	int t;
	for(int i=0;i<=m;i++)
	{
		gets(c);
		//cout<<c<<"--"<<i<<endl;	
		if(i>0)
		{
			x = strlen(c);
			
			t = 0;
			for(int j=0;j<=x;j++)
			{
				//48 - 57
				if(int(c[j])>=48 && int(c[j])<=57)
				{
					buffer[t] = c[j];
					t++;	
				}
				else 
				{
					if(t>0)
					{
						num = atoi(buffer);
						memset(buffer,'\0',sizeof(buffer));
						t = 0;
						s[i-1].push_back(num);
						// cout<<num<<" ";
					}
				}
			}
		}

	}
	vector<int> ans;
	vector<int> buf;
	int mx = -9999;
	int t1;
	int w1 = 0;
	int cost = 0;
	while(p[n]==0)
	{
		w1 = 0;
		for(int i=0;i<m;i++)
		{
			if(p[i]==1)
			{
				w1 += w[i];
			} 
		}
		
		buf.clear();
		if(w1<=k)
		{
			cost = 0;
			for(int i=0;i<m;i++)
			{
				t1=0;
				
				for(int j=0;j<s[i].size();j++)
				{
					if(p[s[i][j]-1]==1)
					{
						t1++;		
					}
				}
				if(t1>=s[i].size())
				{
					cost+=a[i];	
					for(int j=0;j<s[i].size();j++)
					{
						buf.push_back(s[i][j]-1);
					}
				}
			}
			if(cost>mx)
			{
				mx = cost;
				ans.clear();
				for(int j=0;j<buf.size();j++)
				{
					ans.push_back(buf[j]);
				}
			}
		}
		p[0]++;
		for(int i=0;i<n;i++)
		{
			if(p[i]>1)
			{
				p[i] = 0;
				p[i+1]++;
			}
		}
	}             
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
	{	
		if(was[ans[i]+1]) continue;
		else {cout<<ans[i]+1<<" ";was[ans[i]+1]=1;}
	}
	return 0;
}