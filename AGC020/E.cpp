#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
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
#define state __int128
#define ll __int128
// #define __int128 long long
int n; state S0; char str[105];
const ll mod=998244353;
unordered_map<state, ll> f[105];
ll DP(state S, int L) {
  // cerr << S << ' ' << L << endl;
  if(!L) return 1;
  if(f[L][S]) return f[L][S];
  ll t=DP(S>>1, L-1)*(1+(S&1))%mod; state x=0, tmp=1;
  f(i,1,L) {
    x=(S&((tmp<<(i+1))-1));
    f(j,2,L/i) {
      x&=(S>>(j-1)*i);
      t+=DP(x, i) * DP(S>>(i*j), L-i*j);
      t%=mod;
    }
  }
  return f[L][S]=t;
}
int main() {
  scanf("%s", str+1); n=strlen(str+1); d(i,1,n) S0 = S0 << 1 | (str[i]=='1');
  int ans = DP(S0, n); cout << ans << endl;
  return 0;
}
