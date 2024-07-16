#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// Function prototypes
void showInitialMenu();
void changeRoom();
void selectCleaningService();
void calculateBill();
void initializeRooms();
void promptRoomDetails(char *type, char *village, char *block, int &floor,
                       int &unit, int &room);
void saveRoomDetailsToFile(const char *filename);
void loadRoomDetailsFromFile(const char *filename);

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
  initializeRooms();

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

void promptRoomDetails(char *type, char *village, char *block, int &floor,
                       int &unit, int &room) {
  cout << "Enter room type (Shared/Single): ";
  cin >> type;
  cout << "Enter village (V1/V2/V3/V4/V5/V6): ";
  cin >> village;
  cout << "Enter block (e.g., V1a, V1b): ";
  cin >> block;
  cout << "Enter floor number: ";
  cin >> floor;
  cout << "Enter unit number: ";
  cin >> unit;
  cout << "Enter room number: ";
  cin >> room;
}

void changeRoom() {
  char type[10];
  char village[3];
  char block[4];
  int floor;
  int unit;
  int room;

  promptRoomDetails(type, village, block, floor, unit, room);
  cout << "Room change logic here\n";
  cout << "Changed to room: " << type << " in " << village << " " << block
       << " on floor " << floor << ", unit " << unit << ", room " << room
       << endl;
}

void selectCleaningService() {
  char type[10];
  char village[3];
  char block[4];
  int floor;
  int unit;
  int room;

  promptRoomDetails(type, village, block, floor, unit, room);
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
  const double priceRegular = 900.0;
  const double priceAirCond = 1100.0;

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
            room.airCond =
                (strcmp(village, "V4") == 0 || strcmp(village, "V5") == 0) &&
                f == 1;
            room.cleaningService = true;
            room.price = room.airCond ? priceAirCond : priceRegular;

            rooms[roomCount++] = room;

            cout << "Initialized room: "
                 << "Type: " << room.type << ", Village: " << room.village
                 << ", Block: " << room.block << ", Floor: " << room.floor
                 << ", Unit: " << room.unit << ", Room: " << room.room
                 << ", AirCond: " << (room.airCond ? "Yes" : "No")
                 << ", Price: RM " << room.price << endl;
          }
        }
      }
    }
  }
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
