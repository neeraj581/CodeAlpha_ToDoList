#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TodoItem {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\nTo-do List Menu:\n";
    cout << "1. Add a new item\n";
    cout << "2. View all items\n";
    cout << "3. Delete an item\n";
    cout << "4. Mark an item as completed\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void addItem(vector<TodoItem>& todoList) {
    TodoItem newItem;
    cout << "Enter the description of the new item: ";
    cin.ignore();
    getline(cin, newItem.description);
    newItem.completed = false;
    todoList.push_back(newItem);
    cout << "Item added successfully!\n";
}

void viewItems(const vector<TodoItem>& todoList) {
    cout << "\nTo-do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". " << (todoList[i].completed ? "[Completed] " : "[Not Completed] ") << todoList[i].description << "\n";
    }
}

void deleteItem(vector<TodoItem>& todoList) {
    int index;
    cout << "Enter the item number to delete: ";
    cin >> index;
    if (index > 0 && index <= todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "Item deleted successfully!\n";
    } else {
        cout << "Invalid item number!\n";
    }
}

void markCompleted(vector<TodoItem>& todoList) {
    int index;
    cout << "Enter the item number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "Item marked as completed!\n";
    } else {
        cout << "Invalid item number!\n";
    }
}

int main() {
    vector<TodoItem> todoList;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(todoList);
                break;
            case 2:
                viewItems(todoList);
                break;
            case 3:
                deleteItem(todoList);
                break;
            case 4:
                markCompleted(todoList);
                break;
            case 5:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
