#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// Function prototypes
void showInitialMenu();
void changeRoom();
void selectCleaningService();
void calculateBill();
void promptRoomDetails(char *type, char *village, char *block, int &floor,
                       int &unit, int &room);
void saveRoomDetailsToFile(const char *filename);
void loadRoomDetailsFromFile(const char *filename);
void initializeRooms(); // Add this function prototype
bool isValidVillage(const char *village);
bool isValidBlock(const char *village, const char *block);
bool isAirConditioned(const char *village, const char *block, int floor);
bool isValidFloor(int floor);
bool isValidUnit(int unit);
bool isValidRoom(int room);

// Define the Room structure
struct Room {
  char type[10];
  char village[3];
  char block[4];
  int floor;
  int unit;
  int room;
  bool airCond;
  bool cleaningService;
  double price;
};

// Constants
const int MAX_ROOMS = 1000;

// Global variables
Room rooms[MAX_ROOMS];
int roomCount = 0;
double totalBill = 0;

int main() {
  initializeRooms(); // Initialize rooms to ensure there are rooms to save
  bool exit = false;
  while (!exit) {
    showInitialMenu();
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
      changeRoom();
      break;
    case 2:
      selectCleaningService();
      break;
    case 3:
      calculateBill();
      break;
    case 4:
      saveRoomDetailsToFile("rooms.txt");
      break;
    case 5:
      loadRoomDetailsFromFile("rooms.txt");
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

void showInitialMenu() {
  cout << "\nHostel Management System\n";
  cout << "1. Change Room\n";
  cout << "2. Cleaning Service\n";
  cout << "3. Calculate Bill\n";
  cout << "4. Save Room Details to File\n";
  cout << "5. Load Room Details from File\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
}

bool isValidVillage(const char *village) {
  const char *validVillages[] = {"V1", "V2", "V3", "V4", "V5", "V6"};
  for (int i = 0; i < 6; ++i) {
    if (strcmp(village, validVillages[i]) == 0) {
      return true;
    }
  }
  return false;
}

bool isValidBlock(const char *village, const char *block) {
  const char *blocksV1[] = {"V1a", "V1b", "V1c", "V1d"};
  const char *blocksV2[] = {"V2a", "V2b", "V2c", "V2d"};
  const char *blocksV3[] = {"V3a", "V3b", "V3c", "V3d"};
  const char *blocksV4[] = {"V4a", "V4b", "V4c", "V4d", "V4e"};
  const char *blocksV5[] = {"V5a", "V5b", "V5c", "V5d", "V5e", "V5f",
                            "V5g", "V5h", "V5i", "V5j", "V5k"};
  const char *blocksV6[] = {"V6a", "V6b", "V6c", "V6d"};

  const char **blocks;
  int numBlocks;

  if (strcmp(village, "V1") == 0) {
    blocks = blocksV1;
    numBlocks = 4;
  } else if (strcmp(village, "V2") == 0) {
    blocks = blocksV2;
    numBlocks = 4;
  } else if (strcmp(village, "V3") == 0) {
    blocks = blocksV3;
    numBlocks = 4;
  } else if (strcmp(village, "V4") == 0) {
    blocks = blocksV4;
    numBlocks = 5;
  } else if (strcmp(village, "V5") == 0) {
    blocks = blocksV5;
    numBlocks = 11;
  } else if (strcmp(village, "V6") == 0) {
    blocks = blocksV6;
    numBlocks = 4;
  } else {
    return false;
  }

  for (int i = 0; i < numBlocks; ++i) {
    if (strcmp(block, blocks[i]) == 0) {
      return true;
    }
  }
  return false;
}

bool isAirConditioned(const char *village, const char *block, int floor) {
  return (strcmp(village, "V4") == 0 && strcmp(block, "V4c") == 0 &&
          floor == 1) ||
         (strcmp(village, "V5") == 0 && floor == 1);
}

bool isValidFloor(int floor) { return floor >= 0 && floor <= 3; }

bool isValidUnit(int unit) { return unit >= 1 && unit <= 4; }

bool isValidRoom(int room) { return room >= 1 && room <= 6; }

void promptRoomDetails(char *type, char *village, char *block, int &floor,
                       int &unit, int &room) {
  cout << "Enter room type (Shared/Single): ";
  cin >> type;
  do {
    cout << "Enter village (V1/V2/V3/V4/V5/V6): ";
    cin >> village;
    if (!isValidVillage(village)) {
      cout << "Invalid village. Please try again.\n";
    }
  } while (!isValidVillage(village));

  do {
    cout << "Enter block (e.g., V1a, V1b): ";
    cin >> block;
    if (!isValidBlock(village, block)) {
      cout << "Invalid block. Please try again.\n";
    }
  } while (!isValidBlock(village, block));

  do {
    cout << "Enter floor number (0-3): ";
    cin >> floor;
    if (!isValidFloor(floor)) {
      cout << "Invalid floor. Please try again.\n";
    }
  } while (!isValidFloor(floor));

  do {
    cout << "Enter unit number (1-4): ";
    cin >> unit;
    if (!isValidUnit(unit)) {
      cout << "Invalid unit. Please try again.\n";
    }
  } while (!isValidUnit(unit));

  do {
    cout << "Enter room number (1-6): ";
    cin >> room;
    if (!isValidRoom(room)) {
      cout << "Invalid room. Please try again.\n";
    }
  } while (!isValidRoom(room));
}

void changeRoom() {
  char currentType[10];
  char currentVillage[3];
  char currentBlock[4];
  int currentFloor;
  int currentUnit;
  int currentRoom;

  cout << "Enter current room details:\n";
  promptRoomDetails(currentType, currentVillage, currentBlock, currentFloor,
                    currentUnit, currentRoom);

  char newType[10];
  char newVillage[3];
  char newBlock[4];
  int newFloor;
  int newUnit;
  int newRoom;

  cout << "Enter new room details:\n";
  promptRoomDetails(newType, newVillage, newBlock, newFloor, newUnit, newRoom);

  cout << "Room change logic here\n";
  cout << "Changed from room: " << currentType << " in " << currentVillage
       << " " << currentBlock << " on floor " << currentFloor << ", unit "
       << currentUnit << ", room " << currentRoom << endl;
  cout << "Changed to room: " << newType << " in " << newVillage << " "
       << newBlock << " on floor " << newFloor << ", unit " << newUnit
       << ", room " << newRoom << endl;
}

void selectCleaningService() {
  char type[10];
  char village[3];
  char block[4];
  int floor;
  int unit;
  int room;

  cout << "Enter current room details:\n";
  promptRoomDetails(type, village, block, floor, unit, room);

  cout << "Do you want cleaning service? (1 for Yes, 0 for No): ";
  int cleaning;
  cin >> cleaning;
  bool cleaningService = (cleaning == 1);

  cout << "Cleaning service: " << (cleaningService ? "Yes" : "No") << endl;
}

void calculateBill() {
  const double SINGLE_ROOM_PRICE = 1100;
  const double SHARED_ROOM_PRICE = 998;
  const double AIRCON_ROOM_PRICE = 1350;
  const int SEMESTER_MONTHS = 4;

  char type[10];
  int airCond;

  cout << "Enter room type (Shared/Single): ";
  cin >> type;
  cout << "Does the room have air conditioning? (1 for Yes, 0 for No): ";
  cin >> airCond;

  double roomPrice = 0;

  if (strcmp(type, "Single") == 0) {
    roomPrice = SINGLE_ROOM_PRICE;
  } else if (strcmp(type, "Shared") == 0) {
    roomPrice = SHARED_ROOM_PRICE;
  }

  if (airCond == 1) {
    roomPrice = AIRCON_ROOM_PRICE;
  }

  totalBill = roomPrice * SEMESTER_MONTHS;

  cout << "Total bill for the semester: RM " << totalBill << endl;
}

void saveRoomDetailsToFile(const char *filename) {
  ofstream outFile(filename);
  if (outFile.is_open()) {
    outFile << roomCount << endl;
    for (int i = 0; i < roomCount; ++i) {
      outFile << rooms[i].type << " " << rooms[i].village << " "
              << rooms[i].block << " " << rooms[i].floor << " " << rooms[i].unit
              << " " << rooms[i].room << " " << rooms[i].airCond << " "
              << rooms[i].cleaningService << " " << rooms[i].price << endl;
    }
    outFile.close();
    cout << "Room details saved to " << filename << endl;
  } else {
    cout << "Unable to open file for writing." << endl;
  }
}

void loadRoomDetailsFromFile(const char *filename) {
  ifstream inFile(filename);
  if (inFile.is_open()) {
    inFile >> roomCount;
    for (int i = 0; i < roomCount; ++i) {
      inFile >> rooms[i].type >> rooms[i].village >> rooms[i].block >>
          rooms[i].floor >> rooms[i].unit >> rooms[i].room >>
          rooms[i].airCond >> rooms[i].cleaningService >> rooms[i].price;
    }
    inFile.close();
    cout << "Room details loaded from " << filename << endl;
  } else {
    cout << "Unable to open file for reading." << endl;
  }
}

// Function to initialize all rooms
void initializeRooms() {
  const char *villages[] = {"V1", "V2", "V3", "V4", "V5", "V6"};
  const char *blocksV1[] = {"V1a", "V1b", "V1c", "V1d"};
  const char *blocksV2[] = {"V2a", "V2b", "V2c", "V2d"};
  const char *blocksV3[] = {"V3a", "V3b", "V3c", "V3d"};
  const char *blocksV4[] = {"V4a", "V4b", "V4c", "V4d", "V4e"};
  const char *blocksV5[] = {"V5a", "V5b", "V5c", "V5d", "V5e", "V5f",
                            "V5g", "V5h", "V5i", "V5j", "V5k"};
  const char *blocksV6[] = {"V6a", "V6b", "V6c", "V6d"};

  const int numRoomsPerUnit = 6;
  const double priceSingle = 1100.0;
  const double priceShared = 998.0;
  const double priceAirCond = 1350.0;

  roomCount = 0;

  for (int v = 0; v < 6; ++v) {
    const char *village = villages[v];
    const char **blocks = (v == 0)   ? blocksV1
                          : (v == 1) ? blocksV2
                          : (v == 2) ? blocksV3
                          : (v == 3) ? blocksV4
                          : (v == 4) ? blocksV5
                                     : blocksV6;
    int numBlocks = (v == 0 || v == 1 || v == 2 || v == 5) ? 4
                    : (v == 3)                             ? 5
                                                           : 11;
    int numFloors = (v == 5) ? 2 : 3;

    for (int b = 0; b < numBlocks; ++b) {
      const char *block = blocks[b];
      for (int f = 0; f <= numFloors; ++f) {
        for (int u = 1; u <= 4; ++u) {
          for (int r = 1; r <= numRoomsPerUnit; ++r) {
            if (roomCount >= MAX_ROOMS) {
              cout << "Exceeded max room count. Current count: " << roomCount
                   << endl;
              return;
            }
            Room room;
            strcpy(room.type, (r % 2 == 0) ? "Single" : "Shared");
            strcpy(room.village, village);
            strcpy(room.block, block);
            room.floor = f;
            room.unit = u;
            room.room = r;
            room.airCond = isAirConditioned(village, block, f);
            room.cleaningService = true;
            room.price = room.airCond ? priceAirCond
                                      : ((strcmp(room.type, "Single") == 0)
                                             ? priceSingle
                                             : priceShared);

            rooms[roomCount++] = room;
          }
        }
      }
    }
  }
}
