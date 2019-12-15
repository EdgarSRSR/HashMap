#include <iostream>
#include <cstddef>
#include "hashmap.h"

int main(){
	    // insert code here...
     hashmap<std::string,int> hashy;
    hashy.insert(std::pair<std::string, int>("juan", 34));
    hashy.insert(std::pair<std::string, int>("lera", 22));
    hashy.insert(std::pair<std::string, int>("vera", 24));
    hashy.insert(std::pair<std::string, int>("vlad", 23));
    hashy.insert(std::pair<std::string, int>("edgar", 29));
    hashy.insert(std::pair<std::string, int>("paul", 43));
    hashy.insert(std::pair<std::string, int>("paula", 78));
    hashy.insert(std::pair<std::string, int>("roman", 14));
    hashy.insert(std::pair<std::string, int>("mereke", 37));
    hashy.insert(std::pair<std::string, int>("natalya", 25));
    hashy.insert(std::pair<std::string, int>("aysuluu", 20));
    hashy.printMap();
    std::cout << "the number of elements in the first bucket is " << hashy.count(1) << " \n";
    hashy.bucketContent(1);
    
    std::string name = "";
    
    while(name != "exit"){
        //std::cout << "search for";
        std::cout << "remove this element: (type exit to end loop)";
        std::cin >> name;
        if(name != "exit"){
            //hashy.finder(name);
            hashy.erase(name);
        }else{
            break;
        }
    }
    hashy.bucketContent(0);
    hashy.printMap();
    hashy.at("mereke");
    hashy.at("michael");
    hashy.begin();
    hashy.end();
    std::cout<<"example using the iterator to get a key, key from value 34: "<<hashy.iteratorbegin(34)->key<< " \n";
    
    return 0;
}
