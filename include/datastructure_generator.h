#include<map>
#include<String>
#include <fstream>

class DatastructureGenerator
{
private:
  static map<string,string> data;
  static ofstream outputfile;
public:
  static void addData(string type,string value){
    auto itr = data.find(type); 
    if(itr!=data.end()) {
      string s = itr->second+", "+value;
      data.insert({ type, s });
    } else {
      data.insert({ type, value });
    }
  }

  static void saveData(string file_name){
    outputfile.open(file_name,ios::out);
    
    for (auto itr = data.begin(); itr != data.end(); ++itr) {
      outputfile <<itr->first << '\t' << itr->second<< '\n';
    }
    outputfile.close();
  }
};