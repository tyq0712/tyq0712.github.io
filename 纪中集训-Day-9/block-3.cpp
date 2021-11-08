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

int n, a[_], bel[_];
struct block {
  vector<int> vec;
  int l, r, tag;
  void init() {
    f(i,l,r) vec.push_back(-a[i]);
    sort(vec.begin(), vec.end());
  }
  int query(int x) {
    return -*lower_bound(vec.begin(), vec.end(), -x+tag);
  }
} bl[_] ;
void init(int n) {
  int len = sqrt(n);
  for(int i=1, id=1; i<=n; i+=len, ++id) {
    bl[id].l=i; bl[id].r=i+len-1; bl[id].init();
    f(j,0,len-1) bel[i+j]=id;
  }
}
void modify(int l, int r, int c) {
  if(bel[l]==bel[r]) { f(i,l,r) a[i]+=c; bl[bel[l]].init(); return ; }
  int i=l; for(; bel[i]==bel[l]; ++i) a[i]+=c; bl[bel[l]].init();
  int j=r; for(; bel[j]==bel[r]; --j) a[j]+=c; bl[bel[r]].init();
  f(k,bel[i],bel[j]) bl[k].tag+=c;
}
int query(int l, int r, int c) {
  int ans=-1; if(bel[l]==bel[r]) { f(i,l,r) if(a[i]+bl[bel[i]].tag<c) ans=max(ans, a[i]+bl[bel[i]].tag); return ans; }
  int i=l; for(; bel[i]==bel[l]; ++i) if(a[i]+bl[bel[i]].tag<c) ans=max(ans, a[i]+bl[bel[i]].tag);
  int j=r; for(; bel[j]==bel[r]; --j) if(a[i]+bl[bel[i]].tag<c) ans=max(ans, a[i]+bl[bel[i]].tag);
  f(k,bel[i],bel[j]) ans=max(ans, bl[k].query(c));
  return ans;
}
int main() {
  rd(n); f(i,1,n) rd(a[i]);
  init(n);
  f(i,1,n) {
    int o, l, r, c;
    rd(o); rd(l); rd(r); rd(c);
    if(o==0) modify(l, r, c);
    else printf("%d\n", query(l, r, c));
  }
  return 0;
}