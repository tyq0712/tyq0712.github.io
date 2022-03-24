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
int son[_], fa[_], height[_], top[_], ans[_], n;
int buf[_], *f[_], *now=buf; vector<int> edge[_];
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
    solve(son[u], u);
    ans[u]=ans[son[u]]+1;
  }
  for(auto v:edge[u]) {
    if(v==fa || v==son[u]) continue;
    f[v]=now; now+=height[v];
    solve(v, u);
    f(i,1,height[v]) { f[u][i]+=f[v][i-1]; if(f[u][i]>f[u][ans[u]] || (f[u][i] == f[u][ans[u]] && i<ans[u])) ans[u]=i; }
  }
  if(f[u][ans[u]]==1) ans[u]=0;
}
int main() {
  rd(n); f(i,1,n-1) {
    int u=rd(), v=rd(); edge[u].pb(v); edge[v].pb(u);
  }
  dfs(1, 0);
  f[1]=now; now+=height[1];
  solve(1, 0);
  f(i,1,n) cout << ans[i] << endl;
  return 0;
}