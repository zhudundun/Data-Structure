#include <string>
#include <iostream>
#include<algorithm>
#include<vector>

#include "Hash.h"
int incre(int a){
  if(a==1) return 1;
  int b= a*incre(a-1);
  return b;
}
int main()
{
    std::string s = "POTS";
	int M = 13;
  //std::vector<double> vals(1,2,3,2,1);
//vals[0]=1;
    std::cout<<"Bernstein hash of "<<s<<" with range "<<M<<" is: "<<bernstein(s, M)<<'\n';
    std::cout<<"Bernstein hash of the reverse of "<<s<<" - " <<reverse(s)<<" - with range "<<M<<", is: "<<bernstein(reverse(s), M)<<'\n';
  //  std::cout<<vals[4]<<'\n';
    std::cout<<incre(3)<<'\n';
}
