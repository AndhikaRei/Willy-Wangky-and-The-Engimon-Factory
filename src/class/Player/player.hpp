//class player
//file player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream> 
#include <vector> 
#include <string>
//#include "../Exception/Exception.hpp"
//#include "../Item/Item.hpp"
#include "../Engimon/Engimon.hpp"
#include "../Skill_Item/Skill_Item.hpp"


using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class player {
    public:
        string name;
        vector<Engimon *> engimons;
        vector<Skill_Item *> items;
        Engimon * ActiveEngimon;

        //ctor, dtor dkk
        player();
        player(string name_);
        player(const player& other);
        ~player();
        player& operator=(const player& other);
        
        //selector
        vector<Skill_Item *> getItems();
        Skill_Item* getItem(int i); 
        void printItems(); //print inventory list
        
        vector<Engimon *> getEngimons();
        Engimon* getEngimon(int i);
        void printEngimon();

        //Engimon* getActiveEngimon();
        Engimon* getActiveEngimon();
        void changeActiveEngimon(int i);

        void printProfile();
        int getCount();
        void printInventory();
        //modify data
        void addEngimon(Engimon* engimon);
        void addItem(Skill_Item* item);
};

#endif
