#include<vector>
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


public:
  bool three_op_check(string s){
    line = s;
    words = split(line,",");
    if(words.size()==3)
      return true;
    return false;
  }

  bool two_op_check(string s){
    line = s;
    words = split(line,",");
    if(words.size()==2)
      return true;
    return false;
  }

  bool zero_op_check(string s){
    line = s;
    if(line.length()==0)
      return true;
    return false;
  }
};
