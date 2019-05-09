#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>

using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	ifstream words(filename);

	vector<string> out;

	if (filename.is_open()) {
			std::istream_iterator<string> word_iter(words);
			while (!words.eof()) {
					out.push_back(*word_iter);
					++word_iter;
			}
	}
	map<string,unsigned int> count;
	for(string word:out){
		map<string,unsigned int>::iterator lookup=count.find(word);
		if(lookup!=count.end()) lookup->second++;
		else count[word]=1;
	}
return count[0].first;
}
