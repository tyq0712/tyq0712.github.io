#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ull unsigned long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
#define _ 500005
ull id[_], pow[_];
int n, m, q, a[_]; vector<int> edge[_]; map<ull, int> S;
void init() {
  pow[0]=1; for(int i=1; i<=500000; ++i) pow[i]=pow[i-1]*37;
}
void dfs(int u, int f, int sonid) {
  id[u]=id[f] * 37 + sonid; S[id[u]]=u;
  for(int i=0; i<edge[u].size(); ++i) dfs(edge[u][i], u, i+1) ;
}
int sum[_<<4];
ull meg(ull x, ull y, ull t) {
  return x*pow[t]+y;
}
void pushup(int p, int l, int r) {
  int mid=(l+r)>>1;
  sum[p] = meg(sum[p<<1], sum[p<<1|1], pow[r-mid]);
}
void modify(int p, int l, int r, int q, int k) {
  if(l==r) { sum[p]=k; return ; }
  int mid=(l+r)>>1;
  if(l<=mid) modify(p<<1, l, mid, q, k);
  else modify(p<<1, mid+1, r, q, k);
  pushup(p, l, r);
}
int solve(int p, int l, int r, int x, int ql, int qr) {
  int mid=(l+r) >> 1;
}
int main() {
  rd(n); rd(m); rd(q);  
  f(i,1,n) {
    edge[rd()].push_back(rd());
  }
  f(i,1,m) { rd(a[i]); modify(1, 1, n, i, a[i]); }
  dfs(1, 0, 1);
  f(i,1,q) {
    int o, x, l, r, t, k;
    rd(o);
    if(o==1) {
      rd(x); rd(l); rd(r);
      solve(1, 1, n, id[x], l, r);
    } else {
      rd(t); rd(k);
      modify(1, 1, n, t, k);
    }
  }
  return 0;
}