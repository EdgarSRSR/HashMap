# HashMap
A hash Map implementation in C++
# HashMap
An Hash Map implementation in C++

This program creates hash map, it solves the collitions by implementing a chain method by linked lists in the buckets where collisions are present.

The hash map is implemented through a template for a class named hashmap. 
It has the following inbuilt functions:

- hashfunc(key): accepts a key as a parameter and implements the hash function.

- insert(key, value): accepts two parameter,s a key and a value and inserts them to the hashmap.

- get(key): receives a key and returns the value of the key.

- sizeofMap(): returns the size of the hash.

- isEmpty(): returns true if the size of the map is 0, else it returns false.

- count(index): accepts a key parameter counts the number of elements in the bucket and returns an integer showing the number of them.

- iterator(value): accepts a value as a parameterit starts from the beginning and looks for it all over the hashmap and returns it.

- printMap(): this function prints the hashmap it shows the index of each bucket, the key and value of the first element and the number of total elements in the bucket.

- bucketContent(key): prints the content of the linked list of the bucket in the index.

- remove(key): accepts a key parameter and removes it and its value from the hashmap.

*******************************************************************************************
The program can be build through Cmake

hashmap.h file is included in the include file.

main.cpp  file is included in the src
