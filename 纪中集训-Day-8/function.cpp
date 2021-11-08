#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define int __int128
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
#define _ 3000005
int p[_], np[_], cnt, n, mod, id, M, ans, I;
void init(int limit) {
  f(i,2,limit) {
    if(!np[i]) p[++cnt]=i;
    for(int j=1; j<=cnt && p[j]*i<=limit; ++j) { np[i*p[j]]=1; if(i%p[j]==0) break ; }
  }
  f(i,1,cnt) {
    int P=p[i];
    if(M==1) np[P] = (mod-P*P%mod+P)%mod;
    if(M==2) np[P] = (mod-P*P%mod*P%mod*P%mod+P*P%mod+mod)%mod;
    if(M==3) np[P] = (mod-P*P%mod*P%mod*P%mod*P%mod*P%mod+P*P%mod*P%mod+mod)%mod;
  }
}
int geth(int p, int e) { return np[p]; }
int qpow(int a, int b) { int res=1; for(; b; b>>=1, a=a*a%mod) if(b&1) res=res*a%mod; return res; }
int inv(int x) { return qpow(x, mod-2); }
int sumM(int x) {
  if(M==1) return x*(x+1)%mod*I%mod;
  if(M==2) return x*(x+1)%mod*(2*x%mod+1)%mod*I%mod;
  if(M==3) return x*(x+1)%mod*I%mod*x%mod*(x+1)%mod*I%mod;
}
void dfs(int now, int x, int H) {
  ans = (ans+H*sumM(n/x))%mod;
  for(int k=now; p[k]*p[k] <= n / x && k<=cnt; ++k) 
    for(int e=2, x1=p[k]*p[k]; x1 <= n/x; ++e, x1=x1*p[k])
      dfs(k+1, x1*x, H*geth(p[k], e)%mod);
}
void out(int X) { if(!X) return ; out(X/10); putchar(X%10 + '0'); }
void output(int X) {
  if(!X) puts("0");
  else { out(X); putchar('\n'); }
}
void solve() {
  int limit=1; while(limit*limit < n) ++limit;
  init(limit); if(M==1) I=inv(2); if(M==2) I=inv(6); if(M==3) I=inv(2);
  ans = 0; dfs(1, 1, 1); output(ans);
}
#define fopen(X) { freopen(#X".in", "rb", stdin); freopen(#X".out", "wb", stdout); }
signed main() {
  // fopen(function);
  rd(id); rd(n); rd(M); rd(mod);
  solve();
  return 0;
}