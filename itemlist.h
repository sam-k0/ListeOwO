#ifndef ITEMLIST_H
#define ITEMLIST_H
#include "item.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class ItemList
{
private:

    Item<T>* first;
    Item<T>* currentptr;
    Item<T>* last;


public:
    ItemList()
    {
        first = nullptr;
        currentptr = nullptr;
        last = nullptr;
    }
    //Item<T>* get(); // Returns pointer to current Element
    Item<T>* get()// Returns pointer to current Element
    {
        std::cout  << "Returning current with : " << currentptr->getData() << std::endl;
        return currentptr;
    }

    Item<T>* getFirst()// Returns pointer to first Element
    {
        return first;
    }

    Item<T>* getLast()// Returns pointer to last Element
    {
        return last;
    }

    //bool empty(); // Checks if list empty (aka: first is noone)
    bool empty()// Checks if list empty (aka: first is noone)
    {
        if(first == nullptr)
        {
            return true;
        }
        return false;
    }

    //bool end(); // Checks if the current pointer points to the last element
    bool end()// Checks if the current pointer points to the last element
    {
        if(currentptr->isLast() || empty())
        {
            return true;
        }
        return false;
    }



    //bool adv(); // Tries to advance the current pointer to next element : True if successful, false if not, i.e. last element has been reached
    bool adv()// Tries to advance the current pointer to next element : True if successful, false if not, i.e. last element has been reached
    {
        std::cout << "INFO : Trying to advance"<<endl;
        if(currentptr == nullptr) // Check if last element has been reached
        {
            std::cout << ">> currentptr is nullptr!"<<endl;
            // cant advance
            return false;
        }

        if(currentptr->getNext() == nullptr)
        {
            std::cout << ">> next element does not exist!"<<endl;
            return false;
        }

        std::cout << ">> successfully advanced!"<<endl;
        currentptr = currentptr->getNext();
        return true;
    }

    bool back() // Tries to go back one element: Returns false if there is no prev.
    {
        std::cout << "INFO : Trying to retreat!"<<endl;
        if(currentptr == nullptr)
        {
            std::cout << ">> currentptr is nullptr!"<<endl;
            return false;
        }

        if(currentptr->getPrev() == nullptr)
        {
            std::cout << ">> prev element does not exist!"<<endl;
            return false;
        }

        std::cout << ">> successfully retreated!"<<endl;
        currentptr = currentptr->getPrev();
        std::cout << ">> Now sitting at element: " << currentptr->getData()<< std::endl;
        return true;

    }
    //bool reset(); // Tries to reset the pointer to the first element : True if successful, false if list empty
    bool reset()// Tries to reset the pointer to the first element : True if successful, false if list empty (current gets set to NULLPTR)
    {
        if(!empty())
        {
            currentptr = first;
            return true;
        }
        return false;

    }

    //void ins(Item<T>* toAdd); // Inserts a new element at the current pointers position
    void ins(Item<T> *toAdd)// Inserts a new element at the current pointers position
    {
        std::cout << "INFO : Trying to insert:"<<endl;
        // is it the first element?
        if(first == nullptr)
        {
            std::cout << ">> Element is first in list! (case1)"<<endl;
            first = toAdd;
            first->setPrev(nullptr);

            first->setPrev(nullptr);
            last = first;

            currentptr = first;
            return;
        }


        Item<T>* currentptrPrev = currentptr->getPrev(); // Get the current pointer's prev and next so it isnt lost
        Item<T>* currentptrNext = currentptr->getNext();

        if(currentptr == first)
        {
            cout << ">> Inserting to front (case2)"<<endl;

            first = toAdd;
            first->setNext(currentptr);

            currentptr->setPrev(toAdd);
            currentptr = toAdd;
            first->setPrev(nullptr);
            return;
        }

        // if its anywhere in the list:
       currentptrPrev = currentptr->getPrev();
       currentptrPrev->setNext(toAdd);

       toAdd->setPrev(currentptrPrev);
       toAdd->setNext(currentptr);

       currentptr->setPrev(toAdd);
       currentptr = toAdd;




    }

    //void del(); // Deletes the element at the current pointer
    void del()// Deletes the element at the current pointer
    {

        // Case 1: The element is the first and only in the list:
        if(currentptr == first && first->getNext() == nullptr) // just delete the current
        {
            delete currentptr;
            first = nullptr;
            last = nullptr;
            currentptr = nullptr;
            return;
        }

        // Case 2: The element is the first and we have next elements
        if(currentptr == first && first->getNext() != nullptr)
        {
            // keep the deleted in currentptr for now.
            first = currentptr->getNext();
            first->setPrev(nullptr);

            delete currentptr;
            currentptr = first;
            return;
        }

        // Case 3: We delete at the end of the list (and have prev)
        if(currentptr == last && currentptr->getPrev() != nullptr)
        {
            // we keep the to be deleted one in currentptr for now.

            last = currentptr->getPrev();
            last->setNext(nullptr);

            delete currentptr;
            currentptr = last;
            return;
        }

        // Case 4: We delete in middle of the list
        if(currentptr != first && currentptr->getPrev() != nullptr && currentptr->getNext() != nullptr && currentptr != last)
        {
            // lets keep the to be deleted one in currentptr for now

            Item<T>* currPrev = currentptr->getPrev();
            Item<T>* currNext = currentptr->getNext();

            currPrev->setNext(currNext);
            currNext->setPrev(currPrev);

            assert(currentptr != nullptr);

            delete currentptr;

            currentptr = currNext;
            return;

        }

    }

    //void print(); // Prints the list
    void print()
    {
        if(first == nullptr)
        {
            std::cout << "Is empty." << std::endl;
            return;
        }
        std::cout << "Printing list:" << std::endl;
        first->print(currentptr);
    }

    void printcurr()
    {
        if(currentptr != nullptr)
        {
            currentptr->printme();
        }
    }

    void insnew()
    {
        Item<T>* newElement = new Item<T>;
        T data;
        std::cout << "Data?"<<std::endl;

        std::cin >> data;

        newElement->setData(data);

        ins(newElement);

    }

    void wipeList()
    {
        std::cout << "Wiping list..."<<std::endl;
        if (first != nullptr)
        {
            first->delme();
        }

        first = nullptr;
        last = nullptr;
        currentptr = nullptr;
    }

    void compare()
    {
        if(currentptr > currentptr->getNext())
        {
            cout << "A is bigger than B";
        }
        else
        {
            cout << "b is bigger than a";
        }
    }

    void insSorted(Item<T> *toAdd)// Inserts a new element at the correct position
    {
       if(first == nullptr)
       {
            // list is empty
            first = toAdd;
            currentptr = toAdd;
            last = toAdd;
            return;
       }


       if(*first >= *toAdd) // the toadd is smaller than anything
       {
           Item<T>* t = first;
           first = toAdd;

           toAdd->setPrev(nullptr);
           toAdd->setNext(t);

           t->setPrev(toAdd);
           return;
       }


       Item<T>* iterator = first;

       while(true)
       {
           if(*iterator < *toAdd)
           {
               if(iterator->getNext() == nullptr)
               {
                   iterator->setNext(toAdd);
                   toAdd->setPrev(iterator);
                   return;

               }
               else
               {
                   iterator = iterator->getNext();
               }
           }
           else
           {
               Item<T>* preiterator = iterator->getPrev();

               preiterator->setNext(toAdd);
               toAdd->setNext(iterator);

               toAdd->setPrev(preiterator);
               iterator->setPrev(toAdd);
               return;
           }
       }
    }

};

#endif // ITEMLIST_H
