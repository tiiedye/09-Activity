# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {

    char action {};
    vector <int> nums;
    int addNum {};
    int addingVec {0};
    int mean {};

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
                if (nums.size() == 0) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    cout << "[ ";
                    for (auto i: nums) {
                        cout << i << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            case 'a':
            case 'A':
                cout << "Type and integer to add to the list: ";
                cin >> addNum;
                nums.push_back(addNum);
                cout << "You added " << addNum << endl;
                break;
            case 'm':
            case 'M':
                if (nums.size() == 0) {
                    cout << "Unable to calculate mean - no data" << endl;
                } else {
                    for (auto i: nums) {
                        mean += i;
                    }
                    cout << "The mean of all numbers is: " << static_cast<double>(mean)/nums.size() << endl;
                }
                break;
            case 's':
            case 'S':
                cout << "The smallest number is: " << *min_element(nums.begin(), nums.end()) << endl;
                break;
            case 'l':
            case 'L':
                cout << "The smallest number is: " << *max_element(nums.begin(), nums.end()) << endl;
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