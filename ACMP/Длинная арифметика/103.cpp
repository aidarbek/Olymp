#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string long_plus(string s1,string s2)
{
	int maxn = max(s1.size(), s2.size());
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int n = 0, t = 0;
	int n1=0,n2=0;
	string ans;
	for(int i=0;i<maxn;i++)
	{
		  n  = 0;
		  n1 = 0;
		  n2 = 0;
		  if(int(s1[i])>=48 & int(s1[i])<=57)
		  {
		  		n1 = int(s1[i])-48; 
		  }
		  if(int(s2[i])>=48 & int(s2[i])<=57)
		  {
		  		n2 = int(s2[i])-48; 
		  }
		  n=n1+n2+t;
		  if(i==maxn-1)
		  {
		  	   if(n>9)
		  	   {
		  			while(n>9)
		  			{
		  				int val = n%10;
		  				n/=10;
		 	 			ans[i] = char(val+48);
		  				i++;
		  			}
		  		}
		  		else
		  		{
		  			ans[i] = char(n+48);
		  		}	
		  }
		  else
		  {
			  if(n>9)
			  {
			  	t=n/10;
			  	n%=10;
			  }
			  ans[i] = char(n+48);
		  }
	}
	int i=0;
	int npos = 0;
	while(ans[i]=='0')
	{
		npos = i;
		i++;
	}
	ans.substr(0, npos);
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s1,s2;

	cin>>s1>>s2;
	int n = max(s1.size(),s2.size());
	string s;
	s = long_plus(s1, s2);
	for(int i=n+10;i>=0;i--)
	{
		if(int(s[i])>=48 && int(s[i])<=57) cout<<s[i];
	}
	return 0;
}
