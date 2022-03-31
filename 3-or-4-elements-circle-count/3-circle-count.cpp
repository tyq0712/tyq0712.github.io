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
char ch;
int rd() {
  int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
#define _ 100005
vector<int> edge[_]; int rk[_], ova[_], d[_], tag[_], ans, n, m;
int main() {
  rd(n); rd(m); f(i,1,m) {
    int u=rd(), v=rd(); edge[u].pb(v); edge[v].pb(u); ++d[u]; ++d[v];
  }
  f(i,1,n) ova[i]=i; sort(ova+1, ova+n+1, [](int u, int v){return (d[u]==d[v]) ? (u<v) : (d[u]<d[v]); }); f(i,1,n) rk[ova[i]]=i;
  // f(i,1,n) rk[i]=i; random_shuffle(rk+1, rk+n+1);
  f(i,1,n) { 
    for(auto j:edge[i]) if(rk[i]>rk[j]) tag[j]=i;
    for(auto j:edge[i]) if(rk[i]>rk[j]) for(auto k:edge[j]) if(rk[j]>rk[k]) ans+=(tag[k]==i);
  }
  cout << ans << endl;
  return 0;
}