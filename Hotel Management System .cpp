#include <iostream>
#include <string>
using namespace std;

const int MAX_ROOMS = 5;

struct Room {
    int isBooked; 
    string guestName;
};

void showMenu();
void bookRoom(Room rooms[], int size);
void checkOutRoom(Room rooms[], int size);
void displayRooms(const Room rooms[], int size);
void searchRoom(const Room rooms[], int size);

int main() {
    Room rooms[MAX_ROOMS] = {};
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                bookRoom(rooms, MAX_ROOMS);
                break;
            case 2:
                checkOutRoom(rooms, MAX_ROOMS);
                break;
            case 3:
                displayRooms(rooms, MAX_ROOMS);
                break;
            case 4:
                searchRoom(rooms, MAX_ROOMS);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

void showMenu() {
    cout << "\nHotel Management System" << endl;
    cout << "1. Book a Room" << endl;
    cout << "2. Check Out Room" << endl;
    cout << "3. Display Room Status" << endl;
    cout << "4. Search Room by Guest Name" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void bookRoom(Room rooms[], int size) {
    int roomNumber;
    cout << "Enter room number to book (1-" << size << "): ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > size) {
        cout << "Invalid room number." << endl;
    } else if (rooms[roomNumber - 1].isBooked) {
        cout << "Room " << roomNumber << " is already booked." << endl;
    } else {
        cout << "Enter guest name: ";
        cin.ignore();  
        getline(cin, rooms[roomNumber - 1].guestName);
        rooms[roomNumber - 1].isBooked = 1;
          cout << "Room " << roomNumber << " has been booked for " << rooms[roomNumber - 1].guestName << "." << endl;
    }
}

void checkOutRoom(Room rooms[], int size) {
    int roomNumber;
    cout << "Enter room number to check out (1-" << size << "): ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > size) {
        cout << "Invalid room number." << endl;
    } else if (!rooms[roomNumber - 1].isBooked) {
        cout << "Room " << roomNumber << " is not currently booked." << endl;
    } else {
        cout << "Room " << roomNumber << " checked out. Guest: " << rooms[roomNumber - 1].guestName << endl;
        rooms[roomNumber - 1].isBooked = 0;
        rooms[roomNumber - 1].guestName = "";
    }
}

void displayRooms(const Room rooms[], int size) {
    cout << "\nRoom Status:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Room " << (i + 1) << ": " << (rooms[i].isBooked ? "Booked" : "Available");
        if (rooms[i].isBooked) {
            cout << " (Guest: " << rooms[i].guestName << ")";
        }
        cout << endl;
    }
}

void searchRoom(const Room rooms[], int size) {
    string guestName;
    cout << "Enter guest name to search: ";
    cin.ignore();  
    getline(cin, guestName);

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (rooms[i].isBooked && rooms[i].guestName == guestName) {
            cout << "Guest " << guestName << " is in Room " << (i + 1) << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Guest " << guestName << " not found in any room." << endl;
    }
}
