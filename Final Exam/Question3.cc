#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int movieID;
    string title;
    string genre;
    int ratings;
    Node* left;
    Node* right;

    Node() {
        movieID = 0;
        title = " ";
        genre = " ";
        ratings = 0;
        left = nullptr;
        right = nullptr;
    }
};

class MovieRecommendationSystem {
public:
    Node* root;
    Node* array[5];
    int arrayIndex;  // Keep track of the current index in the array

    MovieRecommendationSystem() {
        root = nullptr;
        arrayIndex = 0;
    }

    void insert(Node*& temp, int movie, string t, string g, int r) {
        if (temp == nullptr) {
            temp = new Node;
            temp->movieID = movie;
            temp->title = t;
            temp->genre = g;
            temp->ratings = r;
            temp->left = nullptr;
            temp->right = nullptr;

            // Insert into the array
            if (arrayIndex < 5) {
                array[arrayIndex++] = temp;
            }

            return;
        }

        if (movie < temp->movieID) {
            insert(temp->left, movie, t, g, r);
        }
        else {
            insert(temp->right, movie, t, g, r);
        }
    }

    void recommendMoviesByGenre(Node* temp, string g) {
        if (temp == nullptr) {
            return;
        }
        if (temp->left != nullptr) {
            recommendMoviesByGenre(temp->left, g);
        }
        if (temp->genre == g) {
            cout << "Movie ID: " << temp->movieID << "\nTitle: " << temp->title << "\nRatings: " << temp->ratings << endl;
        }
        if (temp->right != nullptr) {
            recommendMoviesByGenre(temp->right, g);
        }
    }

    void deleteMovieByID(Node*& temp, int key) {
    if (temp == nullptr) {
        cout << "Movie with ID " << key << " not found." << endl;
        return;
    }

    if (key < temp->movieID) {
        deleteMovieByID(temp->left, key);
    } else if (key > temp->movieID) {
        deleteMovieByID(temp->right, key);
    } else {

        if (temp->left == nullptr) {
            Node* tempNode = temp->right;
            delete temp;
            temp = tempNode;
        } else if (temp->right == nullptr) {
            Node* tempNode = temp->left;
            delete temp;
            temp = tempNode;
        } else {
            Node* temp1 = temp->right;
            while (temp1->left != nullptr) {
                temp1 = temp1->left;
            }

            temp->movieID = temp1->movieID;
            temp->title = temp1->title;
            temp->genre = temp1->genre;
            temp->ratings = temp1->ratings;

            deleteMovieByID(temp->right, temp1->movieID);
        }
    }
}



    void selectionSort() {
        for (int i = 0; i < arrayIndex - 1; ++i) {
            int maxIndex = i;
            for (int j = i + 1; j < arrayIndex; ++j) {
                if (array[j]->ratings > array[maxIndex]->ratings) {
                    maxIndex = j;
                }
            }
			//..swap
            Node* temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
        }
    }

    void displayMovies() {
        selectionSort();
        bool check = true;
        for (int i = 0; i < arrayIndex; i++) {
            cout << "Movie ID: " << array[i]->movieID << "\nTitle: " << array[i]->title << "\nRatings: " << array[i]->ratings << endl;
			check = false;
        }
		if(!check){
			cout<<"Empty!!!";
		}
    }
};

int main() {
    MovieRecommendationSystem engine;
    int choice;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Add a Movie\n";
        cout << "2. Delete a Movie by ID\n";
        cout << "3. Recommend Movies by Genre\n";
        cout << "4. Display Movies Sorted by Ratings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int movieID;
                string title, genre;
                int ratings;
                cout << "Enter Movie ID: ";
                cin >> movieID;
                cin.ignore(); // Clear newline character from the buffer
                cout << "Enter Movie Title: ";
                getline(cin, title);
                cout << "Enter Movie Genre: ";
                getline(cin, genre);
                cout << "Enter Ratings: ";
                cin >> ratings;

                engine.insert(engine.root, movieID, title, genre, ratings);
                cout << "Movie added successfully!" << endl;
                break;
            }
            case 2: {
                int deleteID;
                cout << "Enter Movie ID to delete: ";
                cin >> deleteID;
                engine.deleteMovieByID(engine.root, deleteID);
                cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
                break;
            }
            case 3: {
                string genre;
                cout << "Enter your favorite genre: ";
                cin.ignore(); // Clear newline character from the buffer
                getline(cin, genre);
                engine.recommendMoviesByGenre(engine.root, genre);
                break;
            }
            case 4:
                engine.displayMovies();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

