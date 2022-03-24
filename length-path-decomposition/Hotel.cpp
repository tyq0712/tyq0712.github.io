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
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
#define _ 2000005
// f[i, j] i 子树内距离 i 为 j 的点的个数
// g[i, j] i 子树内的点对 (x, y) 数量, 满足 d(x, LCA(x, y)) = d(i, LCA(x, y)) - j
// f[i, j] <- f[son(i), j-1]
// g[i, j] <- g[son(i), j+1]
int son[_], fa[_], height[_], top[_], n; ll ans;
int buf[_<<2], *f[_], *g[_], *now=buf; vector<int> edge[_];
void dfs(int u, int fa) {
  for(auto v:edge[u]) {
    if(v==fa) continue;
    dfs(v, u);
    if(height[v]>height[son[u]]) son[u]=v;
  }
  height[u]=height[son[u]]+1;
}
int solve(int u, int fa) {
  f[u][0]=1;
  if(son[u]) {
    f[son[u]]=f[u]+1;
    g[son[u]]=g[u]-1;
    solve(son[u], u);
  }
  ans += g[u][0];
  for(auto v:edge[u]) {
    if(v==fa || v==son[u]) continue;
    f[v]=now; now+=height[v]<<1;
    g[v]=now; now+=height[v]<<1;
    solve(v, u);
    f(i,0,height[v]-1) { 
      if(i) ans += f[u][i-1]*g[v][i];
      ans += g[u][i+1]*f[v][i];
    }
    f(i,0,height[v]-1) {
      g[u][i+1] += f[u][i+1]*f[v][i];
      if(i) g[u][i-1] += g[v][i];
      f[u][i+1] += f[v][i];
    }
  }
}
int main() {
  rd(n); f(i,1,n-1) {
    int u=rd(), v=rd(); edge[u].pb(v); edge[v].pb(u);
  }
  dfs(1, 0);
  f[1]=now; now+=height[1]<<1;
  g[1]=now; now+=height[1]<<1;
  solve(1, 0);
  cout << ans << endl;
  return 0;
}