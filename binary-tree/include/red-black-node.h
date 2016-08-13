
# pragma once

# define RED 1
# define BLACK 0

template<class T>
class red_black_node{
  private:
    int color;
    red_black_node* left;
    red_black_node* right;
    red_black_node* parent;
    T value;
  public:
    red_black_node(T value,int color):value(value),color(color),left(0),right(0),parent(0){
    }

    red_black_node* Left() const {
      return left;
    }

    red_black_node* Right() const{
      return right;
    }

    T Value() const{
      return value;
    }
    
    int Color() const{
      return color;
    }

    red_black_node* insert(red_black_node* newnode){
      if(this->value > newnode->value){
        if(this->left) this->left->insert(newnode);
        else{
          this->left=newnode;
          newnode->parent=this;
          return adjust(newnode);
        }
      }else{
        if(this->right) this->right->insert(newnode);
        else{
          this->right=newnode;
          newnode->parent=this;
          return adjust(newnode);
        }
      }
      return this;
    }

    //left rotate
    //   A       ->        R
    // L   R             A
    //                 L
    red_black_node* left_rotate(){
      auto parent = this->parent;
      if(parent && parent->left == this) parent->left=this->right;
      if(parent && parent->right == this) parent->right =this->right;

      this->parent= this->right;
      this->right->parent = parent;

      auto temp=this->right->left;
      this->right->left=this;
      this->right=temp;

      return this;
    }

    //reverse leftrotate
    red_black_node* right_rotate(){
      auto parent = this->parent;
      if(parent && this == parent->left) parent->left = this->left;
      if(parent && this == parent->right) parent->right = this->left;

      this->parent = this->left;
      this->left->parent=parent;
      auto temp = this->left->right;
      this->left->right= this;
      this->left = temp;
      return this;
    }

    red_black_node* adjust(red_black_node* newnode){
      auto current = newnode;
      // the current's color is red!
      while(current->parent && current->parent->color ==RED){
        auto parent = current->parent;
        auto g =current->parent->parent; // parent is not null

        if(g->left==parent){
          if(g->right && g->right->color ==RED){
            //case 1
            g->right->color=BLACK;
            parent->color=BLACK;
            g->color=RED;
            current = g;
          }else{
            //case 2
            if(current == parent->right) parent->left_rotate();
            /*    g                 p
             *   p    ->          a    g
             *  a
             * */
            g->color=RED;
            parent->color=BLACK;
            g->right_rotate(); // that's right
          }
        }else{
          if(g->left && g->left->color==RED){
            //case 3
            g->left->color =BLACK;
            parent->color=BLACK;
            g->color=RED;
            current =g;
          }else{
            //case 4
            //reverse case 2
            g->color=RED;
            parent->color=BLACK;
            g->left_rotate();
          }
        }
      }
      auto root = current;
      while(root->parent) root=root->parent;
      root->color=BLACK;
      return root; // the new root
    }

};
