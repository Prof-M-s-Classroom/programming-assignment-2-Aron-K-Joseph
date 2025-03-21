#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}


    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream infile;
        std::string line;
        infile.open("C:/code/DataStructures/programming-assignment-2-Aron-K-Joseph/read.txt");
        Story storyArray[70]; //rough number of element of a tree with depth of 5
        int storyArrayLength = 0;


        if (infile) {

            while (getline (infile,line)) {
                int num = 0;
                int numL = 0;
                int numR = 0;
                std::string des = "";
                std::string token = "";
                std::stringstream stream(line);

                std::getline(stream,token,'|');
                //converts token to int
                num = stoi(token);
                std::getline(stream,token,'|');
                des = token;
                std::getline(stream,token,'|');
                numL = stoi(token);
                std::getline(stream,token,'|');
                numR = stoi(token);

                Story stry =  Story(des,num,numL,numR);
                storyArray[++storyArrayLength] = stry; //we want the 0th index to be free so indeces correspond to eventnumber

            }
            root = new Node<Story>(storyArray[1]);
            fillingTree(root,storyArray);
            std::cout<<"Success"<<std::endl;

            infile.close();
        }

    }
    void fillingTree(Node<Story>* root,Story storyArray[]) {
        //essentially filling tree with Rlr
        int left = root->data.leftEventNumber;
        if (left != -1) {
            root->left = new Node<Story>(storyArray[left]);
            fillingTree(root->left,storyArray);
        }
        int right = root->data.rightEventNumber;
        if (right != -1) {
            root->right = new Node<Story>(storyArray[right]);
            fillingTree(root->right,storyArray);
        }
    }





    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){}
};

#endif // GAMEDECISIONTREE_H