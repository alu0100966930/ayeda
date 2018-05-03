#pragma once
#include <queue>
#include "nodo.h"
#include "DNI.h"

typedef struct{
    
    nodo<clave>* n;
    int nivel;
    
} NODO_;

template<class clave>

class ABB{
    
    private:
    
        int num_niveles;
        int num_nodos;
        nodo<clave>* raiz;
        
    public:
    
        ABB();
        ~ABB();
        void insertar(clave x);
        void eliminar(clave x);
        nodo<clave>* buscar(clave x);
        void imprimir(void);
        void podar(nodo<clave>* &n);
        void insertarRama(nodo<clave>* &n,clave x);
        void eliminarRama(nodo<clave>* &n, clave x);
        void sustituye(nodo<clave>* &eliminado, nodo<clave>* &sustituto);
        nodo<clave>* buscarRama(nodo<clave>* n, clave x);
        void imprimir2(nodo<clave>* n);
    
};

//-------------CONSTRUCTOR------------------


template <class clave>

ABB<clave>::ABB(){
    
    num_nodos=0;
    num_niveles=0;
    raiz=NULL;
    
}




//--------------------DESTRUCTOR-----------------

template <class clave>

ABB<clave>::~ABB(){
    
    podar(raiz);
    
}

template <class clave>

void ABB<clave>::podar(nodo<clave>* &n){
    
    if(n == NULL) return;
    podar(n->izq);
    podar(n->dcha);
    delete n;
    n=NULL;
    
}


//------------------------INSERTAR---------------------


template <class clave>

void ABB<clave>::insertar(clave x){
    
    insertarRama(raiz,x);
    
}

template <class clave>
void ABB<clave>::insertarRama(nodo<clave>* &n, clave x){
    
    if(n==NULL){
        
        n=new nodo<clave>(x);
        num_nodos++;
        
    }
    else{
        
        if(x<n -> dato)
            insertarRama(n->izq,x);   
        else 
            insertarRama(n->dcha,x);
        
    }
}


//--------------------ELIMINAR--------------------


template <class clave>
void ABB<clave>::eliminar(clave x){
    
    eliminarRama(raiz,x);
    
}


template<class clave>

void ABB<clave>::sustituye(nodo<clave>* &eliminado, nodo<clave>* &sustituto){
    
    if(sustituto->dcha !=NULL)
        sustituye(eliminado,sustituto->dcha);
    else{
        
        eliminado->dato=sustituto->dato;
        eliminado=sustituto;
        sustituto=sustituto->izq;
    }
    
}


template <class clave>
void ABB<clave>::eliminarRama(nodo<clave>* &n, clave x){
    
    if(n==NULL) return;
    
    if(x<n->dato)
        eliminarRama(n->izq,x);
    else{
        
        if(x>n->dato)
            eliminarRama(n->dcha,x);
        else{
            
            nodo<clave>* eliminado=n;
            if(n->dcha==NULL)
                n=n->izq;
            else{
                if(n->izq == NULL)
                    n=n->dcha;
                else
                    sustituye(eliminado,n->izq);
            }
            
            delete(eliminado);
        }
        
    }
}



//--------------------------------BUSCAR-------------------------------


template <class clave>

nodo<clave>* ABB<clave>::buscar(clave x){
    
    return buscarRama(raiz,x);
    
}
        
template <class clave>

nodo<clave>* ABB<clave>::buscarRama(nodo<clave>* n, clave x){
    
    if(n==NULL)
        return NULL;
    if(x==n->dato)
        return n;
    if(x < n->dato)
        return buscarRama(n->izq, x);
    return buscarRama(n->dcha,x);
    
}




//-------------------------------IMPRIMIR---------------------------------------

template <class clave>

void ABB<clave>::imprimir(){
    
    if(raiz==NULL)
        cout << "EL ÁRBOL ESTA VACÍO\n";
    else
        imprimir2(raiz);
    
    cout << endl;
    
}


template <class clave>


void ABB<clave>::imprimir2(nodo<clave>* n){
    
    cout << "NÚMERO DE NODOS:" << num_nodos << "\n";
    
    queue<NODO_> q; //UTILIZAMOS UNA COLA PUESTO QUE NOS INTERESA HACER POP DEL PRIMER ELEMENTO (MAS COMPLICADO CON VECTOR)
    
    NODO_ raiz_;
    
    int nivel=0;
    int nivel_actual=0;
    bool fin=false;
    NODO_ nodo_actual;
    
    raiz_.n=raiz;
    raiz_.nivel=0;
    q.push(raiz_);
    cout << "Nivel " << nivel_actual << ":\t";
    while(!q.empty()){
        
        nodo_actual=q.front();
        q.pop();
        
        if(nodo_actual.nivel>nivel_actual){
            
            nivel_actual=nodo_actual.nivel;
            cout<<endl;
            cout << "Nivel " << nivel_actual << "\t";
            
        }
        
        if(nodo_actual.n != NULL){
            
            cout << (nodo_actual.n)->dato << "\t";
            
            NODO_ hizq;
            NODO_ hdcha;
            
            if((nodo_actual.n)->izq != NULL)
                hizq.n=(nodo_actual.n)->izq;
            else
                hizq.n=NULL;
            if((nodo_actual.n)->dcha != NULL)
                hdcha.n=(nodo_actual.n)->dcha;
            else
                hdcha.n=NULL;
            
            hizq.nivel=nivel_actual+1;
            hdcha.nivel=nivel_actual+1;
            q.push(hizq);
            q.push(hdcha);
            
        }
        else
            cout << "[.]" << "\t";
    }
    
    
}








