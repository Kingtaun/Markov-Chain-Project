#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){

    srand(time(0));

    string prefixes[] = {"the", "cat", "the", "the"};
    string suffixes[] = {"cat", "sat", "dog", "bird"};

    string words[] = {"the", "cat", "sat", "down"};

    for (int i = 0; i < 10; i++){
        cout << getRandomPrefix(prefixes, 4) << endl;
    }

    return 0;
}