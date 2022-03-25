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
#define _ 200005
int height[_], val[_], son[_], fa[_], n, k; vector<int> edge[_];
void dfs(int u, int f) {
  fa[u]=f;
  for(auto v:edge[u]) {
    if(v==f) continue ;
    dfs(v, u); if(height[v] >= height[son[u]]) son[u]=v;
  }
  height[u]=height[son[u]]+val[u];
}
signed main() {
  rd(n); rd(k); f(i,1,n) rd(val[i]); f(i,1,n-1) {
    int u=rd(), v=rd();
    edge[u].pb(v); edge[v].pb(u);
  }
  dfs(1, 0); ll ans=0; f(i,1,n) if(son[fa[i]] == i) height[i]=0;
  sort(height+1, height+n+1, [](int u, int v){return u>v;});
  f(i,1,k) ans += height[i];
  cout << ans << endl;
  return 0;
}