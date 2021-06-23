#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll unsigned long long
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
// ll f0=0LL, f1=1LL;
// ll target = 12e9+1, mod = 8e18, md=1e9;
void output(ll x) {
  if(!x) return ;
  output(x/10);
  putchar(x%10 + '0');
}
ll mul(ll a, ll b, ll mod) {
  ll res=(ll)0; for(; b; a=a+a, a=(a>=mod)?(a-mod):a, b>>=(ll)1) if(b&(ll)1) res+=a, res=(res>=mod)?res-mod:res;
  return res;
}
ll qpow(ll a, ll b, ll mod) {
  ll res=(ll)1; for(; b; a=mul(a, a, mod), b>>=(ll)1) { if(b&(ll)1) res=mul(res, a, mod); }return res;
}
ll getinv(ll x, ll y) {
  return qpow(x, 4e8-1, y);
}
const ll mod=1e9;
int main() {
  // output(mod); putchar('\n');
  // mod=mod*md;
  // output(mod); putchar('\n');
  /*for(ll i=2LL; i<=target; ++i) {
    ll ftmp = (f1+f0) ; ftmp = ftmp >= mod ? ftmp - mod : ftmp;
    f0=f1; f1=ftmp;
  }
  output((ll)((f1-1)/8e9)); putchar('\n');
  f1 = 84177449;
  // f1 = 29450496
  cout<< getinv(f1, (ll)1e9) * 125 % (ll)(1e9) << '\n'; */
  ll n, a, d; cin>>n>>a>>d;
  cout<<368131125*a % mod * 12 * mod + 1<< ' ' << 368131125*d % mod * 12 * mod << "\n" ;
  return 0;
}