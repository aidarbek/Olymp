#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstdlib>
#include <utility>
#include <algorithm>
#define PRIME 31
using namespace std;
int n;
string s[1000];
pair<char, char> p[1000];
int h[1000][1000];
bool u_p[1000][1000];
bool us_p[1000];
int pr[1000];
bool u[1000];
int total;
bool u1[1000];

int main()
{            	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n;
	pr[1] = PRIME;
	for(int i=2;i<=10;i++)
	{
		pr[i] = pr[i-1]*PRIME;
	}
	int m_size = 0;
	int y;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<s[i].size();j++)
		{
			if(!int(u1[s[i][j]]))
			{
				total++;
				u1[int(s[i][j])] = 1;
			}
			h[i][j+1] = pr[j+1]*(int(s[i][j])-97+1);
		}
		y = s[i].size();
		m_size = max(m_size, y);
	}
	vector <char> v;
	int k;
	v.clear();
	int p1 = 0;
	/*for(int i=1;i<=n;i++)
	{             
		for(int j=0;j<s[i].size();j++)
		{
			cout<<h[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int j=0;j<m_size;j++)
	{
		k = 1;		
		for(int i=2;i<=n;i++)
		{
			v.clear();
			if(h[i][j]==h[i-1][j])
			{
				k++;
				//cout<<"Yeah"<<endl;
			}
			else
			{
				//cout<<"Nope "<<k<<" "<<i<<endl;
				for(int e=i-k;e<=i-1;e++)
				{
					 for(int y=e+1;y<=i-1;y++)
					 {
					 	   p[p1].first =  s[e][j];
					 	   p[p1].second = s[y][j];
					 	   //cout<<s[e][j]<<" "<<s[y][j]<<endl;
					 	   p1++;
					 }
				}
				k = 1;
			}		
		}
		for(int e=n-k+1;e<=n;e++)
		{
			 for(int y=e+1;y<=n;y++)
			 {
			 	   if(!u_p[int(s[e][j])][int(s[y][j])] && s[e][j]!=s[y][j])
			 	   {
			 	   	   u_p[int(s[e][j])][int(s[y][j])] = 1;
			 	   	   u[int(s[y][j])] = 1;
				 	   u[int(s[e][j])] = 1;
				 	   p[p1].first =  s[e][j];
			 		   p[p1].second = s[y][j];
			 		   //cout<<s[e][j]<<" "<<s[y][j]<<endl;
				 	   /*97 - 122*/
				 	   p1++;
			 	   }
			 }
		}
	}	
	int used = 0;
	for(int i=97;i<=122;i++)
		if(u[i]) used++;
	bool no = 0;
	bool unknown = 0;
	if(used+1 < total) 
	{
		unknown = 1;
	}

	for(int i=0;i<p1;i++)
	{
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}             
	return 0;
}