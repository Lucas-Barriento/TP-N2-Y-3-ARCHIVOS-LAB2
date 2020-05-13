#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void menu_configuracion(){
    anykey();
int opc;
while(true){
    cls();
    setColor(YELLOW);
cout<< "MENÚ CONFIGURACIÓN"<<endl;
cout<< "--------------------------------"<<endl;
cout<< "1) REALIZAR COPIA DE SEGURIDAD"<<endl;
cout<< "2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
cout<< "0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<< "--------------------------------"<<endl;
cout<< "seleccione una opcion: "<<endl;
cin>>opc;
switch (opc)
{
case 1:
    realizar_bkp();
    break;
case 2:
    restaurar_bkp();
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
void realizar_bkp(){
    bkp_plato();
    bkp_cliente();
    bkp_pedido();
}
void restaurar_bkp(){
restaurar_plato();
restaurar_cliente();
restaurar_pedido();

}
void bkp_plato(){
cls();
FILE*vec_pl;
plato reg;
vec_pl=fopen(PATH_PLATO,"rb");
if(vec_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pl;
bkp_pl=fopen("platos.bkp","ab");
if(bkp_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(plato),1,vec_pl)==1){
    fwrite(&reg,sizeof(plato),1,bkp_pl);
}
cout<< "copia archivo de platos realizada"<<endl;
fclose(vec_pl);
fclose(bkp_pl);
}
void bkp_cliente(){
FILE*vec_cl;
cliente reg;
vec_cl=fopen(PATH_CLIENTE,"rb");
if(vec_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_cl;
bkp_cl=fopen("clientes.bkp","ab");
if(bkp_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(cliente),1,vec_cl)==1){
    fwrite(&reg,sizeof(cliente),1,bkp_cl);
}
cout<< "copia archivo de clientes realizada"<<endl;
fclose(vec_cl);
fclose(bkp_cl);
}
void bkp_pedido(){
FILE*vec_pe;
pedido reg;
vec_pe=fopen(PATH_PEDIDO,"rb");
if(vec_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pe;
bkp_pe=fopen("pedidos.bkp","ab");
if(bkp_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(pedido),1,vec_pe)==1){
    fwrite(&reg,sizeof(pedido),1,bkp_pe);
}
cout<< "copia archivo de pedidos realizada"<<endl;
fclose(vec_pe);
fclose(bkp_pe);
}
void restaurar_plato(){
cls();
FILE*vec_pl;
plato reg;
vec_pl=fopen(PATH_PLATO,"wb");
if(vec_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pl;
bkp_pl=fopen("platos.bkp","rb");
if(bkp_pl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(plato),1,bkp_pl)==1){
    fwrite(&reg,sizeof(plato),1,vec_pl);
}
cout<< "restauracion de archivo de platos realizada"<<endl;
fclose(vec_pl);
fclose(bkp_pl);

}
void restaurar_cliente(){
FILE*vec_cl;
cliente reg;
vec_cl=fopen(PATH_CLIENTE,"wb");
if(vec_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_cl;
bkp_cl=fopen("clientes.bkp","rb");
if(bkp_cl==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(cliente),1,bkp_cl)==1){
    fwrite(&reg,sizeof(cliente),1,vec_cl);
}
cout<< "restauracion de archivo de clientes realizada"<<endl;
fclose(vec_cl);
fclose(bkp_cl);

}
void restaurar_pedido(){
FILE*vec_pe;
pedido reg;
vec_pe=fopen(PATH_PEDIDO,"wb");
if(vec_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}

FILE*bkp_pe;
bkp_pe=fopen("pedidos.bkp","rb");
if(bkp_pe==NULL){
    cout<< "no se pudo abrir el archivo"<<endl;
}
while(fread(&reg,sizeof(pedido),1,bkp_pe)==1){
    fwrite(&reg,sizeof(pedido),1,vec_pe);
}
cout<< "restauracion de archivo de pedidos realizada"<<endl;
fclose(vec_pe);
fclose(bkp_pe);

}
#endif // CONFIGURACION_H_INCLUDED
