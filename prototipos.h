#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED
int main();
void menu_platos();
int buscar_id(int );
bool modificar_plato();
void listar_platoXid();
void platosXrestaurante();
bool cargar_plato(struct plato*);
void listar_platos(plato,int);
bool guardar_plato(plato);
void listar_platos_de_archivos(plato);
struct plato leer_plato(int );
int cantidad_registros();
bool sobreescribir_plato(plato,int );
int buscar_id_restaurante(int);
bool eliminar_plato();

struct plato
{
    int id;
    char nombre[50];
    float costo_preparacion,valor_venta;
    int tiempo_preparacion, id_restaurante, comision_restaurante,id_categoria;
    bool estado;
};
const char*PATH_PLATO="platos.dat";

///CLIENTES
void menu_clientes();
const char*PATH_CLIENTE="clientes.dat";

struct fecha{
int dia,mes,anio;
};
struct cliente{
int id;
char nombre[50],apellido[50], mail[50], domicilio[50];
int cp;
struct fecha cargar_fecha;
bool estado;
};
bool cargar_cliente(cliente*);
bool grabar_cliente(cliente);
void listar_clientes(cliente,int);
void listar_clientesXid();
struct cliente leer_cliente(int);
bool sobreescribir_cliente(cliente, int);
bool modificar_cliente();
int buscar_id_cliente(int);
int cant_clientes();
bool eliminar_cliente();
bool validar_mail(char*);
void mostrar_clientes_ordenados();
void ordenar_clientes(cliente*, int);
bool validar_fecha(fecha);
///PEDIDOS
const char*PATH_PEDIDO="pedidos.dat";
struct pedido{
int id, idcliente,idplato,cantidad,estado;
float precio_unitario, valoracion;
struct fecha fecha_pedido;
};
void menu_pedidos();
bool cargar_pedido(pedido*);
bool grabar_pedido(pedido);
bool modificar_pedido(pedido);
int buscar_id_pedido(int );
bool sobreescribir_pedido(pedido, int);
struct pedido leer_pedido(int);
void listar_pedidos(pedido,int);
void listar_pedidos_de_archivos(pedido);
int cant_pedidos();
int buscar_precio_plato(int);
void listar_pedidosXid();
/// configuracion
void menu_configuracion();
void realizar_bkp();
void restaurar_bkp();
void bkp_plato();
void bkp_cliente();
void bkp_pedido();
void restaurar_plato();
void restaurar_cliente();
void restaurar_pedido();
#endif // PROTOTIPOS_H_INCLUDED
