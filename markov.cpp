#include "markov.h"
#include <string>
#include <fstream>
#include <iostream>

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

    int count = 0;

    if (order >= 1 && order <= 3 && numWords > order && maxChainSize > 0){

        for (int i = 0; i < numWords - order; i++){
            
            if (count < maxChainSize){
                prefixes[count] = joinWords(words, i, order);
                suffixes[count] = words[i + order];
                count++;
            }
        }

        return count;
    }

    return 0;
}

std::string getRandomSuffix(const std::string prefixes[], const std::string suffixes[], int chainSize, std::string currentPrefix){

    if (chainSize > 0){

        int matchCount = 0;

        for (int i = 0; i < chainSize; i++){
            if (prefixes[i] == currentPrefix){
                matchCount++;
            }
        }

        if (matchCount > 0){
        
            int pick = rand() % matchCount;
            return suffixes[pick];
        }
    }

    return "";
}
