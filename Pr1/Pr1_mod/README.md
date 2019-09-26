#CYA Práctica 01

###Objetivos
Empleo de los paradigmas de la programación orientada a objetos

Formato propuesto para la escritura de programas en C++

Lectura y escritura de ficheros de texto  en C++

Compilación de programs utilizando make

Edición de ficeros utilizando el editor vim

###Enunciado práctica

Desarollar un programa cliente Racionales.cpp que permita operar con números
racionales y haga uso de la clase Racional que ha de diseñarse.

Especificaiones de este programa:

  Crear objetos del tipo Racional.(Constructor por defecto y parametrizado)

  Leer(por teclado o desde fichero) un objeto del tipo Racional

  Escribir (a fichero o a pantalla) un objeto de tipo Racional

  Sumar dos objetos de tipo Racional

  Restar dos objetos de tipo Racional

  Multiplicar dos objetos de tipo Racional

  Dividir dos objetos de tipo Racional

  Comparar objetos de tipo Racional

El programa a de permitir leer un fichero de texto en el que figuran pares de
números racionales  separados por espacios de la forma:
a/b c/d
e/f g/h

y para cada par de pares, el programa ha de imprimir en otro fichero de salida
todas las operaciones posibles con cada uno de los pares del fichero de 
entrada, de la forma:
a/b + c/d = n/m

Al ejecutarseen línea de comandos sin parámetros: ./Racionales el programa 
mostrará un texto de ayuda indicando la forma de ejecución del programa en
la que el usuario puede pasar como parámetros los nombres de los ficheros de 
entrada y salida que utiliza el programa.

Todo el código fuente ha de estar escrito de acuerdo a la guía de estilo de
google para C++. Prestando particular atención a formateo del código,
comentarios de código de diverso tipo, nominación de identificadores, clases,
ficheros, etc.

###Modificación

Aceptar ficheros de tres fraciones y comprobar si la tersera fracion es
resultado de las 2 anteriores en caso afirmativo imprimir dicha operacion
en el segundo fichero introducido


