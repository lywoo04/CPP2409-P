#include <iostream>
#include <vector>
using namespace std;

class Food{
private:
    string name;
    int price;
    vector<string> features;

public:
    Food(const string& name, double price, const vector<string>& features)
        : name(name), price(price), features(features) {}
};

class Restaurant{
private:
    string name;
    Food food1;
    Food food2;
    float rating;
    vector<int> location;

public:
    Restaurant(const string& name, const Food& food1, const Food& food2, float rating, const vector<int>& location)
        : name(name), food1(food1), food2(food2), rating(rating), location(location) {}

};



int main(){




}