#pragma once
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype>       // std::isdigit
#include <stdio.h>
#include <stdlib.h>


typedef DNI clave;

template<class clave>

class nodo{
    
    public:
        
        nodo();
        ~nodo();
        nodo(clave x, int bal);
        nodo(clave x, int cl, nodo<clave>* izquierda, nodo<clave>* derecha);
        clave get_dato(void);
        void set_dato(clave x);
    
        void set_izquierda(nodo<clave>* izquierda);
        void set_derecha(nodo<clave>* derecha);    
        
        nodo<clave>* get_izquierda();
        nodo<clave>* get_derecha();
        
        nodo<clave>* izq;
        nodo<clave>* dcha;
        clave dato;
        int balanceo;
        int clav;
        
};

//-------------------------CONSTRUCTOR-------------------------------

template <class clave>
nodo<clave>::nodo():izq(NULL),dcha(NULL){}



template <class clave>

nodo<clave>::nodo(clave x, int bal)
{
    dato = x;
    balanceo=bal;
    izq = NULL;
    dcha = NULL;
}



template <class clave>
nodo<clave>::nodo(clave x, int cl, nodo<clave>* izquierda, nodo<clave>* derecha)
{
    dato = x;
    izq = izquierda;
    dcha = derecha;
}


template <class clave>
nodo<clave>::~nodo()
{
    if(izq != NULL)
    {
        delete izq;
        izq = NULL;
    }
    if(dcha != NULL)
    {
        delete dcha;
        dcha = NULL;
    }
}

template <class clave>
clave nodo<clave>::get_dato(void)
{
    return dato;    
}


template <class clave>
void nodo<clave>::set_dato(clave x)
{
    dato = x;
}

template <class clave>
void nodo<clave>::set_izquierda(nodo<clave>* izquierda)
{
    izq = izquierda;
}

template <class clave>
void nodo<clave>::set_derecha(nodo<clave>* derecha)
{
    dcha = derecha;
}

template <class clave>
nodo<clave>* nodo<clave>::get_izquierda(void)
{
    return izq;
}

template <class clave>
nodo<clave>* nodo<clave>::get_derecha(void)
{
    return dcha;   
}
