#include <iostream>
#include "DNI.h"

using namespace std;

//---------------CONSTRUCTOR--------------------------


DNI::DNI(void)
{
    valor_ = 0;
    comparaciones=0;
}

DNI::DNI(int x): valor_(x){}

//--------------------DESTRUCTOR------------------------

DNI::~DNI()
{
    valor_ = 0;
}

int DNI::get_valor(){
    
    return valor_;
}


//-----------------------SOBRECARGA DE OPERADORES------------------------------------

bool DNI::operator==(DNI &dni_)
{
    comparaciones++;

    if(valor_ == dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator<(DNI &dni_)
{
    comparaciones++;
    if(valor_ < dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator>(DNI &dni_)
{
    comparaciones++;

    if(valor_ > dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator<=(DNI &dni_)
{
    comparaciones++;
    if(valor_ <= dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator>=(DNI &dni_)
{
    comparaciones++;

    if(valor_ >= dni_.get_valor())
        return true;
    else
        return false;
}

//Impresión
ostream& operator<<(ostream &salida,const DNI dni_)
{
    salida << dni_.valor_;
    return salida;
}

void DNI::set_valor(int x)
{
    valor_ = x;    
}

//Lectura
istream& operator >>(istream& sin, DNI& dni_)
{
     int auxiliar = 0;
     sin >> auxiliar;
     dni_.set_valor(auxiliar);
     return sin;
}

long int DNI::comparaciones = 0;
