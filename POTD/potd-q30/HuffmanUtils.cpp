#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <vector>
#include <map>


using std::string;
using std::vector;
using std::map;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */


string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    HuffmanNode* current = huffmanTree;
    vector<char> string;
    for (char& c:binaryString) {

         if(c=='1') current=current->right_;
         else current=current->left_;
         if(current->left_==NULL && current->right_==NULL){
string.push_back(current->char_);
           current=huffmanTree;
         }

    }
    std::string str2{string.begin(),string.end()};

    return str2;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */
map<char, string> codes;

 void storeCodes(HuffmanNode* root,string str)
 {


     if (root==NULL) return ;



     if (root->left_==NULL && root->right_==NULL)
     { codes[root->char_]=str;
      // return ;
     }
     storeCodes(root->left_, str + '0');
     storeCodes(root->right_, str + '1');
     //std::cout<<root->char_<<std::endl;
    // return;
   }


string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string result;

    //map<char, string> dictionary;
    //dictionary=storeCodes(huffmanTree,"");
    storeCodes(huffmanTree,"");
    for (char& c:charString){
    result+=codes[c];
    }

    return result;
}
