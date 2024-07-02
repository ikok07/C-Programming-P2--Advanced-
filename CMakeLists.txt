cmake_minimum_required(VERSION 3.28)
project(advancedProgramming C)

set(CMAKE_C_STANDARD 17)

add_executable(advancedProgramming main.c
        utils/swapWithMemFuncs.c
        utils/isPalindrome.c
        utils/areOpposite.c
        utils/maxSum.c
        utils/printRightLeft.c)
