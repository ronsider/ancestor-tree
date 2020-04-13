#include <iostream>
#include <string>

namespace family
{

 class Tree
 {
   string _name;
   Tree* father;
   Tree* mother;

  public:
  Tree(string name);
  Tree addFather(string son,string father);
  Tree addMother(string son,string mother);
  void display() const;//const indicates read only function
  Tree relation(string name) const;//return the relation that correspond to this name and root
  Tree find(string s) const;//put name and get the relation
   Tree remove(string name);//remove current family memeber and all his predessecors(avot)
 }
}
