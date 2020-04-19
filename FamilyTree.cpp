/*Date: April 2020
 *
 *
 * 
 *Ron Sider
 */

#include <iostream>
#include <algorithm>


#include "FamilyTree.hpp"
using namespace std;
using namespace family;


Tree &Tree::addFather(string son, string _father)
{
    if (son == name)
    {
        if (father == NULL)
        {
            father = new Tree(_father);
            return *this;
        }
        else
            throw runtime_error(son + " father already exist!");
    }
    else if (father != NULL)
    {
        try
        {
            father->addFather(son, _father);
            return *this;
        }
        catch (runtime_error &x)
        {

        };
    }
    if (mother != NULL)
        try
        {
            mother->addFather(son, _father);
            return *this;
        }
        catch (runtime_error &x)
        {

        };
    
    throw runtime_error(son + " no such entity: " + name);
}

Tree &Tree::addMother(string son, string _mother)


{
    
    if (son == name)
    {
        if (mother == NULL)
        {
            mother = new Tree(_mother);
            return *this;
        }
        else
            throw runtime_error(son + " mother already exist!");
    }
    else if (mother != NULL)
    {
        try
        {
            mother->addMother(son, _mother);
            return *this;
        }
        catch (runtime_error &x)
        {

        };
    }

    if (father != NULL)
        try
        {
            father->addMother(son, _mother);
            return *this;
        }
        catch (runtime_error &x)
        {

        };

    
    throw runtime_error(son + " /// not exist!");
}



string Tree::relation(string relative)
{
    string answer = "unrelated";

    if (name==relative)
    {



        answer = "me";
        return answer;


    }

    if (father != NULL)
    {


        answer = father->relation(relative);

        if (answer != "unrelated")
        {
            if (answer == "me")
                answer = "father";
            else if (answer == "father" || answer == "mother")
                answer = "grand" + answer;
            else
                answer = "great-" + answer;
        }
    }
    if ((answer == "unrelated") && (mother != NULL))
    {
        answer = mother->relation(relative);

        if (answer != "unrelated")
        {
            if (answer == "me")
                answer = "mother";
            else if ((answer == "mother") || (answer == "father"))
                answer = "grand" + answer;
            else
                answer = "great-" + answer;
        }
    }
    return answer;
}

string Tree::find(string relation)
{
    if (relation == "me")
        return name;
    if (relation == "mother" && mother!=NULL)
        return mother->name;
    if (relation == "father" && father!=NULL)
        return father->name;

    if (relation.at(0) == 'g')
    {
        relation.erase(std::remove(relation.begin(), relation.end(), '-'), relation.end());

            relation.erase(0, 5);

            if (father != NULL)
            try{
                return father->find(relation);
            }
            catch(runtime_error &x){};

            if (mother != NULL)
            try{
                return mother->find(relation);
            }
            catch(runtime_error &x){};
        
    }
    throw runtime_error("The tree cannot handle the: " + relation + " relation");
}
void Tree::display()
{
    int num;
    ezer(num = 0);
}


void Tree::remove(string relative)
{

    if (name == relative)
    {
        throw runtime_error(name + " can't be removed!");
    }
    if ((father != NULL) && (father->name == relative))
    {
        delete father;
        father = NULL;
        return;
    }
    else if (father != NULL){
        try{
            father->remove(relative);
            return;
        }
        catch(runtime_error &x){};
    }
    if ((mother != NULL) && (mother->name == relative))
    {

        delete mother;
        mother = NULL;
        return;
    }
    else if (mother != NULL){
        try{
            mother->remove(relative);
            return;
        }
        catch(runtime_error &x){};
        
    }
    throw runtime_error(relative + " doesn't exist");


}
void Tree::ezer(int num)
{
    if (num == 0)
        cout << "*************" << name << "'s Famiy:*************" << endl;

    num += 10;

    if (father != NULL)
        father->ezer(num);

    cout << endl;
    for (int i = 10; i < num; i++)
        cout << " ";
    cout << name << "\n";

    if (mother != NULL)
        mother->ezer(num);
}
