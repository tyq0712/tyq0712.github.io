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
int head[_], ver[_], Next[_], vis[_], tot, stk[_], d[_], ind[_], outd[_], ans[_], top;
void add(int u, int v) {
  // cerr << "add " << u << ' ' << v << endl;
  ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
}
void dfs_undirected(int u) {
  for(int &e=head[u]; e; e=Next[e]) {
    if(vis[e>>1]) continue; int t=e;
    vis[e>>1]=1; dfs_undirected(ver[e]);
    ans[t>>1] = t&1 ? 0 : 1;
  }
}
int x[_], y[_], n;
int main() {
  tot=1; rd(n); f(i,1,n) { rd(x[i]); rd(y[i]); add(x[i], y[i]+N); add(y[i]+N, x[i]); ++d[x[i]]; ++d[y[i]+N]; }
  int j=0;
  f(i,1,2*N) if(d[i]&1) j?add(j, i), add(i, j), j=0:j=i;
  f(i,1,2*N) dfs_undirected(i);
  f(i,1,n) cout << (ans[i]?'b':'r');
  return 0;
}