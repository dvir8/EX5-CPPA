#include<stdio.h>
#include<map>
using namespace std;


namespace ariel{
        template <typename T>
    
    class BinaryTree{
        map<T,T> L_map;
        map<T,T> R_map;
        struct Node
        {
            int inst;
            Node *left;
            Node *right;
            Node *parent;
            T theValue;
            Node(T val){
                theValue=val;
                inst=0;
            }
        };
        Node *root;

        public:
        

    BinaryTree<T> add_root(T p){
        
        if(!root){
            Node * x = new Node(p);
            x->theValue =p;
            x->inst++;
            root = x;
        }
        
        
        return *this;
    }


        
    BinaryTree<T> add_left(T p ,T a){
        
        
        if(!L_map.count(p)){
            root->inst++;
            L_map.emplace(p,p);
        }
      
        return *this;
    }
        
    
    BinaryTree<T> add_right(T p,T a){   
          
        if(!R_map.count(p)){
            root->inst++;
            R_map.emplace(p,p);
        }
        return *this;

    }
        BinaryTree<T>(Node * ro=nullptr):root(ro){
            
            
        } 
        
        
        


        public:	

	class iterator {

	  private:
        Node *CurrentIndex;
        int index;
       
    public:
        iterator(Node * x = nullptr):CurrentIndex(x){
            index =0;          
            
            
        }
        bool operator!=(const iterator& it) const{
            
            return CurrentIndex->inst!=index;
        }
        

        iterator& operator ++(){
            index++;
            return *this;
        }
        iterator& operator ++(int){
            
            iterator it = *this;
            ++it.index;
            return it;
        }

        T* operator ->(){
            
            return &CurrentIndex->theValue;
        }
        T& operator *(){
            return CurrentIndex->theValue;
        }
        T size(){
            return 0;
        }
        
    };
    
        friend ostream& operator<<(ostream& a, BinaryTree<T>){
            return a;
        }
        
        iterator begin_inorder(){
                return iterator{root};
        }

        iterator end_inorder(){
            

            return iterator{nullptr};
        }

       iterator begin_preorder(){
           
        return iterator{root};
        }

        iterator end_preorder(){
           
        return iterator{nullptr};
        }

        iterator begin_postorder(){
            
        return iterator{root};
        }

        iterator end_postorder(){
        return iterator{nullptr};
        }
        iterator begin(){
           return iterator{root};
        }

        iterator end(){
            return iterator{nullptr};
        }
};
    }



