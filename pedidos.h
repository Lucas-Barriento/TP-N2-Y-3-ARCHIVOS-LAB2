#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

void menu_pedidos(){
    anykey();
int opc;
pedido reg;
while(true){
    int cant_cargas=cant_pedidos();

cls();
setColor(LIGHTMAGENTA);
cout<<"MENÚ PEDIDOS"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) NUEVO PEDIDO"<<endl;
cout<<"2) MODIFICAR PEDIDO"<<endl;
cout<<"3) LISTAR PEDIDO POR ID"<<endl;
cout<<"4) LISTAR TODOS LOS PEDIDOS"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<"--------------------------------"<<endl;
cout<< "seleccione una opcion: "<<endl;
cin>>opc;
switch (opc)
{
case 1:
    if(cargar_pedido(&reg)==true){
        if(grabar_pedido(reg)==true){
               cout<< "nuevo pedido guardado"<<endl;
            }
            else{
            cout<< "no se pudo guardar el nuevo pedido"<<endl;
            }
        }
        else{
            cout<< "no se pudo cargar el nuevo pedido"<<endl;
        }
        break;
        case 2:
            if(cant_cargas>0)
            {
                if(modificar_pedido(reg)==true)
                {
                    cout<< "pedido modificado"<<endl;
                }
                else
                {
                    cout<< "error al modificar pedido"<<endl;
                }
            }
            else
            {
                cout<< "no hay pedidos cargados"<<endl;
            }
            break;
        case 3:
            if(cant_cargas>0)
            {
                listar_pedidosXid();
            }
            else
            {
                cout<< "no hay pedidos cargados"<<endl;
            }
            break;
        case 4:
            if(cant_cargas>0)
            {
                listar_pedidos_de_archivos(reg);
            }
            else
            {
                cout<< "no hay pedidos cargados"<<endl;
            }
            break;
case 0:
    return;
    break;
default:
    cout<< "opcion incorrecta"<<endl;
    break;
}
anykey();
}
}
bool cargar_pedido(pedido*reg){
    cls();
    cin.ignore();
    cout<< "ID generado automaticamente: ";
    reg->id=cant_pedidos()+1;
    cout<<reg->id<<endl;

    cout<< "ID cliente: ";
    cin>>reg->idcliente;
    if(buscar_id_cliente(reg->idcliente)<0){
        cout<< "id cliente invalido"<<endl;
        return false;
    }

    cout<< "ID plato: ";
    cin>>reg->idplato;
    if(buscar_id(reg->idplato)<0){
        cout<< "id plato invalido"<<endl;
        return false;
    }

    cout<< "cantidad: ";
    cin>>reg->cantidad;
    if(reg->cantidad<=0){
        cout<< "cantidad invalida"<<endl;
        return false;
    }

    cout<< "precio unitario: ";
    if(buscar_precio_plato(reg->idplato)<0){
        return false;
    }
    reg->precio_unitario=buscar_precio_plato(reg->idplato);

    cout<< "fecha: "<<endl;
    cout<< "dia: ";
    cin>>reg->fecha_pedido.dia;
    cout<< "mes: ";
    cin>>reg->fecha_pedido.mes;
    cout<< "año: ";
    cin>>reg->fecha_pedido.anio;
    if(validar_fecha(reg->fecha_pedido)==false){
            cout<< "fecha invalida"<<endl;
        return false;
    }

    cout<< "valoracion: ";
    cin>>reg->valoracion;
    if(reg->valoracion<0 || reg->valoracion>10){
        return false;
    }

    cout<< "estado: en curso";
    reg->estado=1;

    return true;
}
bool grabar_pedido(pedido reg){
FILE*p;
p=fopen(PATH_PEDIDO,"ab");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    return false;
}
fwrite(&reg,sizeof(pedido),1,p);
fclose(p);
cls();
return true;
}
bool modificar_pedido(pedido reg){
int id, opc;
    cout<< "ingrese un id: "<<endl;
    cin>>id;
    anykey();
    cls();
    int indice=buscar_id_pedido(id);
    if(indice>=0)
    {
        pedido reg=leer_pedido(indice);
        listar_pedidos(reg,0);
        switch (reg.estado)
        {
        case 1:
            cout<< "ingresar nuevo estado(2-completado, 3-cancelado): ";
                break;
        case 2:
            cout<< "ingresar nuevo estado(1-en curso, 3-cancelado): ";
                break;
        case 3:
            cout<< "ingresar nuevo estado(1-en curso, 2-completado): ";
                break;
        default:
            break;
        }
        cin>>opc;
        reg.estado=opc;
        if(sobreescribir_pedido(reg,indice)==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        cout<< "id no existente."<<endl;
        return false;
    }
    return true;
}
int buscar_id_pedido(int id){
FILE*p;
int i=0;
pedido reg;
p=fopen(PATH_PEDIDO,"rb");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    return -1;
}
while(fread(&reg,sizeof(pedido),1,p)==1){
    if(reg.id==id){
        fclose(p);
        return i;
    }
    i++;
}
return -2;
}
bool sobreescribir_pedido(pedido reg, int ind){
FILE*p;
bool escribir;
p=fopen(PATH_PEDIDO,"rb+");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
fseek(p,ind*sizeof(pedido),SEEK_SET);
escribir=fwrite(&reg,sizeof(pedido),1,p);
fclose(p);
return escribir;
}
struct pedido leer_pedido(int pos){///devuelve un registro
    pedido reg;
    FILE*p;
    p=fopen(PATH_PEDIDO,"rb");
    if(p==NULL){
        cout<< "no se pudo abrir el archivo"<<endl;
    }
    fseek(p,pos*sizeof(pedido),SEEK_SET);
    fread(&reg,sizeof(pedido),1,p);
    fclose(p);
    return reg;
    };
void listar_pedidos_de_archivos(pedido reg){
    cls();
    setColor(LIGHTBLUE);
    FILE*p;
    p=fopen(PATH_PEDIDO,"rb");
    if(p==NULL)
    {
        cout<< "no pudo abrir el archivo"<<endl;
        return;
    }
    else
    {
        int i=0;
        while(fread(&reg,sizeof(pedido),1,p)==1)
        {
                listar_pedidos(reg,i);
                i++;
        }
    }
    fclose(p);
}
void listar_pedidos(pedido reg, int c){
    if(c==0)
    {
        setColor(WHITE);
        cout<<"*======================================================================================================*"<<endl;
        cout<<"*ID  °  IDCLIENTE  °   ID PLATO   °  CANTIDAD  °  PRECIO  °    FECHA    °   VALORACION  °    ESTADO    *"<<endl;
        cout<<"*======================================================================================================*"<<endl;

            cout<<"*";
            gotoxy(2,4);
            cout<<reg.id;

            gotoxy(13,4);
            cout<<reg.idcliente;

            gotoxy(24,4);
            cout<<reg.idplato;

            gotoxy(41,4);
            cout<<reg.cantidad;

            gotoxy(51,4);
            cout<<reg.precio_unitario;

            gotoxy(64,4);
            cout<<reg.fecha_pedido.dia<< "/"<<reg.fecha_pedido.mes<< "/"<<reg.fecha_pedido.anio;

            gotoxy(81,4);
            cout<< reg.valoracion;

            gotoxy(92,4);
            switch (reg.estado){
            case 1:
                cout<< "en curso";
                break;
            case 2:
                cout<< "completado";
                break;
            case 3:
                cout<< "cancelado";
                break;
            default:
                break;
            }
            gotoxy(104,4);
            cout<< "*" <<endl;
        cout<<"*======================================================================================================*"<<endl;
        }
    else
    {
        setColor(WHITE);
            cout<<"*";
            gotoxy(2,4+c*2);
            cout<<reg.id;

            gotoxy(13,4+c*2);
            cout<<reg.idcliente;

            gotoxy(24,4+c*2);
            cout<<reg.idplato;

            gotoxy(41,4+c*2);
            cout<<reg
            .cantidad;

            gotoxy(51,4+c*2);
            cout<<reg.precio_unitario;

            gotoxy(64,4+c*2);
            cout<<reg.fecha_pedido.dia<< "/"<<reg.fecha_pedido.mes<< "/"<<reg.fecha_pedido.anio;

            gotoxy(81,4+c*2);
            cout<< reg.valoracion;

            gotoxy(92,4+c*2);
            switch (reg.estado){
            case 1:
                cout<< "en curso"<<endl;
                break;
            case 2:
                cout<< "completado"<<endl;
                break;
            case 3:
                cout<< "cancelado"<<endl;
                break;
            default:
                break;
            }
            gotoxy(104,4+c*2);
            cout<< "*" <<endl;
        cout<<"*======================================================================================================*"<<endl;
    }
}
int cant_pedidos(){
FILE*p;
int bytes;
p=fopen(PATH_PEDIDO,"ab");
if(p==NULL){
        return -1;
}
fseek(p,0,SEEK_END);
bytes=ftell(p);
int cantidad=bytes/sizeof(pedido);
fclose(p);

return cantidad;

}
int buscar_precio_plato(int id_plato){
FILE*p;
plato reg;
p=fopen(PATH_PLATO, "rb");
if(p==NULL){
    return-2;
}
while(fread(&reg,sizeof(plato),1,p)==1){
    if(reg.id==id_plato){
            fclose(p);
        return reg.valor_venta;
    }
}
fclose(p);
return -1;
}
void listar_pedidosXid(){
    cls();
    int id;
    cout<< "ingrese el id a listar: "<<endl;
    cin>>id;
    cls();
    int indice=buscar_id_pedido(id);
    if(indice>=0)
    {
        pedido reg=leer_pedido(indice);
        listar_pedidos(reg,0);
    }
    else
    {
        cout<< "no existe el id buscado"<<endl;
    }

    }
#endif // PEDIDOS_H_INCLUDED
