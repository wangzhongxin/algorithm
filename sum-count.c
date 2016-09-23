# include <stdio.h>

int sum_cur(int *array,int offset,int length,int max){
  if(max <= 0 || length<=0 ) return 0;
  int count = 0;
  for(int i=0;i<length;++i){
    if(max == array[offset+i]) count++;
    else count += sum_cur(array,offset+i+1,length-i-1,max-array[offset+i]);
  }
  return count;
}

int main(){
  int a[]={5,10,1,10,5};
  printf("%d\n",sum_cur(a,0,5,15));
  return 0;
}
