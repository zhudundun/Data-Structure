#include "Hash.h"
#include <string>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	// for (unsigned i=0;i<str.size();i++){
	// 	b_hash=b_hash*(33+str[i]);
	// }
	for (auto c : str) {
        b_hash = (b_hash << 5) + b_hash + c; /* hash * 33 + c */
    }
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";
	//Your code here
while (!str.empty()){
	output.push_back(str.back());
	str.pop_back();
}
	return output;
}
