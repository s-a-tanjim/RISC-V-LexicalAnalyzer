#include<vector>
#include <regex>

class RulesChecker{

private:
  string line;
  vector<string> words;
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

  bool validOperand(string s){
    return registerChecker(s) || numberChecker(s);
  }

public:
  bool three_op_check(string s){
    line = removeSpace(s);
    words = split(line,",");
    if(words.size()==3){
      if(!registerChecker(words[0]))
        return false;
      if(validOperand(words[1]) && validOperand(words[2]))
        return true;
    }
    return false;
  }

  bool two_op_check(string s){
    line = removeSpace(s);
    words = split(line,",");
    if(words.size()==2){
      if(!registerChecker(words[0]))
        return false;
      return true;
    }

    return false;
  }

  bool zero_op_check(string s){
    line = s;
    if(line.length()==0)
      return true;
    return false;
  }
};
