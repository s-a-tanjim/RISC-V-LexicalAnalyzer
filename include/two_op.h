class TwoOperand:public Rules
{
private:
  string opcode;
  string line;
  vector<string> words;
public:
  ~TwoOperand(){
    words.clear();
  }

  bool validOperand(string s){
    if(opcode=="li") {
      return numberChecker(s);
    } else if(opcode=="la") {
      return variableChecker(s);
    }
    return false;
  }

  void setValue(string _opcode,string _line) {
    opcode = _opcode;
    line = _line;
  }

  string check(){
    line = removeSpace(line);
    words = split(line,",");
    if(words.size()==2){
      if(!registerChecker(words[0]))
        return "";
        if(validOperand(words[1])) {
          return words[0]+" = "+words[1];
        }
    }
    return "";
  }
};
