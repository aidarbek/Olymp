#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
#include <stack>
#include <utility>
using namespace std;
string s;
int n;         //Kol-vo skobok
pair<int, int> p[100]; //Nachalo i Konec i-oy pari skobok
stack<pair<int,int> > st; //Otkrivauwaesya skobki
int a[100];
int c=0;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>s;

	for(int i=0;i<s.size();i++)
	{
	     if(s[i]=='(')
	     {
	     	 st.push(make_pair('(',i));
	     }
	     else if(s[i]==')')
	     {
	     	p[n].first = st.top().second;
	     	p[n].second = i;
	     	st.pop();
	     	n++;
	     }	
	}
	int l,r;
	string ans[10000];
	string s1,s2;  
	int m = 0;
	int w = 0;
	while(a[n]==0)
	{
		s1 = s;  		
		s2.clear();
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				l = p[i].first;
				r = p[i].second;
				//cout<<l<<" "<<r<<endl;
				//cout<<s1[l]<<" "<<s1[r]<<endl;
				
				s1[l] = '#';				
				s1[r] = '#';
				
				c++;
			}
			//if(s1[i]!='#') s2+=s1[i];
		}   
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!='#') s2+=s1[i];
		}

		if(c!=0)
		{
			ans[m] = s2;
			m++;
		}
		a[0]++;
		for(int i=0;i<n;i++)
		{
			if(a[i]>1)
			{   				
				a[i] = 0;
				a[i+1]++;
			}
		}
	}
	sort(ans,ans+m);
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
