#include <iostream>
#include <string>

int main()
{
    std::string map[5] = {"Typically Otaku", "Eye-opener", 
        "Young Traveller", "Excellent Traveller", "Contemporary Xu Xiake"};
    int test_case;
    while(std::cin >> test_case) {
        while(test_case--) {
            int cnt = 0, item;
            for(int _case=0; _case<4; _case++) {
                std::cin >> item;
                if(item != 0) cnt++;
            }
            std::cout << map[cnt] << std::endl;
        }
    }
    return 0;
}

