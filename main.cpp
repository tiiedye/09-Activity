# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

char action {};
vector <int> numbers;
int addNum {};
int addingVec {0};
int mean {};

// prototypes for menu functions
void print_numbers(const vector<int> &nums);
void print_display(const vector<int> &nums);
void add_numbers(const vector<int> &nums);
    
// main program
int main() {
    do {
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
        cin >> action;

        switch (action) {
            case 'p':
            case 'P':
                print_numbers(numbers);
                break;
            case 'a':
            case 'A':
                cout << "Type and integer to add to the list: ";
                cin >> addNum;
                numbers.push_back(addNum);
                cout << "You added " << addNum << endl;
                break;
            case 'm':
            case 'M':
                if (numbers.size() == 0) {
                    cout << "Unable to calculate mean - no data" << endl;
                } else {
                    for (auto i: numbers) {
                        mean += i;
                    }
                    cout << "The mean of all numbers is: " << static_cast<double>(mean)/numbers.size() << endl;
                }
                break;
            case 's':
            case 'S':
                cout << "The smallest number is: " << *min_element(numbers.begin(), numbers.end()) << endl;
                break;
            case 'l':
            case 'L':
                cout << "The smallest number is: " << *max_element(numbers.begin(), numbers.end()) << endl;
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again." << endl;
                break;
        }

    } while (action != 'q' && action != 'Q');


    return 0;
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
void add_numbers(const vector<int> &nums) {

}