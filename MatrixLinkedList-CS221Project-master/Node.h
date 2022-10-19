/**
 * @file Node.h
 * @author Faizan Haq 2021368 && Ali Inayatullah 2021081
 * @brief Class file for Node
 * @version 0.1
 * @date 2022-10-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "headers.h"

/**
 * @brief Node for 4-way linked list
 * 
 */
struct Node {


    /**
     * @brief Data class for Node
     * 
     */
    struct Data{
        long phone_num;
        std::string name;
        std::string address;
        std::string email;
    };

    Data data;

    Node *top = NULL;
    Node *bottom = NULL;
    Node *next = NULL;
    Node *prev = NULL;

    //TODO: make stream insertion operator overload
    void printNode();
};

void Node::printNode(){
    std::cout << "phone num: " << data.phone_num << std::endl;
    std::cout << "name: " << data.name << std::endl;
    std::cout << "address: " << data.address << std::endl;
    std::cout << "email: " << data.email << std::endl;
    std::cout << std::endl;
}
