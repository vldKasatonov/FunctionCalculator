#include "pch.h"
#include "CppUnitTest.h"
#include "C:\KhPI\CppProject\FSE\LabProject\FunctionCalculator\FunctionCalculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(CalculateTests)
	{
	public:
		TEST_METHOD(calculatePositiveNumber)
		{
			int n = 3;
			double x = 2;
			double expected = 3;

			double actual = calculateY(x, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculateNegativeNumber)
		{
			int n = 6;
			double x = -9;
			double expected = -11.55;

			double actual = calculateY(x, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculateBigPositiveNumber)
		{
			int n = 8;
			double x = 143;
			double expected = 1.15288;

			double actual = calculateY(x, n);

			double epsilon = 1e-5;

			Assert::AreEqual(expected, actual, epsilon);
		}
	public:
		TEST_METHOD(calculateBigNegativeNumber)
		{
			int n = 5;
			double x = -343;
			double expected = -371.583;

			double actual = calculateY(x, n);

			double epsilon = 1e-3;

			Assert::AreEqual(expected, actual, epsilon);
		}
	public:
		TEST_METHOD(calculateFractionalNumber)
		{
			int n = 9;
			double x = 14.55;
			double expected = 13.8044;

			double actual = calculateY(x, n);

			double epsilon = 1e-4;

			Assert::AreEqual(expected, actual, epsilon);
		}
	};
	TEST_CLASS(checkValidParamsTests) {
	public:
		TEST_METHOD(checkCorrectParams_ExceptionNotThrown)
		{
			double a = 1;
			double b = 10;
			double h = 2;
			int n = 4;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(checkUncorrectAandB_ExceptionThrown)
		{
			double a = 11;
			double b = 3;
			double h = 2;
			int n = 4;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkUncorrectH_ExceptionThrown)
		{
			double a = 1;
			double b = 10;
			double h = -1;
			int n = 4;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	public:
		TEST_METHOD(checkUncorrectN_ExceptionThrown)
		{
			double a = 1;
			double b = 10;
			double h = 2;
			int n = 0;

			try
			{
				checkValidParams(a, b, h, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}