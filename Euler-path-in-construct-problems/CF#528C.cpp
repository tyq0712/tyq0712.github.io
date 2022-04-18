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
#define _ 1000005
#define N 200005
int head[_], ver[_], Next[_], vis[_], tot, stk[_], d[_], ind[_], outd[_], top;
pir ans[_];
void add(int u, int v) {
  // cerr << "add " << u << ' ' << v << endl;
  ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
}
void dfs_undirected(int u) {
  for(int &e=head[u]; e; e=Next[e]) {
    if(vis[e>>1]) continue; int t=e;
    vis[e>>1]=1; dfs_undirected(ver[e]);
    ++top; ans[top]=top&1 ? make_pair(u, ver[t]) : make_pair(ver[t], u);
  }
}
int n, m;
int main() {
  tot=1; rd(n); rd(m); f(i,1,m) {
    int u=rd(), v=rd(); ++d[u]; ++d[v]; add(u, v); add(v, u);
  }
  int j=0;
  f(i,1,n) if(d[i]&1) j?add(i, j), add(j, i), j=0, ++m:j=i;
  if(m&1) add(1, 1), add(1, 1), ++m;
  cout << m << endl;
  dfs_undirected(1);
  f(i,1,top) cout << ans[i].fir << ' ' << ans[i].sec << endl;
  return 0;
}