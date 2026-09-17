#include <iostream>
#include "markov.h"

using namespace std;

int main (){

    string words[] = {"the", "cat", "sat", "down"};

    cout << joinWords(words,1,2) << endl;

    return 0;
}