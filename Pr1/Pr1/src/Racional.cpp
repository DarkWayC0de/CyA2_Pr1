#include "Racional.h"
#include <algorithm>
#include <numeric>

//Public
CyA::Racional::Racional(): numerador_(0), denominador_(1){}

int CyA::Racional::get_numerador(){
  return numerador_;
}
int CyA::Racional::get_denominador(){
  return denominador_;
}

CyA::Racional::Racional(int numerador, int denominador)
    : numerador_(numerador),
      denominador_(denominador){
  Mcd();
}

CyA::Racional::Racional(const CyA::Racional &old_obj)
    : numerador_(old_obj.numerador_),
      denominador_(old_obj.denominador_){}

std::ostream& CyA::Racional::write(std::ostream& os) const{
  os<<numerador_;
  if (denominador_!=1)   os<<'/'<<denominador_;
  return os;
}

std::istream& CyA::Racional::read(std::istream& is){
  char barra;
  is>>numerador_>>barra>>denominador_;
  if (barra!='/') {
    exit(1);
  }
  Mcd();
  return is;
}

CyA::Racional CyA::Racional::suma(CyA::Racional& operando2){
  int mcm=std::lcm(this->denominador_,operando2.denominador_);
  int a,b; 
  a=operando2.numerador_*(mcm/operando2.denominador_);
  b=this->numerador_*(mcm/this->denominador_);
  Racional A(a+b,mcm);
  return A;
}
CyA::Racional CyA::Racional::operator+(CyA::Racional& operando2){
 return (this->suma(operando2));
}
CyA::Racional CyA::Racional::resta(CyA::Racional& operando2){
  int mcm=std::lcm(this->denominador_,operando2.denominador_);
  int a,b; 
  b=operando2.numerador_*(mcm/operando2.denominador_);
  a=this->numerador_*(mcm/this->denominador_);
  Racional A(a-b,mcm);
  return A;
}
CyA::Racional CyA::Racional::operator-(CyA::Racional& operando2){
 return (this->resta(operando2));
}
CyA::Racional CyA::Racional::multiplicar(CyA::Racional& operando2){
  Racional A(this->numerador_*operando2.numerador_,
             this->denominador_*operando2.denominador_);
  return A;
}
CyA::Racional CyA::Racional::operator*(CyA::Racional& operando2){
 return (this->multiplicar(operando2));
}

CyA::Racional CyA::Racional::dividir(CyA::Racional& operando2){
  Racional A(this->numerador_*operando2.denominador_,
             this->denominador_*operando2.numerador_);
  return A;
}
CyA::Racional CyA::Racional::operator/(CyA::Racional& operando2){
  return (this->dividir(operando2));
}

bool CyA::operator<(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  b=operando2.get_numerador()*(mcm/operando2.get_denominador());
  a=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a<b;
}
bool CyA::operator>(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  b=operando2.get_numerador()*(mcm/operando2.get_denominador());
  a=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a>b;
}
bool CyA::operator<=(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  b=operando2.get_numerador()*(mcm/operando2.get_denominador());
  a=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a<=b;
}
bool CyA::operator>=(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  b=operando2.get_numerador()*(mcm/operando2.get_denominador());
  a=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a>=b;
}
bool CyA::operator==(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  a=operando2.get_numerador()*(mcm/operando2.get_denominador());
  b=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a==b;
}
bool CyA::operator!=(CyA::Racional& operando1, CyA::Racional& operando2){
  int mcm=std::lcm(operando1.get_denominador(),operando2.get_denominador());
  int a,b; 
  a=operando2.get_numerador()*(mcm/operando2.get_denominador());
  b=operando1.get_numerador()*(mcm/operando1.get_denominador());
  return a!=b;
}

//Private
void CyA::Racional::Mcd(){
  int mxcd=std::__gcd(this->numerador_,this->denominador_);
  mxcd=std::abs(mxcd);
  this->denominador_/=mxcd;
  this->numerador_/=mxcd;
}


//OUT
std::istream& CyA::operator>>(std::istream &is, CyA::Racional& obj){
  obj.read(is);
  return is;
}
std::ostream& CyA::operator<<(std::ostream &os, CyA::Racional const &obj){
  obj.write(os);
  return os;
}
