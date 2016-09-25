# include <iostream>
# include <vector>

using namespace std;

int mcount=0 ;
void ccount(vector<int>& array,vector<int>& stack,int deep)  {
  vector<int> temp(array);
  if(!deep) {
    mcount++;
    for(const int i : stack)
      cout << i;
    cout << endl;
    return;
  }
  else{
    for(const int i : array){
      stack.push_back(temp.back());
      temp.pop_back();
      ccount(temp,stack,deep-1);
      stack.pop_back();
    }
  }
}

int main(){
  const int N = 5;
  int width = 2;
  vector<int> array ;
  vector<int> stack;
  for(int i=0;i<N;++i) array.push_back(i);
  ccount(array,stack,width);
  cout << "count is" << mcount <<endl;
  return 0;
}
