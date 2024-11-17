#include <iostream>
#include <vector>
using namespace std;

//푸드 클래스 정의
class Food{
private:
    string name;
    double price;
    vector<string> features;

public:
    //생성자 정의
    Food(const string& name, double price, const vector<string>& features)
        : name(name), price(price), features(features) {}

    //음식 이름을 반환하는 함수
    string GetFoodName() const {
         return name ;
    }

    //음식의 정보를 출력하는 함수
    void Print_foodInfor() const {
        cout << "이름: " << name << endl 
             << "가격: " << price << endl
             << "특징: ";
        for (const auto& feature : features) {
            cout << feature << " ";
        }
        cout << endl << endl;

    }

    //원하는 특징을 음식이 가지고 있는지 확인하는 함수
    bool HasFeature(const string& desiredFeature) const {
        for (const auto& foodFeature : features) {
            if (desiredFeature == foodFeature) {
                return true;
            }
        }
        return false;
    }

};

//식당 클래스 정의
class Restaurant{
private:
    string name;
    Food food1;
    Food food2;
    float rating;
    int location[2];

public:
    //생성자 정의
    Restaurant(const string& name, const Food& food1, const Food& food2, float rating, int x, int y)
        : name(name), food1(food1), food2(food2), rating(rating) {
            location[0] = x;
            location[1] = y; 
            }


    //식당 이름을 반환하는 함수
    string GetRestauName() const {
        return name ;
    }

    //식당 정보를 출력하는 함수
    void Print_infor() const{
        cout << "식당 이름: " << name << endl 
             << "평점: " << rating << endl 
             << "대표 메뉴: 1." << food1.GetFoodName() << ", 2." << food2.GetFoodName()
             << endl << "위치: " << location[0] << ", " << location[1] << endl << endl;
    }

    //식당의 음식 중, 원하는 음식을 선택하여 설명을 출력하는 함수
    void SelectFood(int foodNum) const {
        if (foodNum == 1) {
            food1.Print_foodInfor();
        } else if (foodNum == 2) {
            food2.Print_foodInfor();
        } else {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
    }

    //음식이 원하는 음식인지 확인하고, 맞으면 이름을 출력하는 함수
    bool RecommendFood(const string& desiredFeature) const {
        bool foodFound = false;
        
        if (food1.HasFeature(desiredFeature)) {
            cout <<food1.GetFoodName() << endl;
            foodFound = true;
        }
        
        if (food2.HasFeature(desiredFeature)) {
            cout <<food2.GetFoodName() << endl;
            foodFound = true;
        }
        
        return foodFound;
    }

};

//식당, 요리 정보 입력
const Food woulmidang_f1("buncha", 1.4, {"Vietnamese", "sour", "noodle"});
const Food woulmidang_f2("pho", 1.1, {"Vietnamese", "beef", "noodle"});
const Restaurant woulmidang("woulmidang", woulmidang_f1, woulmidang_f2, 5.0, 0, 0);
 
const Food miss420_f1("friedrice", 0.75, {"Vietnamese", "spicy", "rice"});
const Food miss420_f2("pho", 0.7, {"Vietnamese", "beef", "noodle"});
const Restaurant miss420("misssaigon", miss420_f1, miss420_f2, 4.2, 0, 0);

const Food speedbanjum_f1("jjajang", 0.4, {"chinese", "pork", "noodle"});
const Food speedbanjum_f2("jjambbong", 0.5, {"chinese", "spicy", "seafood" ,"noodle"});
const Restaurant speedbanjum("speedbanjum", speedbanjum_f1, speedbanjum_f2, 4.5, 0,0);

const Food joseon_f1("jjambbong", 0.95, {"chinese", "seafood", "spicy", "noodle"});
const Food joseon_f2("whitejjambbong",0.95 , {"chinese", "seafood", "spicy", "noodle"});
const Restaurant joseon("joseonjjambbong", joseon_f1, joseon_f2, 4.6, 0,0);

const Food shinsacheon_f1("maratang", 1.3, {"chinese", "spicy", "meat", "vegetable"});
const Food shinsacheon_f2("guabaorou", 0.9, {"chinese", "sweet", "sour", "pork"});
const Restaurant shinsacheon("shinsacheon", shinsacheon_f1, shinsacheon_f2, 4.2, 0, 0);

//식당 목록 벡터
vector<Restaurant> restaurantList = {woulmidang, miss420, speedbanjum, joseon,
                                     shinsacheon };
//특징 목록 벡터
vector<string> featureList = {"korean", "chinese", "japanese", "vietnamese", "italian",
                              "spicy", "sour"
                             };

//특징 목록을 출력하는 함수
void DisplayFeatures() {
    cout << "모든 특징 목록:" << endl;
    for (const auto& feature : featureList) {
        cout << feature << " ";
    }
    cout << endl;
}

//원하는 식당의 정보를 출력하는 함수
void DisplayRestaurant(int restauNum){
    if (restauNum > 0 && restauNum <= restaurantList.size()) {
        restaurantList[restauNum - 1].Print_infor();
    } else {
        cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
    }
}

//식당의 목록을 출력하는 함수
void DisplayRestaurantList() {
    int num = 1;

    cout << "식당 목록:" << endl;
    for (const auto& name : restaurantList) {
        cout << num << ". " << name.GetRestauName() << endl;
        num += 1;
    }
    cout << endl;
}

//음식의 정보를 출력하는 함수
void DisplayFoodInfo(int restauNum, int foodNum) {
    if (foodNum == 1 || foodNum == 2) {
        restaurantList[restauNum - 1].SelectFood(foodNum);
    } else if (foodNum == 3) {
        cout << "메뉴 종료" << endl;
    } else {
        cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
    }
}

int main(){

    int num = 1;
    int menu;
    int restauNum;
    int foodNum;
    bool foodFound = false;
    string desiredFeature;

    while(num){
        cout << "----------------------------" << endl;
        cout << "[기능 메뉴]" << endl
             << "1. 식당 정보" << endl
             << "2. 음식 추천받기" << endl
             << "3. 식당 추천받기" << endl
             << "4. 종료" << endl
             << "실행할 기능을 선택하세요: ";

        cin >> menu;
        cout << endl;

        switch (menu) {
            case 1:
                DisplayRestaurantList();
                
                cout << "어떤 식당의 정보를 원하십니까?" << endl
                     << "번호를 입력하십시오: ";
                
                cin >> restauNum;
                cout << endl;

                DisplayRestaurant(restauNum);

                cout << "음식 정보를 원하십니까?" << endl 
                     << "1: 1번 음식" << endl
                     << "2: 2번 음식" << endl
                     << "3: 종료" << endl
                     << "원하는 서비스를 선택하세요: ";

                cin >> foodNum;
                cout << endl;

                DisplayFoodInfo(restauNum, foodNum);

                break;

            case 2:
                DisplayFeatures();
                cout << "원하는 음식의 특징을 입력하십시오: " ;
                cin >> desiredFeature;
                cout << endl;
                
                foodFound = false;
                for (const auto& restaurant : restaurantList) { 
                    if (restaurant.RecommendFood(desiredFeature)) {
                        foodFound = true;
                    }
                }

                if (!foodFound) {
                    cout << "특징에 맞는 음식이 없습니다." << endl;
                }

                break;
            
            case 3:
                cout << "아직 미구현" << endl;
                break;

            case 4:
                cout << "프로그램 종료" ;
                num = 0;
                break;

            default:
                cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;    
        }

    }

}