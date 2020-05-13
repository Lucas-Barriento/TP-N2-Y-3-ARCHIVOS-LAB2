#include <iostream>
#include<cstring>
#include<ctime>
#include<cstdio>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "prototipos.h"
#include "platos.h"
#include "clientes.h"
#include "pedidos.h"
#include "configuracion.h"

int main(){
int opc;
    while(true)
    {
         setlocale(LC_ALL,"spanish");
        setColor(CYAN);
        cls();
        cout<<"MENÚ PRINCIPAL"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1) PLATOS"<<endl;
        cout<<"2) CLIENTES"<<endl;
        cout<<"3) PEDIDOS"<<endl;
        cout<<"4) REPORTES"<<endl;
        cout<<"5) CONFIGURACIÓN"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) SALIR DEL PROGRAMA"<<endl;

        cout<< "ingrese una opcion: "<<endl;
        cin>>opc;
        cls();
        switch (opc)
        {
        case 1:
            menu_platos();
            break;
        case 2:
            menu_clientes();
            break;
        case 3:
            menu_pedidos();
            break;
        case 4:

            break;
        case 5:
            menu_configuracion();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<< "opcion incorrecta"<<endl;
            break;
        }
        anykey();
    }
    return 0;
};


