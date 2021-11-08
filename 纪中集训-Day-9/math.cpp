#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
char ch;
unsigned int rd() {
  unsigned int f=1, x=0; ch=getchar();
  while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
  while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
  return x*f;
}
void rd(unsigned int& x) { x=rd(); }
using namespace std;
#define fopen(X) { freopen(#X".in", "rb", stdin); freopen(#X".out", "wb", stdout); }
#define _ 100005
unsigned int n, A[_], B[_], C[_], MinA, MaxA, MinB, MaxB, MinC, MaxC, All1=1, ans;
unsigned int ABS[_], acs[_], bcs[_], abcs[_], as[_], bs[_], cs[_];
int main() {
  fopen(math);
  rd(n); f(i,1,n) { rd(A[i]); All1=A[i]!=1 ? 0 : All1; } f(i,1,n) rd(B[i]); f(i,1,n) rd(C[i]);
  if(n<=2000) {
    cerr << "N \\leq 2000" << endl;
    f(l,1,n) {
      MinA=A[l]; MaxA=A[l]; MinB=B[l]; MaxB=B[l]; MinC=C[l]; MaxC=C[l];
      f(r,l,n) {
        MinA=min(MinA, A[r]); MaxA=max(MaxA, A[r]);
        MinB=min(MinB, B[r]); MaxB=max(MaxB, B[r]);
        MinC=min(MinC, C[r]); MaxC=max(MaxC, C[r]);
        ans += (MaxA-MinA)*(MaxB-MinB)*(MaxC-MinC);
      }
    }
    cout << ans << endl;
  } else if(All1) {
    cerr << "A is all 1" << endl;
    printf("0\n");
  } else {
    cerr << "A_l \\geq A_r" << endl; 
    d(i,1,n) {
      as[i]=as[i+1]+A[i];
      bs[i]=bs[i+1]+B[i];
      cs[i]=cs[i+1]+C[i];
      ABS[i]=ABS[i+1]+A[i]*B[i];
      acs[i]=acs[i+1]+A[i]*C[i];
      bcs[i]=bcs[i+1]+B[i]*C[i];
      abcs[i]=abcs[i+1]+A[i]*B[i]*C[i];
    }
    f(l,1,n) {
      ans += abcs[l];
      ans -= (n-l+1)*A[l]*B[l]*C[l];
      ans -= A[l]*bcs[l];
      ans -= B[l]*acs[l];
      ans -= C[l]*ABS[l];
      ans += A[l]*B[l]*cs[l];
      ans += A[l]*C[l]*bs[l];
      ans += B[l]*C[l]*as[l];
    }
    cout << ans << endl;
  }
  return 0;
}