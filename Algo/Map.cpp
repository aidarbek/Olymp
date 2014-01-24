#include <iostream>
#include <map>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	map<int, int> m;
	m[1] = 50;
	m[121] = 1;
	for(map<int, int>::iterator iter = m.begin();iter!=m.end();iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}