#include <iostream>
using namespace std;
bool   u[1000];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(!u[i])
		{
			if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
			{
				u[i]   = 1;
				u[i+1] = 1;
				u[i+2] = 1;
			}
		}
	}
	string s1;
	for(int i=0;i<s.size();i++)
	{
		//cout<<u[i]<<endl;
		if(!u[i]) s1+=s[i];
		else
		{
			if(s1.size()>0) cout<<s1<<" ";
			s1.clear();  
		}
	}
	if(s1.size()>0) cout<<s1<<" ";
	return 0;
}