/*
ID: suleyme1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	string s;
	int n;
	cin>>n;
	cin>>s;
	string s1;
	s1 = s; 
	//reverse(s1.begin(),s1.end());
	s=s+s+s;
	int m = n+n;
	int mx = -99999;
	for(int i=n;i<m;i++)
	{   
		char c;
		c = s[i];
		char k;
		k = s[i-1];
		bool  u[10000];
		memset(u,0,sizeof(u));
		int j = i;
		int cnt = 0;
		while((c==s[j] || s[j]=='w' || c=='w') && !u[j])
		{
			if(c=='w') if(s[j]!='w') c=s[j];
			u[j-n] = 1;  
			u[j+n] = 1;
			cnt++;
			j++;
		}
		j = i-1;
		c = s[j];
		int cnt1 = 0;
		while((c==s[j] || s[j]=='w' || c=='w') && !u[j] && j>=0)
		{
			if(c=='w') if(s[j]!='w') c=s[j];
			cnt1++;
			j--;
		}
		if((cnt+cnt1) > mx) mx = cnt+cnt1;  
	}

	cout<<mx<<endl;

	return 0;
}
