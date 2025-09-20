#include <iostream>
#include "DemoVector.h"
#include "vector.h"
using namespace std;

// DONE  (Nivel 1) habilitar el uso de []
// DONE  (Nivel 2) habilitar que el vector pueda ser escrito con cout <<

void DemoVector(){
    cout << "Demo Vector" << endl;
    CVector<int> vector(2);

    cout << "\nVerificar insercion directa" << endl;
    vector.insert(5);
    cout << vector << endl;

    cout << "\nVerificar insercion con variable" << endl;
    int a = 3;
    vector.insert(a);
    cout << vector << endl;

    cout << "\nVerificar asignacion por indice" << endl;
    vector[0] = 8;
    cout << vector << endl;

    cout << "\nVerificar insercion que cause resize" << endl;
    vector.insert(7);
    cout << vector << endl;

    cout << "\nVerificar constructor por copia" << endl;
    CVector<int> vector_copia(vector);
    cout << "Direccion del vector copia: " << &vector_copia << endl;
    cout << "Vector copia: " << vector_copia << endl;
    cout << "Direccion del vector original: " << &vector << endl;
    cout << "Vector original: " << vector << endl;

    cout << "\nVerificar constructor por movimiento/reemplazo" << endl;
    CVector<int> vector_movido(std::move(vector));
    cout << "Direccion del vector copia: " << &vector_movido << endl;
    cout << "Vector movido: " << vector_movido << endl;
    cout << "Direccion del vector original: " << &vector << endl;
    cout << "Vector original: " << vector << endl;

}