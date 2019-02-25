#include "List.h"

int main() {
  List<int> endlist;
  for(int i=0;i<5;i++) endlist.insertBack(i);
  std::cout<<endlist<<std::endl;
  endlist.reverseNth(3);
  std::cout<<endlist<<std::endl;
  endlist.printback();
  return 0;
}
