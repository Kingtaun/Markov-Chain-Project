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