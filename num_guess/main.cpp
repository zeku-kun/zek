#include <iostream>

int main() {
    int low = 1;
    int high;
    int tries = 0;

    std::cout << "Think of a number from 1 to: ";
    std::cin >> high;

    while (low <= high) {
        int mid = (low + high) / 2;
        ++tries;

        std::cout << "Is your number " << mid << "?\n"
                  << "1 = higher, 0 = lower, 2 = correct: ";
        int choice;
        std::cin >> choice;

        if (choice == 2) {
            std::cout << "Got it in " << tries << " tries!\n";
            return 0;
        } else if (choice == 1) {
            low = mid + 1;
        } else if (choice == 0) {
            high = mid - 1;
        } else {
            std::cout << "Please enter 0, 1, or 2.\n";
            --tries;
        }
    }

    std::cout << "Your answers don't add up. Did you change your number?\n";
}