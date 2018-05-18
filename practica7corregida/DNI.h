#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;


class DNI{
    
    private: 
    
        int valor_;
    
    public:
    
        static long int comparaciones;
        DNI();
        DNI(int x);
        ~DNI();
        int get_valor();
        void set_valor(int x);
        
        
        //SOBRECARGA DE OPERADORES
        
        bool operator==(DNI &valor_);
        bool operator<(DNI &valor_);
        bool operator>(DNI &valor_);
        bool operator<=(DNI &valor_);
        bool operator>=(DNI &valor_);

        //Impresión
        friend ostream& operator <<(ostream &salida, const DNI dni_);
        friend istream& operator >>(istream& sin, DNI& n);
    
};