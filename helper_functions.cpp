vector<vector<float>> remove_col(vector<vector<float>> df, int idx){
  for(int i = 0; i < df.size(); i++){
    df[i].erase(df[i].begin() + idx);
  }
  return df;
}

vector<float> get_col(vector<vector<float>> df, int idx){
  vector<float> col; 
  for(int i = 0; i < df.size(); i++){
    col.push_back(df[i][idx]);
  }
  return col; 
}
