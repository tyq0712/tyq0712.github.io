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
#define _ 1000000
int n, R1, R2; int head[_], Next[_], ver[_], vis[_], ans[_], deg[_], tot, E0;
void add(int u, int v) {
  ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
  // cerr << "add " << u << ' ' << v << endl;
}
void dfs(int u) {
  for(int &e=head[u]; e; e=Next[e]) {
    int v=ver[e]; if(vis[e>>1]) continue;
    vis[e>>1]=1; if(e>E0) ans[ (ver[e] > n ? ver[e]-n : ver[e]) ] = e&1 ? 1 : -1; dfs(v);
  }
}
int main() {
  tot=1; rd(n); f(i,1,n) {
    int u=rd(); if(u==-1) { R1=i; continue; }
    add(u, i); add(i, u);
    ++deg[u];
  } f(i,1,n) {
    int u=rd(); if(u==-1) { R2=i; continue; }
    add(u+n, i+n); add(i+n, u+n);
    ++deg[u+n];
  }
  add(R1, R2+n); add(R2+n, R1);
  E0=tot;
  f(i,1,n) {
    deg[i]&=1; deg[i+n]&=1;
    if(deg[i]!=deg[i+n]) { puts("IMPOSSIBLE"); return 0; }
    else if(!deg[i]) { add(i, i+n); add(i+n, i); }
  }
  dfs(R1);
  puts("POSSIBLE");
  f(i,1,n) cout << ans[i] << " \n"[i==n];
  return 0;
}