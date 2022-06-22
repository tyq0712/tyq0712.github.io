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
#define _ 1000005
const ll mod = 1e9+7; ll c, ans, f[_], inv[_]; int n, mx, a[_];
ll qpow(ll x, ll y) {
	ll res=1; for(; y; y>>=1LL, x=x*x%mod) if(y&1LL) res = res*x%mod; return res;
}
signed main() {
	rd(n); f(i,1,n) { rd(a[i]); c+=a[i]; mx=max(mx, a[i]); }
	f(i,0,mx) inv[i]=qpow(c-i, mod-2);
	f(i,1,mx) (inv[i]+=inv[i-1])%=mod;
	f(i,1,mx) f[i]=(c-1)*(c-i)%mod*inv[i-1]%mod;
	f(i,1,n) { ans += f[a[i]]; ans=ans>=mod?ans-mod:ans; }
	cout << ans << endl;
	return 0;
}