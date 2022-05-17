
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
      if(!registerChecker(words[0]))
        return "";
      if(validOperand(words[1]) && validOperand(words[2])){
        if(opcode=="add" || opcode=="addi")
          return words[0]+" = "+words[1]+" + "+words[2];
        else if(opcode=="sub" || opcode=="subi")
          return words[0]+" = "+words[1]+" - "+words[2];
      }

    }
    return "";
  }
};
