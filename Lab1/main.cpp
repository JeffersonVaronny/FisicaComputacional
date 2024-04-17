//archivo main.cpp - el main
#include<iostream>
#include "complex.hpp"

int main()
{
    Complex z0(3 , 5); //construlle numero complejo z0
    Complex z1(2.2 , 3.1); //construlle numero complejo z1
    std::cout<<"z0= ";
    z0.print(); //muestra complejo
    std::cout<<"z1= ";
    z1.print(); //muestra complejo
    std::cout<<"norma z1 = ";
    std::cout<<z1.norm()<<std::endl; //calcula y muestra la norma
    std::cout<<"conjugado z0 = ";
    z0.conj().print(); //calcula y muestra el conjugado
    std::cout<<"z0 + z1 = ";
    (z0 + z1).print(); //suma de complejos
    std::cout<<"z0 - z1 = ";
    (z0 - z1).print(); //resta de complejos
    std::cout<<"z0 * z1 = ";
    (z0 * z1).print(); //producto de complejos
    std::cout<<"z0 / z1 = ";
    (z0 / z1).print(); //divición de complejos

    return 0;
}
