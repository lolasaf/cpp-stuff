#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "=== Test 1: Default constructor (empty array) ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    try {
        empty[0] = 1; // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception (expected): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Test 2: Parameterized constructor and basic operations ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    std::cout << "Array values: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 3: Deep copy (copy constructor) ===" << std::endl;
    Array<int> original(3);
    original[0] = 100; original[1] = 200; original[2] = 300;
    Array<int> copy(original);
    copy[0] = 999; // Modify copy
    std::cout << "Original[0]: " << original[0] << " (should be 100)" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be 999)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 4: Assignment operator (deep copy) ===" << std::endl;
    Array<int> arr1(2);
    arr1[0] = 10; arr1[1] = 20;
    Array<int> arr2(2);
    arr2 = arr1;
    arr2[0] = 99; // Modify assigned array
    std::cout << "arr1[0]: " << arr1[0] << " (should be 10)" << std::endl;
    std::cout << "arr2[0]: " << arr2[0] << " (should be 99)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 5: Different types (string) ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "hello";
    strArray[1] = "world";
    strArray[2] = "cpp";
    std::cout << "String array: ";
    for (size_t i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "=== Test 6: Const correctness ===" << std::endl;
    const Array<int> constArr(3);
    //constArr[0] = 1; //would not compile
    std::cout << "Const array size: " << constArr.size() << std::endl;
    std::cout << "Const array[0]: " << constArr[0] << " (read-only access works)" << std::endl;
    std::cout << std::endl;

    std::cout << "=== Test 7: Original exercise test (large array) ===" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}