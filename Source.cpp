/* Group Member List

Member Name 1:
Matric Number:
Section:

Member Name 2:
Matric Number:
Section:

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class ItemNode {
public:
    string name;
    float price;
    ItemNode* aft;
    ItemNode* bef;

    ItemNode(string i_name = NULL, float i_price = 0) {
        name = i_name;
        price = i_price;
    }
};

class List {
private:
    ItemNode* head;
    ItemNode* tail;
public:
    void task1(ItemNode*);
    void task2(ItemNode*);
    void task3();
    void task4(ItemNode*, int);
    void task5(int);
    void task6();
};

void List::task1(ItemNode* newNode) { // Insert new item to empty list
    head = newNode;
    tail = newNode;

    newNode->aft = newNode->bef = nullptr;
}

void List::task2(ItemNode* newNode) { // Insert at front
    ItemNode* nodePtr = head;
    ItemNode* prevNode = nodePtr->bef;

    prevNode = newNode;
    newNode->bef = nullptr;
    newNode->aft = nodePtr;

    nodePtr->bef = newNode;
    nodePtr->aft = nullptr;

    head = newNode;


}

void List::task3() { // Print backwards
    ItemNode* nodePtr = tail;

    while (nodePtr) {
        cout << "[" << nodePtr->name << "\t" << nodePtr->price << "]\t";
        nodePtr = nodePtr->bef;
    }


}


int main() {
    List ItemList;

    ItemNode* n1 = new ItemNode("Book", 9.59);
    ItemNode* n2 = new ItemNode("Ruler", 3.45);
    ItemNode* n3 = new ItemNode("Pen", 5.69);
    ItemNode* n4 = new ItemNode("Eraser", 2.25);

    cout << fixed << setprecision(2) << left;
    ItemList.task1(n1);
    ItemList.task2(n2);
    ItemList.task3();
}