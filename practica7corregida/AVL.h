#pragma once
#include <queue>
#include "nodo.h"
#include "DNI.h"

using namespace std;

typedef struct{
    
    nodo<clave>* n;
    int nivel;
    
} NODO_;

template<class clave>
class AVL{
    
    private:
    
        int num_niveles;
        int num_nodos;
        nodo<clave>* raiz;
        
    public:
    
        AVL();
        ~AVL();
        void insertar(clave x);
        void eliminar(clave x);
        nodo<clave>* buscar(clave x);
        void imprimir(void);
        void podar(nodo<clave>* &n);        //
        //void insertarRama(nodo<clave>* &n,clave x);
        void eliminarRama(nodo<clave>* &n, clave x, bool &decrece);        //
        void sustituye(nodo<clave>* &eliminado, nodo<clave>* &sustituto, bool &decrece);       //
        nodo<clave>* buscarRama(nodo<clave>* n, clave x);       //
        void imprimir2(nodo<clave>* n);     //
        
        
        //METODOS DE ROTACION
        
        void rotacion_II(nodo<clave>* &n);
        void rotacion_DD(nodo<clave>* &n);
        void rotacion_ID(nodo<clave>* &n);
        void rotacion_DI(nodo<clave>* &n);
    
        //INSERTAR
        
        void inserta_bal(nodo<clave>* &n, nodo<clave>* nuevo, bool &crece);
        void insert_re_balancea_izquierda(nodo<clave>* &n, bool &crece);
        void insert_re_balancea_derecha(nodo<clave>* &n, bool &crece);
    
        //ELIMINAR
        
        void eliminar_re_balancea_izquierda(nodo<clave>* &n, bool &decrece);
        void eliminar_re_balancea_derecha(nodo<clave>* &n, bool &decrece);
    
};

//-------------CONSTRUCTOR------------------


template <class clave>

AVL<clave>::AVL(){
    
    num_nodos=0;
    num_niveles=0;
    raiz=NULL;
    
}




//--------------------DESTRUCTOR-----------------

template <class clave>

AVL<clave>::~AVL(){
    
    podar(raiz);
    
}

template <class clave>

void AVL<clave>::podar(nodo<clave>* &n){
    
    if(n == NULL) return;
    podar(n->izq);
    podar(n->dcha);
    delete n;
    n=NULL;
    
}


//------------------------INSERTAR---------------------


template <class clave>

void AVL<clave>::insertar(clave x){
    
    nodo<clave>* nuevo = new nodo<clave>(x,0);
    bool crece = false;
    inserta_bal(raiz,nuevo,crece);
    
}

template <class clave>
void AVL<clave>::inserta_bal(nodo<clave>* &n,nodo<clave>* nuevo, bool &crece){
    
    if(n==NULL){
        
        n=nuevo;
        crece=true;
        
    }
    else{
        
        if(nuevo->dato < n->dato){
            inserta_bal(n->izq, nuevo, crece); 
            if(crece)
                insert_re_balancea_izquierda(n,crece);
        }
        else{
            inserta_bal(n->dcha,nuevo,crece);
            if(crece)
                insert_re_balancea_derecha(n,crece);
        }
    }
}

template <class clave>
void AVL<clave>::insert_re_balancea_izquierda(nodo<clave>* &n, bool &crece)
{
    switch(n->balanceo)
    {
        case -1:
            n->balanceo = 0;
            crece = false;
            break;
        
        case 0:
            n->balanceo = 1;
            break;
            
        case 1:
            {
            nodo<clave>* nodo1 = n->izq;
            if(nodo1->balanceo == 1)
                rotacion_II(n);
            else
                rotacion_ID(n);
            crece = false;
            break;
            }
        
        default: 
            cerr << "Error en cálculo de balanceo.\n";
    }
}


template <class clave>
void AVL<clave>::insert_re_balancea_derecha(nodo<clave>* &n, bool &crece)
{
    switch(n->balanceo)
    {
        case 1:
            n->balanceo = 0;
            crece = false;
            break;
         
        case 0:
            n->balanceo = -1;
            break;
        
        case -1:{
        
            nodo<clave>* nodo1 = n->dcha;
            if(nodo1->balanceo == -1)
                rotacion_DD(n);
            else
                rotacion_DI(n);
            crece = false;
            break;
        }
        
        default: 
            cerr << "Error en cálculo de balanceo.\n";
    }
}

//--------------------ELIMINAR--------------------


template <class clave>
void AVL<clave>::eliminar(clave x){
    
    bool decrece=false;
    eliminarRama(raiz,x,decrece);
    
}


template<class clave>

void AVL<clave>::sustituye(nodo<clave>* &eliminado, nodo<clave>* &sustituto, bool &decrece){
    
    if(sustituto->dcha !=NULL){
        
        sustituye(eliminado,sustituto->dcha, decrece);
        if(decrece)
            eliminar_re_balancea_derecha(sustituto,decrece);
        
    }else{
        
        eliminado->dato=sustituto->dato;
        eliminado=sustituto;
        sustituto=sustituto->izq;
        decrece=true;
    }
    
}

template <class clave>
void AVL<clave>::eliminar_re_balancea_izquierda(nodo<clave>* &n, bool &decrece)           /////////             
{
    switch(n->balanceo)
    {
        case -1: {
        
            nodo<clave>* nodo1 = n->dcha;
            if(nodo1->balanceo > 0)
                rotacion_DI(n);
            else
            {
                if(nodo1->balanceo == 0)
                    decrece = false;
                rotacion_DD(n);
            }
            break;
        }
        case 0:
            n->balanceo = -1;
            decrece = false;
            break;
        
        case 1:
            n->balanceo = 0;
            break;
        
        default: 
            cerr << "Error en cálculo de balanceo.\n";
            
    }
}


template <class clave>
void AVL<clave>::eliminar_re_balancea_derecha(nodo<clave>* &n, bool &decrece)  ///////
{
    switch(n->balanceo)
    {
        case 1: {
            nodo<clave>* nodo1 = n->izq;
            if(nodo1->balanceo < 0)
                rotacion_ID(n);
            else
            {
                if(nodo1->balanceo == 0)
                    decrece = false;
                rotacion_II(n);
            }
            break;
        }
        case 0:
            n->balanceo = 1;
            decrece = false;
            break;
        
        case -1:
            n->balanceo = 0;
            break;
        
        default: 
            cerr << "Error en cálculo de balanceo.\n";
    }
}

template <class clave>
void AVL<clave>::eliminarRama(nodo<clave>* &n, clave x, bool &decrece){
    
    if(n==NULL) return;
    
    if(x<n->dato){
        eliminarRama(n->izq,x,decrece);
    if(decrece)
        eliminar_re_balancea_izquierda(n,decrece);
        
    }else{
        
        if(x>n->dato){
            eliminarRama(n->dcha,x,decrece);
            if(decrece)
                eliminar_re_balancea_derecha(n,decrece);
            
        }else{
            
            nodo<clave>* eliminado=n;
            if(n->izq==NULL){
                n=n->dcha;
                decrece=true;
            }
            else{
                if(n->dcha == NULL){
                    n=n->izq;
                    decrece=true;
                }else{
                    sustituye(eliminado,n->izq,decrece);
                      if(decrece)
                        eliminar_re_balancea_izquierda(n,decrece);
                }
            }
            
            delete(eliminado);
        }
        
    }
}



//--------------------------------BUSCAR-------------------------------


template <class clave>

nodo<clave>* AVL<clave>::buscar(clave x){
    
    return buscarRama(raiz,x);
    
}
        
template <class clave>

nodo<clave>* AVL<clave>::buscarRama(nodo<clave>* n, clave x){
    
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
void AVL<clave>::imprimir(){
    
    if(raiz==NULL)
        cout << "EL ÁRBOL ESTA VACÍO\n";
    else
        imprimir2(raiz);
    
    cout << endl;
    
}


template <class clave>
void AVL<clave>::imprimir2(nodo<clave>* n){
    
    cout << "NÚMERO DE NODOS:" << num_nodos << "\n";
    
    queue<NODO_> q; //UTILIZAMOS UNA COLA PUESTO QUE NOS INTERESA HACER POP DEL PRIMER ELEMENTO (MAS COMPLICADO CON VECTOR)
    
    NODO_ raiz_;
    
    int nivel=0;
    int nivel_actual=0;
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



//-----------------------------------ROTACIONES------------------------


template <class clave>
void AVL<clave>::rotacion_II(nodo<clave>* &n)
{
    nodo<clave>* nodo1 = n->izq;
    n->izq = nodo1->dcha;
    nodo1->dcha = n;
    if(nodo1->balanceo == 1)
    {
        n->balanceo = 0;
        nodo1->balanceo = 0;
    }
    else
    {
        n->balanceo = 1;
        nodo1->balanceo = -1;
    }
    n = nodo1;
}


template <class clave>
void AVL<clave>::rotacion_DD(nodo<clave>* &n)
{
    nodo<clave>* nodo1 = n->dcha;
    n->dcha = nodo1->izq;
    nodo1->izq = n;
    if(nodo1->balanceo == -1)
    {
        n->balanceo = 0;
        nodo1->balanceo = 0;
    }
    else
    {
        n->balanceo = -1;
        nodo1->balanceo = 1;
    }
    n = nodo1;
}


template <class clave>
void AVL<clave>::rotacion_DI(nodo<clave>* &n)
{
    nodo<clave>* nodo1 = n->dcha;
    nodo<clave>* nodo2 = nodo1->izq;
    n->dcha = nodo2->izq;
    nodo2->izq = n;
    nodo1->izq = nodo2->dcha;
    nodo2->dcha = nodo1;
    if(nodo2->balanceo == 1)
        nodo1->balanceo = -1;
    else
        nodo1->balanceo = 0;
    if(nodo2->balanceo == -1)
        n->balanceo = 1;
    else
        n->balanceo = 0;
    nodo2->balanceo = 0;
    n = nodo2;
}


template <class clave>
void AVL<clave>::rotacion_ID(nodo<clave>* &nd)
{
    nodo<clave>* nodo1 = nd->izq;
    nodo<clave>* nodo2 = nodo1->dcha;
    nd->izq = nodo2->dcha;
    nodo2->dcha = nd;
    nodo1->dcha = nodo2->izq;
    nodo2->izq = nodo1;
    if(nodo2->balanceo == -1)
        nodo1->balanceo = 1;
    else
        nodo1->balanceo = 0;
    if(nodo2->balanceo == 1)
        nd->balanceo = -1;
    else
        nd->balanceo = 0;
    nodo2->balanceo = 0;
    nd = nodo2;
}

