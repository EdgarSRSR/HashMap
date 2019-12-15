#include <iostream>
#include <cstddef>
#include "hashmap.h"

int main(){
	    // insert code here...
    std::cout << "HashMap example";
    hashmap<std::string,int> hashy;
    hashy.insert("juan", 34);
    hashy.insert("lera", 22);
    hashy.insert("vera", 24);
    hashy.insert("vlad", 23);
    hashy.insert("edgar", 29);
    hashy.insert("paul", 43);
    hashy.insert("paula", 78);
    hashy.insert("roman", 14);
    hashy.insert("mereke", 37);
    hashy.insert("natalya", 25);
    hashy.insert("aysuluu", 20);
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
    hashy.iteratorbegin(34);
    std::cout<<"example using the iterator to get a key, key from value 34: "<<hashy.iteratorbegin(34)->key<< " \n";
    return 0;
}
