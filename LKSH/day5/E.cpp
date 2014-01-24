#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> ans;
map <int, bool> f1,f2,f3;
int a1[301], a2[301], a3[301];
int n,m,k;
int main()
{   
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i];
		f1[a1[i]] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a2[i];
		f2[a2[i]] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a3[i];   
		if(f1[a3[i]] && f2[a3[i]] && !f3[a3[i]])
		{
			ans.push_back(a3[i]);
		}
		f3[a3[i]] = 1;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

