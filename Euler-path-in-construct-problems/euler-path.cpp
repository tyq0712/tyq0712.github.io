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
#define _ 10000005
int head[_], ver[_], Next[_], vis[_], tot, stk[_], d[_], ind[_], outd[_], top;
void add(int u, int v) {
  ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
}
void dfs_directed(int u){
  for(int &e=head[u]; e; e=Next[e]) {
    if(vis[e]) continue; int t=e;
    vis[e]=1; dfs_directed(ver[e]);
    stk[++top]=t;
  }
}
void dfs_undirected(int u) {
  for(int &e=head[u]; e; e=Next[e]) {
    if(vis[e>>1]) continue; int t=e;
    vis[e>>1]=1; dfs_undirected(ver[e]);
    stk[++top] = (t&1) ? -(t>>1) : (t>>1);
  }
}
int n, m, typ;
int main() {
  rd(typ); rd(n); rd(m);
  if(typ==1) {
    tot=1; 
    f(i,1,m) {
      int u=rd(), v=rd(); ++d[u], ++d[v];
      add(u, v); add(v, u);
    }
    f(i,1,n) if(d[i]&1) { puts("NO"); return 0; }
    dfs_undirected(ver[2]);
  } else {
    f(i,1,m) {
      int u=rd(), v=rd(); ++ind[v], ++outd[u];
      add(u, v);
    }
    f(i,1,n) if(ind[i]!=outd[i]) { puts("NO"); return 0; }
    dfs_directed(ver[1]);
  }
  // cerr << "qaq" << endl;
  if(top != m) { puts("NO"); return 0; }
  puts("YES"); while(top) cout << stk[top--] << " \n"[top==0];
  return 0;
}