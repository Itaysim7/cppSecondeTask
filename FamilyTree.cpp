#include "FamilyTree.hpp"
#include <iostream>
using namespace family;
using namespace std;

Tree& Tree::addFather(string son,string dad)
{
    Tree* node=findMe(this,son);
    if(node==NULL)
    {
        throw runtime_error(""+son+ "' is not in the family tree");
    }
    if(node->father!=NULL)
    {
        throw runtime_error("There is a father already");
    }
    node->father=new Tree(dad);
    node->father->son=node;
    cout<<dad<<endl;

    return *this;
}
Tree& Tree::addMother(string son,string mom)
{
    Tree* node=findMe(this,son);
    if(node==NULL)
    {
        throw runtime_error(""+son+ "' is not in the family tree");
    }
    if(node->mother!=NULL)
    {
        throw runtime_error("There is a mother already");
    }
    node->mother=new Tree(mom);
    node->mother->son=node;
    cout<<mom<<endl;
    return *this;
}
string Tree::relation(string search)
{
    if(data==search)
        return "me";
    Tree* howIam=findMe(this,search);
    if(howIam==NULL)
        return "unrelated";
    string gender="mother";  
    if(howIam->son->mother==NULL||howIam->son->mother->data!=search)
        gender="father";
    int depthTree=depth(this,search);
    if(depthTree==1)
        return gender;
    gender="grand"+gender;
    if(depthTree==2)
        return gender;
    for(int i=depthTree-2;i>0;i--)
        gender="great-"+gender;
    return gender;
}
string Tree::find(string std)
{
    return std;
}
string Tree::display()
{
    return "";
}
bool Tree::remove(string std){
    return true;
}

Tree* Tree::findMe(Tree* node, string name)
{
    if(node == NULL) return NULL;
    if(node->data == name) return node;
    Tree* treeFather = findMe(node->father, name);
    Tree* treeMother = findMe(node->mother, name);
    if(treeFather != NULL) return treeFather;
    if(treeMother != NULL) return treeMother;
    return NULL;
}
int Tree::depth(Tree* node, string name)
{
    if(node == NULL) return -1;
    if(node->data == name)
        return 0;
    if(node->father!=NULL)
    {
        int countFather = depth(node->father, name);
        if(countFather>=0)
             return (countFather+1);
    }
    if(node->mother!=NULL)
    {
        int countMother = depth(node->mother, name);
        if(countMother>=0)
            return (countMother+1);
    }
    return -1;
}
