#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n,m,x,k;
int main()
{   
	freopen("in","r",stdin);
	freopen("out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>k;
    	for(int j=1;j<=k;j++)
    	{
    		cin>>x;
    	}    
    }
    for(int i=1;i<=m;i++)
    {
    	cin>>k;
    	for(int j=1;j<=k;j++)
    	{
    		cin>>x;    		    	
    	}    
    }
    if(n>m)
    {
    	cout<<n<<" "<<n<<" "<<0<<endl;
    	for(int i=1;i<=n;i++) cout<<i<<" ";
    	cout<<endl;
    	cout<<0;
    }
    else
    {
    	cout<<m<<" "<<0<<" "<<m<<endl;
       	cout<<0;	
       	cout<<endl;
    	for(int i=1;i<=m;i++) cout<<i<<" ";
    	
    }
	return 0;
}