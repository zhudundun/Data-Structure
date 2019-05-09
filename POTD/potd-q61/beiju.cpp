#include <list>
using namespace std;

string beiju(string input) {
  string output;
  //list<char> bei;

    list<char> texto;
    list<char>::iterator it;

        texto.clear();
        it = texto.begin();
        // for(unsigned i=0;i<input.size();++i)
        // {
        //     if(input[i]=='[')
        //         it = texto.begin();
        //     if(input[i]==']')
        //         it = texto.end();
        //     if(input[i]!='[' && input[i]!=']')
        //         texto.push_back(input[i]);
        //
        // }
        for(unsigned i=0;i<input.size();++i)
        {
            if(input[i]=='[')
                it = texto.begin();
            if(input[i]==']')
                it = texto.end();
            //if(input[i]=='[' || input[i]==']') bei.push_back(input[i]);;
            if(input[i]!='[' && input[i]!=']')
            texto.insert(it,input[i]);

        }
      //  for(it=bei.begin();it!=bei.end();it++) output.push_back(*it);
        for(it=texto.begin();it!=texto.end();it++) output.push_back(*it);

    return output;
}
