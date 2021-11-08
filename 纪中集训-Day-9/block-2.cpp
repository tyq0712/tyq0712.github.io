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
#define _ 50005
int bel[_], n; ll a[_];
struct block {
  vector<ll> vec;
  int l, r; ll tag;
  void init() { sort(vec.begin(), vec.end()); }
  int count(ll x) {
    auto it=lower_bound(vec.begin(), vec.end(), x-tag);
    return -distance(it, vec.begin());
    // int ans=0; for(auto t:vec) ans+=(t+tag<x); return ans;
  }
  void reinit() {
    vec.clear();
    f(i,l,r) vec.push_back(a[i]);
    sort(vec.begin(), vec.end());
  }
  void printvec(int id) {
    // cerr << "printvec ["<< id << "]: ";
    // for(auto t:vec) {
      // cerr << t << " " ;
    // }
    // cerr << '\n';
  }
} bl[_] ;
void init(int n) {
  int len=sqrt(n);
  // cerr << "len = " << len << '\n';
  for(int i=1, id=1; i<=n; i+=len, ++id) {
    bl[id].l=i; bl[id].r=min(i+len-1, n);
    f(k,i,min(i+len-1, n)) {
      bel[k]=id;
      bl[id].vec.push_back(a[k]);
    }
    bl[id].init();
  }
  // f(i,1,n) cerr << "bel[" << i << "] = " << bel[i] << '\n';
}
void modify(int l, int r, int c) {
  if(bel[l] == bel[r]) {
    f(i,l,r) a[i]+=c;
    bl[bel[l]].reinit();
    return ;
  }
  int i=l; for(; bel[i]==bel[l]; ++i) a[i]+=c; bl[bel[l]].reinit(); bl[bel[l]].printvec(bel[l]);
  int j=r; for(; bel[j]==bel[r]; --j) a[j]+=c; bl[bel[r]].reinit(); bl[bel[r]].printvec(bel[r]);
  f(k,bel[i],bel[j]) bl[k].tag+=c;
}
int query(int l, int r, ll c) {
  int ans=0; if(bel[l]==bel[r]) { f(i,l,r) ans+=(a[i]+bl[bel[i]].tag<c); return ans; }
  int i=l; for(; bel[i] ==bel[l]; ++i) ans+=(a[i]+bl[bel[i]].tag<c);
  // cerr << "from " << l << " to " << i << " ans = " << ans << '\n';
  int j=r; for(; bel[j]==bel[r]; --j) ans+=(a[j]+bl[bel[j]].tag<c);
  // cerr << "from " << j << " to " << r << " ans = " << ans << '\n';
  f(k,bel[i],bel[j]) { ans+=bl[k].count(c); bl[k].printvec(k); /*cerr << "bl[" << k <<"].count("<<c<<")="<<bl[k].count(c)<<'\n';*/ } return ans;
}
int main() {
  scanf("%d", &n);
  f(i,1,n) scanf("%lld", &a[i]);
  init(n);
  f(i,1,n) {
    int opt, l, r; ll c;
    scanf("%d %d %d %lld", &opt, &l, &r, &c);
    if(opt==0) modify(l, r, c);
    if(opt==1) cout << query(l, r, c*c) << '\n';
  }
  return 0;
}