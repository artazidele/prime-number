//
//  main.cpp
//  prime-number
//
//  Created by Arta Zidele on 17/01/2025.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// use Euclidean algorithm
int gcd(int a, int b)
{
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

int main(int argc, const char * argv[]) {
    
    ifstream file("ieeja.txt");
    int p = 1;
    int a = 10;
    
    if(file.is_open()) {
        string rinda;
        getline(file, rinda);
        p = stoi(rinda);
    }
    file.close();
    
    long long int aP = a;
    for (int i = 1; i<p; i++) {
        aP *= a;
    }
    
    long long int aP1 = a;
    for (int i = 1; i<p-1; i++) {
        aP1 *= a;
    }
    
    // use Fermat's little theorem
    if (gcd(a, p) == 1) {
        if (aP1 % p == 1) {
            cout<<p<<" ir pirmskaitlis(2)"<<endl;
        } else {
            cout<<p<<" nav pirmskaitlis(2)"<<endl;
        }
    } else {
        if (aP % p == a) {
            cout<<p<<" ir pirmskaitlis(1)"<<endl;
        } else {
            cout<<p<<" nav pirmskaitlis(1)"<<endl;
        }
    }
    return 0;
}

