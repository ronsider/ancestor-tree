#include <string>

using namespace std;

namespace family
{

class Tree
{
    string name;
    Tree *mother;
    Tree *father;

public:
    Tree(string n)
    {
        name = n;
        father = NULL;
        mother = NULL;
    }

    Tree &addFather(string son, string _father);
    Tree &addMother(string son, string _mother);
    string relation(string relative);
    string find(string relation);
    void display();
    void ezer(int num);//invoked by display
    void remove(string relative);

    ~Tree()//must use because of dynamic memory allocation
    {
        if (father != NULL)
            delete father;
        
        if (mother != NULL)
            delete mother;
        
    }
};

} 
