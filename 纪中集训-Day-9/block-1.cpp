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
#define __ 250
#define _ 50005
struct block {
  int l, r, tag;
} bl[__] ;
int bel[_], a[_], n;
void init(int n) {
  int len = sqrt(n);
  for(int i=1, id=1; i<=n; i+=len, id+=1) {
    bl[id].l=i; bl[id].r=i+len-1;
    f(j,i,min(i+len-1, n)) bel[j]=id;
  }
}
void modify(int l, int r, int c) {
  if(bel[l]==bel[r]) { f(i,l,r) a[i]+=c; return; }
  int i=l; for(; bel[i]==bel[l]; ++i) a[i]+=c;
  int j=r; for(; bel[j]==bel[r]; --j) a[j]+=c;
  f(k,bel[i],bel[j]) bl[k].tag+=c;
}
int query(int l, int r, int c) {
  return a[r]+bl[bel[r]].tag;
}
int main() {
  rd(n); f(i,1,n) rd(a[i]); init(n);
  f(i,1,n) {
    int o=rd(), l=rd(), r=rd(), c=rd();
    if(o==0) modify(l, r, c);
    if(o==1) printf("%d\n", query(l, r, c));
  }
  return 0;
}