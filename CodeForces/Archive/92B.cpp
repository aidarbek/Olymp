#include <iostream>
using namespace std;
string s;
int a[1000001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{               
		a[i] = int(s[i])-48;
	}
	int n;
	n = s.size();
	int steps = 0;

	while(true)
	{
		 if(a[n-1]==0)
		 {    
		 	 n--;
		 }
		 else
		 {
		 	int t = 1;
		 	for(int i=n-1;i>=0;i--)
		 	{
		 		a[i]+=t;
		 		if(a[i]==2)
		 		{
		 			a[i] = 0;
		 			t    = 1;
		 		}
				else t = 0;
		 	}
		 }
		steps++;
		if(n==1) break;
		for(int i=0;i<n;i++)
		{
		    cerr<<a[i];
		}
		cerr<<endl;
	}
	cout<<steps;
	return 0;
}
