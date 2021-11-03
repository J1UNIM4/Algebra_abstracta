#include <iostream>
using namespace std;

long pow(int b, int q){
  long potencia(1);
  for(int i=0;i<q;i++){
    potencia*=b;
  }
  return potencia;
}
bool repetidos(int* p,int dim){// 2 3 4 2
  bool rep(false);
  for(int i=0;i<dim-1;i++){

    for(int h=i+1;h<dim;h++){
      if(*(p+i)==*(p+h)){
        rep=true;
        break;
      }
    }
  }
  return rep;
}

int coprimos(int b,int* ptr){
  int i(0);
  int len(0);
  for(int h=2;h<100;h++)
  {

  for(i=2;i<b;i++){
    if(b%i==0&&h%i==0){
      break;
    }

  }
  if(i>=b){
    *ptr=h;ptr++;len++;
  }
  }
  return len;
}

class Raiz_P{
  int p,cont,q,serie[15];
  public:
    int get_p(){
      return p;
    }
    void leer(){
      cout<<"Ingrese un numero: ";
      cin>>p;
    }
    void sacar_raiz(int q){
      int exp(0);
      cont=0;
      for(int i=1;i<p-1;i++){
        exp=pow(q,i);
        serie[cont]=exp%p;

        if(serie[cont]==1||repetidos(serie,cont+1)==true){
          break;
        }
        cont++;
      }
       if(cont>=p-2){
        cout<<q<<" es raiz primitiva de "<<p<<endl;
      }
      else cout<<q<<" no es raiz primitiva de "<<p<<endl;
    }

};

int main(){
  bool encontrado(false);
  //inico del algoritmo
  
  Raiz_P p;
  p.leer();
  
  int list[100];
  int len=coprimos(p.get_p(),list);
  for(int i=0;i<len;i++){
    p.sacar_raiz(list[i]);
  }
  return 0;
}