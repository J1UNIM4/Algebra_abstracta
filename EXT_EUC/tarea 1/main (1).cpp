#include <iostream>
using namespace std;
class EU{
  int a,a1,b1;
  public:
  int leer(void);
  void euclides(int a,int b,int*d,int*x,int*y);
  void ver(int x,int y,int d);
};
int EU::leer(void){
  a1=b1=0;
  cout<<"Digite numero"<<endl;
  cin>>a;
  return a;
}
void EU::euclides(int a,int b,int*d,int*x,int*y){
  long x1,y1;
  if(b==0){
    *d=a;
    *x=1;
    *y=0;
  }
  else{
    euclides(b,a%b,d,x,y);
    x1=*x;
    y1=*y;
    *x=y1;
    *y=x1-int((a/b))*y1;
  }
  a1=a;
  b1=b;
}

void EU::ver(int x,int y,int d){
  cout<<"ax + by = d"<<endl;
  cout<<a1<<"*"<<x<<" + "<<b1<<"*"<<y<<" = "<<d<<endl;
  cout<<"x = "<<x<<" , "<<"y = "<<y;
}

int main(){
  int a,b,d,x,y;
  EU e1;

  a=e1.leer();
  b=e1.leer();
  e1.euclides(a,b,&d,&x,&y);
  e1.ver(x,y,d);




  return 0;
}