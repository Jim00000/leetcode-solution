/**
 * @file main.cpp
 * @author Jim00000
 * @brief 1700 Number of Students Unable to Eat Lunch
 * @copyright Copyright (c) 2021 Jim00000
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 */
#include <vector>

/**
 * @brief solution
 * https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 * 
 * - Time complexity  : O(N^3)
 * - Space complexity : O(1) 
 */
class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int failCount = 0;
        int sandwichIndex = 0;
        int consumer;
        const int haltIndex = sandwiches.size() - 1;
        int producer = sandwiches.front();

        // Time complexity of worst cases should be as following :
        // Maximum iteration counts = N + (N - 1) + (N - 2) + ... + 2 + 1 = O(N^2)
        //
        // When failCount reaches the number of student's count, it means that we 
        // have checked the whole round of student list and cannot make steps of counting progress anymore.
        while (failCount < students.size()) {
            consumer = students.front();
            // erase(...) method use linear search.
            // Time complexity: O(N)
            students.erase(students.cbegin());  

            if (consumer == producer) {
                // Avoid accessing out of boundary of array
                if (++sandwichIndex > haltIndex)
                    break;
                producer = sandwiches.at(sandwichIndex);
                failCount = 0;
            }
            else { // For the siutation that the sandwich is that the student dislikes
                students.push_back(consumer);
                failCount++;
            }
        }

        return students.size();
    }
};