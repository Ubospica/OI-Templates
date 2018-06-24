#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define rep(i,l,r) for(register int i=(l);i<=(r);++i)
#define repdo(i,l,r) for(register int i=(l);i>=(r);--i)
#define il inline
typedef long long ll;
typedef double db;

//---------------------------------------
const int nsz=1e6+50;
char s1[nsz],s2[nsz];
int sz1,sz2,ne[nsz],pl[nsz],pp=0;//max sz of prefix and suffix

void getnext(){
	ne[0]=ne[1]=0;
	int k=0;
	rep(i,2,sz2){
		while(k&&s2[i]!=s2[k+1])k=ne[k];
		if(s2[i]==s2[k+1])++k;
		ne[i]=k;
	}
}
void kmp(){
	int k=0;
	rep(i,1,sz1){
		while(k&&s1[i]!=s2[k+1])k=ne[k];
		if(s1[i]==s2[k+1])++k;
		if(k==sz2)pl[++pp]=i-k+1,k=ne[k];
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>(s1+1)>>(s2+1);
	sz1=strlen(s1+1),sz2=strlen(s2+1);
	getnext();
	kmp();
	rep(i,1,pp)cout<<pl[i]<<'\n';
	rep(i,1,sz2)cout<<ne[i]<<' ';
	return 0;
}














//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);





