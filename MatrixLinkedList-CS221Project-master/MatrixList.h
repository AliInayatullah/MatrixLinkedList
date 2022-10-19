/**
 * @file MatrixList.h
 * @author Faizan Haq 2021368 && Ali Inayatullah 2021081
 * @brief Class file for MatrixList
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "headers.h"

/**
 * @brief Linked list matrix class
 *
 */
class MatrixList
{
private:
    int rows, cols;
    Node *headptr, *tailptr;
    uint8_t count;

    // Private Functions

    /**
     * @brief rearrange the list
     *          move tail node to specified node and delete the tail node
     *
     * @param it starting node
     */
    void rearrangeList(Node *it);

    /**
     * @brief Get the Node object
     *
     * @param r row
     * @param c column
     * @return Node* returns address of the specified node
     */
    Node *getNode(uint8_t r, uint8_t c);

public:
    /**
     * @brief Construct a new Matrix List object
     *
     */
    MatrixList();

    /**
     * @brief Construct a new Matrix List object
     *
     * @param rm number of rows
     * @param cm number of columns
     */
    MatrixList(uint8_t rm, uint8_t cm);

    /**
     * @brief Destroy the Matrix List object
     *
     */
    ~MatrixList();

    /**
     * @brief Create a New List
     *        destroy previous list if exists
     *
     * @param rows new list rows
     * @param cols new list columns
     */
    void createNewList(uint8_t rows, uint8_t cols);

    /**
     * @brief Insert a new node at the tail
     *        E-pattern insertion
     *
     * @param newNode New Node
     */
    bool insertNode(Node *newNode);

    /**
     * @brief Search specified phone number
     *
     * @param phNum
     * @return Node* Return address of node with specified phNum
     *         Return NULL if no node exists
     */
    Node *searchPhone(const long &phNum) const;

    /**
     * @brief Search specified name
     *
     * @param phNum
     * @return Node* Return address of node with specified name
     *         Return NULL if no node exists
     */
    Node *searchName(std::string name);

    /**
     * @brief Search specified address
     *
     * @param phNum
     * @return Node* Return address of node with specified address
     *         Return NULL if no node exists
     */
    Node *searchAddress(std::string address);

    /**
     * @brief Search specified email
     *
     * @param phNum
     * @return Node* Return address of node with specified email
     *         Return NULL if no node exists
     */
    Node *searchEmail(std::string email);

    /**
     * @brief delete node using phNum
     *
     * @param phNum
     * @return true if node is deleted successfully
     * @return false if node DNE
     */
    bool deleteNode(long &phNum);

    /**
     * @brief Print Nodes data to console
     *        E-shape printing
     *
     */
    void printToConsole();

    /**
     * @brief Print data of specified node
     *
     * @param r row
     * @param c column
     */
    void printToConsole(uint8_t r, uint8_t c);

    /**
     * TODO
     * @brief prints Node in a proper table
     *
     */
    void printGUI();
};

MatrixList::MatrixList()
{
    rows = 0;
    cols = 0;
    headptr = NULL;
    tailptr = NULL;

    count = 0;
}

MatrixList::MatrixList(uint8_t rm, uint8_t cm)
{
    rows = rm;
    cols = cm;
    headptr = NULL;
    tailptr = NULL;

    count = 0;
}

MatrixList::~MatrixList()
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            Node *del = it;
            it = it->next;
            delete del;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }

    std::cout << "\n\n\ndestructor called\n\n\n\n";
}

void MatrixList::rearrangeList(Node *it)
{
    std::swap(it->data, tailptr->data);
    Node *del = tailptr;

    if(count == 1){
        headptr = NULL;
        tailptr = NULL;
    } else if(tailptr->prev != NULL){
        tailptr = tailptr->prev;
        tailptr->next = NULL;
    } else if(tailptr->top != NULL){
        tailptr = tailptr->top;
        tailptr->bottom = NULL;
    }
    else return;


    delete del;
    count--;
}

Node *MatrixList::getNode(uint8_t r, uint8_t c)
{
    if (r < rows && c < cols)
    {
        Node *it = headptr;
        for (uint8_t c1 = 0; c1 < c; c1++)
            it = it->next;
        for (uint8_t r1 = 0; r1 < r; r1++)
            it = it->bottom;

        return it;
    }

    return NULL;
}

void MatrixList::createNewList(uint8_t rows = 0, uint8_t cols = 0)
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            Node *del = it;
            it = it->next;
            delete del;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    this->rows, this->cols = rows, cols;
    headptr = NULL;
    tailptr = NULL;
    count = 0;
}

bool MatrixList::insertNode(Node *newNode)
{

    if (count >= rows * cols)
    {
        std::cout << "The list is full";
        return 0;
    }
    if (headptr == NULL)
    {
        headptr = newNode;
        tailptr = newNode;
        count++;
    }
    else if (count % cols == 0)
    {
        tailptr = headptr;
        for (int i = 1; i < count / cols; i++)
            tailptr = tailptr->bottom;
        tailptr->bottom = newNode;
        newNode->top = tailptr;
        tailptr = tailptr->bottom;
        count++;
    }
    else
    {
        tailptr->next = newNode;
        newNode->prev = tailptr;
        if (tailptr->top != NULL)
        {
            tailptr->top->next->bottom = newNode;
            newNode->top = tailptr->top->next;
        }
        tailptr = newNode;
        count++;
    }
    return 1;
}

Node *MatrixList::searchPhone(const long &phNum) const
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            if (it->data.phone_num == phNum)
                return it;

            it = it->next;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    return NULL;
}

Node *MatrixList::searchName(std::string name)
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            if (it->data.name == name)
                return it;

            it = it->next;
        }

        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    return NULL;
}

Node *MatrixList::searchAddress(std::string address)
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            if (it->data.address == address)
                return it;

            it = it->next;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    return NULL;
}

Node *MatrixList::searchEmail(std::string email)
{
    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            if (it->data.email == email)
                return it;

            it = it->next;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    return NULL;
}

bool MatrixList::deleteNode(long &phNum)
{
    Node *temp = searchPhone(phNum);
    if (temp)
    {
        temp->data.address = "";
        temp->data.email = "";
        temp->data.name = "";
        temp->data.phone_num = 0;

        // ! PROBLEM
        rearrangeList(temp);
        return 1;
    }
    return 0;
}

void MatrixList::printToConsole()
{
    if (headptr == NULL)
    {
        std::cout << "EMPTY";
        return;
    }

    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            std::cout << std::endl
                      << i << ", " << j << std::endl;
            it->printNode();
            it = it->next;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
}

void MatrixList::printToConsole(uint8_t row, uint8_t col)
{
    getNode(row, col)->printNode();
}

void MatrixList::printGUI()
{
    if (headptr == NULL)
    {
        std::cout << "EMPTY";
        return;
    }

    Node *it = headptr;
    for (int i = 0; it != NULL; i++)
    {
        for (int j = 0; it != NULL; j++)
        {
            std::cout << "(" << i << ", " << j << ")" << std::setw(10) << '|'
            << it->data.phone_num << std::setw(20) <<  '|' << it->data.name << std::setw(20) << '|'
            << it->data.address << std::setw(20) << '|' << it->data.email << std::setw(20) << '|' << std::endl;
            it = it->next;
        }
        it = headptr;
        for (int k = 0; k <= i; k++)
            it = it->bottom;
    }
    std::cout<<std::endl;
}
