# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

vector <int> numbers;
int addingVec {0};
int mean {};

// prototypes for menu functions
void display_menu();
char get_action();
void print_numbers(const vector<int> &nums);
void print_display(const vector<int> &nums);
void add_numbers(vector<int> &nums);
void display_mean(const vector<int> &nums);
void calc_mean(const vector<int> &nums);
void display_smallest(const vector<int> &nums);
void display_largest(const vector<int> &nums);
void quit();
void unknown();
    
// main program
int main() {
    char action {};

    do {
        display_menu();
        action = get_action();

        switch (action) {
            case 'P':
                print_numbers(numbers);
                break;
            case 'A':
                add_numbers(numbers);
                break;
            case 'M':
                display_mean(numbers);
                break;
            case 'S':
                display_smallest(numbers);
                break;
            case 'L':
                display_largest(numbers);
                break;
            case 'Q':
                quit();
                break;
            default:
                unknown();
                break;
        }

    } while (action != 'Q');


    return 0;
}

// displays the starting menu.
void display_menu() {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "P - Print Numbers" << endl;
    cout << "A - Add a Number" << endl;
    cout << "M - Display mean of the Numbers" << endl;
    cout << "S - Display the smallest Number" << endl;
    cout << "L - Display the largest Number" << endl;
    cout << "Q - Quit" << endl;
    cout << endl;
    cout << "What would you like to do? ";
}

// gets the action by the user.
char get_action() {
    char action {};
    cin >> action;
    return toupper(action);
}

// runs when 'P' is selected
void print_numbers(const vector<int> &nums) {
    if (nums.size() == 0) {
        cout << "[] - the list is empty" << endl;
    } else {
        // calls print_display
        print_display(nums);
    }
}

// prints out numbers for the 'P' option, called in print_numbers.
void print_display(const vector<int> &nums) {
    cout << "[ ";
        for (auto i : nums) {
            cout << i << " ";
        }
    cout << "]" << endl;
}

// runs when 'A' is selected.
void add_numbers(vector<int> &nums) {
    int addNum {};
    cout << "Type and integer to add to the list: ";
    cin >> addNum;
    nums.push_back(addNum);
    cout << "You added " << addNum << endl;
}

//  runs when 'M' is selected, and displays the numbers in vector numbers.
void display_mean(const vector<int> &nums) {
    if (nums.size() == 0) {
        cout << "Unable to calculate mean - no data" << endl;
    } else {
        calc_mean(nums);
    }
}

// calculates and displays the mean of all numbers in the vector numbers.
void calc_mean(const vector<int> &nums) {
    for (auto i: nums) {
        mean += i;
    }
    cout << "The mean of all numbers is: " << static_cast<double>(mean)/nums.size() << endl;    
}

// displays the smallest number in the vector when 'S' is selected.
void display_smallest(const vector<int> &nums) {
    if (nums.size() == 0) {
        cout << "There are no numbers in the vector, please add numbers first using the 'Add Numbers' feature" << endl;
    } else {
        cout << "The smallest number is: " << *min_element(nums.begin(), nums.end()) << endl;
    }
}

// displays the largest number in the vector when 'L' is selected.
void display_largest(const vector<int> &nums) {
    if (nums.size() == 0) {
        cout << "There are no numbers in the vector, please add numbers first using the 'Add Numbers' feature" << endl;
    } else {
    cout << "The largest number is: " << *max_element(nums.begin(), nums.end()) << endl;
    }
}

// displays a message and quits the program
void quit() {
    cout << "Goodbye" << endl;
}

// displays when an unkown action is taken.
void unknown() {
    cout << "Unknown selection, please try again." << endl;
}