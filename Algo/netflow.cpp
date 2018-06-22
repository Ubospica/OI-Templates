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
const int nsz=10050,msz=100050,ninf=1e9+7;
int np,s,t;
struct te{int t,c,pr;}edge[msz<<1];
int head[nsz],pe=1;
void adde(int f,int t,int c){edge[++pe]=(te){t,c,head[f]};head[f]=pe;}
void addsg(int f,int t,int c){adde(f,t,c);adde(t,f,0);}
int d[nsz],gap[nsz],cur[nsz];
void init(){
    static int qu[nsz],qh,qt;
    qh=1,qt=0;
    qu[++qt]=t,d[t]=1,gap[1]=1;
    while(qh<=qt){
        int u=qu[qh++];
        for(int i=head[u],v=edge[i].t;i;i=edge[i].pr,v=edge[i].t){
            if(d[v])continue;
            d[v]=d[u]+1,++gap[d[v]];
            qu[++qt]=v;
        }
    }
    rep(i,1,np)cur[i]=head[i];
}
int dfs(int p,int mi){
    if(mi==0||p==t)return mi;
    int fl=0,tmp;
    for(int &i=cur[p],v=edge[i].t;i;i=edge[i].pr,v=edge[i].t){
        if(d[v]+1!=d[p])continue;//
        tmp=dfs(v,min(edge[i].c,mi));
        fl+=tmp,mi-=tmp,edge[i].c-=tmp,edge[i^1].c+=tmp;
        if(mi==0)return fl;
    }
    if(gap[d[p]]==1)d[s]=np+1;
    --gap[d[p]],++d[p],++gap[d[p]];
    cur[p]=head[p]; //
    return fl;
}
int maxfl(){
    int res=0;
    init();
    while(d[s]<=np)res+=dfs(s,ninf);
    return res;
}

int n,m;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>s>>t;
    np=n;
    int u,v,w;
    rep(i,1,m){
        cin>>u>>v>>w;
        addsg(u,v,w);
    }
    cout<<maxfl()<<'\n';
    return 0;
}
















//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);




