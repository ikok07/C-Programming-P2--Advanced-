cmake_minimum_required(VERSION 3.28)
project(advancedProgramming C)

set(CMAKE_C_STANDARD 17)

add_executable(advancedProgramming main.c
        utils/swapWithMemFuncs.c
        utils/isPalindrome.c
        utils/areOpposite.c
        utils/maxSum.c
        utils/printRightLeft.c
        utils/arrAvg.c
        utils/getBinary.c
        utils/swapArrO1.c
        utils/reallocExercise.c
        utils/myRealloc.c
        utils/fillArr.c
        utils/create1DArray.c
        utils/testExercises.c
        utils/removeDuplicates.c
        utils/separateArrays.c
        utils/arrAddRemove.c
        utils/2DArrs.c
        utils/swap2DElements.c
        utils/triangularMatrix.c
        utils/stringMethods.c
        utils/schoolProject.c
        utils/sortArray.c
        utils/pizzaProject.c
        utils/fileRemoveSpaces.c
        utils/sortFileNums.c
        utils/fileCompare.c
        utils/fileTest.c
)
