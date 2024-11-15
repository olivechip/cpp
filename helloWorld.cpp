#include <iostream>

int main()
{
    int nums[10]= {1,2,3,4,5,6,7,8,9,10};
    std::cout << nums << "\n";
    for (int i =0; i< 10; i++){
        std::cout << nums[i] << "\n";
    }

    std::cout << sizeof(nums)/sizeof(nums[0]) << " elements\n";
    std::cout << std::size(nums) << " elements\n";

    std::string name = "Oliver";
    std::cout << name << name.size() << "\n";
    
    return 0;
}

