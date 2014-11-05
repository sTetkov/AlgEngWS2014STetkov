/// \brief This is a implementation of three different algorithms
///        for the calculation of the Fibonacci number.
///
///This program implements three different algorithms for the calculation of the fibonacci number
/// f(n) where f(n) = f(n-1) + f(n-2) and f(0) = 0 and f(1) = 1.
///
///
#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    #ifdef TEST_RUN
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    #else
    return 0;
    #endif // TEST_RUN
}

/// \brief This implements the classic recursive algorithm for the calculation of the fibonacci number.
///
///This algorithm, while quite straightforward, is extremely inefficient, having a runtime of 2^n and a similar
///memory usage.
int fibonacciRet(int n)
{
    #ifdef TEST_RUN
    EXPECT_GE(n,0)<< "A negative value" << n << "was passed to fibonacciRet" ;
    #endif
    if(n<2)
        return n;
    return fibonacciRet(n-1)+fibonacciRet(n-2);
}

#ifdef TEST_RUN
TEST (FibonacciTest,FibonacciRecursiveFunction)
{
        ASSERT_EQ(fibonacciRet(0),0);
        ASSERT_EQ(fibonacciRet(1),1);
        ASSERT_EQ(fibonacciRet(2),1);
        ASSERT_EQ(fibonacciRet(3),2);
        ASSERT_EQ(fibonacciRet(4),3);
        ASSERT_EQ(fibonacciRet(5),5);
        ASSERT_EQ(fibonacciRet(6),8);
        ASSERT_EQ(fibonacciRet(7),13);
        ASSERT_EQ(fibonacciRet(8),21);
        ASSERT_EQ(fibonacciRet(9),34);
        ASSERT_EQ(fibonacciRet(10),55);
}
#endif // TEST_RUN
///\brief This implements an algorithm for the calculation of the fibonacci number that uses an array to
///have a linear runtime and memory usage
///
///In this case we usa an array to store all intermediate values used for the calculation.
int fibonacciArray(int n)
{
    #ifdef TEST_RUN
    EXPECT_GE(n,0)<< "A negative value" << n << "was passed to fibonacciArray";
    #endif
    if(n<2)
        return n;
    int *piVec=new int[n];
    piVec[0]=0;
    piVec[1]=1;
    for (int i=2;i<n;i++)
        piVec[i]=piVec[i-1]+piVec[i-2];
    int ret=piVec[n-1]+piVec[n-2];
    delete[] piVec;
    return ret;
}

#ifdef TEST_RUN
TEST (FibonacciTest,FibonacciArrayFunction)
{
        ASSERT_EQ(fibonacciArray(0),0);
        ASSERT_EQ(fibonacciArray(1),1);
        ASSERT_EQ(fibonacciArray(2),1);
        ASSERT_EQ(fibonacciArray(3),2);
        ASSERT_EQ(fibonacciArray(4),3);
        ASSERT_EQ(fibonacciArray(5),5);
        ASSERT_EQ(fibonacciArray(6),8);
        ASSERT_EQ(fibonacciArray(7),13);
        ASSERT_EQ(fibonacciArray(8),21);
        ASSERT_EQ(fibonacciArray(9),34);
        ASSERT_EQ(fibonacciArray(10),55);
}
#endif

///\brief This implements an algorithm for the calculation of the fibonacci number that has a
///linear runtime and a constant memory usage.
int fibonacciConst(int n)
{
    #ifdef TEST_RUN
    EXPECT_GE(n,0)<< "A negative value" << n << "was passed to fibonacciConst";
    #endif
    if (n<2)
        return n;
    int fib1=0;
    int fib2=1;
    int ret=0;
    for (int i=2;i<n+1;i++)
    {
        ret=fib1+fib2;
        fib1=fib2;
        fib2=ret;
    }
    return ret;
}

#ifdef TEST_RUN
TEST (FibonacciTest,FibonacciConstFunction)
{
        ASSERT_EQ(fibonacciConst(0),0);
        ASSERT_EQ(fibonacciConst(1),1);
        ASSERT_EQ(fibonacciConst(2),1);
        ASSERT_EQ(fibonacciConst(3),2);
        ASSERT_EQ(fibonacciConst(4),3);
        ASSERT_EQ(fibonacciConst(5),5);
        ASSERT_EQ(fibonacciConst(6),8);
        ASSERT_EQ(fibonacciConst(7),13);
        ASSERT_EQ(fibonacciConst(8),21);
        ASSERT_EQ(fibonacciConst(9),34);
        ASSERT_EQ(fibonacciConst(10),55);
}
#endif
