#include <regex>
#include<vector>
#include<string>

#pragma once

class Helper
{
public:
  static vector<string> split (string s, string delimiter) {
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

  static string removeSpace(string s){
    string f="";
    for(int i=0;i<s.length();i++){
      if(s[i]!=' ')
        f+=s[i];
    }
    return f;
  }

  static string operandsSeparator(string line,int from_index) {
    string str="";
    for(int i=from_index;i<line.length();i++){
      str+=line[i];
    }
    return removeSpace(str);
  }

  static bool registerChecker(string s){
    regex reg("[xa][0-9]+");
    if(regex_match(s,reg)){
      return true;
    }
    return false;
  }

  static bool numberChecker(string s){
    regex num("[0-9]+");

    if(regex_match(s,num)){
      return true;
    }
    return false;
  }

  static bool variableChecker(string s){
    regex num("[a-zA-Z_][a-zA-Z_0-9]*");

    if(regex_match(s,num)){
      return true;
    }
    return false;
  }

  static bool operandMacher(string rule,string op) {
    if(rule=="reg" && registerChecker(op)) return true;
    else if(rule=="var" && variableChecker(op)) return true;
    else if(rule=="numb" && numberChecker(op)) return true;
    else if(rule=="none" && op.length()==0) return true;
    return false;
  }
};

