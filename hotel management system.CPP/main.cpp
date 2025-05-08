#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

// Structure to store room details
struct Room {
    string floor;
    int number;
    bool occupied;
    vector<pair<string, string>> mealsOrdered; // Meal and time
    bool orderComplete;
};

// Hotel Management System
class Hotel {
    int totalRooms;
    vector<Room> rooms;
    map<int, string> mealMenu = {{1, "Chicken"}, {2, "Water"}, {3, "Peanuts"}};

public:
    Hotel(int numRooms) {
        totalRooms = numRooms;
        char floorLetter = 'A';

        for (int i = 0; i < totalRooms; ++i) {
            Room r;
            r.floor = string(1, floorLetter + (i / 10)); // Change floor every 10 rooms
            r.number = i + 1;
            r.occupied = false;
            r.orderComplete = false;
            rooms.push_back(r);
        }
    }

    void bookRoom(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= totalRooms) {
            if (!rooms[roomNumber - 1].occupied) {
                rooms[roomNumber - 1].occupied = true;
                cout << "Room " << roomNumber << " booked successfully.\n";
            } else {
                cout << "Room already occupied.\n";
            }
        } else {
            cout << "Invalid room number.\n";
        }
    }

    void orderMeal(int roomNumber, int mealChoice) {
        if (roomNumber > 0 && roomNumber <= totalRooms) {
            if (rooms[roomNumber - 1].occupied) {
                time_t now = time(0);
                string timeStr = ctime(&now);
                timeStr.pop_back(); // Remove trailing newline

                rooms[roomNumber - 1].mealsOrdered.push_back(make_pair(mealMenu[mealChoice], timeStr));
                cout << "Meal ordered: " << mealMenu[mealChoice] << " for Room " << roomNumber << " at " << timeStr << "\n";
            } else {
                cout << "Room is not occupied. Cannot order meal.\n";
            }
        } else {
            cout << "Invalid room number.\n";
        }
    }

    void completeOrder(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= totalRooms) {
            if (rooms[roomNumber - 1].occupied && !rooms[roomNumber - 1].mealsOrdered.empty()) {
                rooms[roomNumber - 1].orderComplete = true;
                cout << "Order for Room " << roomNumber << " has been marked as complete.\n";
            } else {
                cout << "No meals ordered or room not occupied.\n";
            }
        } else {
            cout << "Invalid room number.\n";
        }
    }

    void showOrders() {
        cout << "\nMeal Orders Summary:\n";
        for (const auto &room : rooms) {
            if (!room.mealsOrdered.empty()) {
                cout << "Room " << room.number << " (" << room.floor << "): ";
                for (const auto &meal : room.mealsOrdered) {
                    cout << meal.first << " ";
                }
                cout << (room.orderComplete ? " - Order Complete" : " - Order Pending") << "\n";
            }
        }
    }

    void showVacantRooms() {
        int vacant = 0;
        for (const auto &room : rooms) {
            if (!room.occupied) {
                vacant++;
            }
        }
        cout << "Vacant Rooms: " << vacant << "\n";
    }

    void showDetailedOrders() {
        cout << "\nDetailed Order History:\n";
        for (const auto &room : rooms) {
            if (!room.mealsOrdered.empty()) {
                cout << "Room " << room.number << " (" << room.floor << ")\n";
                for (const auto &meal : room.mealsOrdered) {
                    cout << "  - Meal: " << meal.first << " | Time: " << meal.second << "\n";
                }
                cout << (room.orderComplete ? "  - Order Status: Complete\n" : "  - Order Status: Pending\n");
            }
        }
    }
};

int main() {
    int numRooms;
    cout << "Enter total number of rooms in the hotel: ";
    cin >> numRooms;

    Hotel myHotel(numRooms);

    int choice, roomNumber, mealChoice;
    do {
        cout << "\n1. Book Room\n2. Order Meal\n3. Complete Order\n4. Show Orders\n5. Show Vacant Rooms\n6. Exit\n7. Show Detailed Orders\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                myHotel.bookRoom(roomNumber);
                break;
            case 2:
                cout << "Enter room number to order meal: ";
                cin >> roomNumber;
                cout << "Select meal (1: Chicken, 2: Water, 3: Peanuts): ";
                cin >> mealChoice;
                myHotel.orderMeal(roomNumber, mealChoice);
                break;
            case 3:
                cout << "Enter room number to mark order as complete: ";
                cin >> roomNumber;
                myHotel.completeOrder(roomNumber);
                break;
            case 4:
                myHotel.showOrders();
                break;
            case 5:
                myHotel.showVacantRooms();
                break;
            case 7:
                myHotel.showDetailedOrders();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
