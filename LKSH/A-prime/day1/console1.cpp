#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{            	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	string s1;
	string s[1000];
	bool u =0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		getline(cin,s1);
		cerr<<s1<<endl;
	}
	while(getline(cin,s1))
	{
		//u = 0;
		for(int i=1;i<=n;i++)
		{
			//cerr<<s[i]<<endl;
			if(s1.find(s[i])!=string::npos)
			{
				cout<<s1<<endl;
				break;
			}
		}                     
	}
	return 0;
}