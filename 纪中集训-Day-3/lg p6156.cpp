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
  #define _ 10000005
  ll f[_], g[_], t[_], prime[_], np[_], h[_], F[_], Sh[_], Sf[_], mod=998244353, k; int n, cnt;
  ll qpow(ll a, ll b) {
    ll res=1; for(; b; b>>=1, a=a*a%mod) if(b&1) res=res*a%mod; return res;
  }
  void shai(int limit) {
    // 筛出 f(n) = n^k, g(n) = \mu(n), h(n) = n^{k+1}
    f[1]=1, g[1]=1, t[1]=1, h[1]=1;
    f(i,2,limit){
      if(!np[i]) {
        prime[++cnt]=i;
        f[i]=qpow(i, k);
        g[i]=-1;
      }
      for(int j=1; j<=cnt && prime[j]*i<=limit; ++j) {
        if(i%prime[j] != 0) {
          // i, prime[j] 互质
          g[i*prime[j]]=g[i]*g[prime[j]];
          f[i*prime[j]]=f[i]*f[prime[j]]%mod;
          np[i*prime[j]]=1;
        } else {
          g[i*prime[j]]=0;
          f[i*prime[j]]=f[i]*f[prime[j]]%mod;
          np[i*prime[j]]=1;
          break ;
        }
      }
    }
    f(i,1,limit) { h[i]=f[i]*i%mod; t[i]=g[i]*g[i]; }
    f(i,1,limit) for(int j=1; i*j<=limit; ++j) (F[i*j]+=i*t[i]*g[j])%=mod;
    f(i,1,limit) Sh[i]=Sh[i-1]+h[i];
    f(i,1,limit) Sf[i]=Sf[i-1]+f[i];
    // f(i,1,limit) {
      // cout<< "(f, g, h, t, F)[" << i << "] = (" << f[i] << ", " << g[i] << ", " << h[i] << ", " << t[i] << ", " << F[i] << ")\n";
    // }
  }
  void solve() {
    cin>>n>>k; ll ans=0; shai(2*n);
    f(T,1,n) {
      ans+=f[T]*F[T]%mod*(2*Sh[(n/T)] - Sf[(n/T)] - Sh[2*(n/T)] + (2*(n/T)+1) * (Sf[2*(n/T)] - Sf[(n/T)]))%mod;
      // ll tmp=0;
      // f(i,1,(n/T)) f(j,1,(n/T)) ( tmp += qpow((i+j), k) ) %= mod;
      // if(tmp != 2*Sh[(n/T)] - Sf[(n/T)] - Sh[2*(n/T)] + (2*(n/T)+1) * (Sf[2*(n/T)] - Sf[(n/T)])) {
        // cerr << "n/T = " << n/T << ", tmp = " << tmp << ", " << "myans = " << 2*Sh[(n/T)] - Sf[(n/T)] - Sh[2*(n/T)] + (2*(n/T)+1) * (Sf[2*(n/T)] - Sf[(n/T)-1]) << '\n';
      // }
      // ans+=f[T]*F[T]%mod*tmp%mod;
      ans%=mod;
    }
    cout<<ans<<endl;
  }
  int main() {
    solve();
    return 0;
  }