# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

char action {};
vector <int> numbers;
int addingVec {0};
int mean {};

// prototypes for menu functions
void print_numbers(const vector<int> &nums);
void print_display(const vector<int> &nums);
void add_numbers(vector<int> &nums);
void display_mean(const vector<int> &nums);
void calc_mean(const vector<int> &nums);
void display_smallest(const vector<int> &nums);
void display_largest(const vector<int> &nums);
    
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
                add_numbers(numbers);
                break;
            case 'm':
            case 'M':
                display_mean(numbers);
                break;
            case 's':
            case 'S':
                display_smallest(numbers);
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

void display_smallest(const vector<int> &nums) {
    cout << "The smallest number is: " << *min_element(nums.begin(), nums.end()) << endl;
}