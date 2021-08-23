#include <iostream>
#include <cctype>
#include "characters.h"

int main() {
  //clears output
  std::ofstream output;
  output.open("output.txt");
  if(output.is_open()){
    output << '\n';
  }
  output.close();

  character ch [26];
  char c;
  int size = 0;
  //input.txt is a AI generated chapter of Harry Potter

  //creates array of characters with their frequency from input.txt
  inputCharArray(ch, "input.txt", size);

  //Selection sort the array alphabetically
  sortCharArray(ch, size); 

  printCharArray(ch, size, "output.txt");

  //converts array into binary tree
  node * root = charArrayToTree(ch, size);

  // prints binary tree with inOrder traversal to screen and file
  std::cout << "The contents of the binary tree are:\n";
  printTree(root, "output.txt");

}