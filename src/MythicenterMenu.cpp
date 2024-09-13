#include "../header/MythicenterMenu.h"
#include <thread>
#include <chrono>

void MythicenterMenu::printMenu(){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Nurse Jessie: \"Welcome to the Mythicenter! What service are you looking for?\"\n\n"
         << endl;
    cout << "1. Heal Mythikin" << endl;
    cout << "2. Access PC" << endl;
    cout << "3. Leave\n"
         << endl;

    int command;

    while (true)
    {
        cin >> command;
        cout << endl;

        if (command == 1)
        {
            healMenu();

            cout << "\"Anything else?\"" << endl;
            cout << "1. Heal Mythikin" << endl;
            cout << "2. Access PC" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 2)
        {
            pcMenu();
            cout << "\"Anything else?\"" << endl;
            cout << "1. Heal Mythikin" << endl;
            cout << "2. Access PC" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 3)
        {
            cout << "\n\"Come again!\"" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input. Try again.\n"
                 << endl;
            cout << "1. Heal Mythikin" << endl;
            cout << "2. Access PC" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void MythicenterMenu::healMenu(){
    cout << "\"I will take your Mythicubes for just a moment!\"" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << ".." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    mythicenter->healMythikins(patient.getTeam());
    cout << "\"Here are your Mythikin. All healthy!\"" << endl;
}

void MythicenterMenu::pcMenu(){
    cout << "Opening PC..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cout << "-----------------------------------------------------------------" << endl;
    cout << "What service are you looking for?\n\n"
         << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Leave\n"
         << endl;

    int command;

    while (true)
    {
        cin >> command;
        cout << endl;

        if (command == 1)
        {
            PCDepositMenu();
            cout << "Anything else?" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 2)
        {
            PCWithdrawMenu();
            cout << "Anything else?" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        else if (command == 3)
        {
            cout << "Exiting PC..." << endl;
            cout << "-----------------------------------------------------------------" << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input. Try again.\n"
                 << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "3. Leave\n"
                 << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void MythicenterMenu::PCDepositMenu(){
    cout << "Which Mythikin would you like to deposit?" << endl;
    for(int i = 0; i < patient.getTeam().getSize(); i++){
        cout << i + 1 << ". " << patient.getTeam().getSlot(i).getName() << endl;
    }

    cout << "\nPress -1 to go back\n" 
        << endl;

    int command;
    while (true)
    {
        cin >> command;
        cout << endl;

        if (command > 0 && command <= patient.getTeam().getSize())
        {
            (*mythicenter->getPC()).depositMythikin(patient.getTeam().getSlot(command - 1), patient.getTeam());
            break;
        }
        else if (command == -1)
        {
            cout << "Returning to PC Main Menu." << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input. Try again.\n"
                 << endl;

            cout << "Which Mythikin would you like to deposit?" << endl;
            for(int i = 0; i < patient.getTeam().getSize(); i++){
                cout << i + 1 << ". " << patient.getTeam().getSlot(i).getName() << endl;
            }

            cout << "\nPress -1 to go back\n" 
                << endl;
        }
        cin.clear();
        cin.ignore();
    }
}

void MythicenterMenu::PCWithdrawMenu(){
    cout << "Which Mythikin would you like to withdraw?" << endl;
    for(int i = 0; i < (*mythicenter->getPC()).getPCList().size(); i++){
        cout << i + 1 << ". " << (*mythicenter->getPC()).getPCList()[i]->getName() << endl;
    }

    cout << "\nPress -1 to go back\n" 
        << endl;

    int command;

    if((*mythicenter->getPC()).getPCList().size() == 0){
        cout << "No Mythikin in PC." << endl;
        return;
    }

    while (true)
    {
        cin >> command;
        cout << endl;

        if (command > 0 && command <= (*mythicenter->getPC()).getPCList().size())
        {
            (*mythicenter->getPC()).withdrawMythikin((*mythicenter->getPC()).getPCList()[command - 1]->getName(), patient.getTeam());
            break;
        }
        else if(command == -1)
        {
            cout << "Returning to PC Main Menu." << endl;
            break;
        }
        else
        {
            cout << "\nInvalid input. Try again.\n"
                 << endl;

            cout << "Which Mythikin would you like to withdraw?" << endl;
            for(int i = 0; i < (*mythicenter->getPC()).getPCList().size(); i++){
                cout << i + 1 << ". " << (*mythicenter->getPC()).getPCList()[i]->getName() << endl;
            }

            cout << "\nPress -1 to go back\n" 
                << endl;
        }
        cin.clear();
        cin.ignore();
    }
}