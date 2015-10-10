/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTest_init = false;
#include "/root/ClionProjects/InverseMatrix/MyTest.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTest( "MyTest.h", 12, "MyTest", suite_MyTest, Tests_MyTest );

static class TestDescription_suite_MyTest_test_mult : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test_mult() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 16, "test_mult" ) {}
 void runTest() { suite_MyTest.test_mult(); }
} testDescription_suite_MyTest_test_mult;

static class TestDescription_suite_MyTest_test_Get_matr : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test_Get_matr() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 34, "test_Get_matr" ) {}
 void runTest() { suite_MyTest.test_Get_matr(); }
} testDescription_suite_MyTest_test_Get_matr;

static class TestDescription_suite_MyTest_test_Det : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test_Det() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 56, "test_Det" ) {}
 void runTest() { suite_MyTest.test_Det(); }
} testDescription_suite_MyTest_test_Det;

static class TestDescription_suite_MyTest_test_TransponMtx : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_test_TransponMtx() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 71, "test_TransponMtx" ) {}
 void runTest() { suite_MyTest.test_TransponMtx(); }
} testDescription_suite_MyTest_test_TransponMtx;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
