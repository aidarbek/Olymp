#include<iostream>
#include<stdio.h>
#include<map>
#include<list>
#include<set>
using namespace std;
multiset <int> a[7];
map<pair<int,int>,bool> m1;
const int INF=100001;
int n,p,ans,res,i,st,fret,z;
int main(){
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
    cin>>n>>p;
    for(i=1;i<=n;i++){
       cin>>st>>fret;
    	   if(!a[st].empty() && *a[st].rbegin()>fret){
    	    z=a[st].find(fret);
    	    if(a[st].find(fret)!=fret){
      	  	 a[st].insert(fret);
     	     res++;
     	     m1[make_pair(st,fret)]=1;
    	     }
    	     else{
    	       res+=(a[st].size()-z);
    	     }
       }
       else
       if(a[st].find(fret)!=fret){
       a[st].insert(fret);
       res++;
    	  }
    }
    cout<<res+1;
return 0;}
