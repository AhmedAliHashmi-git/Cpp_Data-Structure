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

    MovieRecommendationSystem() {
        root = nullptr;
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
            return;
        }

        if (movie < temp->movieID) {
            insert(temp->left, movie, t, g, r);
        }
        else {
            insert(temp->right, movie, t, g, r);
        }
    }

    void recommendMoviesByGenre(Node* temp ,string g) {
        if (temp == nullptr) {
            return;  
        }
        if (temp->left != nullptr) {
            recommendMoviesByGenre(temp->left , g);
        }
        if(temp->genre == g){
            cout << "Movie ID: " << temp->movieID << "\nTitle: " << temp->title << "\nRatings: " << temp->ratings << endl;
        }
        if (temp->right != nullptr) {
            recommendMoviesByGenre(temp->right , g);
        }
    }

    void deleteMovieByID(Node*& temp, int key) {
    if (temp == nullptr) {
        cout << "Tree is Empty!!!" << endl;
        return;
    }

    if (key == temp->movieID) {
        if (temp->right == nullptr && temp->left == nullptr) {
            delete temp;
            temp = nullptr;
            return;
        }

        if (temp->right != nullptr && temp->left == nullptr) {
            Node* curr = temp->right;
            delete temp;
            temp = curr;
            return;
        }

        if (temp->left != nullptr && temp->right == nullptr) {
            Node* curr = temp->left;
            delete temp;
            temp = curr;
            return;
        }

        Node* successorParent = temp;
        Node* successor = temp->right;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        temp->movieID = successor->movieID;
        temp->title = successor->title;
        temp->genre = successor->genre;
        temp->ratings = successor->ratings;

        deleteMovieByID(successorParent->right, successor->movieID);
    } else if (key < temp->movieID) {
        deleteMovieByID(temp->left, key);
    } else {
        deleteMovieByID(temp->right, key);
    }
}

    

    void displayMovies(Node* temp) {
        if (temp == nullptr) {
            return;
        }
        if (temp->left != nullptr) {
            displayMovies(temp->left);
        }
        cout << "Movie ID: " << temp->movieID << "\nTitle: " << temp->title << "\nRatings: " << temp->ratings << endl;
        if (temp->right != nullptr) {
            displayMovies(temp->right);
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
				engine.recommendMoviesByGenre(engine.root,genre);
				break;
			}
			case 4:
				engine.displayMovies(engine.root);
				break;
			case 5:
				cout << "Exiting the program." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}
	return 0;
}