#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
bool is_letter(char a)
{         
	if(int(a)>=65 && int(a)<=90) return 1;
	else return 0;
}
string s;
int    n,k;
int    x;
char   a;
bool   u[10000];
bool   error;
int    p = 1;
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
    	cin>>x>>a;
    	p+=x;
    	if(p>n)
    	{
    		p %= n;    
    	}
    	if(!is_letter(s[p]))
    	{
    		s[p] = a;
    	}
    	else
    	{
    		if(s[p]!=a) error = 1;
    	}
    }
    if(error) {cout<<"!";return 0;}
    for(int i=1;i<=n;i++)
    {
    	if(!is_letter(s[i])) s[i] = '?';
    }
    while(!u[p])
    {
    	cout<<s[p];
    	u[p] = 1;
    	p--;    	
    	if(p==0) p = n;

    }
	return 0;
}
