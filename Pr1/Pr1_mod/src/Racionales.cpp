#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include "Racional.h"

#include<algorithm>

void extraer_num(int a[], std::string cadena);
void comando_desconocido_ayuda();
void operaciones(std::ostream &os, CyA::Racional &A, CyA::Racional &B);
void operacionespara3(std::ostream &os, CyA::Racional &A, CyA::Racional &B, CyA::Racional &C);

int main(int argc, char *argv[]){
  switch(argc){
    case 2:{
        std::string namedoc =argv[1]; 
        std::ifstream readfile (namedoc);
        if (readfile.is_open()){
          CyA::Racional A;
          CyA::Racional B;
          while (!readfile.eof()){
            readfile>>A;
            readfile>>B;
            operaciones(std::cout,A,B);
          }
          readfile.close();
        } else {
          std::cout<<"Error, no Se ha podido abrir el archivo "<<
                     argv[1]<<
                     " para adquirir los datos.\n";
          comando_desconocido_ayuda();
        }
    }
      break;
    case 3:{
      std::string argumento1 =argv[1];
      if(std::isdigit(argumento1[0])==std::isdigit(argumento1[argumento1.size()])){
        std::string namedoc =argv[2]; 
        std::ofstream writefile (namedoc);
        namedoc =argv[1]; 
        std::ifstream readfile (namedoc);
        if (readfile.is_open()){
          if(writefile.is_open()){
            CyA::Racional A;
            CyA::Racional B;
            CyA::Racional C;
            while (!readfile.eof()){
              readfile>>A;
              readfile>>B;
              readfile>>C;
              operacionespara3(writefile,A,B,C);
              writefile<<std::endl;
            }
	  writefile.close();
        } else{           
          std::cout<<"Error, no se ha podido abrir o crear el archivo "<<
                     argv[2]<<
                     " para adquirir los datos.\n";
          comando_desconocido_ayuda();
        }
	readfile.close();
        } else {
          std::cout<<"Error, no Se ha podido abrir el archivo "<<
                     argv[1]<<
                     " para adquirir los datos.\n";
          comando_desconocido_ayuda();
        }
      } else {
        std::string cadena = argv[1];
        int num[2];
        extraer_num(num,cadena);
        CyA::Racional A(num[0],num[1]);
        cadena = argv[2];
        extraer_num(num,cadena);
        CyA::Racional B(num[0],num[1]);
        operaciones(std::cout,A,B);
      }
    }
      break;  
    case 4:{
      std::string cadena = argv[1];
      int num[2];
      extraer_num(num,cadena);
      CyA::Racional A(num[0],num[1]);
      cadena = argv[2];
      extraer_num(num,cadena);
      CyA::Racional B(num[0],num[1]);
      std::string namedoc =argv[3]; 
      std::ofstream writefile (namedoc);
      if(writefile.is_open()){
        operaciones(writefile,A,B);
	writefile.close();
      } else {
        std::cout<<"Error, no se ha podido abrir o crear el archivo "<<
                   argv[2]<<
                   " para adquirir los datos.\n";
        comando_desconocido_ayuda(); 
      }
    }
      break; 
  }
  return 0;
}

void extraer_num(int num[], std::string cadena){
      std::string delimitar = "/";
      size_t pos = 0 ;
      std::string numerocadena;
      int i=0;
      while(pos=cadena.find(delimitar)!=std::string::npos){
        numerocadena=cadena.substr(0,pos);
        num[i]=std::stoi(numerocadena);
        cadena.erase(0,pos+delimitar.length());
        i++;
      }
      num[1]=std::stoi(cadena);
}

void comando_desconocido_ayuda(){
  std::cout<<"Comando desconocido.\n\n"<<
             "---------------------------------------------------------\n"<<
             "Para el correcto funcionamiento del programa se tiene que\n"<<
             "usar el siguiente comando \"./Racional\" seguido de dos\n"<<
             "numeros en formato racional n/d o un archivo con los\n"<<
             "datos. En caso de querer guardar la salida en un fichero\n"<<
             "introduce dos ficheros o dos numeros en el formato\n"<<
             "explicado anteriormente y el fichero destino de la salida\n"<<
             "---------------------------------------------------------\n"<<
             "Ejemplos de uso.\n"<<
             "./Racional 4/5 2/9\n"<<
             "./Racional doc_datos\n"<<
             "./Racional 4/5 2/9 doc_salida\n"<<
             "./Racional doc_datos doc_salida\n"<<
             "---------------------------------------------------------\n";
}
void operaciones(std::ostream &os, CyA::Racional &A, CyA::Racional &B){
  os<<"Se han introducido los numeros "<<A<<" y "<<B<<"\n"<<
      "Operacion suma "<<A<<" + "<<B<<" = "<<A+B<<"\n"<<
      "Operacion resta "<<A<<" - "<<B<<" = "<<A-B<<"\n"<<
      "Operacion multiplicacion "<<A<<" * "<<B<<" = "<<A*B<<"\n"<<
      "Operacion divicion "<<A<<" / "<<B<<" = "<<A/B<<"\n";
}
void operacionespara3(std::ostream &os, CyA::Racional &A, CyA::Racional &B,CyA::Racional &C){
  CyA::Racional D;
  D=A+B;
  if(D==C){
    os<<"Operacion suma "<<A<<" + "<<B<<" = "<<A+B<<"\n";
  } else {
    D=A-B;
    if (D==C){
      os<< "Operacion resta "<<A<<" - "<<B<<" = "<<A-B<<"\n";
    } else{
      D=A*B; 
      if (D==C){
        os<<"Operacion multiplicacion "<<A<<" * "<<B<<" = "<<A*B<<"\n";
      } else {
        D=A/B;
        if (D==C) {
          os<< "Operacion divicion "<<A<<" / "<<B<<" = "<<A/B<<"\n";
        }
      }
    }
  }
}
