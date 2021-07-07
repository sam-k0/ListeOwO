#include "item.h"
#include "itemlist.h"

void showMenu()
{
    std::cout << "-------------\nWelcome to list:" << std::endl;
    std::cout << "1: print \n"
                 "2: advance \n"
                 "3: get current \n"
                 "4: del current \n"
                 "5: printme (Debug)\n"
                 "6: retreat \n"
                 "7: getlast (Debug)\n"
                 "8: create new and set value \n"
                 "9: set data \n"
                 "10: exit \n"
                 "11: wipe (Debug)\n"
                 "12: insert new data sorted \n"
                    << std::endl;
}

int getInput()
{
    string input;
    int inputConverted;

    while(true)
    {
        std::cout << "What do you want to do?"<<endl;
        std::cin >> input;


        try
        { // Try to convert stoi
            inputConverted = stoi(input);
            return inputConverted;

        }  catch (invalid_argument)
        { // If not successfull, try again
            std::cout << "Invalid input. Try again."<<endl;
        }
    }

}
/*
 *
 *
 *
*/
/*
int main()
{

    ItemList<char> OWO; // Change to datatype-----------------------------|



    int input = 0;

    bool success = false; // return value from functions
    while(true)
    {
        showMenu();
        input = getInput();

        Item<char>* switchelement; // Change to datatype------------------|
        char data;                  // Here aswell------------------------|
        std::cout << "-----------------"<<std::endl;
        switch(input)
        {
            case 1: // print
            OWO.print();
            break;

            case 2: // advance          
            success = OWO.adv();
            if(!success)
            {
                // Successfull
                std::cout << "Could not advance: Either list is empty or last element is reached."<<std::endl;
            }
            else
            {
                std::cout << "Advanced pointer to next element with value: "<< OWO.get() <<std::endl;
            }
            break;

            case 3: // print
            OWO.get();
            break;

            case 4:  // del curr
            OWO.del();
            break;

            case 5: // printme
            OWO.printcurr();
            break;

            case 6: // printme
            OWO.back();
            break;

            case 7: // printme
            if(OWO.getLast() != nullptr)
            {
                OWO.getLast()->printme();
            }else
            {
                std::cout << "Empty." << std::endl;
            }
            break;

            case 8: // create new and setval
            OWO.insnew();
            break;

            case 9: // set data
            switchelement = OWO.get();


            std::cout << "Data?"<<std::endl;
            std::cin >> data;

            switchelement->setData(data);

            break;

            case 10: // create new and setval
            std::cout << "Exiting...";
            exit(0);
            break;

            case 11: // create new and setval
            OWO.wipeList();
            break;

            case 12: // create new sorted
            switchelement = new Item<char>;

            std::cout << "Data?"<<std::endl;
            std::cin >> data;
            switchelement->setData(data);

            OWO.insSorted(switchelement);

            break;

        default:
            cout << "Invalid input" << endl;
        }

        switchelement = nullptr;

    }
    return 0;
}
*/

