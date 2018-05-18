#include<iostream>
#include<stdlib.h>
#include<vector>

#include "DNI.h"
#include "nodo.h"
#include "AVL.h"

using namespace std;


//----------------------------COMPRIBACION-------------------------

template <class clave>
bool comprobacion(vector<clave> v_aleatorios, int valor)
{
  int contador = 0;
  bool encontrado = false;
  while(contador < v_aleatorios.size() && encontrado != true)
  {
    if(v_aleatorios[contador].get_valor() == valor)
    {
      encontrado = true;
    }
    contador++;
  }
  return encontrado;
}


//--------------------------INICIALIZACION------------------

template <class clave>
void inicializacion(vector<clave> &v, AVL<clave> &arbol_, int sz)
{
    v.resize(sz);
    for(int i=0;i<sz;i++)
    {
        srand(clock());
        int aux = 30000000 + rand()%(80000001-30000000);
        
        while(comprobacion(v,aux))
        {
            aux = 30000000 + rand()%(80000001-30000000);
        }
    
        DNI d(aux);
        v[i] = d;
        arbol_.insertar(d);
    }
}


bool comprobacion_pruebas(vector<int> v_aleatorios, int valor)
{
  int contador = 0;
  bool encontrado = false;
  while(contador < v_aleatorios.size() && encontrado != true)
  {
    if(v_aleatorios[contador] == valor)
    {
      encontrado = true;
    }
    contador++;
  }
  return encontrado;
}





void creacion(vector<int> &v, int limite_inferior, int limite_superior)
{
  for(int i=0;i<v.size();i++)
  {
      srand(clock());
      int aux_p = limite_inferior+rand()%(((limite_superior + 1 ) -1) -limite_inferior);
      while(comprobacion_pruebas(v,aux_p))
      {
         aux_p = limite_inferior+rand()%(((limite_superior + 1 ) -1) -limite_inferior);
      }
      v[i] = aux_p;
  }
}

int main(){
    
    vector<clave> muestra;
    vector<int> pruebas_busqueda;
    vector<int> pruebas_insercion;
    
    AVL<clave> arb;
    int num_nodos=0;
    int num_pruebas=0;
    
    cout << "Introduzcael número de nodos que desee[N]:";
    cin >> num_nodos;
    cout << "Introduzca el número de pruebas que desee[P]:";
    cin >> num_pruebas;
    
    inicializacion(muestra, arb, num_nodos*2);
    cout << endl;
    
    cout << "BÚSQUEDA\n";
    
    cout << "Genero vectores aleatorios\n";
    
    pruebas_busqueda.resize(num_pruebas);
    
    creacion(pruebas_busqueda,0,num_nodos);
    cout << endl;
    
    int maximo_busqueda = 0;
    int minimo_busqueda = 100000000;
    double suma_busqueda = 0;
    double media_busqueda = 0;
    
    DNI::comparaciones = 0;
    
    
     for(int i=0;i<num_pruebas;i++)
    {
      arb.buscar(muestra[pruebas_busqueda[i]]);
      
      //cout << "DNI::comparaciones: " << DNI::comparaciones << endl;
      if(maximo_busqueda<DNI::comparaciones)
        maximo_busqueda = DNI::comparaciones;
      
      if(minimo_busqueda>DNI::comparaciones)
        minimo_busqueda = DNI::comparaciones;
      
      suma_busqueda += DNI::comparaciones;
      DNI::comparaciones = 0;
    }
    
    media_busqueda = suma_busqueda / num_pruebas;
  
    cout << endl;
    cout << "-----------------------------" << endl;
    pruebas_insercion.resize(num_pruebas);
    
    cout << "Genero aleatorios para las pruebas." << endl;

    int maximo_insercion = 0;
    int minimo_insercion = 100000000;
    double suma_insercion = 0;
    double media_insercion = 0;
    
    
    creacion(pruebas_insercion,num_nodos,2*num_nodos);
    
    DNI::comparaciones = 0;
    for(int i=0;i<num_pruebas;i++)
    {
      arb.buscar(muestra[pruebas_insercion[i]]);
      
      //cout << "DNI::comparaciones: " << DNI::comparaciones << endl;
      if(maximo_insercion<DNI::comparaciones)
        maximo_insercion = DNI::comparaciones;
      
      if(minimo_insercion>DNI::comparaciones)
        minimo_insercion = DNI::comparaciones;
      
      suma_insercion += DNI::comparaciones;
      DNI::comparaciones = 0;
    }
    media_insercion = suma_insercion / num_pruebas;
    cout << endl;
    cout << "-----------------------------" << endl;

    cout << "ESTADISTICAS" << endl;
    cout << "\t\tN\tP\tMinimo\tMedio\tMaximo"<<endl;
    cout << "Busqueda\t"<<num_nodos<<"\t"<<num_pruebas<<"\t"<<minimo_busqueda<<"\t"<<media_busqueda<<"\t"<<maximo_busqueda<<endl;
    cout << "Insercion\t"<<num_nodos<<"\t"<<num_pruebas<<"\t"<<minimo_insercion<<"\t"<<media_insercion<<"\t"<<maximo_insercion<<endl;

    cout << endl;
    return 0;
    
    
}
