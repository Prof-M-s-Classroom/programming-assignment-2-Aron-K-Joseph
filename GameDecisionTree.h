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
    Story storyArray[70]; //rough number of element of a tree with depth of 5 will store all of the stories
    int storyArrayLength;
    Node<T>* storySet[70]; //will contain Node pointer with no duplicates
    int storySetLength;


public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr), storyArrayLength(0), storySetLength(0){}


    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream infile;
        std::string line;
        infile.open(filename);


        if (infile) {

            while (getline (infile,line)) {
                int num = 0;
                int numL = 0;
                int numR = 0;
                std::string des = "";
                std::string token = "";
                std::stringstream stream(line);

                std::getline(stream,token,delimiter);
                //converts token to int
                num = stoi(token);
                std::getline(stream,token,delimiter);
                des = token;
                std::getline(stream,token,delimiter);
                numL = stoi(token);
                std::getline(stream,token,delimiter);
                numR = stoi(token);

                Story stry =  Story(des,num,numL,numR);
                storyArray[++storyArrayLength] = stry; //we want the 0th index to be free so indeces correspond to eventnumber

            }
            //to keep track of what eventNumbers are already added to the tree preventing duplicates


            root = new Node<Story>(storyArray[1]);
            fillingTree(root);


            infile.close();
        }

    }
    void fillingTree(Node<Story>* rt) {
        //essentially filling tree with Rlr rt is essentialy a subroot not always the main root
        if (rt != nullptr) {
            int left = rt->data.leftEventNumber;
            if (left != -1) {//if the left is not null
                //only creating new node if event number does not appear in the set
                if (!contains(storySet,left,storySetLength)) {
                    rt->left = new Node<Story>(storyArray[left]);
                    storySet[storySetLength++] = rt->left;
                    fillingTree(rt->left);
                }
                else {
                    //if left is in the set we will find it in the tree and assign left pointer to it
                    rt->left = contains(storySet,left,storySetLength); //want to search from main root of tree not subroot
                    fillingTree(rt->left);

                }

            }
            int right = rt->data.rightEventNumber;
            if (right != -1) {
                if (!contains(storySet,right,storySetLength)) {
                    rt->right = new Node<Story>(storyArray[right]);
                    storySet[storySetLength++] = rt->right;
                    fillingTree(rt->right);
                }
                else {
                    //if left is in the set we will find it in the tree and assign left pointer to it
                    rt->right = contains(storySet,right,storySetLength); //want to search from main root of tree not subroot
                    fillingTree(rt->left);

                }
            }

        }
    }


    Node<Story>* contains(Node<Story>* arr[], int key, int length) {
        for (int i = 0; i < length; i++) {
            if (arr[i]->data.eventNumber == key) {
                return arr[i];
            }
        }
        return nullptr;
    }






    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<Story>* curr = root;
        int response = 3;
        while (curr != nullptr) {
            cout<<curr->data.description<<endl;
            while ((response !=1)&&(response !=2)) { //if it is not either r or it keeps on iterating
                cout<<"Type '1' to go left and '2' to go right." <<endl;
                std::cin>>response;
                if (response == 1) {
                    curr = curr->left;
                }
                if (response == 2) {
                    curr = curr->right;
                }
            }
            response = 3; //reset the response so the while loop at least iterates once
        }
        cout<<"End of Game!!!" <<endl;
    }
};

#endif // GAMEDECISIONTREE_H