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
// sub 1, 2
int mat[105][105], num, n, k, ans;
namespace brute {
  int opt(int x, int y) {
    if(k == 2) return x^y;
    else {
      int _a[10], alen=0, _b[10], blen=0, z=0, k=1;
      memset(_a, 0, sizeof(_a));
      memset(_b, 0, sizeof(_b));
      while(x) {
        _a[++alen]=x%3; x/=3;
      }
      while(y) {
        _b[++blen]=y%3; y/=3;
      }
      f(i,1,9) _a[i]+=_b[i];
      f(i,1,9) { z+=k*(_a[i]%3); k=k*3; }
      return z;
    }
  }
  map< int, int > E;
  void search() {
    int a[20]; f(i,1,n) a[i]=i;
    do {
      int ans=0;
      f(i,1,n) ans = opt(ans, mat[i][a[i]]);
      E[ans]=1;
    } while(next_permutation(a+1, a+n+1));
  }
  void print() {
    f(i,0,k*k*k*k*k*k*k-1) {
      if(E[i]) printf("%d ", i);
    }
    puts("");
  }
}
int main() {
  rd(num); rd(n); rd(k); f(i,1,n) f(j,1,n) rd(mat[i][j]);
  brute::search(); brute::print();
  return 0;
}