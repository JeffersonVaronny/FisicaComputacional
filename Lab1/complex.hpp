//archivo complex.hpp - declaracón de clase
#ifndef COMPLEX_HPP
#define COMPLEXVI_HPP

class Complex
{
    public:
        Complex(); // constructor por defecto
        Complex(double a, double b); //constructor personalizado
        Complex(const Complex &z); // constructor de copia
        Complex &operator=(const Complex &z); //operador de asignación
        ~Complex(); // destructor
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
#endif
