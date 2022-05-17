#include<vector>
#include <regex>

class Rules
{
public:
  //Line splitter
  vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
  }

  string removeSpace(string s){
    string f="";
    for(int i=0;i<s.length();i++){
      if(s[i]!=' ')
        f+=s[i];
    }
    return f;
  }


  bool registerChecker(string s){
    regex reg("[xa][0-9]+");
    if(regex_match(s,reg)){
      return true;
    }
    return false;
  }

  bool numberChecker(string s){
    regex num("[0-9]+");

    if(regex_match(s,num)){
      return true;
    }
    return false;
  }

  bool variableChecker(string s){
    regex num("[a-zA-Z_][a-zA-Z_0-9]*");

    if(regex_match(s,num)){
      return true;
    }
    return false;
  }

  virtual bool validOperand(string s)=0;
  virtual void setValue(string _opcode,string _line)=0;
  virtual string check()=0;
};

