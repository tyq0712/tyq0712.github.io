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
#define _ 64
unsigned ll lb[_], num[1005]; int n, ans, magic[1005], id[1005];
int check(unsigned ll x) {
  d(i,0,63) {
    if(!(x>>i)&1) continue ;
    if(!lb[i]) { lb[i]=x; return 1; }
    else x^=lb[i];
  }
  return 0;
}
int main() {
  scanf("%d", &n); f(i,1,n) { scanf("%lld%d", num+i, magic+i); id[i]=i; }
  sort(id+1, id+n+1, [](int u, int v){return magic[u]>magic[v];});
  f(i,1,n) {
    if(check(num[id[i]])) ans+=magic[id[i]];
  }
  cout << ans << endl;
  return 0;
}