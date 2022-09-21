#include <typeinfo>
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <variant> 
#include <string> 
using namespace std; 

vector<vector<float>> df; 

void print_df(){
    for(int i = 0; i < df.size(); i++){
    for(int j = 0; j < df[i].size(); j++){
      if(j < df[i].size() - 1){
        cout << df[i][j] << ",";  
      }
      else{
        cout << df[i][j];
      }
    }
    cout << endl; 
  }
}

int num_vars(){
  fstream file; 
  int j; 
  file.open("file.csv",ios::in);
  if(file.is_open()){
    string line; 
    while(getline(file,line)){ 
      j = 1; 
      for(int i = 0; i < line.length(); i++){
        if(line[i] == ','){
          j++;
        }
      }
      break; 
    }
    file.close();
  }
  return j;
}


int main(){
  fstream file; 
  file.open("file.csv",ios::in);
  if(file.is_open()){
    string line; 
    int length = 0; 
    while(getline(file,line)){
      vector<float> ls = {}; 
      length ++; 
      string tmp = ""; 
      int j = 0; 
      for(int i = 0; i < line.length(); i++){
        if(line[i] != ','){
          tmp += line[i];
          if(i == line.length() - 1){
            try{
              ls.push_back(stof(tmp));
            } 
            catch(invalid_argument) {continue;}
          }
        }
        else{
          j ++;
          try{
            ls.push_back(stof(tmp));
            tmp = "";
          }
          catch(invalid_argument) {continue;}
        }
      }
      df.push_back(ls); 
    }
    file.close(); 
    cout << "There are " << num_vars() << " columns" << " and " << length << " records in the file!" << endl; 
  }
  else{
    cout << "An error has occurred!"; 
  }
  //print_df();   
  return 0; 
}
