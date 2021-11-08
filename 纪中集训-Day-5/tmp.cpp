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
int L[2005][2005], id=0, N;
void work(pir p, pir q, pir r) {
  L[p.fir+N+1][p.sec+N]=L[q.fir+N+1][q.sec+N]=L[r.fir+N+1][r.sec+N]=++id;
}
void make(int n) {
  if(n==2) {
    work(mp(0, 0), mp(0, 1), mp(-1, 0));
    work(mp(0, 2), mp(1, 2), mp(1, 1));
    work(mp(0, -1), mp(1, -1), mp(1, 0));
    work(mp(-2, 0), mp(-2, -1), mp(-1, -1))
  } else if(n==1) {
    work(mp(0, 0), mp(1, 0), mp(0, 1));
  }
  make(n-1);
  if(n-2 % 3 == 0) {
    for(int i=0; i>=n-2; i-=3) {
      work() ;
    }
  }
}
int main() {
  
  return 0;
}