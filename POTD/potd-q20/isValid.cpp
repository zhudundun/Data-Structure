#include <string>
#include <stack>
#include <queue>
#include<iostream>

using namespace std;

bool isValid(string input) {
    stack<char> st;

  //  if (input.empty()) return true;

    for (unsigned i=0; i<input.length(); i++) {
      char c=input[i];
      if(c=='[' || c=='{' || c=='(') st.push(c);

      if (c==']' || c=='}' || c==')'){
        if (st.empty()) return false;

          if( c==']' && st.top()=='[' ) st.pop();
          if( c==')' && st.top()=='(' ) st.pop();
          if( c=='}' && st.top()=='{' ) st.pop();

      }
    }

      if (st.empty()) return true;
       else return false;

    } // modify this!
