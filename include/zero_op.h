class ZeroOperand:public Rules
{
private:
  string opcode;
  string line;
  vector<string> words;
public:
  ~ZeroOperand(){
    words.clear();
  }

  bool validOperand(string s){
    if(s.length()==0)
      return true;
    return false;
  }

  void setValue(string _opcode,string _line) {
    opcode = _opcode;
    line = _line;
  }

  string check(){
    if(validOperand(line)){
      DatastructureGenerator::addData("opcode",opcode);
      return ";";
    }
    else
      return "";
  }
};
