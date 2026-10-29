#include <bits/stdc++.h>
using namespace std;
    int fib(int n) {
        if (n <= 1) { //caso base
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    int main() {
    
    cout << "Resultado: " << fib(6)  << endl;
    
    return 0;
}


/*

n	fib(n)	Cálculo
0	0	caso base
1	1	caso base
2	1	fib(1) + fib(0) = 1 + 0
3	2	fib(2) + fib(1) = 1 + 1
4	3	fib(3) + fib(2) = 2 + 1
5	5	fib(4) + fib(3) = 3 + 2
6	8	fib(5) + fib(4) = 5 + 3

7	13	fib(6) + fib(5) = 8 + 5
8	21	fib(7) + fib(6) = 13 + 8
9	34	fib(8) + fib(7) = 21 + 13

*/