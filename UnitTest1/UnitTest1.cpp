#include "pch.h"
#include "CppUnitTest.h"
#include "../labit71/labit71.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int matrix[numRows][numCols];
            const int lowerBound = -12;
            const int upperBound = 23;

            initializeMatrix(matrix, lowerBound, upperBound);

            // Перевірка, чи всі елементи матриці належать вказаному діапазону
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    Assert::IsTrue(matrix[i][j] >= lowerBound && matrix[i][j] <= upperBound);
                }
            }
        }
      
    };
    }
