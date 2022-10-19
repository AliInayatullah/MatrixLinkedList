#define print(str) std::cout << str << std::endl;
#include "Node.h"
#include <iostream>

int main(){

    uint8_t i= 5;
    uint8_t j= 5;
{
    Node ***arr;
    for(size_t k = 0; k < i; k++)
        arr = new **Node();
    for(size_t k = 0; k < j; k++)
        arr = new *Node();


    for(size_t k = 0; k < i; k++)
    for(size_t l = 0; l < j; l++){
        arr[k][l]->next= l==0 ? NULL : arr[k][l+1];
        arr[k][l]->prev= l==j-1 ? NULL : arr[k][l-1];
        arr[k][l]->top= k==0 ? NULL : arr[k-1][l];
        arr[k][l]->bottom= k==i-1 ? NULL : arr[k+1][l];
    }
    
    Node *head = arr[0][0];
}
    
    


    return 0;
}
