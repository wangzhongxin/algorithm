# include <iostream>
# include <time.h>
# include <stdlib.h>


using std::cout;
using std::endl;

template<class T>
void swap(T& a , T& b){
  T c=a;
  a=b;
  b=c;
}

// the quick sort
template<class T>
void quick_sort(T* source,const int length){
  if(length<=1) return;

  if(length==2){
    if(source[0]>source[1])
      swap(source[0],source[1]);
    return;
  }

  int begin=0;
  int end=length-2;
  while(begin<end){
    //find first large than source[length-1]
    while(begin<end && source[begin]<=source[length-1]) begin++;
    //find last less than source[length-1]
    while(end>begin && source[end]>source[length-1]) end--;
    if(begin<end) swap(source[begin],source[end]);
  }
  swap(source[begin],source[length-1]);
  quick_sort(source,begin);
  quick_sort(&source[begin],length-begin);
}

int main(){
  srand(time(0));

  //random array
  int a[]={1,3,6,4,3};
  for(int i=0;i<5;++i){
    a[i]=rand()%255;
    cout<<a[i]<<" ";
  }
  cout<<endl;

  quick_sort(a,5);

  for(int i=0;i<5;++i){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
