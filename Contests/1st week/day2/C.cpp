#include <iostream>
#include <string.h>
#include <string>
using namespace std;
string s1, s2, s;
bool   u[10000];
int    t;
int    n1,n2;
int main()
{
	freopen("otcoci.in","r",stdin);
	freopen("otcoci.out","w",stdout);
	cin>>n1>>n2;
	cin>>s1>>s2;
	cin>>t;
	reverse(s1.begin(), s1.end());
	s = s1+s2;
	for(int i=0;i<n2;i++)
	{
		u[int(s2[i])]  = 1;
	}
	int offset = 0;
	for(int i=0;i<t;i++)
	{
		int n = n1 + offset;
		for(int i=n;i>=0;i-=2)
		{
			if(i>0)
			{
				if(u[int(s[i])] && !u[int(s[i-1])])
				{
					swap(s[i],s[i-1]);
				}
			}
		}
		if(offset<n2)
		{
			 offset++;
		}
	}
	cout<<s;
	return 0;
}
