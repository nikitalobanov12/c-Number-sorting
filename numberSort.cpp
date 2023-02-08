// g++ -pedantic -Wall -Wextra -std=c++17 numberSort.cpp
// input & output
#include <iostream>
// strings
#include <string>
// vectors
#include <vector>
// random
#include <ctime>
// step 1. generate 2 vectors that contain 8 random ints
// one vector will be ascending order, the other descending order
void random_vector(std::vector<int> &v1, std::vector<int> &v2)
{
    // seed the random number generator
    srand(time(0));
    // generate 8 random numbers for the ascending vector
    for (int i = 0; i < 8; i++)
    {
        // generate a random number between 1 and 100
        int num = rand() % 100 + 1;
        // add the number to the vector
        v1.push_back(num);
    }
    // generate 8 random numbers for the descending vector
    for (int i = 0; i < 8; i++)
    {
        // generate a random number between 1 and 100
        int num = rand() % 100 + 1;
        // add the number to the vector
        v2.push_back(num);
    }

    // sort the first vector in ascending order using bubble sort and print the number of comparisons
    int comparisons = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {   
            comparisons++;
            if (v1[i] > v1[j])
            {
                int temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }
    }

    std::cout << "Number of comparisons for the ascending order sort: " << comparisons << std::endl;

    comparisons = 0;
    // sort the second vector in descending order using bubble sort
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            comparisons++;
            if (v2[i] < v2[j])
            {
                int temp = v2[i];
                v2[i] = v2[j];
                v2[j] = temp;
            }
        }
    }
    std::cout << "Number of comparisons for the descending order sort: " << comparisons << std::endl;

}

// step 2. function that takes the two vectors and merges them into a third vector which has the numbers ordered from smallest to largest
void merge_vector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
{
    // i is set to 0 so that it starts at the beginning of the vector
    int i = 0;
    // j is set to 7 so that it starts at the end of the second vector
    int j = 7;
    int comparisons = 0;
    //while there are still numbers in both vectors
    while (i < 8 && j > -1)
    {   comparisons++;
        // if the number at i is less than the number at j
        if (v1[i] < v2[j])
        {
            // add the number at i to the end of v3
            v3.push_back(v1[i]);
            // increment i
            i++;
        }
        // if the number at i is greater than the number at j
        else if (v1[i] > v2[j])
        {
            // add the number at j to the end of v3
            v3.push_back(v2[j]);
            // decrement j
            j--;
        }
        // if the number at i is equal to the number at j
        else
        {
            // add the number at i to the end of v3
            v3.push_back(v1[i]);
            // increment i
            i++;
            // add the number at j to the end of v3
            v3.push_back(v2[j]);
            // decrement j
            j--;
        }
    }


    // if i is less than 8
    if (i < 8)
    {  
        // while i is less than 8
        while (i < 8)
        {
        comparisons++;
            // add the number at i to the end of v3
            v3.push_back(v1[i]);
            // increment i
            i++;
        }
    }
    // if j is greater than -1
    if (j > -1) 
    {   
        // while j is greater than -1
        while (j > -1)
        {
        comparisons++;
            // add the number at j to the end of v3
            v3.push_back(v2[j]);
            // decrement j
            j--;
        }
    }
    std::cout << "Number of comparisons for the merge sort: " << comparisons << std::endl;
}
// function that prints out the vectors
void print_vector(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &v3)
{
    std::cout << "Ascending order: ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Descending order: ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Merged order: ";
    for (int i = 0; i < 16; i++)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;
    random_vector(v1, v2);
    std::vector<int> v3;
    merge_vector(v1, v2, v3);
    print_vector(v1, v2, v3);
    return 0;
}



