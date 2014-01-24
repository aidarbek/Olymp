#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
int    a[15010][15010];
int    b[15010][15010];
int    w;
string s,s1;
bool   flag[15010];
bool   flag1[15010];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>w>>s>>s1;
	int n =  s.size();
	int m = s1.size();
	int l = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<m;j++)
		{
			  a[i][j] = l;
			  if(s[i]==s1[j] && !flag[i])
			  {
			  	l++;
			  	a[i][j] = l;
			  	flag[i] = 1;
			  	break;
			  }
		}
	}
	int l1 = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<n;j++)
		{
			  b[i][j] = l;
			  if(s1[i]==s[j])
			  {
			  	l1++;
			  	b[i][j] = l;
			  	flag1[i] = 1;
			  	break;
			  }
		}
	}

	 int f = 0;
	 bool fail = 0;
	 for(int i=0;i<n;i++)
	 {
	 	if(flag[i]==0)
	 	{
	 		f++;
	 	}
	 	else
	 	{
	 		f = 0;
	 	}
	 	if(f>w) 
	 	{
	 		fail = 1;
	 	}
	 }
	 f = 0;
	 for(int i=0;i<m;i++)
	 {
	 	if(flag1[i]==0)
	 	{
	 		f++;
	 	}
	 	else
	 	{
	 		f = 0;
	 	}
	 	if(f>w) 
	 	{
	 		fail = 1;
	 	}
	 }
	 if(fail) 
	 {
	 	cout<<"No solution";
	 }
	 else
	 {
	 	string ans;
	 	for(int i=0;i<n;i++)
	 	{
	 		if(flag[i]==1)
	 		{
	 			ans+=s[i];
	 		}

	 	}
	 	cout<<ans;
	 }
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			  cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}