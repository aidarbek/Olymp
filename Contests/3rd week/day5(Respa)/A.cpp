#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int sm(int v)
{
	return ((v)*(1+v))/2;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	long long int s;
	int sum;
	cin>>s;
	vector<int> ans;
	vector<int> ans1;
	for(int i=1;i<=s;i++)
	{
		/*for(int j=i;j<=s;j++)
		{   
			if(sm(j)-sm(i-1)==s)
			{
				//cout<<i<<" "<<j<<endl;
				ans.push_back(i);
				ans1.push_back(j);
			}
		}   */
		int v = s+sm(i);
		int y = ((-1)+sqrt(8*v+1))/2;
		if(sm(y)-sm(i)==s) 
		{
			 ans.push_back(i+1);
			 ans1.push_back(y);
		}
		//cout<<i<<" "<<((-1)-sqrt(8*v+1))/2+1<<endl;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" "<<ans1[i]<<endl;
	}
	return 0;
}