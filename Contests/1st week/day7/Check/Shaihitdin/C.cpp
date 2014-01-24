#include<iostream>
#include<stdio.h>
#include<map>
#include<list>
using namespace std;
list <int> a[7];
map<pair<int,int>,bool> m1;
const int INF=100001;
int n,p,ans,res,i,st,fret;
int main(){
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
    cin>>n>>p;
    for(i=1;i<=n;i++){
       cin>>st>>fret;
    	   if(!a[st].empty() && *a[st].rbegin()>fret){
    	     for(list<int> :: iterator it=a[st].end();it!=a[st].begin();it++){      
    	 	   	res++;
    	     	if(*it<=fret){
    	    		 break;
    	  	 	  }

   	     }
       	if(m1[make_pair(st,fret)]==0){
      	  	 a[st].push_back(fret);
     	     res++;
     	     m1[make_pair(st,fret)]=1;
    	     }
       }
       else
       if(m1[make_pair(st,fret)]==0){
       a[st].push_back(fret);
       res++;
       m1[make_pair(st,fret)]=1;
    	  }
    }
    cout<<res+1;
return 0;}
