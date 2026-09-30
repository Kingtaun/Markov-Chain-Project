#include <iostream>
#include "markov.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main (){

    srand(time(0));

    cout << "\n\n";

    string testWords[] = {"the", "cat", "sat", "down"};
    cout << joinWords(testWords, 0, 2) << endl;  // Should print: the cat
    cout << joinWords(testWords, 1, 3) << endl;  // Should print: cat sat down

    cout << "\n\n";

    string words[1000];

    int count = readWordsFromFile("test.txt", words, 1000);
    cout << "Read " << count << " words" << endl;

    for (int i = 0; i < 20 && i < count; i++) {
        cout << words[i] << endl;
    }

    cout << "\n\n";

    std::string prefixes[1000], suffixes[1000];
    int chainSize = buildMarkovChain(words, count, 1, prefixes, suffixes, 1000);

    for (int i = 0; i < 20 && i < chainSize; i++) {
        std::cout << "[" << prefixes[i] << "] -> [" << suffixes[i] << "]" << std::endl;
    }

    cout << "\n\n";

    for (int i = 0; i < 10; i++) {
        std::cout << getRandomSuffix(prefixes, suffixes, chainSize, "am") << std::endl;
    }

    cout << "\n\n";

    return 0;
}