#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define loop(i,x,y) for(int i=x, i##end=y, i##delta=
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
struct query {
  int l, r, n;
} q[_] ;
int lmost[_][];
struct block {
  vector< query > q;
  void sort_by_r() { sort(q.begin(), q.end(), [](query x, query y){ return x.r<y.r; } }
  int size() { return q.size(); }
} bl[_];
int n, m, k, a[_], xs[_];
int main() {
  rd(n); rd(m); rd(k); f(i,1,n) { rd(a[i]); xs[i]=xs[i-1]^a[i]; } f(i,1,m) { rd(q[i].l); rd(q[i].r); q[i].n=i; }
  int len=sqrt(n);
  f(i,1,m) bl[q[i].l/len+1].q.pb(q[i]);
  f(i,1,n) if(bl[i].size()) bl[i].sort_by_r();
  f(i,1,n) if(bl[i].size()) bl[i].solve();
  return 0;
}