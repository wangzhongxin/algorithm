# pragma once

class TREE_NODE{
public:
  TREE_NODE():child_left(0),child_right(0),parent(0),intvalue(0){
  }
  TREE_NODE(int initvalue):child_left(0),child_right(0),parent(0),intvalue(initvalue){
  }

  ~TREE_NODE(){
    if(this->child_left){
     delete this->child_left;
     this->child_left=0;
    }
    if(this->child_right){
      delete this->child_right;
      this->child_right=0;
    }
  }

  TREE_NODE* insert(TREE_NODE* child){
    if(this->value()>child->value()){
      if(this->child_left) this->child_left->insert(child);
      else this->insert_left(child);
    }else{
      if(this->child_right) this->child_right->insert(child);
      else this->insert_right(child);
    }

    return this;
  }


  TREE_NODE* left() const{
    return this->child_left;
  }
  TREE_NODE* right() const{
    return this->child_right;
  }

  int value() const{
    return this->intvalue;
  }


protected:
  class TREE_NODE* child_left;
  class TREE_NODE* child_right;
  class TREE_NODE* parent;
  int intvalue;

  TREE_NODE* insert_left(TREE_NODE* child){
    this->child_left=child;
    if(child) child->parent=this;
    return this;
  }
  TREE_NODE* insert_right(TREE_NODE* child){
    this->child_right=child;
    if(child) child->parent=this;
    return this;
  }
};
