#include <kategorienserver.h>

///<summary> adds a category to the game settings </summary>
///<parameters> category in string </parameters>
//<<<<<<< HEAD
bool extern addCategory(std::string category){
  /*  std::vector<std::string> categories = _einstellung->getKategorienListe();
    int n = categories.size();
=======
bool Categories::addCategory(string category){
    int n = CategoryList.size();
>>>>>>> 9874751bf14cd5d5f24f774d98ddbf835364158b
    for(int i = 0; i < n ; i++){
        if(CategoryList[i] == category){
            return false;
        }
    }
<<<<<<< HEAD
    _einstellung->setKategorienlListe(category);
=======
    CategoryList.push_back(category);
>>>>>>> 9874751bf14cd5d5f24f774d98ddbf835364158b*/
    return true;
}

vector<string> Categories::getCategories(){
    return CategoryList;
}
void Categories::setCategories(vector<string> newCategories){
    CategoryList = newCategories;
}

//<<<<<<< HEAD

///<summary> adds a category to the game settings </summary>
///<parameters> category in string  and game settings as Spieleinstellungen </parameters>
bool extern addCategory(std::string category, Spieleinstellungen* _einstellungen){
  /*  std::vector<std::string> categories = _einstellung->getKategorienListe();
    int n = categories.size();
    for(int i = 0; i < n ; i++){
        if(categories[i] == category){
            return false;
        }
    }
    _einstellung->setKategorienlListe(category);*/
    return true;
//=======
int Categories::getAmount(){
    return CategoryList.size();
//>>>>>>> 9874751bf14cd5d5f24f774d98ddbf835364158b
}
