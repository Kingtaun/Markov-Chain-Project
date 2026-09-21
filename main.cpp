#include <iostream>
#include "markov.h"

using namespace std;

int main (){

    string prefixes[6];
    string sufixes[6];

    string words[] = {"the", "cat", "sat", "down"};

    cout << buildMarkovChain(words,4,2,prefixes,sufixes,5) << endl;

    return 0;
}