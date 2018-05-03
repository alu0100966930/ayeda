#include "DNI.h"

//---------------CONSTRUCTOR--------------------------


DNI::DNI(void)
{
    valor = 0;
}

DNI::DNI(int x)
{
    valor = x;
}

//--------------------DESTRUCTOR------------------------

DNI::~DNI()
{
    valor = 0;
}

int DNI::get_valor(){
    
    return valor;
}


//-----------------------SOBRECARGA DE OPERADORES------------------------------------

bool DNI::operator==(DNI &dni_)
{
    comparaciones++;
    // cout << "Comparaciones: " << comparaciones << endl;

    if(valor == dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator<(DNI &dni_)
{
    comparaciones++;
    // cout << "Comparaciones: " << comparaciones << endl;
    if(valor < dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator>(DNI &dni_)
{
    comparaciones++;
    // cout << "Comparaciones: " << comparaciones << endl;

    if(valor > dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator<=(DNI &dni_)
{
    comparaciones++;
    // cout << "Comparaciones: " << comparaciones << endl;
    if(valor <= dni_.get_valor())
        return true;
    else
        return false;
}

bool DNI::operator>=(DNI &dni_)
{
    comparaciones++;
    // cout << "Comparaciones: " << comparaciones << endl;

    if(valor >= dni_.get_valor())
        return true;
    else
        return false;
}

//Impresión
ostream& operator<<(ostream &salida,const DNI dni_)
{
    salida << dni_.valor;
    return salida;
}

void DNI::set_valor(int x)
{
    valor = x;    
}

//Lectura
istream& operator >>(istream& sin, DNI& dni_)
{
     int auxiliar = 0;
     sin >> auxiliar;
     dni_.set_valor(auxiliar);
     return sin;
}

int DNI::comparaciones = 0;



