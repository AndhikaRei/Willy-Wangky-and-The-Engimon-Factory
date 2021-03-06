//class player
//file player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream> 
#include <vector> 
#include <string>
#include "../Exception/Exception.hpp"
//#include "../Item/Item.hpp"
#include "../Engimon/Engimon.hpp"
#include "../Skill_Item/Skill_Item.hpp"
#define null 0


using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Player {
    private:
        string name;
        vector<Engimon *> engimons;
        vector<Skill_Item *> items;
        Engimon * ActiveEngimon;
    public:


        //ctor, dtor dkk
        Player();
        Player(string name_);
        Player(const Player& other);
        ~Player();
        Player& operator=(const Player& other);
        
        //selector
        vector<Skill_Item *> getItems();
        Skill_Item* getItem(int i); 
        void printItems(); //print inventory list
        
        vector<Engimon *> getEngimons();
        Engimon* getEngimon(int i);
        void printEngimon();
        string getName()const;

        // Engimon& getEngimonFromIndex(int i);

        //Engimon* getActiveEngimon();
        Engimon* getActiveEngimon();
        void changeActiveEngimon(int i);
        void changeActiveEngimon();
        void printProfile();
        int getCount();
        void printInventory();
        void interactWithActiveEngimon();
        void printItemCount();
        //modify data
        void addEngimon(Engimon* engimon);
        void addItem(Skill_Item* item);
        
        void killActiveEngimon();
        void useItem(string ItemName);
};

#endif
