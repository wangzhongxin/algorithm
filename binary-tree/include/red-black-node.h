
# pragma once

# define RED 0
# define BLACK 1

template<class T>
class red_black_node{
  private:
    int color;
    red_black_node* left;
    red_black_node* right;
    red_black_node* parent;
    T value;
  public:
    red_black_node(T value,int color):color(color),value(value),left(0),right(0),parent(0){
    }

    red_black_node* Left() const{
      return left;
    }

    red_black_node* Right() const{
      return right;
    }

    red_black_node* Parent() const{
      return parent;
    }

    int Color() const{
      return color;
    }

    T Value() const{
      return value;
    }

    red_black_node* insert(red_black_node* newnode) {
      if(this->value > newnode->value){
        if(this->left) return this->left->insert(newnode);
        else{
          this->left=newnode;
          newnode->parent=this;
          return fixup(newnode); // return the new root
        }
      }else{
        if(this->right) return this->right->insert(newnode);
        else{
          this->right=newnode;
          newnode->parent=this;
          return fixup(newnode);
        }
      }
    }

    //left rotate
    /*
     *     P              P
     *     A       ->     R
     *   L   R           A
     *                 L
     * */

    red_black_node* left_rotate(){
      auto parent = this->parent;
      if(parent && parent->left == this) parent->left = this->right;
      if(parent && parent->right == this) parent->right = this->right;

      this->parent = this->right;
      this->right->parent = parent;

      auto temp= this->right->left;
      this->right->left = this;
      this->right = temp;
      return this;
    }

    //right rotate
    //reverse left_rotate
    red_black_node* right_rotate(){
      auto parent = this->parent;
      if(parent && parent->left == this) parent->left = this->left;
      if(parent && parent->right == this) parent->right = this->left;

      this->parent = this->left;
      this->left->parent = parent;

      auto temp = this->left->right;
      this->left->right = this;
      this->left = temp;
      return this;
    }

    red_black_node* fixup(red_black_node* newnode){
      auto current = newnode;
      //the current's color is red
      while(current->parent && current->parent->color == RED){
        auto parent = current->parent;
        auto g = parent->parent ; // parent is not null and color is red -> g is not null

        if(g->left == parent){
          if(g->right && g->right->color == RED){
            //case 1
            g->right->color=BLACK;
            parent->color=BLACK;
            g->color=RED;
            current=g;
          }else{
            //case 2
            if(this == parent->right){
              parent->left_rotate();
              current=parent;
            }else{
              /*
               *   G           P
               *  P    ->    A   G
               * A
               * */
              g->right_rotate();
              g->color=RED;
              parent->color=BLACK; // that's right
            }
          }
        }else{
          if(g->left && g->left->color == RED){
            //case 3
            g->left->color = BLACK;
            parent->color = BLACK;
            g->color =RED;
            current = g;
          }else{
            //case 4
            //reverse case 2
            
            if(this == parent->left){
              parent->right_rotate();
              current=parent;
            }else{
              g->left_rotate();
              g->color=RED;
              parent->color=BLACK;
            }
          }
        }
      }

      auto root = current;
      while(root->parent) root = root->parent;
      root->color=BLACK;

      return root; // the new root
    }
};

