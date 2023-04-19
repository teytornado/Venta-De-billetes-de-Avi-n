

#include <iostream>
#include <string>
using namespace std;

struct Pasajero {
    int id;
    string nombre;
    string telefono;
    string correo;
    string ruta;
    string fecha_vuelo;
    string fecha_salida;
    string hora_llegada;
    int num_vuelo;
    float precio_pasaje;
};

struct Nodo {
    Pasajero pasajero;
    Nodo* siguiente;
};

void crear_por_inicio(Nodo*& lista, Pasajero pasajero) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pasajero = pasajero;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
}

void crear_por_fin(Nodo*& lista, Pasajero pasajero) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pasajero = pasajero;
    nuevo_nodo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
        return;
    }

    Nodo* auxiliar = lista;

    while (auxiliar->siguiente != NULL) {
        auxiliar = auxiliar->siguiente;
    }

    auxiliar->siguiente = nuevo_nodo;
}

void anexar_por_inicio(Nodo*& lista, Pasajero pasajero) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pasajero = pasajero;

    if (lista == NULL) {
        lista = nuevo_nodo;
        return;
    }

    Nodo* auxiliar = lista;

    while (auxiliar->siguiente != NULL) {
        auxiliar = auxiliar->siguiente;
    }

    auxiliar->siguiente = nuevo_nodo;
}

void anexar_por_fin(Nodo*& lista, Pasajero pasajero) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->pasajero = pasajero;

    if (lista == NULL) {
        lista = nuevo_nodo;
        return;
    }

    Nodo* auxiliar1 = lista;

    while (auxiliar1->siguiente != NULL) {
        auxiliar1 = auxiliar1->siguiente;
    }

    auxiliar1->siguiente = nuevo_nodo;

}

void ver_informacion(Nodo* lista) {
    
     if (lista == NULL) {
        cout << "No hay información para mostrar." << endl << endl;;
        return; 
     }
    
     while (lista != NULL) {
         cout << "ID del pasajero: " << lista->pasajero.id << endl
              << "Nombre completo: " << lista->pasajero.nombre << endl
              << "Teléfono: " << lista->pasajero.telefono << endl
              << "Correo: " << lista->pasajero.correo << endl
              << "Ruta: " << lista->pasajero.ruta << endl
              << "Fecha de vuelo: " << lista->pasajero.fecha_vuelo << endl
              << "Fecha de salida: " << lista->pasajero.fecha_salida << endl
              << "Hora de llegada: " << lista->pasajero.hora_llegada << endl
              << "Número de vuelo: " << lista->pasajero.num_vuelo << endl
              << "Precio del pasaje: $" << lista->pasajero.precio_pasaje 
              << endl<<endl;

         lista = lista->siguiente; 
     }
}

void ver_sillas_vendidas_y_total_recaudado(Nodo* lista) {

     if (lista == NULL) {
        cout<<"No hay información para mostrar."<<endl<<endl;;
        return; 
     }
    
     int sillas_ejecutivas_vendidas=0, sillas_economicas_vendidas=0; 
     float total_recaudado=0;

     while (lista != NULL) {
         if (lista->pasajero.num_vuelo == 1) {
             sillas_ejecutivas_vendidas++;
             total_recaudado += lista->pasajero.precio_pasaje;
         }
         else if (lista->pasajero.num_vuelo == 2) {
             sillas_economicas_vendidas++;
             total_recaudado += lista->pasajero.precio_pasaje;
         }
         lista = lista->siguiente; 
     }

     cout << "Número de sillas vendidas en clase ejecutiva: " << sillas_ejecutivas_vendidas << endl
          << "Número de sillas vendidas en clase económica: " << sillas_economicas_vendidas << endl
          << "Total recaudado: $" << total_recaudado << endl<<endl;
}

void buscar_por_numero_de_vuelo(Nodo* lista, int num_vuelo) {

    if (lista == NULL) {
        cout<<"No hay información para mostrar."<<endl<<endl;;
        return; 
    }

    while (lista != NULL) {
        if (lista->pasajero.num_vuelo == num_vuelo) {
            cout << "ID del pasajero: " << lista->pasajero.id << endl
                 << "Nombre completo: " << lista->pasajero.nombre << endl
                 << "Teléfono: " << lista->pasajero.telefono << endl
                 << "Correo: " << lista->pasajero.correo << endl
                 << "Ruta: " << lista->pasajero.ruta << endl
                 << "Fecha de vuelo: " << lista->pasajero.fecha_vuelo << endl
                 << "Fecha de salida: " << lista->pasajero.fecha_salida << endl
                 << "Hora de llegada: " << lista->pasajero.hora_llegada << endl
                 << "Número de vuelo: " << lista->pasajero.num_vuelo 
                 <<" Precio del pasaje: $" 
                 << lista->pasajero.precio_pasaje<<endl<<endl;
        }
        lista = lista->siguiente; 
    }
}

void buscar_por_id_del_pasajero(Nodo* lista, int id_pasajero) {

    if (lista == NULL) {
        cout<<"No hay información para mostrar."<<endl<<endl;;
        return; 
    }

    while (lista != NULL) {
        if (lista->pasajero.id == id_pasajero) {
            cout<<"ID del pasajero: "<<lista->pasajero.id<<endl
                <<"Nombre completo: "<<lista->pasajero.nombre<<endl
                <<"Teléfono: "<<lista->pasajero.telefono<<endl
                <<"Correo: "<<lista->pasajero.correo<<endl
                <<"Ruta: "<<lista->pasajero.ruta<<endl
                <<"Fecha de vuelo: "<<lista->pasajero.fecha_vuelo<<endl
                <<"Fecha de salida: "<<lista->pasajero.fecha_salida<<endl
                <<"Hora de llegada: "<<lista->pasajero.hora_llegada<<endl
                <<"Número de vuelo: "<<lista->pasajero.num_vuelo 
                <<" Precio del pasaje: $" 
                << lista->pasajero.precio_pasaje<<endl<<endl;
        }
        lista = lista->siguiente; 
    }
}

void venta_de_sillas_de_los_vuelos(Nodo*& lista, Pasajero pasajero) {

    int opcion;

    cout<<"Seleccione el tipo de silla que desea comprar:"<<endl;
    cout<<"1. Clase ejecutiva"<<endl;
    cout<<"2. Clase económica"<<endl;
    cin>>opcion;

    if (opcion == 1) {
        crear_por_inicio(lista, pasajero);
    }
    else if (opcion == 2) {
        crear_por_fin(lista, pasajero);
    }
}

   // Función principal

int main() {

    Nodo* lista = NULL;
    Pasajero pasajero;
    int opcion, num_vuelo, id_pasajero;

    do {
        cout << "1. Venta de sillas de los vuelos" << endl
             << "2. Ver información de los pasajeros" << endl
             << "3. Ver sillas vendidas y total recaudado" << endl
             << "4. Buscar por número de vuelo" << endl
             << "5. Buscar por ID del pasajero" << endl
             << "6. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el ID del pasajero: ";
                cin >> pasajero.id;
                cout << "Ingrese el nombre completo del pasajero: ";
                cin >> pasajero.nombre;
                cout << "Ingrese el teléfono del pasajero: ";
                cin >> pasajero.telefono;
                cout << "Ingrese el correo del pasajero: ";
                cin >> pasajero.correo;
                cout << "Ingrese la ruta: ";
                cin >> pasajero.ruta;
                cout << "Ingrese la fecha de vuelo: ";
                cin >> pasajero.fecha_vuelo;
                cout << "Ingrese la fecha de salida: ";
                cin >> pasajero.fecha_salida;
                cout << "Ingrese la hora de llegada: ";
                cin >> pasajero.hora_llegada;
                cout << "Ingrese el número de vuelo: ";
                cin >> pasajero.num_vuelo;
                cout << "Ingrese el precio del pasaje: ";
                cin >> pasajero.precio_pasaje;
                venta_de_sillas_de_los_vuelos(lista, pasajero);
                break;
            case 2:
                ver_informacion(lista);
                break;
            case 3:
                ver_sillas_vendidas_y_total_recaudado(lista);
                break;
            case 4:
                cout << "Ingrese el número de vuelo: ";
                cin >> num_vuelo;
                buscar_por_numero_de_vuelo(lista, num_vuelo);
                break;
            case 5:
                cout << "Ingrese el ID del pasajero: ";
                cin >> id_pasajero;
        }
    } while (opcion != 6);

    return 0;
}











