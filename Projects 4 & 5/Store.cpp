//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 5
//  April 6, 2016
//

#include "Store.h"
#include "Fastener.h"
#include "Hinge.h"
#include "Hardwood.h"
#include "Softwood.h"
#include "Plastic.h"

Store::Store()
{
    _num = 0;

    for (int i = 0; i < MAX; i++)
        _store[i] = NULL;
}

Store::~Store()
{
    for (unsigned i = 0; i < _num; i++)
        delete _store[i];
}

void Store::Run()
{
    cout << "\n\n\nChoose One of the Following:\n"
         << "1. Enter a new item into inventory\n"
         << "2. Remove an item from inventory\n"
         << "3. Display the inventory\n"
         << "4. Display the totals: gross profits per item type and total gross profits\n"
         << "5. Quit\n\n";

    int option = 0;
    cin >> option;

    switch (option) {
        case 1:
            newItem();
            break;
        case 2:
            removeItem();
            break;
        case 3:
            displayInventory();
            break;
        case 4:
            displayTotals();
            break;
        case 5:
            return;
            break;

        default:
            cout << "\nError -- Invalid Choice.\n";
            Run();
            break;
    }
}

void Store::newItem()
{
    if (_num == MAX) {
        cout << "There are too many items in the inventory. Remove an item before trying to add another." << endl;
        Run();
        return;
    }

    cout << "\nChoose which item to add to inventory:\n"
         << "1. Fastener\n"
         << "2. Hinge\n"
         << "3. Hardwood\n"
         << "4. Softwood\n"
         << "5. Plastic\n\n";

    int option = 0;
    cin >> option;

    switch (option) {
        case 1:
            _store[_num++] = new Fastener(Fastener::Nails, 56);
            cout << "\nYou have added a new Fastener to the inventory." << endl;
            break;
        case 2:
            _store[_num++] = new Hinge(Hinge::Butt, 99);
            cout << "\nYou have added a new Hinge to the inventory." << endl;
            break;
        case 3:
            _store[_num++] = new Hardwood(Hardwood::Maple, 34);
            cout << "\nYou have added a new Hardwood to the inventory." << endl;
            break;
        case 4:
            _store[_num++] = new Softwood(Softwood::Redwood, 12);
            cout << "\nYou have added a new Softwood to the inventory." << endl;
            break;
        case 5:
            _store[_num++] = new Plastic();
            cout << "\nYou have added a new Plastic to the inventory." << endl;
            break;
        default:
            cout << "\nError -- Invalid Choice.\n";
            newItem();
            return;
            break;
    }

    Run();
}

void Store::removeItem()
{
    if (_num == 0) {
        cout << "There are no items in the inventory. Add an item before trying to remove one." << endl;
        Run();
        return;
    }

    delete _store[--_num];
    cout << "You have removed an item from the inventory." << endl;

    Run();
}

void Store::displayInventory()
{
    if (_num == 0) cout << "There are no items in inventory to display." << endl;

    for (unsigned i = 0; i < _num; i++)
    {
        _store[i]->display(cout);
        cout << endl;
    }

    Run();
}

void Store::displayTotals()
{
    if (_num == 0) cout << "There are no items in inventory." << endl;

    float totalProfit = 0;

    for (unsigned i = 0; i < _num; i++)
    {
        totalProfit += _store[i]->gross_profit();
        _store[i]->display(cout);
        cout << "Gross profit for item: $" << _store[i]->gross_profit() << endl << endl;
    }

    cout << "\nTotal gross profit is: $" << totalProfit << endl;

    Run();
}
