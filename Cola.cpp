#include <iostream>
#include <string>
using namespace std;

class Cola {
private:
    int frente;
    int final;
    int capacidad;
    string* elementos;

public:
    Cola(int capacidad) {
        this->capacidad = capacidad;
        elementos = new string[capacidad];
        frente = -1;
        final = -1;
    }

    bool estaVacia() {
        return frente == -1;
    }

    bool estaLLena() {
        return (final + 1) % capacidad == frente;
    }

    void encolar(string valor) {
        if (estaLLena()) {
            cout << "Cola llena, no se puede agregar.\n";
            return;
        }
        if (estaVacia()) {
            frente = 0;
        }
        final = (final + 1) % capacidad;
        elementos[final] = valor;
    }

    string desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia, no se puede quitar elemento."<<endl;
            return "";
        }
        string valor = elementos[frente];
        if (frente == final) {
            frente = final = -1; 
        } else {
            frente = (frente + 1) % capacidad;
        }
        return valor;
    }

    void mostrar() {
        if (estaVacia()) {
            cout << "Cola vacía." << endl;
            return;
        }
        cout << "Cola: ";
        int i = frente;
        while (true) {
            cout << elementos[i] <<endl;
            if (i == final) break;
            i = (i + 1) % capacidad;
        }
        cout << endl;
    }
};

int main() {
    cout<<"COLA DE PERSONAS ATENDIDAS\n"<<endl;
    cout<<"Ingrese el tamaño de la cola: ";
    int size;
    cin>>size;
    Cola cola(size);
    int opcion;

    do{
        cout << "\n1. Encolar persona\n2. Desencolar persona\n3. Mostrar cola\n4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese un nombre de persona para encolar: ";
                string valor;
                cin >> valor;
                cola.encolar(valor);
                break;
            }
            case 2: {
                string valor = cola.desencolar();
                if (!valor.empty()) {
                    cout << "Persona atendida: " << valor << endl;
                }
                break;
            }
            case 3: {
                cola.mostrar();
                break;
            }
            case 4:
                cout << "Saliendo...";
                return 0;

            default:
                cout << "Opción inválida, intente de nuevo."<<endl;
        }

    }while(opcion != 4);

    return 0;
}
