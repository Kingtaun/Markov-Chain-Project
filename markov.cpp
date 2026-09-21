#include "markov.h"
#include <string>
#include <fstream>

using namespace std;

string joinWords(const std::string words[], int startIndex, int count){

    string result;

    for (int i = startIndex; i < startIndex + count; i ++){
        
        if (i != startIndex){result += " ";}
        result = result + words[i];
    }

    return result;
}

int readWordsFromFile(std::string filename, std::string words[], int maxWords){

    ifstream file(filename);

    if (file.is_open()){

        int counter = 0;

        while (counter < maxWords && file >> words[counter]){
            counter++;
        }

        file.close();
        return counter;
    }

    return -1;
}

int buildMarkovChain(const std::string words[], int numWords, int order, std::string prefixes[], std::string suffixes[], int maxChainSize){

    int count;

    if (order >= 1 && order <= 3 && numWords > order && maxChainSize > 0){

        for (int i = 0; i < numWords - order; i++){
            
            if (count < maxChainSize){
                prefixes[i] = joinWords(words, i, order);
                suffixes[i] = words[i + order];
                count++;
            }
        }

        return count;
    }

    return 0;
}
