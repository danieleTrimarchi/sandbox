#include "Item.h"


Item::~Item(){
  for(auto child : children_) 
    delete child;
}
        
void Item::add(Item* child){
    children_.push_back(child);
};
    
void Item::accept(Visitor& v){
    
    v.visitItem(this);

    for( auto child : children_ )
        child->accept(v);
};

void Child::accept(Visitor& v){
    v.visitChild(this);
};       

void Visitor::visitItem(Item* a) {
    std::cout<<"-> Root\n";
};

void Visitor::visitChild(Child* b) {
    std::cout<<"-> Child\n";
};
