#ifndef RACIONAL_H
#define RACIONAL_H
#include <iostream>

namespace CyA {
class Racional{
 public:
  Racional();

  Racional(int numerador, int denominador);

  Racional(const CyA::Racional &old_obj);

  ~Racional(){}

  std::istream& read(std::istream& is);
  std::ostream& write(std::ostream &os) const;

  Racional suma(CyA::Racional& operando2);
  Racional resta(CyA::Racional& operando2);
  Racional multiplicar(CyA::Racional& operando2);
  Racional dividir(CyA::Racional& operando2);

  Racional operator+(CyA::Racional& operando2);
  Racional operator-(CyA::Racional& operando2);//TODO CORREGIR ressultados negativos salen positivos y resultados positivos salen negativos 
  Racional operator*(CyA::Racional& operando2);
  Racional operator/(CyA::Racional& operando2);
  int get_numerador();
  int get_denominador();

 private:
 int numerador_;
 int denominador_;

 void Mcd();

};
  bool operator<(CyA::Racional& operando1, CyA::Racional& operando2);
  bool operator>(CyA::Racional& operando1, CyA::Racional& operando2);
  bool operator<=(CyA::Racional& operando1, CyA::Racional& operando2);
  bool operator>=(CyA::Racional& operando1, CyA::Racional& operando2);
  bool operator==(CyA::Racional& operando1, CyA::Racional& operando2);
  bool operator!=(CyA::Racional& operando1, CyA::Racional& operando2);
  std::ostream& operator<<(std::ostream &os, CyA::Racional const &obj);
  std::istream& operator>>(std::istream &is, CyA::Racional& obj);
}
#endif
