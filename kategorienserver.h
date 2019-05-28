#ifndef KATEGORIENSERVER_H
#define KATEGORIENSERVER_H
#include <string>
#include <vector>
#endif // KATEGORIENSERVER_H
using namespace std;

class Categories{
public:
    bool addCategory(string category);
    vector<string> getCategories();
    void setCategories(vector<string> newCategories);
    int getAmount();
private:
    vector<string> CategoryList;
};
