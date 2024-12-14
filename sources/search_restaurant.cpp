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

    double getPrice() const {
        return price;
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
    bool HasFeature(const string& first_string) const {
        for (const auto& foodFeature : features) {
            if (first_string == foodFeature) {
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

    float getRating() const {
        return rating; 
    }

    double getFoodPrice(const int foodNum) const {
        if (foodNum == 1)
            return food1.getPrice();
        else if (foodNum == 2)
            return food2.getPrice();
        else
            return 0.0;  // 잘못된 입력에 대한 처리
    }

    const int* getLocation() const {
        return location;
    }

    //식당 정보를 출력하는 함수
    void Print_infor() const{
        cout << "식당 이름: " << name << endl 
             << "평점: " << rating << endl 
             << "대표 메뉴: 1." << food1.GetFoodName() << ", 2." << food2.GetFoodName()
             << endl << "위치: " << location[0] << ", " << location[1] << endl << endl;
    }

    //식당의 음식 중, 원하는 음식을 선택하여 설명을 출력하는 함수
    void SelectFood(int second_num) const {
        if (second_num == 1) {
            food1.Print_foodInfor();
        } else if (second_num == 2) {
            food2.Print_foodInfor();
        } else {
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
        }
    }

    //음식이 원하는 음식인지 확인하고, 맞으면 이름을 출력하는 함수
    bool HasRecommendFood(const string& first_string, int print_name = 0) const {
        bool food_found = false;
        
        if (food1.HasFeature(first_string) || food1.GetFoodName() == first_string) {
            if (print_name == 1) {
                cout <<food1.GetFoodName() << endl;
            }
            food_found = true;
        }
        
        if (food2.HasFeature(first_string) || food2.GetFoodName() == first_string) {
            if (print_name == 1) {
                cout <<food2.GetFoodName() << endl;
            }
            food_found = true;
        }
        
        return food_found;
    }
};

//식당, 요리 정보 입력
const Food woulmidang_f1("buncha", 1.4, {"vietnamese", "sour", "noodle"});
const Food woulmidang_f2("pho", 1.1, {"vietnamese", "beef", "noodle"});
const Restaurant woulmidang("woulmidang", woulmidang_f1, woulmidang_f2, 5.0, 5, 5);
 
const Food miss420_f1("friedrice", 0.75, {"vietnamese", "spicy", "rice"});
const Food miss420_f2("pho", 0.7, {"vietnamese", "beef", "noodle"});
const Restaurant miss420("misssaigon", miss420_f1, miss420_f2, 4.2, 10, 10);

const Food speedbanjum_f1("jjajang", 0.4, {"chinese", "pork", "noodle"});
const Food speedbanjum_f2("jjambbong", 0.5, {"chinese", "spicy", "seafood" ,"noodle"});
const Restaurant speedbanjum("speedbanjum", speedbanjum_f1, speedbanjum_f2, 4.5, 9,9);

const Food joseon_f1("joseonjjambbong", 0.95, {"chinese", "seafood", "spicy", "noodle"});
const Food joseon_f2("whitejjambbong",0.95 , {"chinese", "seafood", "spicy", "noodle"});
const Restaurant joseon("joseonjjambbong", joseon_f1, joseon_f2, 4.6, 1,1);

const Food shinsacheon_f1("maratang", 1.3, {"chinese", "spicy", "meat", "vegetable"});
const Food shinsacheon_f2("guabaorou", 0.9, {"chinese", "sweet", "sour", "pork"});
const Restaurant shinsacheon("shinsacheon", shinsacheon_f1, shinsacheon_f2, 4.2, 3, 3);

//식당 목록 벡터
vector<Restaurant> restaurantList = {woulmidang, miss420, speedbanjum, joseon,
                                     shinsacheon };
//특징 목록 벡터
vector<string> featureList = {"korean", "chinese", "japanese", "vietnamese", "italian",
                              "spicy", "sour"
                             };

//특징 목록을 출력하는 함수
void DisplayFeatures();
//식당의 목록을 출력하는 함수
void DisplayRestaurantList();
//음식의 정보를 출력하는 함수
void DisplayFoodInfo(int first_num, int second_num);
// 사용자의 위치를 입력받는 함수
vector<int> InputUserLocate(int max_x, int max_y);
// 재귀적으로 우선순위가 높은 항목 출력
void PrintSortedRestaurants(vector<string>& recommendedRestaurantList, int align,
    const vector<Restaurant>& restaurantList, vector<int>& user_locate, int max_x, int max_y); 
void PrintMap(int max_x, int max_y, vector<int> user_locate, vector<Restaurant>& restaurantList);







int main(){

    int menu;
    int align;
    int first_num;
    int second_num;
    bool food_found = false;
    string first_string;
    vector<string> recommendedRestaurantList;

    int max_x = 10, max_y = 10; //임시 맵 최대값
    vector<int> user_locate; 




    while(true){
        cout << "----------------------------" << endl;
        cout << "[기능 메뉴]" << endl
             << "1. 식당 정보" << endl
             << "2. 음식 추천받기" << endl
             << "3. 식당 추천받기" << endl
             << "4. 지도 보기" << endl
             << "5. 종료" << endl
             << "당신의 입력: ";

        cin >> menu;
        cout << endl;

        switch (menu) {
            case 1:
                DisplayRestaurantList();
                
                cout << "어떤 식당의 정보를 원하십니까?" << endl
                     << "당신의 입력: ";
                
                while (true) {
                    cin >> first_num;
                    cout << endl;
                    if (first_num > 0 && first_num <= restaurantList.size()) {
                        restaurantList[first_num - 1].Print_infor();
                        break;
                    } else {
                        cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
                        continue;
                    }
                }

                cout << "음식 정보를 원하십니까?" << endl 
                     << "1: 1번 음식" << endl
                     << "2: 2번 음식" << endl
                     << "3: 종료" << endl
                     << "당신의 입력: "; 

                while (true){
                    cin >> second_num;
                    cout << endl;

                    if (second_num == 1 || second_num ==2 || second_num ==3){
                        DisplayFoodInfo(first_num, second_num);
                        break;
                    }
                    else {
                        cout << "잘못된 입력입니다. 다시 입력하세요: " ;
                        continue;
                    }
                }
                
                break;

            case 2:
                DisplayFeatures();
                cout << "원하는 음식의 특징을 입력하십시오" << endl
                     << "당신의 입력: ";
                cin >> first_string;
                cout << endl;
                
                food_found = false;
                for (const auto& restaurant : restaurantList) { 
                    if (restaurant.HasRecommendFood(first_string, 1)) {
                        food_found = true;
                    }
                }

                if (!food_found) {
                    cout << "특징에 맞는 음식이 없습니다." << endl;
                }

                break;
            
            case 3: //식당 추천
                cout << "어떤 식당을 추천받고 싶으싶니까?" << endl
                     << "1. 특정 음식을 파는 식당" << endl
                     << "2. 원하는 특징의 음식을 파는 식당" << endl
                     << "당신의 입력: ";
                
                while(true) {
                    cin >> first_num ;
                    cout << endl;

                    if (first_num != 1 && first_num != 2) {
                        cout << "잘못된 입력입니다. 다시 입력하세요: ";
                        continue;
                    }
                    break;
                }
                
                if (first_num == 1) {
                    cout << "원하는 음식을 입력하십시오" << endl
                         << "당신의 입력: ";
                    cin >> first_string;
                    cout << endl;

                    // 특정 음식을 찾는 식당 검색
                    food_found = false;
                    for (const auto& restaurant : restaurantList) {
                        if (restaurant.HasRecommendFood(first_string)) {
                            cout << restaurant.GetRestauName() << "에서 " << first_string 
                                 << "을(를) 판매합니다." << endl;
                            food_found = true;
                        }
                    }
                    if (!food_found) {
                        cout << "해당 음식을 판매하는 식당이 없습니다." << endl;
                    }

                } else if (first_num == 2) { // 원하는 특징의 음식을 파는 식당 추천
                    recommendedRestaurantList.clear();

                    DisplayFeatures();
                    cout << "원하시는 음식의 특징을 입력하십시오:" << endl
                         << "당신의 입력: ";
                    cin >> first_string;
                    cout << endl;

                    // 특징을 기반으로 식당 검색
                    food_found = false;
                    for (const auto& restaurant : restaurantList) {
                        if (restaurant.HasRecommendFood(first_string)) {
                            recommendedRestaurantList.push_back(restaurant.GetRestauName());
                            cout << restaurant.GetRestauName() <<  endl;
                            food_found = true;
                        }
                    }
                    cout << "에서 " << first_string << " 특징을 가진 음식을 판매합니다." << endl;

                    if (food_found){
                        cout << "새로운 기준에 따라 목록을 정렬하시겠습니까?" << endl
                             << "1. 별점" << endl 
                             << "2. 가격" << endl 
                             << "3. 거리" << endl 
                             << "4. 아니오" << endl
                             << "당신의 입력: ";
                        cin >> align;

                        if (align == 1) cout << "별점이 높은 순으로 정렬합니다." << endl << endl;
                        else if (align == 2) cout << "평균 가격이 싼 순으로 정렬합니다." << endl << endl;
                        else if (align == 3) cout << "거리가 가까운 순으로 정렬합니다." << endl << endl;
                        else if (align == 4) {
                            cout << "기능 메뉴로 돌아갑니다." << endl;
                            break;
                        }
                        else {
                            cout << "잘못된 입력입니다." << endl; 
                            break;
                        }

                        PrintSortedRestaurants(recommendedRestaurantList, align, restaurantList, user_locate, max_x, max_y);
                        
                        break;
                    }
                    else {
                        cout << "해당 특징의 음식을 판매하는 식당이 없습니다." << endl;
                    }

                } else {
                    cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;

                }
                break;

            case 4:
                user_locate = InputUserLocate(max_x, max_y);

                PrintMap(max_x, max_y, user_locate, restaurantList);

                cout << "원하는 추가 기능 선택" << endl
                     << "1. 사용자 위치 재설정하기" << endl
                     << "2. 나가기" << endl
                     << "당신의 입력: " ;
                
                while (true) {
                    cin >> first_num;
                    cout << endl;

                    if (first_num == 1) {
                        user_locate = InputUserLocate(max_x, max_y);
                        break;
                    }
                    else if (first_num == 2) {
                        cout << "[기능메뉴 4. 지도보기]를 종료합니다" << endl;
                        break;
                    }
                    else {
                        cout << "잘못된 입력입니다" << endl;
                        continue;
                    }
                }
                
                break;
            case 5:
                cout << "프로그램 종료" ;
                return 0;

            default:
                cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;    
        }

    }
    return 0;

}





//특징 목록을 출력하는 함수
void DisplayFeatures() {
    cout << "모든 특징 목록:" << endl;
    for (const auto& feature : featureList) {
        cout << feature << " ";
    }
    cout << endl;
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
void DisplayFoodInfo(int first_num, int second_num) {
    if (second_num == 1 || second_num == 2) {
        restaurantList[first_num - 1].SelectFood(second_num);
    } else if (second_num == 3) {
        cout << "메뉴 종료" << endl;
    } else {
        cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
    }
}

// 사용자의 위치를 입력받는 함수
vector<int> InputUserLocate(int max_x, int max_y) {
    int user_locateX = 0, user_locateY = 0;

    cout << "현재 위치(x, y)를 입력하십시오(0~10): " << endl;
    cin >> user_locateX >> user_locateY;
    if ( 0 <= user_locateX && user_locateX <= max_x &&
         0 <= user_locateY && user_locateY <= max_y) {
        return {user_locateX, user_locateY};
    }
    else {
        cout << "잘못된 입력입니다. 다시 입력하십시오." << endl;
        return InputUserLocate(max_x, max_y);
    }
}

// 재귀적으로 우선순위가 높은 항목 출력
void PrintSortedRestaurants(vector<string>& recommendedRestaurantList, int align,
 const vector<Restaurant>& restaurantList, vector<int>& user_locate, int max_x, int max_y) {
    if (recommendedRestaurantList.empty()) {
        return; 
    }
    
    int bestIndex = 0;
    int num = 1;
    for (int i = 1; i < recommendedRestaurantList.size(); ++i) {
        const string& current = recommendedRestaurantList[i];
        const string& best = recommendedRestaurantList[bestIndex];

        if (align == 1) { // 별점 기준
            float currentRating = 0, bestRating = 0;
            for (const auto& restaurant : restaurantList) {
                if (restaurant.GetRestauName() == current) currentRating = restaurant.getRating();
                if (restaurant.GetRestauName() == best) bestRating = restaurant.getRating();
            }
            if (currentRating > bestRating) bestIndex = i;

        } 
        else if (align == 2) { // 평균 가격 기준
            double currentPrice = 0, bestPrice = 0;
            for (const auto& restaurant : restaurantList) {
                if (restaurant.GetRestauName() == current) {
                    currentPrice = (restaurant.getFoodPrice(1) + restaurant.getFoodPrice(1)) / 2;
                }
                if (restaurant.GetRestauName() == best) {
                    bestPrice = (restaurant.getFoodPrice(1) + restaurant.getFoodPrice(1)) / 2;
                }
            }
            if (currentPrice < bestPrice) bestIndex = i;

        } 
        else if (align == 3) { // 거리 기준
            if (num) {
                if (user_locate.empty()) {
                    cout << "사용자의 위치가 설정되지 않았습니다" << endl;

                    user_locate = InputUserLocate(max_x, max_y);
                    cout << endl;
                }
                
            }
                
            int currentDist = 0, bestDist = 0;
            for (const auto& restaurant : restaurantList) {
                if (restaurant.GetRestauName() == current) {
                    currentDist = (restaurant.getLocation()[0] - user_locate[0])^2 + 
                                  (restaurant.getLocation()[1] - user_locate[1])^2 ;
                } 
                if (restaurant.GetRestauName() == best) {
                    bestDist = (restaurant.getLocation()[0] - user_locate[0])^2 + 
                               (restaurant.getLocation()[1] - user_locate[1])^2;
                }
            }
            if (currentDist < bestDist) bestIndex = i;
        }
        else {
            return;
        }
    }

    // 가장 우선순위가 높은 항목 출력
    cout << "- " << recommendedRestaurantList[bestIndex] << endl;

    // 해당 항목 제거
    recommendedRestaurantList.erase(recommendedRestaurantList.begin() + bestIndex);

    // 나머지 항목에 대해 재귀 호출
    PrintSortedRestaurants(recommendedRestaurantList, align, restaurantList, user_locate, max_x, max_y);
}

void PrintMap(int max_x, int max_y, vector<int> user_locate, vector<Restaurant>& restaurantList){
    for (int i = 0; i < max_y; i++) {
        cout << "-----------------------------------------" << endl;
        for (int j = 0; j < max_x; j++){
            bool find = false;

            cout << "|" ;
            for (const auto& restaurant : restaurantList){
                if (restaurant.getLocation()[0] == j && restaurant.getLocation()[1] == i){
                    find = true;
                    break;
                }
            }
            if (find == true && user_locate[0] == j && user_locate[1] == i) {
                cout << "L&U";
            }
            else if (find == true){
                cout << " L "; 
            }
            else if (user_locate[0] == j && user_locate[1] == i) {
                cout << " U ";
            } 
            else {
                cout << "   ";
            }
        }
        cout << "|" << endl;
    }
    cout << "-----------------------------------------" << endl;
}