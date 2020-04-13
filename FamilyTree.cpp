#include <iostream>
#include <string>
#include "FamilyTree"

using namespace std;

namespace family
{
   
    class Tree
    {
    
     string _name;
     Tree* mother;
     Tree* father;
     
     public:
     
     Tree(string name){
     _name=name;
     mother=NULL;
     father=NULL;
     }
     
     Tree addFather(string son,string father)//father is rightside
     {
      
        
        
     }
     
     Tree addMother(string son,string mother)//mother is leftside
     {
     
        
     }
     
    
     
};

}
