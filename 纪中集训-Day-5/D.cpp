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
int dp[205][205], n, mod=1e9+7;
vector<int> edge[205];
int fa[205][10], dep[205], siz[205], ans;
int qpow(int a, int b) {
  int res=1; for(; b; b>>=1, a=a*a%mod) if(b&1) res=res*a%mod; return res;
}
int inv(int a) {
  return qpow(a, mod-2);
}
void dfs(int u, int f) {
  fa[u][0]=f; dep[u]=dep[f]+1; siz[u]=1;
  for(auto v:edge[u]) if(v!=f) { dfs(v, u); siz[u]+=siz[v]; }
}
void init() {
  f(t,1,9) f(i,1,n) fa[i][t]=fa[fa[i][t-1]][t-1];
}
int lca(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	for(int k=9; k>=0; --k) if(dep[fa[u][k]] >= dep[v]) u = fa[u][k];
  // cout<<"u, v="; cout << u << " " << v << endl;
	if(u == v) return u;
	for(int k=9; k>=0; --k) if(fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
	return fa[u][0];
}
signed main() {
  rd(n); f(i,1,200) dp[0][i]=1; f(i,1,200) dp[i][0]=0;
  f(t,1,400) f(i,1,200) if(t-i <= 200) dp[i][t-i]=(dp[i-1][t-i]+dp[i][t-i-1])%mod*inv(2)%mod;
  // f(i,1,n) f(j,1,n) printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
  f(i,1,n-1) {
    int x=rd(), y=rd();
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, 0); init();
  // f(i,1,n) cout<< "dep, siz="<<dep[i]<<" "<<siz[i]<<endl;
  f(i,1,n) f(j,1,n) {
    if(i>=j) continue;
    int l=lca(i, j), len=dep[i]+dep[j]-2*dep[l], tmp=0;
    // cout << i << " " << j << " len = " << len << " lca = " << lca(i, j) << endl;
    if(l==i) {
      int p=i;
      f(t,1,len-1) { p=fa[p]; tmp+=dp[t][len-t] ; tmp%=mod; }
      tmp+=n-siz[j]-len+1; tmp%=mod;
      tmp+=(n-siz[i])*dp[-dep[l]+dep[i]][len+dep[l]-dep[i]]%mod; tmp%=mod;
      // cout << "for " << i << " " << j << ", tmp = " << tmp << endl;
      ( ans += tmp*inv(n)%mod )%=mod;
      continue;
    } else if(l==j) {
      f(t,1,len-1) { tmp+=dp[t][len-t]; tmp%=mod; }
      tmp+=siz[i]; tmp%=mod;
      tmp+=(n-siz[j])*dp[-dep[l]+dep[i]][len+dep[l]-dep[i]]%mod; tmp%=mod;
      // cout << "for " << i << " " << j << ", tmp = " << tmp << endl;
      ( ans += tmp*inv(n)%mod )%=mod;
      continue;
    }
    f(t,1,len-1) { tmp+=dp[t][len-t]; tmp%=mod; }
    // cout << "for " << i << " " << j << ", tmp = " << tmp << endl;
    tmp += siz[i]; tmp%=mod; tmp += (n-siz[i]-siz[j]-len+1)*dp[-dep[l]+dep[i]][len+dep[l]-dep[i]]%mod; tmp%=mod;
    // cout << "for " << i << " " << j << ", tmp = " << tmp << endl;
    ( ans += tmp*inv(n)%mod )%=mod;
  }
  cout << (n*(n-1)%mod*inv(2)%mod - ans + mod) % mod << endl;
  return 0;
}