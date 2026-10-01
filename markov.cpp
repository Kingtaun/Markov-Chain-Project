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

string getRandomSuffix(const std::string prefixes[], const std::string suffixes[], int chainSize, std::string currentPrefix){

    if (chainSize > 0){

        int matchCount = 0;
        

        for (int i = 0; i < chainSize; i++){
            if (prefixes[i] == currentPrefix){
                matchCount++;
            }
        }

        string matches[matchCount];
        int j = 0;

        if (matchCount > 0){
            for (int i = 0; i < chainSize; i++){
                if (prefixes[i] == currentPrefix){
                    matches[j] = suffixes[i];
                    j++;
                }
            }
        }

        int pick = rand() % matchCount;
        return matches[pick];
    }

    return "";
}

string getRandomPrefix(const std::string prefixes[], int chainSize){
    if (chainSize > 0){
        int index = rand() % chainSize;
        return prefixes[index];
    }
    return "";
}

string generateText(const std::string prefixes[], const std::string suffixes[], int chainSize, int order, int numWords){

    if (chainSize > 0 && (order > 0 && order <= 3) && numWords >= order){

        string currentPrefix = getRandomPrefix(prefixes,chainSize);

        string currentWords[3]; // supports the validated orders 1, 2, and 3
        int wordIndex = 0;                                                                                                                                                                 
        string temp = "";

        for (int i = 0; i < currentPrefix.length(); i++) {     

             if (currentPrefix[i] == ' ') {

                currentWords[wordIndex] = temp;                                                                                                                                            
                wordIndex++;                                                                                                                                                               
                temp = "";    

            } else {                                                                                                                                                                       
                temp += currentPrefix[i];  
            }
        }

        currentWords[wordIndex] = temp; // don't forget the last word

        string result = currentPrefix;
        string newWord;

        for (int i = 0; i < numWords - order; i++){
            newWord = getRandomSuffix(prefixes, suffixes, chainSize, currentPrefix);

            if (newWord != ""){
                result = result + " " + newWord;
            } else {
                break;
            }
        }

        for (int j = 0; j < order - 1; j++){
            currentWords[j] = currentWords[j+1];
        }

        currentWords[order - 1] = newWord;
        currentPrefix = joinWords(currentWords, 0, order);

        return result;

    }

    return "";
    
}
