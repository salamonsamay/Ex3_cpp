#include "doctest.h"
#include "solver.hpp"

using namespace std;

using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Test case 1 - RealVariable - CHECK_THROWS")
{
    RealVariable x;

    CHECK_THROWS(solve((x^2) == -16));
    CHECK_THROWS(solve((x^2) == (x^2)));
    CHECK_THROWS(solve(x == x));
    CHECK_THROWS(solve(x + 3 == x + 3));
    CHECK_THROWS(solve((x^2) == -1.0));
    CHECK_THROWS(solve((x^2) == 4-20));
    CHECK_THROWS(solve((x^2) == (x^2)));
    CHECK_THROWS(solve((x^2) + x == -16.0 + x));
    CHECK_THROWS(solve((x^2) + x - 16.0 == -32.0 + x));
    CHECK_THROWS(solve((x^2) + 2*x + 1 == (x^2) + 2*x + 1));
}


TEST_CASE("Test case 2 - RealVariable - CHECK")
{
    RealVariable x;

    CHECK((solve((x^2) == 16) == 4 || solve((x^2) == 16) == -4));
    CHECK((solve((x^2) == 25) == 5 || solve((x^2) == 25) == -5));
    CHECK((solve((x^2) + x == 16.0 + x) == 4 || solve((x^2) + x == 16.0 + x) == -4));
    CHECK((solve((x^2) + x == x + 16.0) == 4 || solve((x^2) + x == x + 16.0) == -4));
    CHECK((solve((x^2) + x + 16.0 == 32.0 + x) == 4 || solve((x^2) + x + 16.0 == 32.0 + x) == -4));
    CHECK((solve((x^2) + x + 16.0 == x + 32.0) == 4 || solve((x^2) + x + 16.0 == x + 32.0) == -4));
    CHECK(solve(x == 1.0) == 1.0);
    CHECK(solve(x == 0.0) == 0.0);
    CHECK(solve(x + 1 == 0.0) == -1.0);
    CHECK(solve(x - 1 == 0.0) == 1.0);
}


TEST_CASE("Test case 3 - ComplexVariable - CHECK")
{
    ComplexVariable y;

    complex<double> a = solve((y^2) == 16);
    CHECK((a == complex<double>(4,0) || a == complex<double>(-4,0)));

    a = solve((y^2) == -16);
    CHECK((a == complex<double>(0,4) || a == complex<double>(0,-4)));

    a = solve((y^2) + 2*y + 4 == 20 + 6*y/2 - y);
    CHECK((a == complex<double>(4,0) || a == complex<double>(0,-4)));

    a = solve(y+5i == 2*y+3i);
    CHECK(a == complex<double>(0,2));

    a = solve(y+4i == 0);
    CHECK(a == complex<double>(0,-4));

    a = solve(y+4i == 2*y);
    CHECK(a == complex<double>(0,4));

    CHECK_THROWS(solve(y+4i == y));
    CHECK_THROWS(solve(2*y+4i == 2*y));
    CHECK_THROWS(solve(2*y == y + y));
    CHECK_THROWS(solve(2*y == y + y + 2));
    CHECK_THROWS(solve(y + y == 2*y));
    CHECK_THROWS(solve(y + y + 2 == 2*y));
    CHECK_THROWS(solve(2*y == 2*y+4i));
    CHECK_THROWS(solve(y == y+4i));

    CHECK_THROWS(solve(y-4i == y));
    CHECK_THROWS(solve(2*y-4i == 2*y));
    CHECK_THROWS(solve(2*y - y == y + y + y));
    CHECK_THROWS(solve(2*y == y + y - 2));
    CHECK_THROWS(solve(y + y - y == 2*y - y));
    CHECK_THROWS(solve(y + y - 2 == 2*y));
    CHECK_THROWS(solve(2*y == 2*y-4i));
    CHECK_THROWS(solve(y == y-4i));

    CHECK(solve(y == 2*y) == complex<double>(0,0));
    CHECK(solve(y + 3i == 2) == complex<double>(2,-3));
    CHECK(solve(y + 3i + 2 == 2) == complex<double>(0,-3));
    CHECK(solve(y - 2i == 2*y) == complex<double>(0,0));
    CHECK(solve(y*y == 0) == complex<double>(0,0));
    CHECK(solve(y - 3i - 4 == 2) == complex<double>(6,3));
    CHECK(solve(y - 6i + 2 == 2) == complex<double>(0,6));
    CHECK(solve(y - 6i - 2 == 2) == complex<double>(4,6));
    CHECK(solve(y - 2i + 2*y == 2*y) == complex<double>(0,2));
    CHECK(solve(y == 2*y - 2*y) == complex<double>(0,0));
    CHECK(solve(y == 2*y - y + 2 - 2) == complex<double>(0,0));
    CHECK(solve(y + 3i - 2 == 2*y + 4i) == complex<double>(-1,-2));
    CHECK(solve(y + 2*y == 0) == complex<double>(0,0));
    CHECK(solve(y - 2i == 2*y) == complex<double>(0,-2));

//////////////57

}

TEST_CASE("Test case 4 - RealVariable")
{
    RealVariable x;

    CHECK(solve(x == 8) == 8);
    CHECK(solve((x^2) == 0) == 0.0);
    CHECK(solve(x + 1 - 1 == -1.0) == -1.0);
    CHECK(solve(x - 1 == 0) == 1.0);
    CHECK(solve(10*x == 100) == 10);
    CHECK(solve(2*x == 2*x + x) == 0);
    CHECK(solve(5*x + 5 == 5) == 0);
    CHECK(solve(3 + x == 0) == -3);
    CHECK(solve(10/2 + x == 5) == 0);
    CHECK(solve(10*2 + x == 5) == -15);
    /////////////////////////////////////////////////
    
    CHECK(solve(x == 8) == 8);
    CHECK(solve((x^2) == 0) == 0.0);
    CHECK(solve(x + 1 - 1 == -1.0) == -1.0);
    CHECK(solve(x - 1 == 0) == 1.0);
    CHECK(solve(10*x == 100) == 10);
    CHECK(solve(2*x == 2*x + x) == 0);
    CHECK(solve(5*x + 5 == 5) == 0);
    CHECK(solve(3 + x == 0) == -3);
    CHECK(solve(10/2 + x == 5) == 0);
    CHECK(solve(10*2 + x == 5) == -15);

    CHECK(solve(x == 8) == 8);
    CHECK(solve((x^2) == 0) == 0.0);
    CHECK(solve(x + 1 - 1 == -1.0) == -1.0);
    CHECK(solve(x - 1 == 0) == 1.0);
    CHECK(solve(10*x == 100) == 10);
    CHECK(solve(2*x == 2*x + x) == 0);
    CHECK(solve(5*x + 5 == 5) == 0);
    CHECK(solve(3 + x == 0) == -3);
    CHECK(solve(10/2 + x == 5) == 0);
    CHECK(solve(10*2 + x == 5) == -15);

    CHECK(solve(x == 8) == 8);
    CHECK(solve((x^2) == 0) == 0.0);
    CHECK(solve(x + 1 - 1 == -1.0) == -1.0);
    CHECK(solve(x - 1 == 0) == 1.0);
    CHECK(solve(10*x == 100) == 10);
    CHECK(solve(2*x == 2*x + x) == 0);
    CHECK(solve(5*x + 5 == 5) == 0);
    CHECK(solve(3 + x == 0) == -3);
    CHECK(solve(10/2 + x == 5) == 0);
    CHECK(solve(10*2 + x == 5) == -15);

    CHECK(solve(5*x + 5 == 5) == 0);
    CHECK(solve(3 + x == 0) == -3);
    CHECK(solve(10/2 + x == 5) == 0);
    CHECK(solve(10*2 + x == 5) == -15);


}