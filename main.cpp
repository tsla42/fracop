#include <iostream>
using namespace std;

int gcd(int a, int b) {
  a=abs(a);
  b=abs(b);
  while (a>0 && b>0) {
    if (a>b) a=a%b; 
    else b=b%a;
  }
  return (a+b) ;
}

int main() {
  int N, a1, p1, a2, p2, ar, par;
  char oper;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> oper >> a1 >> p1 >> a2 >> p2 ;
    if ( (p1==0) || (p2==0) || (oper=='/' && a2==0) )
      cout << "error" << endl;
    else {
     switch (oper) {
      case '+':
        ar=a1*p2 + a2*p1;
        par=p1*p2;
      break;
    
      case '-' :
        ar=a1*p2 - a2*p1;
        par=p1*p2;
      break;

      case '*' :
        ar=a1*a2;
        par=p1*p2;
      break;

      case '/' :
        ar=a1*p2;
        par=p1*a2;
      break;
      }
      if (ar/par==0 && ((ar>0 && par <0) || (ar<0 && par>0)) )
      cout << -0 << " " << (abs(ar%par))/gcd(ar,par) << " " << (abs(par))/gcd(ar,par) << endl;
      else 
      cout << ar/par << " " << (abs(ar%par))/gcd(ar,par) << " " << (abs(par))/gcd(ar,par) << endl;
    }
  }
  return 0;
}