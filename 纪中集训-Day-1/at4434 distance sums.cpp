#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<ll, int>
#define fir first
#define sec second
#define mp make_pair
#define _ 100005
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
pir d[_]; int n, siz[_], fa[_]; map<ll, int> id; vector<int> edge[_];
int dep[_], sz[_]; ll chkd, dis;
void dfs(int u, int f, int d0) {
  dep[u]=d0; sz[u]=1;
  for(auto v:edge[u]) if(v!=f) { dfs(v, u, d0+1); sz[u]+=sz[v]; }
}
int chk() {
  dfs(1, -1, 0);
  f(i,1,n) dis += dep[i];
  return chkd == dis;
}
int main() {
  rd(n); f(i,1,n) { scanf("%lld", &d[i].fir); if(i==1) chkd=d[i].fir; d[i].fir=-d[i].fir; d[i].sec=i; }
  sort(d+1, d+n+1); f(i,1,n) { d[i].fir=-d[i].fir; id[d[i].fir]=d[i].sec; siz[i]=1; }
  f(i,1,n-1) {
    ll dfa=d[i].fir-n+2*siz[d[i].sec];
    if(!id[dfa]) {
      // printf("%d\n", d[i].fir);
      puts("-1"); return 0;
    }
    fa[d[i].sec]=id[dfa];
    siz[fa[d[i].sec]]+=siz[d[i].sec];
    edge[d[i].sec].push_back(fa[d[i].sec]);
    edge[fa[d[i].sec]].push_back(d[i].sec);
  }
  if(!chk()) { puts("-1"); return 0; }
  f(i,1,n) if(fa[i]) printf("%d %d\n", i, fa[i]);
  return 0;
}