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
  f(i,1,n) f(j,1,n) printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
  f(i,1,n-1) {
    int x=rd(), y=rd();
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1, 0); init();
  // f(i,1,n) cout<< "dep, siz="<<dep[i]<<" "<<siz[i]<<endl;
  f(i,1,n) f(j,1,n) {
    // (i, j) 为逆序对
    // i 出现在 j 前面
    // i > j
    if(i<=j) continue;
    int k = lca(i, j); int len = dep[i] + dep[j] - 2*dep[k], tmp=0;
    if(k == i) {
      int p=j, l=0;
      while(p!=i) {
        int s = -siz[p];
        p=fa[p][0];
        // 统计 p 在非链上的子树大小
        s+=siz[p];
        ++l;
        tmp += s * dp[len-l][l];
      }
      tmp += (siz[i]-siz[j]-l);
      tmp %= mod;
      printf("for (%lld, %lld), tmp = %lld\n", i, j, tmp);
    } else if(k == j) {
      int p=i, l=0;
      while(p!=j) {
        int s = -siz[p];
        p=fa[p][0];
        // 统计 p 在非链上的子树大小
        s+=siz[p];
        printf("siz[%d]=%d\n", p, siz[p]);
        ++l;
        tmp += s * dp[l][len-l];
        printf("for %d, s = %d\n", p, s);
      }
      tmp += siz[i];
      tmp %= mod;
      printf("for (%lld, %lld), tmp = %lld\n", i, j, tmp);
    } else {
      int p=j, l=0;
      while(p!=k) {
        int s = -siz[p];
        p=fa[p][0];
        // 统计 p 在非链上的子树大小
        s+=siz[p];
        ++l;
        tmp += s * dp[len-l][l];
      }
      p=i, l=0;
      while(p!=k) {
        int s = -siz[p];
        p=fa[p][0];
        // 统计 p 在非链上的子树大小
        s+=siz[p];
        ++l;
        tmp += s * dp[l][len-l];
      }
      tmp += siz[i];
      int p0=j; while(fa[p0][0]!=k) p0=fa[p0][0];
      p=i; while(fa[p][0]!=k) p=fa[p][0];
      tmp += (-siz[p0]-siz[p]+n) * (dp[dep[i]-dep[k]][len-dep[i]+dep[k]]);
      tmp %= mod;
      printf("for (%lld, %lld), tmp = %lld\n", i, j, tmp);
    }
    ans += tmp*inv(n)%mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
/*
6
1 2
2 3
2 4
4 5
4 6

*/