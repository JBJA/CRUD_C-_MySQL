// Tarea_CRUD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <mysql.h>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;
int q_estado;

void menu_principal();
void menu_productos();
void menu_marcas();
void agregar_producto();
void mostrar_productos();
void mostrar_marcas();
void agregar_marca();
void eliminar_marca();
void eliminar_producto();
void actualizar_marca();
void menu_actualizar_producto();
void actualizar_producto();

int main()
{
   
    MYSQL* conectar;
    MYSQL_ROW row;
    MYSQL_RES* res;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud",3306, NULL, 0);
   
// el programa conecto exitosamente con la base de datos
    if (conectar) {
        system("color a");
        cout << "Conexion exitosa . . ."<<endl;
        system("pause");

        int entrada = 0;

// inicio menu principal 
        while (entrada != 3) {
            menu_principal();
            cout << "Opcion: ";
            cin >> entrada;

            if (entrada == 1) { // menu del crud productos
                while (entrada != 5) {
                    menu_productos();
                    cout << "Opcion: ";
                    cin >> entrada;

                    if (entrada == 1) {
                        mostrar_productos();
                        system("pause");
                    }

                    if (entrada == 2) {
                        agregar_producto();
                        system("pause");
                    }

                    if (entrada == 3) {
                        mostrar_productos();
                        actualizar_producto();
                        system("pause");
                    }

                    if (entrada == 4) {
                        mostrar_productos();
                        eliminar_producto();
                        system("pause");
                    }
                }
            }

            if (entrada == 2) { // menu del crud marcas
                while (entrada != 5) {
                    menu_marcas();
                    cout << "Opcion: ";
                    cin >> entrada;

                    if (entrada == 1) {
                        mostrar_marcas();
                        system("pause");
                    }

                    if (entrada == 2) {
                        agregar_marca();
                        system("pause");
                    }

                    if (entrada == 3) {
                        mostrar_marcas();
                        actualizar_marca();
                        system("pause");
                    }

                    if (entrada == 4) {
                        mostrar_marcas();
                        eliminar_marca();
                        system("pause");
                    }
                }
            }
        }
    }

// no se pudo conectar con la base de datos
    else {
        system("color c");
        cout << "Conexion fallida . . ." << endl;
    }
 

    system("pause");
    return 0;
}


void menu_principal() {
    system("cls");
    cout << " ________________________________________" << endl;
    cout << "|                                        |" << endl;
    cout << "|          CRUD EN C++ Y MYSQL           |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    1. CRUD PRODUCTOS                   |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    2. CRUD MARCAS                      |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    3. SALIR                            |" << endl;
    cout << "|________________________________________|" << endl;
}

void menu_productos() {
    system("cls");
    cout << " ________________________________________" << endl;
    cout << "|                                        |" << endl;
    cout << "|          CRUD TABLA PRODUCTOS          |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    1. VER DATOS                        |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    2. AGREGAR DATOS                    |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    3. ACTUALIZAR DATOS                 |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    4. ELIMINAR DATOS                   |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|           5. MENU PRINCIPAL            |" << endl;
    cout << "|________________________________________|" << endl;
}

void menu_marcas() {
    system("cls");
    cout << " ________________________________________" << endl;
    cout << "|                                        |" << endl;
    cout << "|           CRUD TABLA MARCAS            |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    1. VER DATOS                        |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    2. AGREGAR DATOS                    |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    3. ACTUALIZAR DATOS                 |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    4. ELIMINAR DATOS                   |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|           5. MENU PRINCIPAL            |" << endl;
    cout << "|________________________________________|" << endl;
}

void menu_actualizar_marca() {
    cout << " ________________________________________" << endl;
    cout << "|                                        |" << endl;
    cout << "|           ACTUALIZAR MARCAS            |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    1. MODIFICAR ID MARCA               |" << endl;
    cout << "|    2. MODIFICAR MARCA                  |" << endl;
    cout << "|    3. REGRESAR                         |" << endl;
    cout << "|________________________________________|" << endl;
}

void menu_actualizar_producto() {
    cout << " ________________________________________" << endl;
    cout << "|                                        |" << endl;
    cout << "|          ACTUALIZAR PRODUCTO           |" << endl;
    cout << "|________________________________________|" << endl;
    cout << "|                                        |" << endl;
    cout << "|    1. MODIFICAR ID PRODUCTO            |" << endl;
    cout << "|    2. MODIFICAR PRODUCTO               |" << endl;
    cout << "|    3. MODIFICAR DESCRIPCION            |" << endl;
    cout << "|    4. MODIFICAR PRECIO COSTO           |" << endl;
    cout << "|    5. MODIFICAR PRECIO VENTA           |" << endl;
    cout << "|    6. MODIFICAR EXISTENCIA             |" << endl;
    cout << "|    7. REGRESAR                         |" << endl;
    cout << "|________________________________________|" << endl;
}

void agregar_producto(){
    system("cls");
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 3306, NULL, 0);
    if (conectar)
    {
        string producto, descripcion, fecha, idmarca, existencia, precioc, preciov;

        cout << "Ingrese el producto: ";
        cin>>producto;
        cout << "Ingrese el id_marca: ";
        cin >> idmarca;
        cin.ignore();
        cout << "Ingrese la descripcion: ";
        getline(cin, descripcion);
        cout << "Ingrese el precio costo: ";
        cin >> precioc;
        cin.ignore();
        cout << "Ingrese el precio venta: ";
        cin >> preciov;
        cin.ignore();
        cout << "Ingrese las existencias: ";
        cin >> existencia;
        cout << "Ingrese la fecha (A/M/D): " << endl;
        getline(cin, fecha);

        string insert = "insert into productos(producto,idmarca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , '" + idmarca + "' , '" + descripcion + "' , '" + precioc + "','" + preciov + "','" + existencia + "','" + fecha + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "Insert exitoso . . ." << endl;
        }
        else
        {
            cout << "Error en insert . . ." << endl;
        }
    }
}

void mostrar_productos() {
    system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 3306, NULL, 0);
    if (conectar) {
        string consulta = "select * from productos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado){
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ", " << fila[1] << endl;
            }
        }
        else{
            cout << "Error en insert . . ." << endl;
        }
    }
}

void mostrar_marcas() {
    system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 0, NULL, 0);
    if (conectar) {
        string consulta = "select * from marcas";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << ", " << fila[1] << endl;
            }
        }
        else {
            cout << "Error en insert . . ." << endl;
        }
    }
}

void agregar_marca() {
    system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 3306, NULL, 0);
    if (conectar) {
        string marca;
        cout << "Ingrese marca: ";
        cin >> marca;
        string insert = "insert into marcas(marca) values('" + marca + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar,i);
        if (!q_estado) {
            cout << "Insert exitoso . . ." << endl;
        }
        else {
            cout << "Error en insert . . ." << endl;
        }

    }
}

void eliminar_marca() {
    //system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 3306, NULL, 0);
    if (conectar) {
        int idaux;
        cout << "Ingrese el id que desea eliminar: ";
        cin >> idaux;
        string borrar = "delete from marcas where marcas.id = idaux ";
        const char* i = borrar.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Borrado exitoso . . ." << endl;
        }
        else {
            cout << "Error en el borrado . . ." << endl;
        }
    }
}

void eliminar_producto() {
    //system("cls");
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 3306, NULL, 0);
    if (conectar) {
        int idaux;
        cout << "Ingrese el id que desea eliminar: ";
        cin >> idaux;
        string borrar = "delete from productos where productos.id = idaux ";
        const char* i = borrar.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Borrado exitoso . . ." << endl;
        }
        else {
            cout << "Error en el borrado . . ." << endl;
        }
    }
}

void actualizar_marca() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 0, NULL, 0);
    if (conectar) {
        int idaux, op = 0;

        while (op != 3) {
            menu_actualizar_marca();
            cout << "Opcion: ";
            cin >> op;

            if (op == 1) {
                string nid;
                cout << "Ingrese el id de la marca que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo id: ";
                getline(cin, nid);
                cin.ignore();

                string update = "update marcas set (idmarca) values('" + nid + "') where idmarca = idaux ";
                    const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 2) {
                string nmarca;
                cout << "Ingrese el id de la marca que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese la nueva marca: ";
                cin>>nmarca;
                
                string update = "update marcas set marca='" + nmarca + "' where idmarca = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

        }
    }
}



void actualizar_producto() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "programer1", "db_crud", 0, NULL, 0);
    if (conectar) {
        int idaux, op = 0;

        while (op != 7) {
            menu_actualizar_producto();
            cout << "Opcion: ";
            cin >> op;

            if (op == 1) {
                string nid;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo id: ";
                getline(cin, nid);
                cin.ignore();

                string update = "update productos set (idproducto) values('" + nid + "') where productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 2) {
                string nproducto;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo producto: ";
                cin >> nproducto;

                string update = "update productos set producto='" + nproducto + "' productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 3) {
                string npdesc;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese la nueva descripcion: ";
                getline(cin, npdesc);
                cin.ignore();

                string update = "update productos set descipcion='" + npdesc + "' productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 4) {
                string npc;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo precio costo: ";
                cin >> npc;

                string update = "update productos set precio_costo='" + npc + "' productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 5) {
                string npv;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese el nuevo precio venta: ";
                cin >> npv;

                string update = "update productos set precio_venta='" + npv + "' productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

            if (op == 6) {
                string nexis;
                cout << "Ingrese el id del producto que quiere modificar: ";
                cin >> idaux;

                cout << "Ingrese la existencia actual: ";
                cin >> nexis;

                string update = "update productos set existencia='" + nexis + "' productos.id = idaux ";
                const char* i = update.c_str();

                q_estado = mysql_query(conectar, i);
                if (!q_estado)
                {
                    cout << "Update exitoso . . ." << endl;
                }
                else
                {
                    cout << "Error en Update . . ." << endl;
                }
            }

        }
    }
}