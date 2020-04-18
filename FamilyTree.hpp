#include <string>

using namespace std;

namespace family
{

class Tree
{
    string name;
    Tree *mother, *father;

public:
    Tree(string n)
    {
        name = n;
        father = nullptr;
        mother = nullptr;
    }

    Tree &addFather(string son, string father);
    Tree &addMother(string son, string mother);
    string relation(string _name);
    string find(string relation);
    void display();
    void printFamily(int num);
    void remove(string _name);

    ~Tree()//destructor 
    {
        if (father != nullptr)
            delete father;
        
        if (mother != nullptr)
            delete mother;
        
    }
};

} 
