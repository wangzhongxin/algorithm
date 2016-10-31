/*
  需使用c++11进行编译
*/
# include <iostream>
# include <string>
# include <cstring>

using std::cout;
using std::endl;
using std::string;

struct commonStr{
  const char* ptr;
  int len;
};

/*
  获取最大公共子串
  return: commonStr
*/
struct commonStr getCommonMaxSubStr(const char* ptr1,const int len1,const char* ptr2,const int len2){
  if(len1 ==0 || len2==0) return { 0,0 };
  //optimize
  if(len2 > len1){
    return getCommonMaxSubStr(ptr2,len2,ptr1,len1);
  }
  //find
  const char* ptr = strstr(ptr1,string(ptr2,len2).c_str());
  if(ptr) return {ptr,len2};
  
  //compare
  auto ans1 = getCommonMaxSubStr(ptr1,len1,ptr2+1,len2-1);
  auto ans2 = getCommonMaxSubStr(ptr1,len1,ptr2,len2-1);

  //return
  return (ans1.len > ans2.len ? ans1 : ans2);
}

int main(){
  string a1="hdsallellohsadllx";
  string a2="llox";

  auto a = getCommonMaxSubStr(a1.c_str(),a1.length(),a2.c_str(),a2.length());
  cout << a.len <<": "<<string(a.ptr,a.len)<<endl;
  return 0;
}
