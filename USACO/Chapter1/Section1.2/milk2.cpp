/*
ID: suleyme1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <utility> 
#include <algorithm>

using namespace std;
pair<int, int>  p[10000];
int d[10000];
int f[10000];
int mx = 0, mx1 = 0;
int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int x,y;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
		f[i] = p[i].second;
	}
	sort(p, p+n);
   	mx  = -9999;
	mx1 = 0;
	int start = p[0].first, end = p[0].second;
	mx = p[0].second-p[0].first;
	for(int i=1;i<n;i++)
	{
		 if(p[i].first <= end)
		 {
		 	 	end = max(end,p[i].second);
		 	 	mx = max(mx, end-start);  
		 }
		 else if(p[i].first>end )
		 {
			 		
		 		/*if(i==n-1)
		 		{
		 			mx1 = max(mx1, p[i].second-end);
		 	    	end   = p[i].second;
		 	  	  	start = p[i].first;		 
		 		}
		 		else*/
		 		{
		 		    mx1 = max(mx1, p[i].first-end);
		 		    end   = p[i].second;
		 		    start = p[i].first;		 
		 	    }
		}
	}
	cout<<mx<<" "<<mx1<<endl;
	return 0;
}
