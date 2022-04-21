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
#define int ll 
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
int k, a[100005], x=2, y=2;
signed main() {
  rd(k); f(i,1,k) rd(a[i]);
  d(i,1,k) {
    int z=a[i], k0 = y/z, k1 = (x+z-1)/z;
    if(k0<k1) { puts("-1"); return 0; }
    else {
      x=k1*z;
      y=k0*z+z-1;
    }
  }
  cout << x << ' ' << y << endl;
  return 0;
}