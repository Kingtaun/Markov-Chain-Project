#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){

    srand(time(0));

    // // Implementations
    // cout << "\n\n";

    // string testWords[] = {"the", "cat", "sat", "down"};
    // cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    // cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    // cout << "\n\n";

    // string words[1000];

    // int count = readWordsFromFile("test.txt", words, 1000);
    // cout << "Read " << count << " words" << endl;

    // for (int i = 0; i < 35 && i < count; i++) {
    //     cout << words[i] << endl;
    // }

    // cout << "\n\n";

    // string prefixes[1000], suffixes[1000];
    // int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 1000);

    // for (int i = 0; i < 35 && i < chainSize; i++) {
    //     cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << endl;
    // }

    // cout << "\n\n";

    // for (int i = 0; i < 10; i++) {
    //     cout << getRandomSuffix(prefixes, suffixes, chainSize, "I") << endl;
    // }

    // cout << "\n\n";

    // for (int i = 0; i < 5; i++) {
    //     cout << getRandomPrefix(prefixes, chainSize) << endl;
    // }

    // cout << "\n\n";

    // string output = generateText(prefixes, suffixes, chainSize, 1, 100);
    // cout << output << endl;

    // cout << "\n\n";

    // Markov chain generator
    string fileName;
    int order;
    int maxWords;

    const int CAPACITY = 5000;

    // Get file name
    cout << "\n\nWhat is the name of the file you would like to use?\n\n" << endl;
    cin >> fileName;

    // Get order and validate input
    do {
        cout << "\n\nWhat is the order you would like to use?\n\n" << endl;
        cin >> order;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            order = -1;
        }

        if (order <= 0 || order > 3){
         cout << "\n\nOrder must be a number between 1 and 3\n\n" << endl;
        }

    } while (order <= 0 || order > 3);

    // Get maxWords and validate input
    do {
        cout << "\n\nWhat is the maximum number of words you would like to allow?\n\n" << endl;
        cin >> maxWords;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            order = -1;
        }

        if (maxWords <= order){
         cout << "\n\nThe maximum amount of words must be a number greater than the order\n\n" << endl;
        }

    } while (maxWords <= order);


    // Initilize arrays
    string words[CAPACITY];
    string prefixes[CAPACITY];
    string suffixes[CAPACITY];

    // Read and validate file
    int count = readWordsFromFile(fileName,words,CAPACITY);

    if (count == -1){
        cout << "The file failed to open." << endl;

    } else if (count < order + 1){
        cout << "This file contains less words than the order allows for" << endl;
    }

    // Build chain
    int chainSize = buildMarkovChain(words,count,order,prefixes,suffixes,CAPACITY);

    // Check for capacity
    if (chainSize >= CAPACITY - order){
        cout << "\n\nChain reached capacity. All additional words, if any, were ignored." << endl;
    }

    // Generate output
    string output;
    int wordCount = 0;

    if (chainSize > 0){
        output = generateText(prefixes,suffixes,chainSize,order,maxWords);
        cout << "\n" << output << "\n" << endl;
        wordCount = 1;
    } else {
        cout << "Unable to build Markov chain." << endl;
    }

    // Get word count
    for (char i : output){
        if(i == ' '){
            wordCount++;
        }
    }

    // Print word count
    cout << "Printed " << wordCount << " words. ";
    if (wordCount < maxWords){
        cout << "Generation stopped at dead end.";
    }
    cout << "\n" << endl;

    return 0;
}
