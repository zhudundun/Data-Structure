#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

using std::string;

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    std::vector<bool> num (M,false);
		std::vector<string> input ;	// Hint: This comes in handy
	int permutation_count = 0;
	float goodness = 0;
	float collisions=0;
	//sort(str.begin(), str.end());
	do {
		if (permutation_count == M) break;
		//unsigned long num=bernstein(str, M);
	input.push_back(str);
	//std::cout<<str<<std::endl;
	//std::cout<<array->size()<<std::endl;

	//std::cout<<bernstein(str, M)<<std::endl;

		//std::cout<<num<<'#'<<std::endl;

		// for(std::vector<unsigned long>::iterator j=array->begin();j!=array->end();j++){
	  // if(*j==num){
	  //   collisions++;
		//
		//
	  //   break;
	  // }
	// }
//std::cout<<collisions<<std::endl;
		// Code for computing the hash and updating the array
permutation_count++;
	} while(std::next_permutation(str.begin(), str.end()));

	for(int i=0;i<M;i++){
unsigned long a=bernstein(input[i], M);
//std::cout<<input[i]<<std::endl;
	if(num[a]==true) collisions++;
	else num[a]=true;


	}

	//Code for determining goodness
goodness=collisions/permutation_count;
	return goodness;
}
