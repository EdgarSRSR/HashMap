//
//  hashmap.hpp
//  hashmap
//
//  Created by Edgar SR on 10/12/19.
//  Copyright © 2019 Edgar SR. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <list>
#include <cstddef>
#include <string>

template <typename k, typename v>
class hashmap{
private:

    // determines size of the hash map
    static const int hashmapsize = 10;

    //creates the ctructure called bucket for each bucket in the hash map
    struct bucket{
        k key;
        v value;
        bucket* next;
    };
    //creates a hashmap with the buckets 
    bucket* HashMap[hashmapsize];
    
    
public:
    
    hashmap(){
        // initializes the hash map
        for(int i = 0; i < hashmapsize; i++){
            HashMap[i] = new bucket;
            HashMap[i]-> next = NULL;
        };
    };
    
    // This implements hash function
    int hashfunc(k key)
    {
        int hash = 0;
        int index;
        //the key is turned into an integer and added to create the hash
        for(int i = 0; i < key.length();i++){
            hash = hash + (int)key[i];
        }
        //the hash is divided by the size of the hashmap 
        index = hash % hashmapsize;
        //the index is returned
        return index;
    }
    
    //inserts a new key and value to the hashmap
    void insert( k key, v value){
        int index = hashfunc(key);
        std::string checker = std::string(HashMap[index]->key);
        // if the bucket is free
        if(checker.length()==0){
            HashMap[index]->key = key;
            HashMap[index]->value = value;
        } else{
            // else it starts creating a linked list
            bucket* Ptr = HashMap[index];
            bucket* n = new bucket;
            n->key = key;
            n->value = value;
            n->next = NULL;
            while(Ptr->next != NULL){
                Ptr = Ptr->next;
            }
            Ptr->next = n;
        }
    };
    
    //Function to search the value for a given key
    v get(k key)
    {
        int index = hashfunc(key);
        bool foundname = false;
        v value;
        std::string result;
         // goes directly to the bucket by calculating the index and starts looking through the elements of th bucket
        bucket* Ptr = HashMap[index];
        while(Ptr != NULL){
            if(Ptr->key == key){
                foundname = true;
                result = std::to_string(Ptr->value);
                value = Ptr->value;
                break;
            }
            Ptr = Ptr->next;
        }
        if(foundname == true){
            //returns the value
            std::cout << "value = " << result << std::endl;
            return value;
        } else {
            //if the element doesn't exists  it returns a message
            std::cout << key << " was not found\n";
            
        }
    }
    
    //Return current size of hashmap
    int sizeofMap()
     {
     return hashmapsize;
     }
    
    //Return true if size is 0
    bool isEmpty()
     {
     return hashmapsize == 0;
     }

    // count the number of elements in the bucket
    int count(int index){
        int count = 0;
        // to check if the key exists it checks it as a string
        std::string checker = std::string(HashMap[index]->key);
        if(checker.length()==0){
            return count;
        } else{
            count++;
            bucket* Ptr = HashMap[index];
            while(Ptr->next != NULL){
                count++;
                Ptr = Ptr->next;
            }
        }
        return count;
    }

    // an iterator, it starts from the beginning and looks for a value all over the hashmap
    bucket iterator(v value){
        bucket interbucket = HashMap[0];
        for(int i = 0; i <= hashmapsize; i++){
            interbucket = HashMap[i];
            int elementnumber = interbucket[i].count(i);
            if(interbucket->value == value){
                return interbucket;
            } else if (interbucket->value != value && elementnumber > 1){
                interbucket = interbucket->next;
                for(int j = 1; j <= elementnumber; j++){
                    if(interbucket->value == value){
                        return interbucket;
                    }else{
                        interbucket = interbucket->next;
                    }
                }
            }
        }
    }
    
    //this function prints the hashmap it shows the index of each bucket, the key and value of the first
    //element and the number of total elements in the bucket
    void printMap(){
        
        int number;
        for(int i = 0; i<hashmapsize; i++){
            number = count(i);
            std::cout << "----------------\n";
            std::cout << "index = " << i << std::endl;
            std::cout << HashMap[i]->key << std::endl;
            std::cout << HashMap[i]->value << std::endl;
            std::cout << "number of items = " << number << std::endl;
            std::cout << "----------------\n";
        }
    }
    
    //this prints the content of the linked list of the bucket in the index
    void bucketContent(int index){
        bucket* Ptr = HashMap[index];
        std::string checker = std::string(HashMap[index]->key);
        if(checker.length()==0){
            std::cout << "index = " << index << " is empty\n";
        } else{
            std::cout << "index" << index << " contains the following item\n";
            while(Ptr != NULL){
                std::cout << "---------------\n";
                std::cout << Ptr->key << std::endl;
                std::cout << Ptr->value << std::endl;
                std::cout << "---------------\n";
                Ptr = Ptr->next;
            }
        }
    }
    
    // removes a key and its value from the hashmap
     void remove(k key){
     int index = hashfunc(key);
     bucket* delPtr;
     bucket* p1;
     bucket* p2;
     
     // if the bucket is empty
    std::string checkkey = std::string(HashMap[index]->key);
    std::string checkval = std::to_string(HashMap[index]->value);
     if(checkkey.length()== 0 && checkval.length()== 0 ){
        std::cout << key << " is not in the hashmap\n";
     }
     // if there is only one item in the bucket and it matches with the name
     else if(HashMap[index]->key == key && HashMap[index]->next == NULL){
         HashMap[index]->key = '0';
         HashMap[index]->value = '0';

         std::cout << key << " was removed from the hashmap\n";
     }
     // if there is a match in the first item in the bucket but there are more items in it
     else if(HashMap[index]->key == key){
         delPtr = HashMap[index];
         HashMap[index] = HashMap[index]->next;
         delete delPtr;
         std::cout << key << " was removed from the hashmap\n";
         }
     // if the bucket contains items, but first item is not a match
     else{
         p1 = HashMap[index]->next;
         p2 = HashMap[index];
         while(p1 != NULL && p1->key != key){
         p2 = p1;
         p1 = p1->next;
     }
     // if the bucket contains items, but first item is not a match, no match found
     if(p1 == NULL){
         std::cout << key << " was not found in the hash table\n";
     }
     // if the bucket contains items, but first item is not a match, match is found
     else{
         delPtr = p1;
         p1 = p1 ->next;
         p2->next = p1;
         delete delPtr;
         std::cout << key << " was removed from the hashmap\n";
         
     }
     }
     }
};
