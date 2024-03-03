/*
Team: Syntax Samurai
Dalton Weiland, Jakob Clark, Zachary Bluhm
03/2/24
Trash Taste Recipe
*/

#include <unistd.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct ingrediant { // Create class to use for map and store ingrediants. isWet and isDry have zero functionality
    string name;
    string unit;
    int min;
    int max;
    bool isUsed;
    bool isWet;
    bool isDry;
};

void openFile(ifstream &inFile, string filename); // Open file. Exit if not found
void initarr(ifstream &inFile); // Input data into desert[], appetizer[], entree[]
void print_input(int cat); // Depreicated
void initList(string fname, unordered_map<string, ingrediant> &test1, bool isSpecial); // Input data into unordered map
void selectf(int cat); // Select a food from a category and randomly select ingrediants. Grab data from list
void loadSpecial(string addSpecial); // Init special ingrediants

string * desert;
string * appetizer;
string * entree;
string * special;
string * resetL;
int dSize; // Desert Size
int aSize; // Appetizer Size
int eSize; // Entree Size
int sSize; // SpecialSIze
int rSize; // resetL size

unordered_map<string, ingrediant> list;
unordered_map<string, ingrediant> listSpecial;

int main(int argv, char* argc[]) {
    
    if(argv < 1) {
        cerr << "Improper Usage. Expected a 1 for Dessert, 2 for Entree, or 3 for Appetizer\n";
    }
    

    // The worst way to do things
    sleep(2);
    srand (time(NULL));
    desert = new string[100];
    dSize = 0;
    appetizer = new string[100];
    aSize = 0;
    entree = new string[100];
    eSize = 0;
    special = new string[100];
    sSize = 0;
    resetL = new string[20];
    rSize = 0;
    ifstream inFile;
    openFile(inFile, "cat.txt");
    initarr(inFile);
    // Gets Better from here

    initList("ingrediants.txt", list, false); // Init list from txt file
    initList("special.txt", listSpecial, true); // Init list from txt file

    /*
     Allow User to Select Which Category
    cout << "=========Welcome to Trash Taste Recipies=========\n";
    cout << "Enter 1 for Deserts, 2 for Entrees, and 3 for Appetizers. Enter l for exiting: ";
    
    char input;
    cin >> input;

    while(input != 'l') {
        if(input == '1') {
            selectf(1);
        } else if(input == '2') {
            selectf(2);
        } else if(input == '3') {
            selectf(3);
        }
        cout << "Enter your next request please: ";
        cin >> input;
    }
    */
    selectf(stoi(argv[argc - 1])); // Function that does it all and how we generated txt files CLI
   // selectf(3);
    return 0;
}

void openFile(ifstream &inFile, string filename){
    inFile.open(filename);
    if (inFile.is_open()){
        //cout << "Opened File" << endl;
    } else {
        cout << "No Open File Named: " << filename << endl;
        exit(-1);
    }
}

void initarr(ifstream &inFile){
    string input;
    int cat;
    inFile >> input;
    while(!inFile.eof()) {
        if(input == "Dessert") {
          //  printf("Desert found\n");
            cat = 1;
        } else if (input == "Appetizer") {
            cat = 3;
        } else if (input == "Entree") {
            cat = 2;
        } else {
          //  cout <<"Added " << input << " to an arr\n";
            if(cat == 1) {
                desert[dSize] = input;
                dSize++;
            } else if(cat == 2) {
                entree[eSize] = input;
                eSize++;
            } else if(cat == 3) {
                appetizer[aSize] = input;
                aSize++;
            }
        }
        inFile >> input;
    }
}

void print_input(int cat) {
    if(cat == 1) {
        for(int i = 0; i < dSize; i++) {
            cout << desert[i] << endl;
        }
    } else if(cat == 2) {
        for(int i = 0; i < eSize; i++) {
            cout << entree[i] << endl;
        }
    } else if(cat == 3) {
        for(int i = 0; i < aSize; i++) {
            cout << appetizer[i] << endl;
        }
    }
}

void initList(string fname, unordered_map<string, ingrediant> &test1, bool isSpecial) {
    string input;
    string unit;
    int min;
    int max;
    string tag;
    ifstream inFile;

    openFile(inFile, fname);
    inFile >> input;
    while(!inFile.eof()) {
        string foodReal = input;
        ingrediant ingred;
        for(int i = 0; i <input.size(); i++) {
            if(input.at(i) == '_') {
                input.at(i) = ' ';
            }
        }
        ingred.name = input;
        inFile >> min;
        inFile >> max;
        ingred.min = min;
        ingred.max = max;
        ingred.isUsed = false;
        inFile >> unit;
        ingred.unit = unit;
        inFile >> tag;

        while(tag != ";") {
            if (tag == "dry") {
                ingred.isDry = true;
            } else if(tag == "wet") {
                ingred.isWet = true;
            }
            inFile >> tag;
        }
        if(isSpecial) {
            loadSpecial(foodReal);
        }
        test1[foodReal] = ingred;

        inFile >> input;
    }
}

void selectf(int cat) { // 1 Desert, 2 Entree, 3 Appetizer
    int rannum;
    string food;
    string input;
    ifstream foodfile;
    stringstream stream;
    if(cat == 1) {
        rannum = rand() % dSize;
        food = desert[rannum];
    } else if(cat == 2) {
        rannum = rand() % eSize;
        food = entree[rannum];
    } else if (cat == 3) {
        rannum = rand() % aSize;
        food = appetizer[rannum];
        
    }
    // Print food
    string food2 = food;
    // Create stringName to Open
    int iSize = 0;
    string iarr[100];
    if(cat == 1) {
        food = "Cake.txt";
    } else if (cat == 2) {
        food ="Steak.txt";
    }
    if(cat != 3) {
    openFile(foodfile,food);
    }
    // Init ingrediant arr from 'food'.txt
    foodfile >> input;
    while(!foodfile.eof()) {
        iarr[iSize] = input;
        iSize++;
        foodfile >> input;
    }
    // Each Catagory has a min and max on the number of ingrediants it can pull.
    int dMin = 4;
    int dMax = 6;
    int eMin = 3;
    int eMax = 6;
    int aMin = 1;
    int aMax = 3;

    int sMin = 2; // Special ingrediants
    int sMax = 2;

     // Special Ingrediants

    rannum = rand() % sSize;
    string in2 = special[rannum];
    ingrediant ingtest = listSpecial[in2];
    stream << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " " << ingtest.unit <<" of " << ingtest.name;

    string food3 = food2;
    for(int i = 0; i < food3.length(); i++) {
        if(food3.at(i) == '_') {
            food3.at(i) = ' ';
        }
    }
    string in3 = in2;
    for(int i = 0; i < in3.length(); i++) {
        if(in3.at(i) == '_') {
            in3.at(i) = ' ';
        }
    }
    string foodName = in3 + " " + food3;

    cout <<"<h1>" << foodName << " Recipe:</h1>\n";
    // Regular Ingrediants
    int i = (rand() % (dMax - dMin + 1) + dMin);
    int i2 = i / 2;

    // Desert Ouput
    if(cat == 1){
        // Format for Desert
        cout << "<p>Step 1. Add ";
        while(i > i2) {
            rannum = rand() % iSize;
            string in1 = iarr[rannum];
        // cout << in1 << " ";
        // Check to see if it is used
            if(list[in1].isUsed) {
            } else {
                list[in1].isUsed = true;
                ingrediant ingtest = list[in1];
                cout << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " " << ingtest.unit << " of " << ingtest.name <<", ";
                // Add item to used array to reset later
                resetL[rSize] = in1;
                rSize++;
                i--;
            }
        }
        // Desert Format Cont.
        cout << "to a large bowl or the bowl of a stand mixer. Whisk through to combine or, using your paddle attachment, stir through flour mixture until combined well.\n";
        cout << "</p>\n<p>2. Add ";
        while(i2 > 0) {
            rannum = rand() % iSize;
            string in1 = iarr[rannum];
        // cout << in1 << " ";
        // Check to see if it is used
            if(list[in1].isUsed) {
            } else {
                list[in1].isUsed = true;
                ingrediant ingtest = list[in1];
                cout << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " " << ingtest.unit << " of " << ingtest.name << ", ";
                // Add item to used array to reset later
                resetL[rSize] = in1;
                rSize++;
                i2--;
            }
        }
        cout << stream.str();
        cout << " mixture and mix together on medium speed until well combined. Reduce speed and carefully add boiling water to the " << foodName <<" batter until well combined.\n";
        stream.clear();
        cout << "</p>\n<p>3. Distribute " << foodName << " batter evenly between the two prepared " << foodName << " pans. Bake for " << (rand()% 30) + 25 <<  " minutes.\n";
        cout << "</p>\n<p>4. Remove from the oven and allow to cool for about " << (rand()% 10) + 5 << " minutes, remove from the pan and cool completely.</p>\n";
    }
    // Entree Output
    if(cat == 2) {
        cout << "\n<p>1. Prepare: ";
        stringstream foodlist;
        int i = (rand() % (dMax - dMin + 1) + dMin);
        while(i > 0) {
            rannum = rand() % iSize;
            string in1 = iarr[rannum];
            // cout << in1 << " ";
            // Check to see if it is used
            if(list[in1].isUsed) {
            } else {
                list[in1].isUsed = true;
                ingrediant ingtest = list[in1];
                cout << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " " << ingtest.unit << " of " << ingtest.name <<", ";
                // Add item to used array to reset later
                foodlist << ingtest.name << ", ";
                resetL[rSize] = in1;
                rSize++;
                i--;
                }
            }
            cout << stream.str();
            cout << " ahead of time.</p>\n";
            cout <<"\n<p>2. Add " << foodlist.str() << in3 << " and let sit for " << rand() % 20 << " minutes to flavor.</p>" << endl;
            cout << "\n<p>3. Toss oil and heat pan to high heat.</p>\n";
            cout << "\n<p>4. Sear " << foodlist.str() << " and " << in3 << " in pan for " << rand() % 14 << " minutes until cooked appropriatley.</p>\n";
            cout << "\n<p>5. Season the prepared meal and plate, allow " << rand() % 50 << " minutes to cool before serving.</p>\n";
    }
    // Appetizer Output
    if (cat == 3) {
        cout << "\n<p>1. Gather and Prepare: ";
        
        cout << stream.str();
        cout << " to get started making "<< foodName <<".</p>\n";
        cout <<"\n<p>2. Make sure to mix in " << in3 << " with the " << foodName << " and cover in " << rand() % 8 + 2 << " cups of batter or flour.</p>\n";
        cout << "\n<p>3. Heat up a pot of " << rand() % 12 + 2 << " ml of oil to " << rand() % 150 + 75 << ", once heated take battered appetizer and drop in oil for " << rand() % 30 + 5 << " minutes unil cooked.</p>\n";
        cout << "\n<p>4. After the " <<  foodName << " has been cooked in oil pull out, dry off, season up, and allow to cool for " << rand() % 20 + 3 << " minutes before serving.</p>\n";    
      }
    



    // Generic Output
    cout <<"\n<h3>Enjoy your fresh " << foodName << "!(Serves " << rand() % 9 + 4 << " people)</h3>\n\n";

    // Reset L
    for(int i = 0; i < rSize; i++) {
        list[resetL[i]].isUsed = false;
    }
    rSize = 0;
}

void loadSpecial(string addSpecial) {
    special[sSize] = addSpecial;
    sSize++;
    return;
}