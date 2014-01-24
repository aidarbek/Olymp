/*
ID: suleyme1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <math.h>
//#include <tgmath.h>
#include <cmath>
#include <string.h>
#include <map>
#include <utility>
using namespace std;
map <string, int> m;
pair<string, int> p[10000];
int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		m[s] = i;
		p[i].first  = s;
		p[i].second = 0;
	}
	string name;
	int m1;
	int val;
	string to;
	for(int i=1;i<=n;i++)
	{
		cin>>name>>val>>m1;
		int to_one = 0;
		to_one = int(double(val)/double(m1));
		
		int index =  m[name];
		 
		//p[index].second += (val-(to_one*m1));
		p[index].second -= (to_one*m1);

		for(int j=0;j<m1;j++)
	    {
			cin>>to;
			int n_to        = m[to];
			p[n_to].second += to_one;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<p[i].first<<" "<<p[i].second<<endl;
	}
	return 0;
}
