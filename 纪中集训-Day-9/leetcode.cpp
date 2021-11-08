#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
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
#define _ 100005
int n, m, a[_];
namespace b2 {
  int tr[_<<2][105];
  void pushup(int p) {
    f(i,0,100) tr[p][i]=tr[p<<1|1][tr[p<<1][i]];
  }
  void build(int l, int r, int p) {
    if(l==r) {
      f(i,0,100) tr[p][i]=abs(i-a[l]); return ;
    }
    int mid=(l+r)>>1;
    build(l, mid, p<<1); build(mid+1, r, p<<1|1); pushup(p);
  }
  int query(int p, int l, int r, int ql, int qr, int k) {
    if(ql<=l && r<=qr) return tr[p][k];
    int mid=(l+r)>>1, res=k;
    if(ql<=mid) res = query(p<<1, l, mid, ql, qr, res);
    if(qr>mid) res = query(p<<1|1, mid+1, r, ql, qr, res);
    return res;
  }
  void solve() {
    build(1, n, 1); int lst=0;
    f(i,1,m) {
      int l=rd(), r=rd(), v=rd();
      // fprintf(stderr, "(l, r, v) = (%d, %d, %d)", l, r, v);
      l^=lst; r^=lst; v^=lst;
      printf("%d\n", lst = query(1, 1, n, l, r, v));
    }
  }
}
namespace b1 {
  void solve() {
    int lst=0;
    f(i,1,m) {
      int l=rd(), r=rd(), v=rd();
      l^=lst; r^=lst; v^=lst;
      f(i,l,r) v=abs(v-a[i]);
      printf("%d\n", lst = v);
    }
  }
}
namespace b3 {
  int ans[_];
  void solve() {
    f(i,1,m) {
      int l=rd(), r=rd(), v=rd(); ans[i-1]=l^1;
      if(i==m) {
        v=v^ans[i-1];
        f(i,1,n) v=abs(v-a[i]);
        ans[i]=v;
      }
    }
    f(i,1,m) printf("%d\n", ans[i]);
  }
}
int MX=-1;
#define fopen(X) { freopen(#X".in", "rb", stdin); freopen(#X".out", "wb", stdout); }
int main() {
  fopen(leetcode);
  rd(n); rd(m); f(i,1,n) { rd(a[i]); MX=max(MX, a[i]); }
  if(n<=1000 && m<=1000) b1::solve();
  else if(MX <= 100) b2::solve();
  else b3::solve();
  return 0;
}