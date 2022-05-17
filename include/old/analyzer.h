#include "rules_checker.h"

class Analyzer{
private:
  string line;
  //string opcodes[]={"add","addi","sub","subi","la","li","ecall"};
  RulesChecker rules_check;

  void commentCheck(){
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

  bool keywordCheck(){
    if(line.length()==0) return true;
    string opcode = "";
    int i=0;
    for(;i<line.length() && line[i]!=' ';i++){
      opcode+=line[i];
    }

    if(opcode=="add" || opcode=="addi" || opcode =="sub" | opcode=="subi") {
      return rules_check.three_op_check(line.substr(i,line.length()-1));
    } else if(opcode=="la" || opcode=="li") {
      return rules_check.two_op_check(line.substr(i,line.length()-1));
    } else if(opcode=="ecall") {
      return rules_check.zero_op_check(line.substr(i,line.length()-1));
    } else {
      return false;
    }
  }



public:

  void analyze(string s){
    line = s;
    commentCheck();

    cout<<line<<endl;
    if(keywordCheck()){
      cout<<"Grammar right!\n";
    } else {
      cout<<"Grammar wrong!\n";
    }

    cout<<endl<<endl;
  }
};
