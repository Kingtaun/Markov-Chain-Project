#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){

    srand(time(0));

    string fileName;
    int chainOrder;

    cout << "What is the name of the file you would like to use?" << endl;
    cin >> fileName;

    do {
        cout << "What order would you like to use?" << endl;
        cin >> chainOrder;

        if (chainOrder <= 0){
            cout << "invalid order" << endl;
            chainOrder = 0;
        }

    } while (chainOrder <= 0);

    return 0;
}