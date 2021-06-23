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
#define _ 2000005
vector<int> edge[_], b, w;
int n, p[_], col[_];
void dfs(int u, int f, int c) {
  col[u]=c; if(c) b.push_back(u); else w.push_back(u);
  for(auto v:edge[u]) if(v!=f) dfs(v, u, c^1);
}
void printvec(vector<int> x) {
  for(auto it=x.begin(); it!=x.end(); ++it) printf("%d ", *it);
  puts("");
}
void solve() {
  int x0=b.size(), y0=w.size(), p1=1, p2=2, p3=3;
  if(x0>n/3 && y0>n/3) {
    f(i,1,n)
      if(col[i]) {
        if(p2<=n) p[i]=p2, p2+=3;
        else if(p3<=n) p[i]=p3, p3+=3;
      } else {
        if(p1<=n) p[i]=p1, p1+=3;
        else if(p3<=n) p[i]=p3, p3+=3;
      }
  } else if(x0<=n/3) {
    f(i,1,n)
      if(col[i]) p[i]=p3, p3+=3;
      else {
        if(p1<=n) p[i]=p1, p1+=3;
        else if(p2<=n) p[i]=p2, p2+=3;
        else if(p3<=n) p[i]=p3, p3+=3;
      }
  } else if(y0<=n/3) {
    f(i,1,n)
      if(col[i]) {
        if(p1<=n) p[i]=p1, p1+=3;
        else if(p2<=n) p[i]=p2, p2+=3;
        else if(p3<=n) p[i]=p3, p3+=3;
      } else p[i]=p3, p3+=3;
  }
  f(i,1,n) printf("%d%c", p[i], " \n"[i==n]);
}
int x, y;
int main() {
  rd(n); f(i,1,n-1) { rd(x); rd(y); edge[x].push_back(y); edge[y].push_back(x); }
  dfs(1, -1, 1); solve();
  return 0;
}
/*
5
1 2
1 3
3 4
3 5

*/