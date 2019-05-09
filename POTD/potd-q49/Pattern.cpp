#include "Pattern.h"
#include <string>
#include <iostream>

#include <array>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findPattern(string pattern){
    vector<int> counts;
    for (int i = 0; i < pattern.size(); ++i){
        counts.push_back(0);
        int counter = 0;
        for (int j = i + 1; j < pattern.size(); ++j){
            if (pattern[i] == pattern[j]){
                ++counter;
            }
            counts[i] = counter;
        }
    }
    return counts;
}

vector<int> findPatternLong(string pattern){
    istringstream iss (pattern);
    string word;
    vector<string> v;
    while (iss >> word){
        v.push_back(word);
    }
    vector<int> counts2;
    for (int i = 0; i < v.size(); ++i){
        counts2.push_back(0);
        int counter = 0;
        for (int j = i + 1; j < v.size(); ++j){
            if (v[i] == v[j]){
                ++counter;
            }
            counts2[i] = counter;
        }
    }
    return counts2;
}


bool wordPattern(std::string pattern, std::string str) {

    //write your code here
  vector<int> v1 = findPattern(pattern);
   vector<int> v2 = findPatternLong(str);
for(auto i=v1.begin();i!=v1.end();i++) cout<<*i<<endl;
for(auto i=v1.begin();i!=v1.end();i++)   cout<<*i<<endl;
   if (v1.size() == v2.size()){
       for (int i = 0; i < v1.size(); ++i){
           if (v1[i] != v2[i]){
               return false;
           }
       }
       return true;
   } else
   return 0;

}
