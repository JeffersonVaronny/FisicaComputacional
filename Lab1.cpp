#include<iostream>
#include <math.h>
////////////////////////////////////
//declaracion clase - archivo: complex.hpp
////////////////////////////////////
class Complex 
{
    public:
        Complex();// constructor por defecto
        Complex(double a, double b); //constructor personalizado
        Complex(const Complex &z); // constructor de copia
        Complex &operator=(const Complex &z); //operador de asignación
        ~Complex();// destructor
        Complex operator + (const Complex &z); //sobrecarga +
        Complex operator - (const Complex &z); //sobrecarga -
        Complex operator * (const Complex &z); //sobrecarga *
        Complex operator / (const Complex &z); //sobrecarga /

        //atributos
        double real;
        double imag;

        //metodos
        double norm();//calcula la norma
        Complex conj();// calcula el conjugado
        void print();// imprime en la consola
};
//////////////////////////////////////////
//implementacion clase - archivo: complex.cpp
/////////////////////////////////////////
Complex::Complex()//implemetación constructor por defecto (inicializa el número complejo  a 0.0 + i0.0)
{
    real = 0;
    imag = 0;
    std::cout << "Se llamo al constructor por defecto" <<std::endl;
}
Complex::Complex(double a, double b)//implementación constructor personalizado
{
    std::cout << "Se llamo al constructor persolalizado" <<std::endl;
    real = a;
    imag = b;
}
Complex::Complex(const Complex &z)//implemetación constructor de copia
{
    std::cout << "Se llamo al constructor de copia" <<std::endl;
    real = z.real;
    imag = z.imag;
}
Complex &Complex::operator=(const Complex &z)//implementación operador de asignación
{
    std::cout << "se llamo al operador de asignación" << std::endl;
    real = z.real;
    imag = z.imag;
    return *this;
}
Complex::~Complex()//implementacion de destructor ( vacio ya que la clase no maneja recursos)
{
    //std::cout << "se llamo al destructor" << std::endl;
    //delete [] ?;
}

//metodos
double Complex::norm()//implementacin de calculo de norma
{
    return std::sqrt((real*real)+(imag*imag));
}
Complex Complex::conj()//función calcular conjugado
{
    Complex conj;
    conj.real= real;
    conj.imag = -1*imag;
    return conj;
}
void Complex::print ()//funcion imprimir
{
    std::cout << real << " + " << imag <<"i"<<std::endl;
}

//implementacion de sobreacargas de operadores
Complex Complex::operator + (const Complex &z)//sobrecarga +
{
    std::cout << "se llamo +" << std::endl;
    return Complex(real + z.real , imag + z.imag);
}
Complex Complex::operator - (const Complex &z)//sobrecarga -
{
    std::cout << "se llamo -" << std::endl;
    return Complex(real - z.real , imag - z.imag);
}
Complex Complex::operator * (const Complex &z)//sobrecarga *
{
    std::cout << "se llamo *" << std::endl;
    double a,b;
    a=real*z.real-imag*z.imag;
    b=real*z.imag+imag*z.real;
    return Complex(a, b);
}
Complex Complex::operator / (const Complex &z)//sobrecarga /
{
    std::cout << "se llamo /" << std::endl;
    Complex deno = z;
    Complex nume (real,imag);
    Complex rdeno = deno*deno.conj();
    Complex rnume = nume*deno.conj();

    return Complex(rnume.real/rdeno.real,rnume.imag/rdeno.real);
}
/////////////////////////////////////////////////////////////
//main - archivo: main.cpp
////////////////////////////////////////////////////////////
int main()
{
    Complex z0(3 , 5);
    Complex z1(2.2 , 3.1);
    z0.print();
    z1.print();
    std::cout<<z1.norm()<<std::endl;
    z0.conj().print();
    (z0 + z1).print();
    (z0 - z1).print();
    (z0 * z1).print();
    (z0 / z1).print();

    return 0;
}