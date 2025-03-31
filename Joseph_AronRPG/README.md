[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Aron Joseph`  
### **Student ID:** `132267197`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)


>This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Main function file where we run the game]`  
- **`GameDecisionTree.h`** → `[Header file for GameDecisionTree which contains the functions for creating the tree 
and traversing through it]`  
- **`Node.h`** → `[Header file for Node template class enabling us to make story nodes]`  
- **`Story.h`** → `[Header file for Story class which enables us to make story objects]`  
- **`story.txt`** → `[Text file containing the game story]`  

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- Each line is read from the txt file and each line is parsed and values for all the Story fields are for the 
  specific Story object is assigned based on the "|" delimitter.

- How are nodes linked based on left and right event numbers?  
- There is an array of node pointers which contains the event number The left and right nodes are assigned from this 
  array.

- What happens if an event has `-1` as left or right children?  
- If an event has '-1' as a left or right child that child is null

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
-If user selects 1 the left side is taken and if 2 the right side is taken

- What happens when the player reaches a leaf node?  
-When the player reaches a leaf node the user is no longer prompted.

- Explain the special case where multiple events lead to the same outcome.  
- If a node has two parents the parents will both have the option to go to that same child.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
-Each line is read from the txt file and each line is parsed and values for all the Story fields are for the
  specific Story object is assigned based on the "|" delimitter.


- How do you ensure nodes are properly linked?
-There is an array of node pointers which contains the event number. The left and right nodes of a particular story 
  node are found in the array and assigned appropriatly. 


- Any challenges faced while handling file input?  
-Not really while handling the file input but I had some difficulty opening the file.
---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

-I was not able to load the file so I had to provide the complete path of the file which seemed to work.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
You wake up and realize you are in Kenya Africa.
Do You go to Euroupe. (1) or Do You stay in Africa. (2)
1

You go to Euroupe.
Do You go to France. (1) or Do You go to Spain. (2)
2

You go to Spain.
Do You go underground. (1) or Do You go to Bunol. (2)
1

You go underground.
Do You go all the way into the mantle of the earth. (1) or Do You die to unexpected events. (2)
1

You go all the way into the mantle of the earth.
Do You evaporate. (1) or Do You develop resistance to the heat. (2)
2

You develop resistance to the heat.
End of Game!!!
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N)`  
- **Searching for an event in the tree** → `O(N)`  
- **Game traversal efficiency** → `O(logN)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> 
-I tested a scenario where the player reaches a  leaf node and it prompted the user again so I fixed it so if you 
reach a leaf node no more prompts occur.
---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
-No additional features.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
