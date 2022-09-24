#include <math.h>
#include <typeinfo>
#include <iostream> 
#include <cstdlib>
#include <fstream> 
#include <vector> 
#include <string> 
using namespace std; 


class LinearRegression{
  private:
  vector<float> weights; 
  float bias;
  float lr; 
  int n_iters; 
  
  public:
  LinearRegression(int iterations, float learning_rate){
    this -> n_iters = iterations; 
    this -> lr = learning_rate; 
  }
  
  
  float RMSE(vector<float> Y_train, vector<float> predictions){
    float rmse = 0; 
    for(int i = 0; i < Y_train.size(); i++){
      rmse += pow((Y_train[i] - predictions[i]),2);
    }
    return pow((rmse / Y_train.size()),0.5);
  }
  
  public:
  void fit(vector<vector<float>> X_train, vector<float> Y_train){
    bias = 1; 
    for(int i = 0; i < X_train[0].size(); i++){
      weights.push_back(100);
    }
    for(int i = 0; i < n_iters; i++){
      vector<float> predictions = {}; 
      for(int j = 0; j < X_train.size(); j++){
        vector<float> derivatives;  
        float pred = 0; 
        for(int z = 0; z < weights.size(); z++){
          pred += (weights[z] * X_train[j][z]); 
        }
        pred += bias; 
        predictions.push_back(pred);

        for(int z = 0; z < weights.size(); z++){
          // Calculate derivatives 
          float dw = (X_train[j][z] * (pred - Y_train[j])) * lr;
          derivatives.push_back(dw);
        }
        for(int z = 0; z < weights.size(); z++){
          // Update weights 
          weights[z] -= derivatives[z];
        }
        bias -=  (pred - Y_train[j]) * lr; 
      }
      if(i % 1000 == 0){
        float rmse = RMSE(Y_train, predictions);
        cout << "RMSE after " << i << " iterations is " << rmse << "!" << endl;
      }
    }
  }
  
  public:
  vector<float> predict(vector<vector<float>> X_test, vector<float> y_test){
      vector<float> predictions; 
      for(int i = 0; i < X_test.size(); i++){
          float pred = 0;
          for(int j = 0; j < X_test[0].size();j++){
              pred += (weights[j] * X_test[i][j]) + bias;
          }
          predictions.push_back(pred);
      }
      cout << "RMSE on test data " << RMSE(y_test,predictions) << "!";
      return predictions; 
  }
}; 


int main(){
  df = read_csv(path);
  train_test_split();
  vector<vector<float>> X_train = remove_col(train,train[0].size()-1);
  vector<vector<float>> X_test = remove_col(test,test[0].size()-1);
  vector<float> y_train = get_col(train,train[0].size()-1);
  vector<float> y_test = get_col(test,test[0].size()-1);
  LinearRegression lr = LinearRegression(10000, 0.0000001);
  lr.fit(X_train,y_train);
  lr.predict(X_test,y_test);
  return 0; 
}
