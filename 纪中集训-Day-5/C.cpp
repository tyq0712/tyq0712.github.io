#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll unsigned long long
#define int ll
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
int t, n, d[10000005];
signed main() {
  rd(t);
  f(i,1,t) {
    ll ans=0;
    rd(n); f(i,1,n) rd(d[i]);
    sort(d+1, d+1+n);
    f(j,2,n) ans += (d[j]-d[j-1])*(n-j+1)*(j-1);
    f(i,2,n) ans -= d[i]-d[i-1];
    if(ans!=0) cout << "-" << ans << endl; 
    else cout << "0" << endl;
  }
  return 0;
}