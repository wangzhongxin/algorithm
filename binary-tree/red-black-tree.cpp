# include <iostream>
# include "./include/red-black-node.h"
# include "./include/dot.h"

using std::endl;
using std::cout;

int main(){
  int array[] ={1,2,3,4,5,6,7};
  red_black_node<int>* root=NULL;

  for(int i=0;i<sizeof(array)/sizeof(int);++i){
    if(!root) root=new red_black_node<int>(array[i],BLACK);
    else root = root->insert(new red_black_node<int>(array[i],RED));
  }

  createDotFile("mytree.dot",root);

  cout << " done !" <<endl;
  return 0;
}
