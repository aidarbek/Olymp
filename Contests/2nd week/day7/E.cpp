#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string mul2(string s)
{
	reverse(s.begin(),s.end());
	int t = 0;
	int n;
	for(int i=0;i<s.size();i++)
	{
		 n = int(s[i])-48;
		 n*=2;
		 n+=t;
		 t = n/10;
		 n = n%10;
		 s[i] = char(n+48);
	}
	if(t!=0)
	{
		s+=char(t+48);
	}                          
	reverse(s.begin(),s.end());
	return s;
}
string plus1(string s)
{
	reverse(s.begin(),s.end());
	int n;
	int t = 0;
	for(int i=0;i<s.size();i++)
	{
		n = int(s[i])-48;
		
		if(i==0)
		{
			n++;
			if(n>=10) t = 1;
			s[i] = char(n%10+48);
		}
		else
		{
			n += t;
			if(n>=10)
			{
				s[i] = char(n%10+48);
				t = n/10;
			}
			
		}

	}
	if(t!=0)
	{
		s+=char(t+48);
	}
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	string s;
	string x="1";
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='L') 
		{
			x=mul2(x);
			
		}
		if(s[i]=='R') 
		{
			x=plus1(mul2(x));
			
		}
	}
	cout<<x;
	return 0;
}