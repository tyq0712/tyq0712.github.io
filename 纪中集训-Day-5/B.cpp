#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define int ll
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
int t, n, a[1000005];
signed main() {
  rd(t);
  f(i,1,t) {
    int ans=0;
    rd(n); f(i,1,n) rd(a[i]);
    f(i,1,n) {
      // a_i | i+j
      int j=-i; while(j<=0) j+=a[i];
      for(; j<=n; j+=a[i]) {
        if(a[i]*a[j] == i+j && j>i && j<=n) ++ans;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}