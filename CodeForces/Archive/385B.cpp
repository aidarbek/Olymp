#include <iostream>

using namespace std;
string s;
int n = 0;
int c = 0;
bool u = 0;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>s;
	n = s.size();
	for(int i=3;i<n;i++)
	{
		u = 0;
		for(int j=i;j<n;j++)
		{
			if(s[j]=='r' && s[j-1]=='a' && s[j-2]=='e' && s[j-3]=='b' || u)
			{
				c++;
				u = 1;
			}
		}
	}
	cout<<c;
	return 0;
}