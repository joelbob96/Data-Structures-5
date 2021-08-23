#include <iostream>
#include <fstream>
#include <string>

struct character{
  char c = '*';
  int num = 1;
};

struct node{
  character ch;
  node * left = NULL;
  node * right = NULL;
};

void printCharArray(character ch[], int size, std::string o){
  std::cout << "The contents of the array are:\n";
  for(int i = 0; i < size; i++){
    std::cout << '|' <<ch[i].c << "| " << ch[i].num << '\n';
  }
  std::cout << '\n';

  std::ofstream output;
  output.open(o, std::ios_base::app);
  if(output.is_open()){
    output << "The contents of the array are:\n";
    for(int i = 0; i < size; i++){
    output << '|' <<ch[i].c << "| " << ch[i].num << '\n';
    }
    output << '\n';
    output.close();
  }
}

void inputCharArray(character ch[], std::string str, int &size){
char c;
std::string filename(str);
  FILE* input = fopen(filename.c_str(), "r");
  bool stored;
    while(!feof(input)){
      stored = false;
      c = tolower(getc(input));
      if(isalpha(c)){
      for(int i = 0; i < size; i++){
        if(ch[i].c == c){
          ch[i].num++;
          stored = true;
        }
      }
      if(stored == false){
        ch[size].c = c;
        size++;
        }
      }
    }
    fclose(input);
}

void Swap(character &a, character &b){
  character temp = a;
  a = b;
  b = temp;
}

//bubble sort
void sortCharArray(character ch[], int size){
  for(int i = 0; i < size; i++){
    for(int j = i + 1; j < size; j++){
      if(ch[i].num < ch[j].num)
        Swap(ch[i], ch[j]);
    }
  }
}

//Adds nodes to tree based on frequency
void Add(node * root, character ch){
  if(root->ch.num < ch.num){
    if(root->left != NULL){
      //std::cout << ch.c << " went left\n";
      Add(root->left, ch);
    }else{
      root->left = new node;
      root->left->ch = ch;
      //std::cout << ch.c << " added\n";
    }
    }else{
      if(root->right != NULL){
    //std::cout << ch.c << " went right\n";
    Add(root->right, ch);
      }else{
        root->right = new node;
      root->right->ch = ch;
      //std::cout << ch.c << " added\n";
      }
  }
}

node * charArrayToTree(character ch[], int size){
  node * root = new node;
  root->ch = ch[0];

  for(int i = 1; i < size-1; i++){
  Add(root, ch[i]);
  }
  
  return root;
}

//In order traversal printing
void printTree(node * root, std::string o){
  if(!root) return;
  printTree(root->left, o);
  std::ofstream output;
  output.open(o, std::ios_base::app);
  if(output.is_open()){
    output << root->ch.c << " occurs " << root->ch.num << " times\n";
  }
  output.close();
  std::cout << root->ch.c << " occurs " << root->ch.num << " times\n";
  printTree(root->right, o);
}