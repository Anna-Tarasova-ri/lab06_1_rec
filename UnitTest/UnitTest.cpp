// Unit-тести до лабораторної роботи № 6.1, варіант 27 — Спосіб 2 (рекурсивний)
// Native Unit Test Project (Microsoft C++ Unit Test Framework)
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6_1_rec/pr6_1_rec.cpp"   // підключаємо код тестованого проєкту

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6_1_rec
{
    TEST_CLASS(UnitTest6_1_rec)
    {
    public:

        // Критерій: x > 0 або x не кратне 3
        TEST_METHOD(SatisfiesTest)
        {
            Assert::IsTrue(Satisfies(28));    // додатне
            Assert::IsTrue(Satisfies(33));    // додатне і кратне 3
            Assert::IsTrue(Satisfies(-7));    // від'ємне, не кратне 3
            Assert::IsFalse(Satisfies(-9));   // від'ємне і кратне 3
            Assert::IsFalse(Satisfies(0));    // нуль не додатний, але кратний 3
        }

        // Create: усі елементи у діапазоні [-10; 35]
        TEST_METHOD(CreateRangeTest)
        {
            const int size = 22;
            int a[size];
            Create(a, size, -10, 35, 0);
            for (int i = 0; i < size; i++)
            {
                Assert::IsTrue(a[i] >= -10);
                Assert::IsTrue(a[i] <= 35);
            }
        }

        // Count: підходять 28, 33, -7
        TEST_METHOD(CountTest)
        {
            int a[] = { -9, 28, 33, -7, 0, -6 };
            Assert::AreEqual(3, Count(a, 6, 0));
        }

        // Count: жоден елемент не підходить
        TEST_METHOD(CountNoneTest)
        {
            int a[] = { -3, -6, -9 };
            Assert::AreEqual(0, Count(a, 3, 0));
        }

        // Sum: 28 + 33 + (-7) = 54
        TEST_METHOD(SumTest)
        {
            int a[] = { -9, 28, 33, -7, 0, -6 };
            Assert::AreEqual(54, Sum(a, 6, 0));
        }

        // Sum: жоден елемент не підходить
        TEST_METHOD(SumNoneTest)
        {
            int a[] = { -3, -6, -9 };
            Assert::AreEqual(0, Sum(a, 3, 0));
        }

        // Zero: підходящі елементи стають нулями, решта без змін
        TEST_METHOD(ZeroTest)
        {
            int a[] = { -9, 28, 33, -7, 0, -6 };
            int expected[] = { -9, 0, 0, 0, 0, -6 };
            Zero(a, 6, 0);
            for (int i = 0; i < 6; i++)
                Assert::AreEqual(expected[i], a[i]);
        }
    };
}
