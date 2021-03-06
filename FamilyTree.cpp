#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
namespace helpFunctions 
{
    int split(string str)
    {
        int count=2;//the depth of the realtive is at least  2
        int isTheLastGreat=false;
        while(!isTheLastGreat) //until there is more great
        {
            string temp=str.substr(0,6);//split the great-
            if(temp.compare("great-")!=0)//if the word is not great-
            {
                if(str.compare("grandfather")==0||str.compare("grandmother")==0)//if the word is grandmother or grandfather, finish
                    isTheLastGreat=true;
                else
                    throw runtime_error("The tree cannot handle the "+str+" relation"); //the word is not legal
            }
            else
                count++;
            str=str.substr(6,str.length());
        }
        return count;
    }
}
namespace family 
{
    Tree& Tree::addFather(string son,string dad)
    {
        Tree* node=findMe(this,son);
        if(node==NULL) //there is not node named son
        {
            throw runtime_error(""+son+ "' is not in the family tree");
        }
        if(node->father!=NULL) //if there is father already
        {
            throw runtime_error("There is a father already");
        }
        node->father=new Tree(dad);
        node->father->son=node;
        return *this;
    }
    Tree& Tree::addMother(string son,string mom)
    {
        Tree* node=findMe(this,son);
        if(node==NULL) //there is not node named son
        {
            throw runtime_error(""+son+ "' is not in the family tree");
        }
        if(node->mother!=NULL) //if there is father already
        {
            throw runtime_error("There is a mother already");
        }
        node->mother=new Tree(mom);
        node->mother->son=node;
        return *this;
    }
    string Tree::relation(string search)
    {
        if(data==search)
            return "me";
        Tree* howIam=findMe(this,search);
        if(howIam==NULL) //if there is no node named search
            return "unrelated";
        string gender="mother";  
        if(howIam->son->mother==NULL||howIam->son->mother->data!=search)  //if the gender is male
            gender="father";
        int depthTree=depth(this,search); //find the depth of the tree
        if(depthTree==1) //if it is mother or father
            return gender;
        gender="grand"+gender;
        if(depthTree==2) //if it is grandMother or grandFather
            return gender;
        for(int i=depthTree-2;i>0;i--)
            gender="great-"+gender;
        return gender;
    }
    string Tree::find(string relation)
    {
        if(relation == "me") //if its the root
            return (this->data);
        if(relation == "father") //if its the father
        {
            if(this->father!=NULL)
                return (this->father->data);
            throw runtime_error("could not find relation: "+relation);
        }
        if(relation == "mother")//if its the mother
        {
            if(this->mother!=NULL)
                return (this->mother->data);
            throw runtime_error("could not find relation: "+relation);
        }
        if(relation == "grandmother")//if its the grandMother
        {
            if(this->mother!=NULL&&this->mother->mother!=NULL)
                return (this->mother->mother->data);
            if(this->father!=NULL&&this->father->mother!=NULL)
                return (this->father->mother->data);
            throw runtime_error("could not find relation: "+relation);
        }
        if(relation == "grandfather")//if its the grandFather
        {
            if(this->mother!=NULL&&this->mother->father!=NULL)
                return (this->mother->father->data);
            if(this->father!=NULL&&this->father->father!=NULL)
                return (this->father->father->data);
            throw runtime_error("could not find relation: "+relation);
        }
        string ans="";
        int depthTree=helpFunctions::split(relation);
        string type=relation.substr(relation.length()-6,relation.length());//type==mother||father
        if(type.compare("mother")==0)//if the type is mother
            ans=helpFind(this,depthTree,1);
        else
            ans=helpFind(this,depthTree,0);
        if(ans.compare("-1")==0)
            throw runtime_error("co1uld not find relation: "+relation);
        return ans;
    }
    void Tree::display()
    {
       print2DUtil(this, 0);
    }
    bool Tree::remove(string name)
    {
        if(name==data)
        {
             throw runtime_error("You can't remove the root");
        }
        Tree* node=findMe(this,name);
        if(node==NULL) //if name is not in the tree
            throw runtime_error(""+name+" is not in the tree");
        Tree* sonTemp=node->son;
        if(sonTemp!=NULL)
        {
            if(sonTemp->father!=NULL&&name==sonTemp->father->data) //if the gender is male
            {
                sonTemp->father=NULL;
            }
            else // the gender is female
                sonTemp->mother=NULL; 
        }
        delete node;
        return true;
    }
    Tree* Tree::findMe(Tree* node, string name) //find the node of name in the tree
    {
        if(node == NULL) return NULL;
        if(node->data == name) return node;
        Tree* treeFather = findMe(node->father, name);
        Tree* treeMother = findMe(node->mother, name);
        if(treeFather != NULL) return treeFather;
        if(treeMother != NULL) return treeMother;
        return NULL;
    }
    int Tree::depth(Tree* node, string name) //find the depth of the tree
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
    string Tree::helpFind(Tree* node, int count,int type)
    {
        if(node == NULL) return "-1"; //The depth of this branch is smaller than count
        if(count==1)
        {
            if(type==0&&node->father!=NULL)
                return (node->father->data);
            if(type==1&&node->mother!=NULL)
                return (node->mother->data);
            return "-1";//The depth of this branch is smaller than count
        }
        string motherBranch=helpFind(node->mother,count-1,type);
        string fatherBranch=helpFind(node->father,count-1,type);
        if(motherBranch.compare("-1")!=0)
            return motherBranch;
        return fatherBranch;
    }
    void Tree::print2DUtil(Tree *root, int space)     // https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    {  
        if (root == NULL)          // Base case  
            return;  
        space += 10;          // Increase distance between levels  
        print2DUtil(root->father, space);        // Process right child  
        cout<<endl;          // Print current node after space  
        for (int i = 10; i < space; i++)  
            cout<<" ";  
        cout<<root->data<<"\n";  
        print2DUtil(root->mother, space);          // Process left child  
    }  
}
