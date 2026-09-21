#include <iostream>
#include "markov.h"

using namespace std;

int main (){

    string words[] = {"cat", "sat", "down"};

    cout << joinWords(words,0,3) << endl;

    return 0;
}