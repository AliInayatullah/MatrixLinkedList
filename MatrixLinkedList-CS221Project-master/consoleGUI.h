#include "headers.h"

//"1. Create a new list\n2. Insert a new node\n3. delete a node using phNum\n4. Seach for a Node\n5. Display All Nodes\n

class consoleGUI{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char key_press;
    int ascii_value;
    int current_menu = 1;

public:
    consoleGUI(){
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        current_menu = 1;
    }
    int Menu(){
        while (1){
            system("CLS");

            SetConsoleTextAttribute(hConsole, 15);
            std::cout << "\tMAIN MENU \nUSE ARROW KEYS TO NAVIGATE!\n";

            switch (current_menu){

            case 1:
                SetConsoleTextAttribute(hConsole, 112);
                std::cout << "\n1. Create a new List. \n";
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "2. Insert a new node\n3. delete a node using phNum\n4. Seach for a Node\n5. Display All Nodes\n";
                break;
            case 2:
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "\n1. Create a new List. \n";
                SetConsoleTextAttribute(hConsole, 112);
                std::cout << "2. Insert a new node\n";
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "3. delete a node using phNum\n4. Seach for a Node\n5. Display All Nodes\n";
                break;
            case 3:
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "\n1. Create a new List. \n2. Insert a new node\n";
                SetConsoleTextAttribute(hConsole, 112);
                std::cout << "3. delete a node using phNum\n";
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "4. Seach for a Node\n5. Display All Nodes\n";
                break;
            case 4:
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "\n1. Create a new List. \n2. Insert a new node\n3. delete a node using phNum\n";
                SetConsoleTextAttribute(hConsole, 112);
                std::cout << "4. Seach for a Node\n";
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "5. Display All Nodes\n";
                break;
            case 5:
                SetConsoleTextAttribute(hConsole, 8);
                std::cout << "\n1. Create a new List. \n2. Insert a new node\n3. delete a node using phNum\n4. Seach for a Node\n";
                SetConsoleTextAttribute(hConsole, 112);
                std::cout << "5. Display All Nodes\n";
                SetConsoleTextAttribute(hConsole, 8);
                break;
            }

            key_press = _getch();
            ascii_value = key_press;

            if (ascii_value == 72){
                if (current_menu > 1){
                    current_menu--;
                }
                else{
                    current_menu = 5;
                }
            }
            else if (ascii_value == 80){
                if (current_menu < 5){
                    current_menu++;
                }
                else{
                    current_menu = 1;
                }
            }
            else if (ascii_value == 27)
                return 10;
            else if (ascii_value == 13)
                return current_menu;
        }
    }

    int searchMenu(){
        int selection;
        std::cout << "\n\nInput what you want to seach by:\n1.Name\n2.Address\n3.Email\n\nEnter your choice: ";
        
        do{
            std::cin >> selection;
        } while(selection > 3 || selection < 1);

        return selection;
    }

    void Loading(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("CLS");
        std::cout << "\n\n\n\n\n\tLoading...\n";
        for (int i = 0; i < 10; i++){
            Sleep(150);
            SetConsoleTextAttribute(hConsole, 20 + (15 * i));
            std::cout << "  ";
            SetConsoleTextAttribute(hConsole, 8);
            std::cout << " ";
        }
    }
};