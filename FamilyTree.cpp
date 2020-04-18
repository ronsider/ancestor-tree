/*
 *Ron Sider
 *
 * Date: 2020-04
 *
 */
#include "FamilyTree.hpp"
#include <iostream>



#include <algorithm>
using namespace std;
using namespace family;


Tree &Tree::addFather(string son, string _father)
{
    if (name == son)
    {
        if (father == nullptr)
        {
            father = new Tree(_father);
            return *this;
        }
        else
            throw runtime_error(son + " father exist alreay!");
    }
    else if (father != nullptr)
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
   
    throw runtime_error(son + " no such son " + name);
}

Tree &Tree::addMother(string son, string _mother)
{
    if (name==son)
    {
        if (mom == NULL)
        {
            mother = new Tree(_mother);
            return *this;
        }
        else
            throw runtime_error(son + " already has a mother!");
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

    
    throw runtime_error(son + " // not exist!");
}

string Tree::relation(string _name)
{
    string ans = "unrelated";

    if (_name == name)
    {
        ans = "me";
        return ans;
    }

    if (dad != NULL)
    {
        ans = dad->relation(_name);

        if (ans != "unrelated")
        {
            if (ans == "me")
                ans = "father";
            else if (ans == "father" || ans == "mother")
                ans = "grand" + ans;
            else
                ans = "great-" + ans;
        }
    }
    if ((ans == "unrelated") && (mother != NULL))
    {
        ans = mother->relation(_name);

        if (ans != "unrelated")
        {
            if (ans == "me")
                ans = "mother";
            else if ((ans == "mother") || (ans == "father"))
                ans = "grand" + ans;
            else
                ans = "great-" + ans;
        }
    }
    return ans;
}

string Tree::find(string relation)
{
    if (relation == "me")
        return name;
    if (relation == "mother" && mother!=NULL)
        return mom->name;
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
    throw runtime_error("The relation cant be treated: " + relation);
}
void Tree::display()
{
    int num;
    printFamily(num = 0);
}


void Tree::remove(string relative)//remove node according to relation paramater
{



}
void Tree::printFamily(int num)
{
    
}
