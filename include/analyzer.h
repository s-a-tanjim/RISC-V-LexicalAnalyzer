#include<vector>
#include "rules.h"
#include "helper.h"
#include "data.h"

#pragma once

class Analyzer{
private:
  string line;
  Data *d;

  void removeComment(){
    if(line.length()>0 && line[0]=='#'){
      line="";
    }
    //Checking comment in the end
    for(int i=1;i<line.length();i++){
      if(line[i]=='#'){
        line = line.substr(0,i-1);
        break;
      }
    }
  }

  string keywordCheck(){
    if(line.length()==0) return "";

    //separate opcode
    string opcode = "";
    int i=0;
    for(;i<line.length() && line[i]!=' ';i++){
      opcode+=line[i];
    }

    //find if opcode is valid
    auto itr = Rules::lexicalRules.find(opcode);
    if(itr==Rules::lexicalRules.end())
      return ""; // opcode is not valid

    string operand = Helper::operandsSeparator(line,i);

    return checkOperand(opcode,operand,itr->second);
  }

  string checkOperand(string opcode, string operand, string operand_rules){
    vector<string> rules = Helper::split(operand_rules,",");
    vector<string> operators = Helper::split(operand,",");

    //If both size is not same then invalid syntax. ie: reg,reg,reg != x0,a0
    if(rules.size()!=operators.size()) return "";

    bool flag = 0;
    for(int i=0;i<rules.size();i++){
      bool res = Helper::operandMacher(rules[i],operators[i]);
      if(!res) {
        flag = 1;
        break;
      }
    }

    if(flag==0) { //Grammar is OK
      Data::storeData("opcode",opcode);
      for(int i=0;i<rules.size();i++) {
        Data::storeData(rules[i],operators[i]);
      }
    } else { //Grammar is not okay
      return "";
    }

    return "";
  }

public:
  Analyzer(string _output_file){
    d = new Data(_output_file);
  }

  ~Analyzer(){
    delete d;
  }

  void analyze(string s){
    line = s;
    removeComment();

    string temp = keywordCheck();
  }

  void saveData(){
    d->saveData();
  }
};
