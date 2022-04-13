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
#define _ 100005
struct node {
  int id, a, b, c;
} ;
int n, k, f[_], ans[_];
int c[_ << 2];
vector<node> seq;
inline int lowbit(int x) { return x&-x; }
void add(int p, int x) {
  // cerr << p << ' ' << x << endl;
  for(; p<=k; p+=lowbit(p)) c[p]+=x;
  // cerr << "end miao" << endl;
}
int query(int p) {
  // cerr << "p: " << p << endl;
  int ans=0; for(; p; p-=lowbit(p)) ans+=c[p]; return ans;
}
void conquer(int l, int r) {
  if(l==r) return ;
  int mid=l+r>>1;
  conquer(l, mid); conquer(mid+1, r);
  vector<node> seql, seqr; seql.pb(node()); seqr.pb(node());
  f(i,l,mid) seql.pb(seq[i]); f(i,mid+1,r) seqr.pb(seq[i]);
  auto cmp = [](node a, node b){return a.b<b.b;};
  sort(seql.begin()+1, seql.end(), cmp);
  sort(seqr.begin()+1, seqr.end(), cmp);
  // cerr << "cdq: " << l << ' ' << r << endl;
  // cerr << "seql: " << endl;
  // for(auto x:seql) cerr << x.a << ' ' << x.b << ' ' << x.c << endl;
  // cerr << "seqr: " << endl;
  // for(auto x:seqr) cerr << x.a << ' ' << x.b << ' ' << x.c << endl;
  auto itl=seql.begin()+1, itr=seqr.begin()+1;
  // cerr << "maintain" << endl;
  for(; itl!=seql.end(); ++itl) {
    while(itr != seqr.end() && itr->b<=itl->b) { add(itr->c, 1); ++itr; }
    f[itl->id] += query(itl->c);
    // cerr << "f[" << itl->id << "]+=" << query(itl->c) << endl;
    // cerr << "miao" << endl;
  }
  // cerr << "end" << endl;
  for(auto x:seqr) if(x.c) add(x.c, -1);
}
int main() {
  rd(n); rd(k); seq.pb(node()); f(i,1,n) {
    node x; rd(x.a); rd(x.b); rd(x.c); x.id=i; seq.pb(x);
  }
  sort(seq.begin()+1, seq.end(), [](node a, node b){return a.a == b.a ? (a.b == b.b ? a.c > b.c : a.b > b.b) : a.a>b.a;});
  conquer(1, n);
  // f(i,1,n) cerr << "f[" << i << "]=" << f[i] << endl;
  f(i,1,n) ++ans[f[i]];
  f(i,0,n-1) cout << ans[i] << endl;
  return 0;
}