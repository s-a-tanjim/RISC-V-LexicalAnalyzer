#include "rules.h"
#include "zero_op.h"
#include "two_op.h"
#include "three_op.h"
#include "output.h"

class Analyzer{
private:
  string line;
  Rules *rules=nullptr;
  Output *op_file=nullptr;

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

  string keywordCheck(){
    if(line.length()==0) return "";

    //separate opcode
    string opcode = "";
    int i=0;
    for(;i<line.length() && line[i]!=' ';i++){
      opcode+=line[i];
    }

    if(rules!=nullptr)
      delete rules;

    if(opcode=="add" || opcode=="addi" || opcode =="sub" | opcode=="subi") {
      rules = new ThreeOperand();

    } else if(opcode=="la" || opcode=="li") {
      rules = new TwoOperand();

    } else if(opcode=="ecall") {
      rules = new ZeroOperand();

    } else {
      return "";
    }

    rules->setValue(opcode,line.substr(i,line.length()-1));
    return rules->check();
  }



public:
  Analyzer(string _output_file){
    op_file = new Output(_output_file);
  }

  ~Analyzer(){
    if(rules!=nullptr)
      delete rules;
    delete op_file;
  }

  void analyze(string s){
    line = s;
    commentCheck();

    cout<<line<<endl;
    string temp = keywordCheck();
    if(temp!="")
      op_file->writeLine(temp);
  }
};
