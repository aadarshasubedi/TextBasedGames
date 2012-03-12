#include <iostream>
#include <string>

using namespace std;

void Initialize (const string* container[], int capacity);
bool IsFull (const string* const container[], int capacity);
bool IsEmpty (const string* const container[], int capacity);
bool Contains (const string* const pItem, const string* container[], int capacity);
void DisplayItems (const string* const items[], int capacity);
void DisplayItems (const string items[], int capacity);
void Add (const string* const pItem, const string* container[], int capacity);
void Remove (const string* const pItem, const string* container[], int capacity);

int main () {
    cout << "\tWelcome to Inventory!" << endl;

    const int numOfItems = 5;
    const string items[numOfItems] = { "sword", "axe", "shield", "gold", "potion" };
    const string* const pItems = items;

    const int inventoryCapacity = 3;
    const string* inventory[inventoryCapacity];
    Initialize(inventory, inventoryCapacity);

    int choice;
    int itemNumber;

    do {
        cout << endl << "Inventory" << endl;
        cout << "--------------" << endl << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Display items in your inventory" << endl;
        cout << "2 - Add an item to your inventory" << endl;
        cout << "3 - Remove an item from your inventory" << endl;
        cout << endl << "Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 0:
                cout << "Good-bye" << endl;
                return 0;
            case 1:
                cout << "Inventory:" << endl;
                DisplayItems(inventory, inventoryCapacity);
                break;
            case 2:
                DisplayItems(pItems, numOfItems);

                do {
                    cout << "Enter the number of the item to add: ";
                    cin >> itemNumber;
                } while (itemNumber < 0 || itemNumber >= numOfItems);

                Add(&items[itemNumber], inventory, inventoryCapacity);
                break;
            case 3:
                DisplayItems(items, numOfItems);

                do {
                    cout << "Enter the number of the item to remove: ";
                    cin >> itemNumber;
                } while (itemNumber < 0 || itemNumber >= numOfItems);

                Remove(&items[itemNumber], inventory, inventoryCapacity);
                break;
            default:
                cout << "Sorry, " << choice << "isn't a valid choice." << endl;
                break;
        }

    } while (true);

    return 0;
}

void Initialize (const string* container[], int capacity) {
    for (int i = 0; i < capacity; ++i)
        container[i] = NULL;
}

bool IsFull (const string* const container[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (container[i] == NULL)
            return false;
    }

    return true;
}

bool IsEmpty (const string* const container[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (container[i] != NULL)
            return false;
    }

    return true;
}

bool Contains (const string* const pItem, const string* container[], int capacity) {
    bool has = false;
    int i = 0;

    while (!has && i < capacity) {
        if (container[i] == pItem)
            has = true;

        i++;
    }

    return has;
}

void DisplayItems (const string* const items[], int capacity) {
    if (IsEmpty(items, capacity)) {
        cout << "<Empty>" << endl;
        return;
    }

    for (int i = 0; i < capacity; i++) {
        if (items[i])
            cout << i << " - " << *(items[i]) << endl;
    }
}

void DisplayItems (const string items[], int capacity) {
    if (IsEmpty(&items, capacity)) {
        cout << "<Empty>" << endl;
        return;
    }

    for (int i = 0; i < capacity; i++) {
        cout << i << " - " << items[i] << endl;
    }
}

void Add (const string* const pItem, const string* container[], int capacity) {
    if (pItem == NULL)
        return;

    if (Contains(pItem, container, capacity)) {
        cout << "Item already exists.  Can't add." << endl;
        return;
    }

    if (IsFull(container, capacity)) {
        cout << "Container full.  Can't add." << endl;
        return;
    }

    bool found = false;
    int i = 0;

    while (!found && i < capacity) {
        if (container[i] == NULL) {
            container[i] = pItem;
            found = true;
        }

        i++;
    }
}

void Remove (const string* const pItem, const string* container[], int capacity) {
    if (pItem == NULL)
        return;

    bool found = false;
    int i = 0;

    while (!found && i < capacity) {
        if (container[i] == pItem) {
            container[i] = NULL;
            found = true;
        }

        i++;
    }
}