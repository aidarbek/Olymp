#include <iostream>        
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
using namespace std;
int main()
{
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	int n;
	string name, surname, klass, date;
	pair<string, pair<string, pair<string, string> > > p[1001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		 cin>>surname>>name>>klass>>date;
		 if(klass[0]=='1' && klass[1]=='0'  || klass[0]=='1' && klass[1]=='1')
		 {
		 	   klass[0] = ':';
		 }
		 p[i].first                = klass;
		 p[i].second.first         = surname;
		 p[i].second.second.first  = name;
		 p[i].second.second.second = date;
	}
	sort(p,p+n);
	for(int i=0;i<n;i++)
	{
		klass = p[i].first; 
		if(klass[0]==':' && klass[1] =='1' || klass[0]==':' && klass[1] =='0')
		{
			klass[0] = '1';
		}
		cout<<klass<<" "<<p[i].second.first<<" "<<p[i].second.second.first<<" "<<p[i].second.second.second<<endl;
	}
	return 0;
}
