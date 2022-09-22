#include <iostream> 
#include <cstdlib>
#include <fstream> 
#include <time.h>
#include <vector>  
#include <string> 

using namespace std;

struct train_test_split_result{
  vector<vector<float>> train; 
  vector<vector<float>> test; 
};

train_test_split_result train_test_split(vector<vector<float>> df, float train_size = 0.8){
  train_test_split_result result;
  srand(time(NULL)); 
  for(int i = 0; i < df.size(); i++){
    int x = rand() % 10 + 1; 
    if(x <= train_size * 10){
      result.train.push_back(df[i]);
    } 
    else{
      result.test.push_back(df[i]);
    }
  }
  cout << "training size: " << result.train.size() << ", test size: " << result.test.size() << endl;
  return result; 
} 
