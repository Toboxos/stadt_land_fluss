#include "spieleinstellungen.h"
#include <QString>
#include "spielerliste.h"


///<summary> adds a category to the game settings </summary>
///<parameters> category in string </parameters>
bool extern addCategory(std::string category){
  /*  std::vector<std::string> categories = _einstellung->getKategorienListe();
    int n = categories.size();
    for(int i = 0; i < n ; i++){
        if(categories[i] == category){
            return false;
        }
    }
    _einstellung->setKategorienlListe(category);*/
    return true;
}



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
}
