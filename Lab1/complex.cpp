//archivo complex.cpp - implementación de la clase
#include<iostream>
#include <math.h>
#include "complex.hpp"

Complex::Complex() //implemetación constructor por defecto (inicializa el número complejo  a 0.0 + i0.0)
{
    real = 0;
    imag = 0;
    //std::cout << "Se llamo al constructor por defecto" <<std::endl;
}
Complex::Complex(double a, double b) //implementación constructor personalizado
{
    //std::cout << "Se llamo al constructor persolalizado" <<std::endl;
    real = a;
    imag = b;
}
Complex::Complex(const Complex &z) //implemetación constructor de copia
{
    //std::cout << "Se llamo al constructor de copia" <<std::endl;
    real = z.real;
    imag = z.imag;
}
Complex &Complex::operator=(const Complex &z) //implementación operador de asignación
{
    //std::cout << "se llamo al operador de asignación" << std::endl;
    real = z.real;
    imag = z.imag;
    return *this;
}
Complex::~Complex() //implementación de destructor (vacio ya que la clase no maneja recursos)
{
    //std::cout << "se llamo al destructor" << std::endl;
    //delete [] ?;
}

//metodos de la clase
double Complex::norm() //implementación de calculo de norma
{
    return std::sqrt((real*real)+(imag*imag));
}
Complex Complex::conj() //función calcular conjugado
{
    return Complex(real, -1*imag);
}
void Complex::print () //funcion imprimir complex
{
    std::cout << real << " + " << imag <<"i"<<std::endl;
}

//implementacion de sobreacargas de operadores
Complex Complex::operator + (const Complex &z) //sobrecarga +
{
    //std::cout << "se llamo +" << std::endl;
    return Complex(real + z.real , imag + z.imag);
}
Complex Complex::operator - (const Complex &z) //sobrecarga -
{
    //std::cout << "se llamo -" << std::endl;
    return Complex(real - z.real , imag - z.imag);
}
Complex Complex::operator * (const Complex &z) //sobrecarga *
{
    //std::cout << "se llamo *" << std::endl;
    double a,b;
    a=real*z.real-imag*z.imag;
    b=real*z.imag+imag*z.real;
    return Complex(a, b);
}
Complex Complex::operator / (const Complex &z) //sobrecarga /
{
    //std::cout << "se llamo /" << std::endl;
    Complex deno = z;
    Complex nume (real,imag);
    Complex rdeno = deno*deno.conj();
    Complex rnume = nume*deno.conj();

    return Complex(rnume.real/rdeno.real,rnume.imag/rdeno.real);
}
