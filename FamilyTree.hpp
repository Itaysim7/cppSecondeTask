#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace family 
{
class Tree{
   private:
        string data;
        Tree* mother;
        Tree* father;
        Tree* son;
  public:
    // methods defined inline:
    Tree(string data1)
    {
        data=data1;
        mother=NULL;
        father=NULL;
        son=NULL;
    }
    ~Tree()
    {
        delete this->father;
        delete this->mother;
     }
    // methods defined in the CPP file:
    Tree& addFather(string,string);
    Tree& addMother(string,string);
    string relation(string);
    string find(string);
    void display();
    bool remove(string); 
private:
    Tree* findMe(Tree*, string);
    int depth(Tree*, string);
    string helpFind(Tree*,int,int);
    void print2DUtil(Tree *root, int space);
    }; 
};
