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
int n, m; int d[_], vis[_], used[_], head[_], ver[_], Next[_], tot, lop;
void add(int u, int v) {
  ver[++tot]=v, Next[tot]=head[u], head[u]=tot;
}
void dfs(int u, int t) {
  // cerr << u << endl;
  for(int e=head[u]; e; e=Next[e]) {
    int v=ver[e]; if(vis[v]) { ++vis[v]; continue; }
    else if(v==t) {  ++vis[v]; continue; }
    else { ++vis[v]; dfs(v, t); }
  }
}
int main() {
  tot=1; rd(n); rd(m); f(i,1,m) {
    int u=rd(), v=rd();
    add(u, v); add(v, u);
    ++d[u]; ++d[v];
  }
  // f(i,1,n) cerr << d[i] << endl;
  f(i,1,n) if(d[i]&1) { puts("No"); exit(0); }
  int dmax = 2, dcount = 0;
  f(i,1,n) {
    if(d[i]>dmax) { dmax=d[i], dcount=1; }
    else if(d[i]==dmax) ++dcount;
  }
  cerr << dmax << ' ' << dcount << endl;
  if(dmax <= 2) { puts("No"); exit(0); }
  else if(dmax >= 6) { puts("Yes"); exit(0); }
  else {
    if(dcount <= 1) { puts("No"); exit(0); }
    else if(dcount >= 3) { puts("Yes"); exit(0); }
    else {
      int node[2], cnt=-1; f(i,1,n) if(d[i]==dmax) node[++cnt]=i;
      vis[node[0]]=1; dfs(node[0], node[1]); puts((vis[node[1]] == 2) ? "Yes" : "No"); exit(0);
    }
  }
  return 0;
}