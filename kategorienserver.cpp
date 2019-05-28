#include <kategorienserver.h>

///<summary> adds a category to the game settings </summary>
///<parameters> category in string </parameters>
bool Categories::addCategory(string category){
    int n = CategoryList.size();
    for(int i = 0; i < n ; i++){
        if(CategoryList[i] == category){
            return false;
        }
    }
    CategoryList.push_back(category);
    return true;
}

vector<string> Categories::getCategories(){
    return CategoryList;
}
void Categories::setCategories(vector<string> newCategories){
    CategoryList = newCategories;
}

int Categories::getAmount(){
    return CategoryList.size();
}
