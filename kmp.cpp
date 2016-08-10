# include <iostream>
# include <string.h>

using std::cout;
using std::endl;

inline int max(int a,int b){
  return a>b?a:b;
}


int main(){
  const char * source = "ABC ABC ABDDABC ABDDAB ABCDABCDABDE";
  const char * pattern = "ABCDABD";

  signed int compile_pattern[7] = {0};

  //KMP Begin
  for(int i=0;i<strlen(pattern);++i){
    if(i==0) compile_pattern[i] = -1;
    if(i==1) compile_pattern[i] = 0;
    else if(pattern[i-1]==pattern[compile_pattern[i-1]])
      compile_pattern[i] = compile_pattern[i-1]+1;
  }
  //KMP End

  cout<<"compile pattern: ";
  for(int i : compile_pattern)
    cout<<" "<<i;
  cout<<endl;


  //find substring
  int m=0;
  int i=0;
  int count=0;
  while(i<strlen(pattern)&&m<strlen(source)){
    count++;
    if(pattern[i] == source[m+i]){
      i++;
    }else{
      m=m+i-compile_pattern[i];
      i=max(compile_pattern[i],0);
    }
  }
  if(i==strlen(pattern)){
    cout<<"find it!"<<m<<"  total step :"<<count<<endl;
  }else
    cout<<"can\'t find"<<endl;
  return 0;
}
