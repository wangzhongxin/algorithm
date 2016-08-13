# include <fstream>
# include <iostream>
# include <string>
# include "./red-black-node.h"

using std::ofstream;
using std::endl;
using std::string;

template<class T>
void pre_progress(ofstream & out,red_black_node<T>* root){
  out<<root->Value()<<"[color="<<(root->Color()==BLACK?"black":"red")<<"]"<<endl;
  if(root->Left()) pre_progress(out,root->Left());
  if(root->Right()) pre_progress(out,root->Right());
}

template<class T>
void visit_node(ofstream &out,red_black_node<T>* root){
  if(root->Left()){
    out << root->Value() <<" ->" << root->Left()->Value() <<endl;
    visit_node(out,root->Left());
  }
  if(root->Right()){
    out << root->Value() <<" ->" << root->Right()->Value()<<endl;
    visit_node(out,root->Right());
  }
}

template<class T>
void createDotFile(string filename,red_black_node<T>* root){
  ofstream out;
  out.open(filename);

  out << "digraph mygraph{"<<endl;
  pre_progress(out,root);
  visit_node(out,root);
  out << "}" <<endl;
  out.close();
}
