#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../Lab1/Lab1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestImplication)
        {
            Assert::AreEqual(true, implication(true, true));   
            Assert::AreEqual(false, implication(true, false));  
            Assert::AreEqual(true, implication(false, true));  
            Assert::AreEqual(true, implication(false, false)); 
        }

        TEST_METHOD(TestEquivalence)
        {
            Assert::AreEqual(true, equivalence(true, true));
            Assert::AreEqual(false, equivalence(true, false));
            Assert::AreEqual(false, equivalence(false, true));
            Assert::AreEqual(true, equivalence(false, false));
        }

        TEST_METHOD(TestBitwiseOperations)
        {
            std::string a = "11001010";
            std::string b = "10111001";

            std::string or_result, and_result, xor_result;
            bitwise_operations(a, b, or_result, and_result, xor_result);

            Assert::AreEqual(std::string("11111011").c_str(), or_result.c_str());
            Assert::AreEqual(std::string("10001000").c_str(), and_result.c_str());
            Assert::AreEqual(std::string("01110011").c_str(), xor_result.c_str());
        }
    };
}
