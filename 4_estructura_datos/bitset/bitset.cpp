#include <iostream>
#include <bitset>
using namespace std;

int main() {

    bitset<8> b(13);

    cout << "Bits: " << b << "\n";

    cout << "Bit 0: " << b[0] << "\n";

    b.set(1);

    cout << "Despues de set(1): " << b << "\n";

    b.flip(2);

    cout << "Despues de flip(2): " << b << "\n";

    cout << "Cantidad de unos: " << b.count() << "\n";

    cout << "Como entero: " << b.to_ulong() << "\n";

    return 0;
}
/*
Salida posible:
Bits: 00001101
Bit 0: 1
Despues de set(1): 00001111
Despues de flip(2): 00001011
Cantidad de unos: 3
Como entero: 11
*/