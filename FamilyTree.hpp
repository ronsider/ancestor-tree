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
  Tree relation(string name) const;//return the node that correspond to this name
  void find(string s) const;//relation based on name
 }
}
