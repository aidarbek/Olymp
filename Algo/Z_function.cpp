#include <iostream>AIDAR LOH
#include <string>
#include <string.h>
#include <vector>
#define MINN -9999
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int z[10000];

	string s;
	int n;
	int mx = MINN;
	cin>>n;                                                                        
	for(int i=1;i<=n;i++)
	{                                 		
		memset(z,0,sizeof(z));
		cin>>s;                                                                                
		mx = MINN;
		int m = s.size();
		int l=0;
		for (int i=0; i<m; i++)                
		{
			l=0;
			for(int j=0;j<i;j++)
			{
				 if(s[i]==s[j])
				 {
				 	l++;
				 }
			}	
			z[i] = l;
			mx = max(mx, z[i]);
		}
		cout<<mx<<endl;
	}
	return 0;
}