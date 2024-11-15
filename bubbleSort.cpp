#include <iostream>

using std::cout;

void sortArray(int nums[], int size);

int main()
{
    int nums[] = { 5, 4, 10, 6, 7, 3, 2, 8, 1, 9 };
    int size = std::size(nums);

    sortArray(nums, size);

    for (int element : nums){
        cout << element << "\n";
    }
    return 0;
}

void sortArray(int nums[], int size){
    int temp;
    for(int i = 0; i < size -1; i++){
        for (int j = 0; j <size - 1; j++){
            if (nums[j] > nums[j + 1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}