#include <iostream>
#include <stdlib.h>

#include "DNI.h"
#include "nodo.h"
#include "ABB.h"

using namespace std;


int main(){
    
    
    ABB<clave> arb; //GENERAMOS UN OBJETO DE TIPO ARBOL
    
    int op=0, cont=0;
    clave insertar_dato, eliminar_dato,buscar_dato;
    
        cout << "SELECCIONE LO QUE DESEE HACER:\n";
    
    do{
        
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Buscar\n";
        cout << "4. Salir\n";
        
        cout << "Opción elegida:";
        cin >> op;
        switch(op){
            
            case 1: 
                cout << "Dato que desea insertar:";
                cin >> insertar_dato;
                arb.insertar(insertar_dato);
                arb.imprimir();
                break;
            
            case 2:
                cout << "Dato que desea eliminar:";
                cin >> eliminar_dato;
                arb.eliminar(eliminar_dato);
                arb.imprimir();
                break;
                
            case 3:
                cout << "Dato que desea buscar:";
                cin >> buscar_dato;
                if(arb.buscar(buscar_dato) != NULL)
                    cout << "El dato que busca se encuentra en el árbol\n";
                else 
                    cout << "El dato que busca no se encuentra en el árbol\n";
                
                arb.imprimir();
                break;
            
            case 4: 
                cout << "Saliendo...\n";
                break;
                
            
            default:
                cerr << "OPCIÓN NO VÁLIDA\n";
                op=4;
        }
        
        
    } while (op != 4);
    
    cout << endl;
    
    
    
    
    
    
    
}