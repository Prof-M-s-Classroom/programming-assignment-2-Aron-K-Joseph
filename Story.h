#ifndef STORY_H
#define STORY_H
#include <iostream>

#include <string>
using namespace std;
class Story {
public:
    string description;
    int eventNumber;
    int leftEventNumber;
    int rightEventNumber;

    // Default constructor
    Story();

    // Parameterized constructor
    Story(string desc, int num, int leftNum, int rightNum);

    void print() {
        std::cout<<description<<" "<<eventNumber<<" "<<leftEventNumber<<" "<<rightEventNumber<<std::endl;
    }
};

#endif // STORY_H