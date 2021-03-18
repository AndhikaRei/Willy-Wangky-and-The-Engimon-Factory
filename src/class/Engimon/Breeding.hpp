#ifndef _BREEDING_HPP_
#define _BREEDING_HPP_

#include "Engimon.hpp"
#include <vector>
#include <random>
#include <set>
#include <algorithm>

using std::vector;
using std::set;

vector<Skill> sortingSkill(Engimon& parent_a, Engimon& parent_b);

bool isElementSimilar(Engimon& parent_a, Engimon& parent_b, vector<Elements>* similiarEle);
vector<Elements> sortElementAdvantage(Engimon& parent_a, Engimon& parent_b);
Engimon& breeding(Engimon& parent_a, Engimon& parent_b);


#endif