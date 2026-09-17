#include "markov.h"
#include <string>

using namespace std;

string joinWords(const std::string words[], int startIndex, int count){

    string result;

    for (int i = startIndex; i < startIndex + count; i ++){
        
        if (i != startIndex){result += " ";}
        result = result + words[i];
    }

    return result;
}