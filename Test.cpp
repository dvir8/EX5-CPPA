#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <array>
#include "BinaryTree.hpp"
using namespace std;



using namespace ariel;



TEST_CASE("GOOD TREE"){
    BinaryTree<int> tree_of_ints;
    tree_of_ints.add_root(1)
  .add_left(1, 9)      // Now 9 is the left child of 1
  .add_left(9, 4)      // Now 4 is the left child of 9
  .add_right(9, 5)     // Now 5 is the right child of 9
  .add_right(1, 3)     // Now 3 is the right child of 1
  .add_left(1, 2);     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  int arr[6] = {1,2,4,5,3};
  size_t i =0;

    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
     CHECK_EQ(*it,arr[i]);
     i++;
     
  } 
  i = 0;
  int arr2[6] = {4 , 2 , 5 ,  1 ,  3};
  for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
     CHECK_EQ(*it,arr2[i]);     
     i++;
  }
  i = 0;
  int arr3[6] = {4 , 5 , 2 ,  3 ,  1};
  for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
    
     CHECK_EQ(*it,arr3[i]);     
     i++;
  }
  i = 0;
  for (int element: tree_of_ints) {  // this should work like inorder
  
    CHECK_EQ(element,arr3[i]);
    i++;
     
  }
  
  BinaryTree<string> tree_of_strings;
  tree_of_strings.add_root("1")     
  .add_left("1", "9")      // Now 9 is the left child of 1
  .add_left("9", "4")      // Now 4 is the left child of 9
  .add_right("9", "5")     // Now 5 is the right child of 9
  .add_right("1", "3")     // Now 3 is the right child of 1
  .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
  cout << tree_of_strings << endl; 
  const array<string, 5> s = {"1", "2", "4", "5" , "3"};
  i = 0;
  for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
    CHECK_EQ(*it,s.at(i));
    CHECK_EQ(*it+"s",s.at(i)+"s");
    CHECK_EQ(*it+"sf",s.at(i)+"sf");
    CHECK_EQ(*it+"sfte",s.at(i)+"sfte");
    CHECK_EQ(*it+"sftew",s.at(i)+"sftew");
    i++;
  }  

}






