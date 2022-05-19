#include<string>
#include<map>

#pragma once

class Rules
{
private:
  
public:
  static map<string,string> lexicalRules;
  Rules(/* args */);
  ~Rules();
};


map<string,string> Rules::lexicalRules = {
   {"add", "reg,reg,reg"},
   {"addi", "reg,reg,numb"},
   {"sub", "reg,reg,reg"},
   {"subi", "reg,reg,numb"},
   {"li", "reg,numb"},
   {"la", "reg,var"},
   {"ecall", "none"}
};
