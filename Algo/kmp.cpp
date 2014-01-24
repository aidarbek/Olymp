#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) 
	{
		
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]) 
			j = pi[j-1];
		if (s[i] == s[j])  
			++j;
		pi[i] = j;
        
	}
	return pi;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	vector<int> v;
	v = prefix_function("abcabc");
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}