#include <iostream>
#include <string>
#include<vector>

class Visitor; 

class Item {
    
    public:

        Item(){};
        ~Item();

        std::vector<Item*> children_;
        
        void add(Item* child);
        
        virtual void accept(Visitor& v);
}; 

class Child: public Item {

    public:

        Child(){};
        ~Child(){};

        virtual void accept(Visitor& v);       
};


class Visitor {
    
    public: 
        void visitItem(Item* a);
        void visitChild(Child* b);
};

