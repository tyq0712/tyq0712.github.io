#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define int __int128
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
void out(int X) { if(!X) return ; out(X/10); putchar(X%10 + '0'); }
void output(int X) {
  if(!X) puts("0");
  else { out(X); putchar('\n'); }
}
using namespace std;
#define _ 2000005
vector<int> edge[_], st; int n, m, vis[_], cnt[_], fa[_], tot, siz[_], Q[_];
int dfs(int u, int f, int lim) {
  int ans=0; vis[u]=lim;
  // for(auto v:edge[u]) if(v!=f) ans += dfs(v, u, lim);
  for(vector<int>::iterator it=edge[u].begin(); it!=edge[u].end(); ++it) {
    int v=*it; if(v!=f) ans += dfs(v, u, lim);
  }
  ans += lim*siz[u]-cnt[u];
  return max(ans, (int)(0));
}
int chk(int lim) {
  int S=m; for(vector<int>::iterator it=st.begin(); it!=st.end(); ++it) { S-=dfs(*it, -1, lim); if(S<0) return 0; } return 1;
}
stack<int> S; vector<int> loop; int inloop[_];
void findLoop(int u, int f, int id) {
  S.push(u); vis[u]=id;
  for(vector<int>::iterator it=edge[u].begin(); it!=edge[u].end(); ++it) {
    int v=*it;
    if(v==f) continue;
    if(vis[v]!=id) findLoop(v, u, id);
    else {
      while(S.size()) { loop.push_back(S.top()); inloop[S.top()]=1; S.pop(); }
      loop.push_back(v);
    }
  }
  if(S.size()) S.pop();
}
void makeTree() {
  f(i,1,n) {
    if(!vis[i]) {
      findLoop(i, fa[i], i);  
      // cout << "LOOP : size = " << loop.size() << endl;
      if(loop.size()) {
        ++tot;
        for(vector<int>::iterator it=loop.begin(); it!=loop.end(); ++it) {
          int node=*it;
          cnt[tot]+=cnt[node];
          for(vector<int>::iterator it0=edge[node].begin(); it0!=edge[node].end(); ++it0) { int v=*it0; if(!inloop[v]) edge[tot].push_back(v); }
        }
        fa[tot]=-1;
        siz[tot]=loop.size();
        // cout << "cnt = "; output(cnt[tot]);
        loop.clear();
      }
    }
  }
  // cout << "TOT = "; output(TOT);
}
#define fopen(X) { freopen(#X".in", "rb", stdin); freopen(#X".out", "wb", stdout); }
int tmp=0;
int clc() {
  return (m+tmp)/n + 1;
}
signed main() {
  // fopen(hamiltonian);
  rd(n); rd(m);
  f(i,1,n) {
    rd(fa[i]); if(fa[i]!=-1) edge[fa[i]].push_back(i);
    ++tot; siz[i]=1;
  }
  // cerr << "readed in" << endl;
  f(i,1,n) { rd(cnt[i]); tmp+=cnt[i]; }
  makeTree();
  f(i,1,tot) if(fa[i]==-1) st.push_back(i);
  // cerr << "Made Tree" << endl;
  int l=0, r=clc();
  while(l<r) {
    int mid=(l+r+1)>>1;
    if(chk(mid)) l=mid;
    else r=mid-1;
    // cout << "l = " << l << ", r = " << r << endl;
  }
  output(l);
  return 0;
}