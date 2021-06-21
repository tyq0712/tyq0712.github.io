#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define _ 1005
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
int n; ll c[_]; pair<ll, ll> tar[_]; char f[_][_];
ll func(ll x) {
  return x<0LL ? -x : x;
}
ll min(ll x, ll y) {
  return x<y ? x : y;
}
int main() {
  rd(n); f(i,1,n) { tar[i].fir=rd(); tar[i].sec=rd(); }
  int acc=(func(tar[1].fir + tar[1].sec))%2LL;
  f(i,2,n) if((func(tar[i].fir+tar[i].sec))%2LL!=acc) { puts("-1"); return 0; }
  puts("30");
  if(acc) {
    f(i,0,30) c[i+1]=1LL<<(ll)i; f(i,1,30) printf("%lld%c", c[i], " \n"[i==30]);
  } else {
    c[1]=1LL; f(i,1,30) c[i+1]=(1LL<<((ll)i-1LL)); f(i,1,30) printf("%lld%c", c[i], " \n"[i==30]);
  }
  // make |x| + |y| get less more
  f(i,1,n) {
    ll nx=tar[i].fir, ny=tar[i].sec;
    d(j,1,30) {
      // enum step j
      ll __10=func(nx-c[j]) + func(ny), _10=func(nx+c[j]) + func(ny), _01=func(nx) + func(ny+c[j]), _0_1=func(nx) + func(ny-c[j]);
      ll x=min(min(__10, _10), min(_01, _0_1));
      if(__10==x) { f[i][j]='R'; nx-=c[j]; }
      else if(_10==x) { f[i][j]='L'; nx+=c[j]; }
      else if(_01==x) { f[i][j]='D'; ny+=c[j]; }
      else { f[i][j]='U'; ny-=c[j]; }
    }
    f(j,1,30) printf("%c%c", f[i][j], " \n"[j==30]);
    // self check
    /*nx=0; ny=0;
    f(j,1,30) {
      if(f[i][j]=='L') nx-=c[j];
      if(f[i][j]=='R') nx+=c[j];
      if(f[i][j]=='U') ny+=c[j];
      if(f[i][j]=='D') ny-=c[j];
    }
    printf("chk : (%d, %d)\n", nx==tar[i].fir, ny==tar[i].sec);*/
  }
  return 0;
}