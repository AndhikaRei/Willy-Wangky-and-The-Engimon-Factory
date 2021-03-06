#include "Player.hpp"
#include "../Engimon/Engimon.hpp"
#include "../Skill_Item/Skill_Item.hpp"
#include "../Engimon/Engimon.hpp"
#include <iostream> 
#include <vector> 
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

Player::Player(){
    // Reihan coba coba buat tes battle
    this->name = "Willy Wangky";
    this->engimons = vector<Engimon*>();
    Engimon *a1 = new Pyro("Pyro1");
    Engimon *a2 = new Hydro("Hydro1");
    Engimon *a3 = new Electro("Electro1");
    Engimon *a4 = new Geo("Geo1");
    Engimon *a5 = new Cryo("Cryo1");
    
    engimons.push_back(a1);
    engimons.push_back(a2);
    engimons.push_back(a3);
    engimons.push_back(a4);
    engimons.push_back(a5);
    
    this->ActiveEngimon = engimons.at(0);

    this->items = vector<Skill_Item*>();

    // Debug Ronggur
    //vector<Engimon *> engimons;
    //vector<Skill_Item *> items;
}

Player::Player(string name_){
    this->name = name_; // masi salah
    //strcpy(this->name,name_);

}

Player::Player(const Player& other){
    this->name = other.name;
    for(int i = 0;i < other.items.size(); ++i){
        this->items[i] = other.items[i]; //gtw dah dibikin atau belum di items
    }
    for(int i = 0;i < other.engimons.size(); ++i){
        this->engimons[i] = other.engimons[i]; //gtw dah dibikin atau belum di items
    }
}
Player::~Player(){

}

Player& Player::operator=(const Player& other){
    //strcpy(this->name,other.name);
    this->name = other.name; // masi salah
    for(int i = 0;i < other.items.size(); ++i){
        this->items[i] = other.items[i]; //gtw dah dibikin atau belum di items
    }
    for(int i = 0;i < other.engimons.size(); ++i){
        this->engimons[i] = other.engimons[i]; //gtw dah dibikin atau belum di items
    }
    
    return *this;
}

//selector
vector<Skill_Item *> Player::getItems(){
    return this->items;
}
Skill_Item* Player::getItem(int i){
    if(i >= this->items.size() || i < 0){
        throw InvalidIndex();
    }
    return this->items[i];
}
void Player::printItems(){ // nunggu implementasi yg lain
    vector<Skill_Item *>::iterator it;
    int i = 0;
    for ( it = this->items.begin();it < this->items.end();it++){
        if(this->items[i]->getAmount() == 0){
            //Skill_Item* tobedeleted = this->items[i];
            this->items.erase(it);
            //delete tobedeleted;
        }else{
            i++;
        }
    }  
    for(int i = 0;i<this->items.size();i++){
        this->items[i]->showItem();
    }
    this->printItemCount();
}

vector<Engimon *> Player::getEngimons(){
    return this->engimons;
}
Engimon* Player::getEngimon(int i){
    if (i < 0 || i >= this->engimons.size()){
        throw InvalidIndex();
    } else {
        return this->engimons[i];
    }
    
}
void Player::printEngimon(){// nunggu implementasi yg lain
    cout << "this is all your engimons : \n";
    
    for(int i = 0; i< this->engimons.size();i++){
        cout << i << ") ";
        this->engimons[i]->showEngimon();
    }
}

string Player::getName()const{
    return this->name;
};


Engimon* Player::getActiveEngimon(){
    return this->ActiveEngimon; 
}

void Player::changeActiveEngimon(int i){
     if (i < 0 || i >= this->engimons.size()){
        throw InvalidIndex();
    } else {
        this->ActiveEngimon = this->engimons[i];
    }
    
}
void Player::changeActiveEngimon(){
    // Kalau seandainya engimon active mati dibikin wajib milih active engimon juga gpp sih
    if (this->engimons.size() !=0){
        cout << "Engimon activemu telah mati, anda harus memilih engimon active baru \n";
        int i= -999;
        while(i < 0 || i > this->engimons.size() ){
            printEngimon();
            cout << "Masukkan index engimon(input akan diulang hingga index valid) : ";
            std::cin >> i;
        }
        changeActiveEngimon(i);
    } else {
        cout << "Sayang sekali engimon kamu sudah habis \n";
    }
}

void Player::printProfile(){
    cout << "Name : " << this->name << endl;
    printEngimon();
    printInventory();
}
int Player::getCount(){
    int Itemcount = 0;
    vector<Skill_Item *>::iterator it;
    int i = 0;
    for (it = this->items.begin();it < this->items.end();it++){
        Itemcount += this->items[i]->getAmount();
        i++;
    }  
    return this->engimons.size() + Itemcount;
}
void Player::printItemCount(){
    cout << "jumlah Item : " << this->getCount() << endl;
}


void Player::printInventory(){
	cout << "this is all your Inventory : \n";
    vector<Skill_Item *>::iterator it;
    int i = 0;
    for ( it = this->items.begin();it < this->items.end();it++){
        if(this->items[i]->getAmount() == 0){
            //Skill_Item* tobedeleted = this->items[i];
            this->items.erase(it);
            //delete tobedeleted;
        }else{
            i++;
        }
        
    }    
    // found = true;
    // if(this->items[i]->getAmount() == 0){
    //     Skill_Item* tobedeleted = this->items[i];
    //     this->items.erase(it);
    //     delete tobedeleted;
    // }
    for(int i = 0; i< this->items.size();i++){
        cout << i <<") ";
        this->items[i]->showSimpleItem();
    }
    this->printItemCount();
}
void Player::interactWithActiveEngimon(){
    this->getActiveEngimon()->interact();
}
//modify data
//
void Player::addEngimon(Engimon* engimon){
   if(this->getCount() >= 100){
       throw InventoryFull();
   }
   Engimon *temp = engimon->clone();
   this->engimons.push_back(engimon);
}

void Player::addItem(Skill_Item *item){ 
    if(this->getCount() >= 100){
        throw InventoryFull();
    }
    int found = 0;
    int i = 0;
    while(!found && i < this->items.size()){
        if(this->items[i]->getSkill().getName() == item->getSkill().getName()){
            this->items[i]->addAmount();
            found = true;
            break;
        }
        i++;
    }
    if(!found){
        this->items.push_back(item);
    }
    
}
void Player::killActiveEngimon(){
    int i = 0;
    vector<Engimon *>::iterator it;
    it = this->engimons.begin();
    while(this->ActiveEngimon->getName() != this->engimons[i]->getName()){
        it++;
        i++;
    }
    //it = i;
    this->engimons.erase(it);
    changeActiveEngimon();
}

void Player::useItem(string ItemName){
    int i = 0;
    int found = 0;
    vector<Skill_Item *>::iterator it;
    while(!found && i < getItems().size() ){
        if(this->items[i]->getSkill().getName() == ItemName){
            //use Item disini
            
            this->items[i]->addAmount(-1);
            found = true;
            if(this->items[i]->getAmount() == 0){
                Skill_Item* tobedeleted = this->items[i];
                this->items.erase(it);
                delete tobedeleted;
            }
            break;
        }
        
        i++;
        it++;
    }
}