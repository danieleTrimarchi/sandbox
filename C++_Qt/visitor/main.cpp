#include <iostream>
#include <string>
#include<vector>

#include "Item.h"

int main()
{
    Item* pRoot = new Item();
    
    pRoot->add( new Child() ); 
    
    Visitor v; 
    pRoot->accept(v);

    Child* pChild = new Child();
    pChild->accept(v);
    
    delete pRoot; 
    
}