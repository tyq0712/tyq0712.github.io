#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back 
#define int ll
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
// g[u, v] : u 子树内距 u >= x 的点, 每个点贡献 siz x 的和
// g[u, v] = \sum g[x, v-1]
#define _ 2000005
int son[_], height[_], ans[_], siz[_], dep[_], n, q;
int buf[_], *g[_], *now=buf; vector<int> edge[_];
vector< pir > query[_];
void dfs(int u, int fa) {
  siz[u]=1; dep[u]=dep[fa]+1;
  for(auto v:edge[u]) {
    if(v==fa) continue;
    dfs(v, u);
    if(height[v]>height[son[u]]) son[u]=v;
    siz[u] += siz[v];
  }
  height[u]=height[son[u]]+1;
}
int solve(int u, int fa) {
  g[u][0]=siz[u]-1;
  if(son[u]) {
    g[son[u]]=g[u]+1;
    solve(son[u], u);
    g[u][0]+=g[son[u]][0];
  }
  for(auto v:edge[u]) {
    if(v==fa || v==son[u]) continue;
    g[v]=now; now+=height[v]+1;
    solve(v, u);
    f(i,1,height[v]) g[u][i] += g[v][i-1];
    g[u][0]+=g[v][0];
  }
  for(auto Q:query[u]) {
    int qk=Q.fir, qid=Q.sec;
    ans[qid] += min(qk, dep[u]-1) * (siz[u]-1);
    ans[qid] += qk>=height[u] ? (g[u][0] - siz[u]+1) : (g[u][0] - g[u][qk+1] - siz[u]+1);
  }
}
signed main() {
  rd(n); rd(q);
  f(i,1,n-1) {
    int u=rd(), v=rd(); edge[u].pb(v); edge[v].pb(u);
  }
  f(i,1,q) {
    int p=rd(), k=rd(); query[p].pb(mp(k, i));
  }
  dfs(1, 0);
  g[1]=now; now+=height[1]+1;
  solve(1, 0);
  f(qid,1,q) cout << ans[qid] << endl;
  return 0;
}