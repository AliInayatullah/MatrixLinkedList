#include "headers.h"

int main()
{

    consoleGUI gui;
    MatrixList list(3, 3);

    gui.Loading();

    while (1)
    {
        std::string search;
        Node *newNode;
        switch (gui.Menu())
        {
        case 1:
            list.createNewList(3, 3); // deafult is 3x3;
            std::cout << "New List created" << std::endl;
            break;
        case 2:
            newNode = new Node();
            std::cout << "Phone num: ";
            std::cin >> newNode->data.phone_num;
            if (list.searchPhone(newNode->data.phone_num) != NULL)
            {
                std::cout << "\n\nThis phNum already exists bro wyd?\n\n\n";
                break;
            }

            std::cout << "Name: ";
            std::cin >> newNode->data.name;
            std::cout << "Address: ";
            std::cin >> newNode->data.address;
            std::cout << "Email(optional): ";
            std::cin >> newNode->data.email;
            list.insertNode(newNode);
            break;
        case 3:
            long phNum;
            std::cout << "Enter a phone Num to delete: ";
            std::cin >> phNum;
            if (list.deleteNode(phNum))
                std::cout << "deleted successfully\n";
            else
                std::cout << "Node not found // not deleted successfully\n";
            break;
        case 4:
            switch (gui.searchMenu())
            {
            case 1:
                std::cout << "Enter Name: ";
                std::cin >> search;
                if (list.searchName(search) != NULL)
                    std::cout << "The phone num of the person is: " << list.searchName(search)->data.phone_num << std::endl;
                else
                    std::cout << "Person DNE\n";
                break;
            case 2:
                std::cout << "Enter Address: ";
                std::cin >> search;
                if (list.searchAddress(search) != NULL)
                    std::cout << "The phone num of the person is: " << list.searchAddress(search)->data.phone_num << std::endl;
                else
                    std::cout << "Person DNE\n";
                break;
            case 3:
                std::cout << "Enter Email: ";
                std::cin >> search;
                if (list.searchEmail(search) != NULL)
                    std::cout << "The phone num of the person is: " << list.searchEmail(search)->data.phone_num << std::endl;
                else
                    std::cout << "Person DNE\n";
                break;
            default:
                std::cout << "bro u dun messed up sum where" << std::endl;
            }
            break;
        case 5:
            list.printGUI();
            break;
        default:
            std::cout << "bro u dun messed up sum where" << std::endl;
        }
        std::cout << "Press any key to continue..." << std::endl;
        getch();
    }

    return 0;
}
