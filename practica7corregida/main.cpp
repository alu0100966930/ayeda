#include <iostream>
#include <stdlib.h>

#include "DNI.h"
#include "nodo.h"
#include "AVL.h"

using namespace std;

int main(){
    
    AVL<clave> a;
    
    int op=0;
    clave nuevo_dato;
    clave eliminar_dato;
    
    cout << "¿Qué desea hacer?\n";
    
    do{
        
        cout << "1. Salir.\n";
        cout << "2. Insertar.\n";
        cout << "3. Eliminar.\n";
        
        cout << "Introduzca una opción: ";
        cin >> op;
        
        switch(op){
            
            case 1:
                cout << "Saliendo del programa...\n";
                break;
            
            case 2:
                cout << "Nodo que desea insertar:";
                cin >> nuevo_dato;
                a.insertar(nuevo_dato);
                a.imprimir();
                break;
                
            case 3:
                cout << "Nodo que desea eliminar: ";
                cin >> eliminar_dato;
                a.eliminar(eliminar_dato);
                a.imprimir();
                break;
                
            default:
                cerr << "Opción incorrecta.\n";
                op=1;
        }
    }while(op!=1);
    
    
    
    
    
}