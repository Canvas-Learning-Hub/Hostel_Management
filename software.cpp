#include <iostream>
#include <cstring>

using namespace std;

void showMenu();
void selectRoom();
void selectVillage();
void selectFloor();
void selectCleaningService();
void calculateBill();
void changeRoom();
void initializeRooms();

struct Room {
  char type[20];
  char village[2];
  int floor;
  int number;
  bool cleaningService;
  double price;
};

const int MAX_ROOMS = 100;
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
      selectCleaningService();
      break;
    case 5:
      calculateBill();
      break;
    case 6:
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
  cout << "4. Select Cleaning Service\n";
  cout << "5. Calculate Bill\n";
  cout << "6. Change Room\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
}

void selectRoom() {
  cout << "Enter room type (Single/Double/Suite): ";
  char type[20];
  cin >> type;
  cout << "Room type selected: " << type << endl;
}

void selectVillage() {
  cout << "Enter village (A/B/C): ";
  char village[2];
  cin >> village;
  cout << "Village selected: " << village << endl;
}

void selectFloor() {
  cout << "Enter floor number: ";
  int floor;
  cin >> floor;
  cout << "Floor selected: " << floor << endl;
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
  Room room1 = {"Single", "A", 1, 101, true, 300.0};
  Room room2 = {"Double", "A", 1, 102, false, 500.0};
  Room room3 = {"Suite", "B", 2, 201, true, 1000.0};

  rooms[0] = room1;
  rooms[1] = room2;
  rooms[2] = room3;

  roomCount = 3;
}
