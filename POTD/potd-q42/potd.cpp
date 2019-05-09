#include <unordered_map>

using namespace std;

unordered_map<string, int> common_elems(unordered_map<string, int>& mapA,
                                        unordered_map<string, int>& mapB) {

    // your code here
unordered_map<string, int>* mapC=new unordered_map<string, int>;
//bool ex=false;
    for (pair<string, int> elementA : mapA){
      for(pair<string, int> elementB : mapB){

        if (elementA.first==elementB.first) {
          elementA.second=elementA.second+elementB.second;
          mapC->insert(elementA);

          //ex=true;
        }

      }
}

unordered_map<std::string, int>::iterator it ;

      for(pair<string, int> elementC : *mapC){
        for (it=mapA.begin();it!=mapA.end();it++){
          if (it->first==elementC.first)  { mapA.erase(it);
            //ex=true;
 break;}
        }
  }

  for(pair<string, int> elementC : *mapC){
    for (it=mapB.begin();it!=mapB.end();it++){
      if (it->first==elementC.first) {mapB.erase(it);
        //ex=true;
        break;}
    }

}

//ex=false;

    return *mapC;

    //return unordered_map<string, int>();
}
