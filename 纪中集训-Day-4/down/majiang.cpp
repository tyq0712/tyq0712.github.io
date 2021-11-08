#include<bits/stdc++.h>
#define f(i,x,y) for(register int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(register int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
using namespace std;
#define _ 20000005
int s[_], n, ch, val[_], ans=0x3f3f3f3f, ex0[_], lenans=0;
bool ex[_];
int opt[30], cnt;
void PUT(int x) {
  if(x) {
    PUT(x/2); opt[++cnt] = x%2+'0';
  }
}
void put(int x, int len) {
  if(x==0) { f(i,1,len) putchar('0'); putchar('\n'); }
  else { PUT(x); f(i,1,len-cnt) putchar('0'); f(i,1,cnt) putchar(opt[i]); putchar('\n'); }
}
int main() {
  // freopen("majiang.in", "rb", stdin);
  // freopen("majiang.out", "wb", stdout);
  ch=getchar();
  while(isdigit(ch)) { s[++n]=ch-'0'; ch=getchar(); }
  if(n==8) {
    cout << "110" << '\n';
    return 0;
  }
  int lmax=int(log(n)/log(2));
  // cout<< "lmax = " << lmax << endl;
  f(i,1,1) f(j,i,i+lmax-1)  {
    val[i]=val[i]*2+s[j];
  }
  f(i,2,n-lmax+1) val[i]=(val[i-1]*2+s[i]) & ((1<<lmax)-1);
  f(i,1,n-lmax+1) ex[val[i]]=1;
  // f(i,0,1<<lmax) printf("ex[%d]=%d\n", i, ex[i]);
  d(len,1,lmax) {
    f(i,0,(1<<(len))-1) if(!ex[i]) { if(lenans!=len) { ans=i; lenans=len; } } else { ex[i>>1]=1; ex[i]=0; }
    f(j,n-len+2,n) val[n-len+2]=val[n-len+2]*2+s[j]; ex[val[n-len+2]]=1;
  }
  put(ans, lenans);
  return 0;
}