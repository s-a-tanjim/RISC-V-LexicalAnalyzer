#pragma once

class ThreeOperand:public Rules
{
private:
  string opcode;
  string line;
  vector<string> words;
public:
  ~ThreeOperand(){
    words.clear();
  }

  bool validOperand(string s){
    return registerChecker(s) || numberChecker(s);
  }

  void setValue(string _opcode,string _line) {
    opcode = _opcode;
    line = _line;
  }

  string check(){
    line = removeSpace(line);
    words = split(line,",");
    if(words.size()==3){
      if(!registerChecker(words[0]) || !registerChecker(words[1]))
        return "";
      if(opcode=="add" && registerChecker(words[2])){

        DatastructureGenerator::addData("opcode",opcode);
        DatastructureGenerator::addData("register",words[0]);
        DatastructureGenerator::addData("register",words[1]);
        DatastructureGenerator::addData("register",words[2]);
        return words[0]+" = "+words[1]+" + "+words[2];

      } else if(opcode=="addi" && numberChecker(words[2])) {

        DatastructureGenerator::addData("opcode",opcode);
        DatastructureGenerator::addData("register",words[0]);
        DatastructureGenerator::addData("register",words[1]);
        DatastructureGenerator::addData("number",words[2]);
        return words[0]+" = "+words[1]+" + "+words[2];

      } else if(opcode=="sub" && registerChecker(words[2])) {

        DatastructureGenerator::addData("opcode",opcode);
        DatastructureGenerator::addData("register",words[0]);
        DatastructureGenerator::addData("register",words[1]);
        DatastructureGenerator::addData("register",words[2]);
        return words[0]+" = "+words[1]+" - "+words[2];

      } else if(opcode=="subi" && numberChecker(words[2])) {

        DatastructureGenerator::addData("opcode",opcode);
        DatastructureGenerator::addData("register",words[0]);
        DatastructureGenerator::addData("register",words[1]);
        DatastructureGenerator::addData("number",words[2]);
        return words[0]+" = "+words[1]+" - "+words[2];

      }
    }
    return "";
  }
};
