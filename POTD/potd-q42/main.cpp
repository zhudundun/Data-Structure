#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    // unordered_map<string, int> mapA({
    //                                 {"common", 13},
    //                                 {"unique_a", 13}
    //                                 });
    // unordered_map<string, int> mapB({
    //                                 {"common", 17},
    //                                 {"unique_b", 17}
    //                                 });

                                    unordered_map<string, int> mapA({
                                                                    {"a", 1},
                                                                    {"b", 2},
                                                                    {"c", 3}
                                                                    });
                                    unordered_map<string, int> mapB({
                                      {"a", 4},
                                      {"b", 5},
                                      {"d", 6}
                                                                    });


    unordered_map<string, int> common =common_elems(mapA, mapB);

    // check your outputs here
    int sum=0;
    int c=0;
    unordered_map<std::string, int>::iterator it ;

    for (it=mapB.begin();it!=mapB.end();it++) {
      sum+=it->second;
      c++;
    cout<<it->first<<endl;}
    cout<<c<<endl;


}
