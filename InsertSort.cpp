# include <iostream>
# include <vector>

using std::cout;
using std::vector;
using std::endl;

vector<int> insert_sort(vector<int> source){
  vector<int> answer;
  for(const auto iter: source){
    auto iiter = answer.begin();
    while(iiter!=answer.end()){
      if(iter > *iiter) iiter++;
      else break;
    }
    answer.insert(iiter,iter);
  }
  return answer;
}

int main(){
  vector<int> source={3,4,6,1,23,23};

  auto answer=insert_sort(source);

  for(const auto iter : answer){
    cout << iter << " ";
  }
  cout<<endl;
  return 0;
}
