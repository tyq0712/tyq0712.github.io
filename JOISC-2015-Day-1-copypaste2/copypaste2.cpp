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
#define _ 200005
int k, m, n; char str[_]; int a[_], b[_], c[_], p[_];
int main() {
  rd(k); rd(m); scanf("%s", str+1); rd(n); f(i,1,n) rd(a[i]), rd(b[i]), rd(c[i]);
  f(j,1,k) p[j]=j;
  d(i,1,n) {
    f(j,1,k) {
      if(p[j] <= c[i]) continue;
      else if(p[j] <= c[i] + b[i] - a[i]) p[j] = p[j]-c[i]+a[i];
      else p[j] = p[j] - (b[i] - a[i]);
    }
  }
  f(j,1,k) putchar(str[p[j]]);
  return 0;
}