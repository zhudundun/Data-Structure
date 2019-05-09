#pragma once

#include <string>
//#include <map>

using std::string;
//using std::map;

string stringToBinary(string charString, HuffmanNode* huffmanTree);
string binaryToString(string binaryString, HuffmanNode* huffmanTree);
//map<char, string> storeCodes(HuffmanNode* root, char str);
