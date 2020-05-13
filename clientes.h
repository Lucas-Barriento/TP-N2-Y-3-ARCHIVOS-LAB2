#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

void menu_clientes(){
    anykey();
    int opc;
    cliente reg;
    while(true){
        int cant_cargas=cant_clientes();
    cls();
    setColor(YELLOW);
cout<< "MENÚ CLIENTES"<<endl;
cout<< "--------------------------------"<<endl;
cout<< " 1) NUEVO CLIENTE"<<endl;
cout<< " 2) MODIFICAR CLIENTE"<<endl;
cout<< " 3) LISTAR CLIENTE POR ID"<<endl;
cout<< " 4) LISTAR TODOS LOS CLIENTES"<<endl;
cout<< " 5) ELIMINAR CLIENTE"<<endl;
cout<< " 0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<< "--------------------------------"<<endl;
cout<< "seleccione una opcion: "<<endl;
cin>>opc;
    switch (opc)
    {
    case 1:
        if(cargar_cliente(&reg)==true){
            if(grabar_cliente(reg)==true){
                cout<< "nuevo cliente guardado"<<endl;
            }
            else{
            cout<< "no se pudo guardar el nuevo cliente"<<endl;
            }
        }
        else{
            cout<< "no se pudo cargar el nuevo cliente"<<endl;
        }
        break;
    case 2:
        if(cant_cargas>0){
        if(modificar_cliente()==true){
            cout<< "cliente modificado"<<endl;
        }
        else{
            cout<< "error al modificar cliente"<<endl;
        }
        }
        else{
            cout<< "no hay clientes cargados"<<endl;
        }
        break;
    case 3:
                if(cant_cargas>0){
        listar_clientesXid();
                }
                else{
                    cout<< "no hay clientes cargados"<<endl;
                }

        break;
    case 4:
                if(cant_cargas>0){
        mostrar_clientes_ordenados();
                }
                else{
                    cout<< "no hay clientes cargados"<<endl;
                }
        break;
    case 5:
                if(cant_cargas>0){
        if(eliminar_cliente()==true){
            cout<< "cliente eliminado"<<endl;
        }
        else{
            cout<< "no se pudo eliminar el producto"<<endl;
        }
                }
                else{
                    cout<< "no hay clientes cargados"<<endl;
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
        cin.ignore();
    }
}
bool cargar_cliente(cliente*reg){
    cls();
    cin.ignore();
    cout<< "ID generado automaticamente: ";
    reg->id=cant_clientes()+1;
    cout<< reg->id<<endl;

    cout<< "ingrese el nombre: ";
    anykey();
    cin.getline(reg->nombre,50);
    if(strcmp(reg->nombre,"\0")==0){
        cout<< "nombre invalido"<<endl;
        return false;
    }

    cout<< "ingrese el apellido: ";
    anykey();
    cin.getline(reg->apellido,50);
    if(strcmp(reg->apellido, "\0")==0){
        cout<< "apellido invalido"<<endl;
        return false;
    }

    cout<< "ingrese el mail: ";
    anykey();
    cin.getline(reg->mail,50);
    if(validar_mail(reg->mail)==false){
        cout<< "mail invalido"<<endl;
        return false;
    }
    cout<< "ingrese el domicilio: ";
    anykey();
    cin.getline(reg->domicilio,50);
    if(strcmp(reg->domicilio,"\0")==0){
        cout<< "domicilio invalido"<<endl;
        return false;
    }
    cout<< "ingrese el CP: ";
    cin>>reg->cp;
    if(reg->cp<1000 || reg->cp>9999){
        cout<< "codigo postal invalido"<<endl;
        return false;
    }

    cout<< "ingrese la fecha de nacimiento: "<<endl;
    cout<< "dia: ";
    cin>>reg->cargar_fecha.dia;
    cout<< "mes: ";
    cin>>reg->cargar_fecha.mes;
    cout<< "año: ";
    cin>>reg->cargar_fecha.anio;
    if(validar_fecha(reg->cargar_fecha)==false){
            cout<< "fecha invalida"<<endl;
        return false;
    }

    reg->estado=true;

    return true;
}
bool grabar_cliente(cliente reg){
FILE*p;
p=fopen(PATH_CLIENTE,"ab");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    return false;
}
fwrite(&reg,sizeof(cliente),1,p);
fclose(p);
cls();
return true;
}
void listar_clientes(cliente reg, int c){
    if(c==0)
    {
        setColor(WHITE);
        cout<<"*================================================================================================================================*"<<endl;
        cout<<"*ID  ° NOMBRE        °    APELLIDO       °             MAIL                °      DOMICILIO         °    CP    °    FECHA NAC.   *"<<endl;
        cout<<"*================================================================================================================================*"<<endl;
        if(reg.estado==true)
        {

            cout<<"*";
            gotoxy(2,4);
            cout<<reg.id;

            gotoxy(8,4);
            cout<<reg.nombre;

            gotoxy(27,4);
            cout<<reg.apellido;

            gotoxy(49,4);
            cout<<reg.mail;

            gotoxy(79,4);
            cout<<reg.domicilio;

            gotoxy(105,4);
            cout<<reg.cp;

            gotoxy(117,4);
            cout<<reg.cargar_fecha.dia<< "/"<<reg.cargar_fecha.mes<< "/"<<reg.cargar_fecha.anio;

            gotoxy(130,4);
            cout<< "*" <<endl;
            cout<<"*================================================================================================================================*"<<endl;
        }
    }
    else
    {
        setColor(WHITE);
        if(reg.estado==true)
        {
            cout<<"*";
            gotoxy(2,4+c*2);
            cout<<reg.id;

            gotoxy(8,4+c*2);
            cout<<reg.nombre;

            gotoxy(27,4+c*2);
            cout<<reg.apellido;

            gotoxy(49,4+c*2);
            cout<<reg.mail;

            gotoxy(79,4+c*2);
            cout<<reg.domicilio;

            gotoxy(105,4+c*2);
            cout<<reg.cp;

            gotoxy(117,4+c*2);
            cout<<reg.cargar_fecha.dia<< "/"<<reg.cargar_fecha.mes<< "/"<<reg.cargar_fecha.anio;

            gotoxy(130,4+c*2);
            cout<< "*" <<endl;
            cout<<"*================================================================================================================================*"<<endl;
        }
    }
}
void listar_clientesXid(){
    cls();
    int id;
    cout<< "ingrese el id a listar: "<<endl;
    cin>>id;
    cls();
    int indice=buscar_id_cliente(id);
    if(indice>=0)
    {
        cliente reg=leer_cliente(indice);
        if(reg.estado==true){
        listar_clientes(reg,0);
        }
        else{
        cout<< "no existe el id buscado"<<endl;
        }
    }
    else
    {
        cout<< "no existe el id buscado"<<endl;
    }
    }
struct cliente leer_cliente(int pos){
    cliente reg;
    FILE*p;
    p=fopen(PATH_CLIENTE,"rb");
    if(p==NULL){
        cout<< "no se pudo abrir el archivo"<<endl;
    }
    fseek(p,pos*sizeof(cliente),SEEK_SET);
    fread(&reg,sizeof(cliente),1,p);
    fclose(p);
    return reg;
    };
bool modificar_cliente(){
int id;
    cout<< "ingrese un id: "<<endl;
    cin>>id;
    anykey();
    cls();
    int indice=buscar_id_cliente(id);
    if(indice>=0)
    {
        cliente reg=leer_cliente(indice);
        listar_clientes(reg,0);
        cout<< "ingrese el nuevo domicilio: ";
        anykey();
        cin.getline(reg.domicilio,50);
        if(sobreescribir_cliente(reg,indice)==true)
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
int buscar_id_cliente(int id){
FILE*p;
int i=0;
cliente reg;
p=fopen(PATH_CLIENTE,"rb");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    return -1;
}
while(fread(&reg,sizeof(cliente),1,p)==1){
    if(reg.id==id){
            if(reg.estado==true){
        fclose(p);
        return i;
            }
    }
    i++;
}
return -2;
}
bool sobreescribir_cliente(cliente reg, int ind){
FILE*p;
bool escribio;
p=fopen(PATH_CLIENTE,"rb+");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
fseek(p,ind*sizeof(cliente),SEEK_SET);
escribio=fwrite(&reg,sizeof(cliente),1,p);
fclose(p);
return escribio;/// devuelve 0 o 1
}
bool eliminar_cliente(){
cls();
int id;
cliente reg;
cout<< "ingrese el id a eliminar"<<endl;
cin>>id;
cls();
int indice=buscar_id_cliente(id);
if(indice<0){
    cout<< "id no existente"<<endl;
    return false;
}
reg=leer_cliente(indice);
listar_clientes(reg,0);
reg.estado=false;
if(sobreescribir_cliente(reg,indice)==false){
        return false;
}
return true;
}
int cant_clientes(){
FILE*p;
int bytes;
p=fopen(PATH_CLIENTE,"ab");
if(p==NULL){
        return -1;
}
fseek(p,0,SEEK_END);
bytes=ftell(p);
int cantidad=bytes/sizeof(cliente);
fclose(p);

return cantidad;
}
bool validar_mail(char*mail){
if (strchr(mail,'@')==NULL){/// tener arroba/s
    return false;
}

if(strchr(mail,'.')==0){/// tener punto/s
    return false;
}
int i=0,cont=0;
while(mail[i]!='\0'){
    if(mail[i]=='@'){
        cont++;
    }
    i++;
}
if(cont>1){/// tener un solo arroba
    return false;
}

int tam=strlen(mail);/// no empezar ni terminar con @ o .
if(mail[0]=='@' || mail[tam-1]=='@' || mail[0]=='.' || mail[tam-1]=='.'){
    return false;
}

int j=0;
while(mail[j]!='\0'){/// no tener dos puntos seguidos
    if(mail[j]=='.'){
        if(mail[j+1]=='.'){
            return false;
        }
    }
    j++;
}
return true;
}
void mostrar_clientes_ordenados(){
cls();
int cantidad=cant_clientes();
cliente*vec;
///solicitar el espacio de memoria
vec=(cliente*)malloc(cantidad*sizeof(cliente));
if(vec==NULL){
    cout<< "sin memoria"<<endl;
    return;
}
///abrir el archivo
FILE*p;
p=fopen(PATH_CLIENTE,"rb");
if(p==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
    free(vec);
    return;
}
///leer archivo y ordenar
fread(&vec[0],sizeof(cliente),cantidad,p);
fclose(p);
ordenar_clientes(vec,cantidad);

///mostrar
int j=0;
for (int i=0;i<cantidad ;i++ ){
        if(vec[i].estado==true){
    listar_clientes(vec[i],j);
    j++;
        }
}

free(vec);
}
void ordenar_clientes(cliente*reg, int cant){
    cliente aux;
    for(int x=0;x<cant;x++){
        for (int y=0;y<cant-1 ;y++ ){
            if(strcmp(reg[y].apellido,reg[y+1].apellido)>0){
                aux=reg[y];
                reg[y]=reg[y+1];
                reg[y+1]=aux;
            }
        }

    }
}
bool validar_fecha(fecha fecha_nac){
time_t t;
t=time(NULL);
struct tm*fec;
fec= localtime(&t);

if(fecha_nac.anio>=(fec->tm_year+1900)){
    return false;
}
else{
    switch (fecha_nac.mes)
    {
    case 1:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 2:
        if(fecha_nac.anio%4==0 && fecha_nac.anio%100==0 && fecha_nac.anio%400==0){
            if(fecha_nac.dia>=1 && fecha_nac.dia<=28){
                return true;
            }
            else{
                return false;
            }
}
else{
    if(fecha_nac.dia>=1 && fecha_nac.dia<=29){
        return true;
    }
    else{
        return false;
    }
}
        break;
    case 3:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 4:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 5:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 6:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 7:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 8:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 9:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 10:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    case 11:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=30){
            return true;
        }
        else{
            return false;
        }
        break;
    case 12:
        if(fecha_nac.dia>=1 && fecha_nac.dia<=31){
            return true;
        }
        else{
            return false;
        }
        break;
    default:
        return false;
        break;
    }

}

return false;
}
#endif // CLIENTES_H_INCLUDED
