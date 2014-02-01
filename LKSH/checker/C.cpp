#include <iostream>
#include <stdio.h>
#include <cstdlib>

#define MAXN 32401

using namespace std;
int    n;
string s;
int    t[MAXN];
int    x[MAXN];
int    dinner = 13*3600;
int toint(char c)
{
	return int(c)-48;
}	
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>x[i];
		t[i] = (toint(s[0])*10+toint(s[1]))*3600 + (toint(s[3])*10+toint(s[4]))*60 + (toint(s[6])*10+toint(s[7]));
		//cout<<(toint(s[0])*10+toint(s[1]))<<":"<<(toint(s[3])*10+toint(s[4]))<<":"<<(toint(s[6])*10+toint(s[7]))<<endl;
	}
	int start = t[0], v = x[0], c=0;
	int ans = 0;
	while(true)
	{
		
		if(start+v <= dinner)
		{
			start+=v;
			ans++;
		}
		else if(start+v>dinner) break;
		if(start>=t[c]) c++;
		if(start==t[c])
		{
			v=x[c];	
		}

	}
	cerr<<start;
	int dend = 14*3600;
	while(t[c]<dend)
	{
		v = x[c];
		c++;
	}
	int end = 18*3600;
	start = dend;
	while(true)
	{
		if(start+v <= end)
		{
			start+=v;
			ans++;
		}
		else if(start+v>end) break;
		if(start>=t[c]) c++;
		if(start==t[c])
		{
			v=x[c];	
		}
	}        
	cout<<ans;	
	return  0;
}