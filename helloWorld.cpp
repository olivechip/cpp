#include <iostream>

// function declarations
int sum(int nums[], int size);
int search(int nums[], int size, int element);

int main()
{
    // Declaring an Array
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    // Size of Array
    std::cout << sizeof(numbers) / sizeof(int) << " elements\n"; // legacy
    std::cout << std::size(numbers) << " elements\n";            // modern

    // Looping Over an Array
    // traditional for loop
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << '\n';
    }

    // for each loop (range-based)
    for (int num : numbers)
    {
        std::cout << num << '\n';
    }

    // establish and executing function w/ arrays
    int size = sizeof(numbers) / sizeof(int);
    std::cout << sum(numbers, size) << '\n';

    // searching for an element in an array
    int element;
    std::cout << "Enter a number to search for: \n";
    std::cin >> element;
    int index = search(numbers, size, element);
    std::cout << index << '\n';

    // declaring pointers
    std::string name = "Oliver";
    std::string *pName = &name;
    std::cout << *pName << '\n';

    int age = 69;
    int *pAge = &age;
    std::cout << *pAge << '\n';

    std::string fruit[4] = {"banana", "strawberry", "apple"};
    std::cout << fruit << '\n';

    return 0;
}

// defining a function w/ arrays
int sum(int nums[], int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += nums[i];
    }
    return total;
}

// searching for an element in an array
int search(int nums[], int size, int element){
    for (int i = 0; i < size; i++){
        if (nums[i] == element){
            return i;
        }
    }
    return -1;
}