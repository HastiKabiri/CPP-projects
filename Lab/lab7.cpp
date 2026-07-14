#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


struct Song {
    int no;
    string artist;
    string title;
    int released;
    string genre;
    double length;
};


struct Node {
    Song data;
    Node* prev;
    Node* next;
    
    Node(Song s) {
        data = s;
        prev = nullptr;
        next = nullptr;
    }
};

class MusicPlayer {
private:
    Node* head;
    Node* tail;
    Node* currentPlaying;

public:
    MusicPlayer() {
        head = nullptr;
        tail = nullptr;
        currentPlaying = nullptr;
    }


    void addAtBeginning(Song s) {
        Node* newNode = new Node(s);
        if (head == nullptr) {
            head = tail = currentPlaying = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "[+] Added '" << s.title << "' to the beginning.\n";
    }

  
    void addAtEnd(Song s) {
        Node* newNode = new Node(s);
        if (tail == nullptr) {
            head = tail = currentPlaying = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "[+] Added '" << s.title << "' to the end.\n";
    }

  
    void addAtPosition(Song s, int pos) {
        if (pos <= 1) {
            addAtBeginning(s);
            return;
        }
        
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr || temp == tail) {
            addAtEnd(s);
        } else {
            Node* newNode = new Node(s);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            cout << "[+] Added '" << s.title << "' at position " << pos << ".\n";
        }
    }

    
    void printSongHeader() {
        cout << left << setw(5) << "No" << setw(20) << "Artist" << setw(25) << "Song" 
             << setw(10) << "Released" << setw(10) << "Genre" << setw(10) << "Length" << endl;
        cout << string(80, '-') << endl;
    }

    void printSongRow(Song s) {
        cout << left << setw(5) << s.no << setw(20) << s.artist << setw(25) << s.title 
             << setw(10) << s.released << setw(10) << s.genre << setw(10) << fixed << setprecision(2) << s.length << endl;
    }

   
    void viewUnsorted() {
        if (!head) { cout << "Playlist is empty!\n"; return; }
        printSongHeader();
        Node* temp = head;
        while (temp != nullptr) {
            printSongRow(temp->data);
            temp = temp->next;
        }
    }

   
    void viewSorted() {
        if (!head) { cout << "Playlist is empty!\n"; return; }
        
       
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data.no > ptr1->next->data.no) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
        
        cout << "--- Playlist Sorted by Song Number ---\n";
        viewUnsorted(); 
    }

   
    void viewSingleSong(string action) {
        if (!currentPlaying) { cout << "No songs to play.\n"; return; }
        
        if (action == "next" && currentPlaying->next != nullptr) {
            currentPlaying = currentPlaying->next;
        } else if (action == "prev" && currentPlaying->prev != nullptr) {
            currentPlaying = currentPlaying->prev;
        } else if (action == "next" || action == "prev") {
            cout << "[!] Reached the end/beginning of the playlist.\n";
            return;
        }
        
        cout << "\n>>> Currently Playing <<<\n";
        printSongHeader();
        printSongRow(currentPlaying->data);
    }

    
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = currentPlaying = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
            if (currentPlaying == temp) currentPlaying = head;
        }
        cout << "[-] Deleted '" << temp->data.title << "' from the beginning.\n";
        delete temp;
    }

   
    void deleteEnd() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = currentPlaying = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
            if (currentPlaying == temp) currentPlaying = tail;
        }
        cout << "[-] Deleted '" << temp->data.title << "' from the end.\n";
        delete temp;
    }

  
    void deleteByArtist(string artist) {
        if (!head) return;
        Node* temp = head;
        bool found = false;
        
        while (temp != nullptr) {
            if (temp->data.artist == artist) {
                found = true;
                if (temp == head) {
                    deleteBeginning();
                    temp = head; 
                    continue;
                } else if (temp == tail) {
                    deleteEnd();
                    break;
                } else {
                    Node* toDelete = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (currentPlaying == toDelete) currentPlaying = temp->next;
                    temp = temp->next;
                    cout << "[-] Deleted song by '" << artist << "'.\n";
                    delete toDelete;
                    continue;
                }
            }
            temp = temp->next;
        }
        if (!found) cout << "[!] Artist '" << artist << "' not found.\n";
    }


    void searchByGenre(string genre) {
        if (!head) return;
        Node* temp = head;
        bool found = false;
        
        cout << "--- Search Results for Genre: " << genre << " ---\n";
        printSongHeader();
        while (temp != nullptr) {
            if (temp->data.genre == genre) {
                printSongRow(temp->data);
                found = true;
            }
            temp = temp->next;
        }
        if (!found) cout << "No songs found in this genre.\n";
    }
};


int main() {
    MusicPlayer player;

    Song s1 = {1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58};
    Song s2 = {2, "Taylor Swift", "You Belong With Me", 2008, "Pop", 3.48};
    Song s3 = {3, "The Cranberries", "Promises", 1999, "Rock", 4.30};

    cout << "--- Initializing Lab Data ---\n";
    player.addAtEnd(s1);
    player.addAtEnd(s2);
    player.addAtEnd(s3);
    cout << "\n";

    int choice;
    do {
        cout << "\n=== Music Player Lab Demo ===\n";
        cout << "1. View Unsorted List\n";
        cout << "2. View Sorted List (by No)\n";
        cout << "3. Play Next Song\n";
        cout << "4. Play Previous Song\n";
        cout << "5. Add Song at Beginning\n";
        cout << "6. Add Song at Position 2\n";
        cout << "7. Delete Song at Beginning\n";
        cout << "8. Delete Song at End\n";
        cout << "9. Delete Song by Artist (Celine Dion)\n";
        cout << "10. Search by Genre (Pop)\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        Song newSong = {4, "Linkin Park", "Numb", 2003, "Rock", 3.05};

        switch (choice) {
            case 1: player.viewUnsorted(); break;
            case 2: player.viewSorted(); break;
            case 3: player.viewSingleSong("next"); break;
            case 4: player.viewSingleSong("prev"); break;
            case 5: player.addAtBeginning(newSong); break;
            case 6: player.addAtPosition(newSong, 2); break;
            case 7: player.deleteBeginning(); break;
            case 8: player.deleteEnd(); break;
            case 9: player.deleteByArtist("Celine Dion"); break;
            case 10: player.searchByGenre("Pop"); break;
            case 0: cout << "Exiting lab demo...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}