#include <string>
using namespace std;
class BeadNode {
    public:
        string material;
        BeadNode* next; //pointer to the bead in the linked list
        
        BeadNode(const string& mat); //constructor for initialization of BeadNode
};
class Necklace {
    private: 
    BeadNode* head;
    
    public:
        Necklace(); //Constructor for Necklace with no inputs yet
        ~Necklace(); //Destructor to delete beads in linked list
        
        //All return 0 or -1 for success or failure
        int append(const string& material);
        int insert(int position, const string& material);
        int deleteNode(int position);
        int search(const string& material);
        void display();
        int size();
};