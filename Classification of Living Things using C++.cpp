#include <iostream>
#include <string>
using namespace std;

struct LivingThings {
    string name;
   string category;
};

struct Vertebrate {
    string name;
    string category;
};

struct Invertebrate {
    string name;
   string category;
};

LivingThings livingThings[10]; 
Vertebrate vertebrates[6]; 
Invertebrate invertebrates[2]; 

int livingThingsCount = 1;
int vertebratesCount = 0;
int invertebratesCount = 0;

void addVertebrate(Vertebrate vertebrates[], string name) {
    vertebrates[vertebratesCount].name = name;
    vertebrates[vertebratesCount].category = "Vertebrate";
    vertebratesCount++;
}

void addInvertebrate(Invertebrate invertebrates[], string name) {
    invertebrates[invertebratesCount].name = name;
    invertebrates[invertebratesCount].category = "Invertebrate";
    invertebratesCount++;
}

void displayAll(LivingThings livingThings[], Vertebrate vertebrates[], Invertebrate invertebrates[]) {
    bool anyEmpty = false;

    cout << "LivingThings:\n";
    if (livingThingsCount == 0) {
        cout << "No living things found.\n";
        anyEmpty = true;
    } else {
        for (int i = 0; i < livingThingsCount; i++) {
            cout << livingThings[i].category << " -> " << livingThings[i].name << "\n";
        }
    }

    cout << "\nVertebrates:\n";
    if (vertebratesCount == 0) {
        cout << "No vertebrates found.\n";
        anyEmpty = true;
    } else {
        for (int i = 0; i < vertebratesCount; i++) {
            cout << vertebrates[i].category << " -> " << vertebrates[i].name << "\n";
        }
    }

    cout << "\nInvertebrates:\n";
    if (invertebratesCount == 0) {
        cout << "No invertebrates found.\n";
        anyEmpty = true;
    } else {
        for (int i = 0; i < invertebratesCount; i++) {
            cout << invertebrates[i].category << " -> " << invertebrates[i].name << "\n";
        }
    }

    if (anyEmpty) {
        cout << "\nOne or more categories is empty.\n";
    }
}


void displayVertebrates(Vertebrate vertebrates[]) {
    cout << "\nVertebrates:\n";
    if (vertebratesCount == 0) {
        cout << "No vertebrates found.\n";
    } else {
        for (int i = 0; i < vertebratesCount; i++) {
            cout << vertebrates[i].category << " -> " << vertebrates[i].name << "\n";
        }
    }
}


void displayInvertebrates(Invertebrate invertebrates[]) {
    cout << "\nInvertebrates:\n";
    if (invertebratesCount == 0) {
        cout << "No invertebrates found.\n";
    } else {
        for (int i = 0; i < invertebratesCount; i++) {
            cout << invertebrates[i].category << " -> " << invertebrates[i].name << "\n";
        }
    }
}

void deleteClass(Vertebrate vertebrates[], Invertebrate invertebrates[]) {
    int categoryChoice;
    cout << "Choose category to delete from:\n";
    cout << "1. Vertebrates\n";
    cout << "2. Invertebrates\n";
    cin >> categoryChoice;

    if (categoryChoice == 1) {
        string name;
        cout << "Enter the name of the Vertebrate class to delete: ";
        cin >> name;

        bool found = false;
        for (int i = 0; i < vertebratesCount; i++) {
            if (vertebrates[i].name == name) {
                // Shift elements to fill the gap
                for (int j = i; j < vertebratesCount - 1; j++) {
                    vertebrates[j] = vertebrates[j + 1];
                }
                vertebratesCount--;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Class not found.\n";
        }
    } else if (categoryChoice == 2) {
        string name;
        cout << "Enter the name of the Invertebrate class to delete: ";
        cin >> name;

        bool found = false;
        for (int i = 0; i < invertebratesCount; i++) {
            if (invertebrates[i].name == name) {
                // Shift elements to fill the gap
                for (int j = i; j < invertebratesCount - 1; j++) {
                    invertebrates[j] = invertebrates[j + 1];
                }
                invertebratesCount--;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Class not found.\n";
        }
    } else {
        cout << "Invalid category choice.\n";
    }
}

void Search() {
    string className;
    cout << "Enter the name of the class to search for: ";
    cin >> className;

    bool found = false;

    for (int i = 0; i < vertebratesCount; i++) {
        if (vertebrates[i].name == className) {
            cout << livingThings[i].name  << " -> "<< vertebrates[i].category << " -> " << vertebrates[i].name << "\n";
            
            className = vertebrates[i].category;
            found = true;
            break;
        }
    }

    if (!found) {
        for (int i = 0; i < invertebratesCount; i++) {
            if (invertebrates[i].name == className) {
                cout << livingThings[i].name  << " -> "<< invertebrates[i].category << " -> " << invertebrates[i].name << "\n";

				className = invertebrates[i].category;
                found = true;
                break;
            }
        }
    }

    // Search in LivingThings if not found in Vertebrates or Invertebrates
    if (!found && livingThings[0].name == className) {
        cout << livingThings[0].category << " -> " << livingThings[0].name << "\n";
    }
}

void clear() {
    livingThingsCount = 0;
    vertebratesCount = 0;
    invertebratesCount = 0;
    cout << "Lists cleared.\n";
}


int main() {
    
    livingThings[0].name = "LivingThings";
    livingThings[0].category = "Root";

    int choice;
    
   do {
   	cout << "\n-----------------------------\n";
    cout << "1. add a new class\n";
    cout<< "2. display all classes\n";
    cout<< "3. display Vertebrates\n";
    cout<< "4. display Invertebrates\n";
    cout<< "5. delete Vertebrates or Invertebrates\n";
    cout<< "6. Search for a particular class and show its complete hierarchy till LivingThings\n";
    cout<< "7. Clear List\n";
    cout<< "8. Exit\n";
 	cout << "\n-----------------------------\n";

        cin >> choice;
        switch (choice) {
        case 1:
            {
                int cat;
                cout << "\n-----------------------------\n";
                cout << "1. add a Vertebrate\n";
                cout << "2. add an Invertebrate";
 				cout << "\n-----------------------------\n";
                cin >> cat;
                string name;
                cout << "Enter the name of the class: ";
                cin >> name;
                if (cat == 1) {
                    addVertebrate(vertebrates, name);
                } else if (cat == 2) {
                    addInvertebrate(invertebrates, name);
                }
                break;
            }
        case 2:
            displayAll(livingThings, vertebrates, invertebrates);
            break;
        case 3:
            displayVertebrates( vertebrates);
            break;
            case 4:
            displayInvertebrates( invertebrates);
            break;
        case 5:
			deleteClass(vertebrates, invertebrates);
        	break;
        case 6:
       cout << "Displaying hierarchy:\n";

             Search();
            break;
            case 7:
            clear();
             break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
      
    } while (choice != 8);
    return 0;
}
