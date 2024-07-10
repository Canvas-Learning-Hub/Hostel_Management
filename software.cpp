#include <iostream>
#include <cstring>

using namespace std;

// Function prototypes
void showMenu();
void selectRoom();
void selectVillage();
void selectFloor();
void selectBlock();
void selectCleaningService();
void calculateBill();
void changeRoom();
void initializeRooms();

// Define the Room structure
struct Room {
    char type[10];
    char village[3];
    char block[3];
    int floor;
    int unit;
    int room;
    bool airCond;
    bool cleaningService;
    double price;
};

// Constants
const int MAX_ROOMS = 100;

// Global variables
Room rooms[MAX_ROOMS];
int roomCount = 0;
double totalBill = 0;

int main() {
    initializeRooms();

    bool exit = false;
    while (!exit) {
        showMenu();
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            selectRoom();
            break;
        case 2:
            selectVillage();
            break;
        case 3:
            selectFloor();
            break;
        case 4:
            selectBlock();
            break;
        case 5:
            selectCleaningService();
            break;
        case 6:
            calculateBill();
            break;
        case 7:
            changeRoom();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

void showMenu() {
    cout << "\nHostel Management System\n";
    cout << "1. Select Room\n";
    cout << "2. Select Village\n";
    cout << "3. Select Floor\n";
    cout << "4. Select Block\n";
    cout << "5. Select Cleaning Service\n";
    cout << "6. Calculate Bill\n";
    cout << "7. Change Room\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void selectRoom() {
    cout << "Enter room type (Shared/Single): ";
    char type[10];
    cin >> type;
    cout << "Room type selected: " << type << endl;
}

void selectVillage() {
    cout << "Enter village (V1/V2/V3/V4/V5/V6): ";
    char village[3];
    cin >> village;
    cout << "Village selected: " << village << endl;
}

void selectFloor() {
    cout << "Enter floor number: ";
    int floor;
    cin >> floor;
    cout << "Floor selected: " << floor << endl;
}

void selectBlock() {
    cout << "Enter block (e.g., V1a, V1b, etc.): ";
    char block[3];
    cin >> block;
    cout << "Block selected: " << block << endl;
}

void selectCleaningService() {
    cout << "Do you want cleaning service? (1 for Yes, 0 for No): ";
    int cleaning;
    cin >> cleaning;
    bool cleaningService = (cleaning == 1);
    cout << "Cleaning service: " << (cleaningService ? "Yes" : "No") << endl;
}

void calculateBill() {
    totalBill = 0;
    for (int i = 0; i < roomCount; ++i) {
        totalBill += rooms[i].price;
    }
    cout << "Total bill: RM " << totalBill << endl;
}

void changeRoom() {
    cout << "Room change logic here\n";
}

void initializeRooms() {
    // Initialize rooms based on given structure
    // Adding some sample rooms for demonstration
    Room room1 = {"Shared", "V1", "V1a", 1, 1, 1, false, true, 900.0};
    Room room2 = {"Single", "V4", "V4a", 1, 1, 1, true, true, 1100.0};
    Room room3 = {"Shared", "V5", "V5a", 1, 1, 1, true, true, 1100.0};
    Room room4 = {"Single", "V2", "V2a", 2, 1, 1, false, true, 900.0};

    rooms[0] = room1;
    rooms[1] = room2;
    rooms[2] = room3;
    rooms[3] = room4;

    roomCount = 4;
}
