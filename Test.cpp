#include "doctest.h"
#include "solver.hpp"

using namespace std;

using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Test case 1 - RealVariable - CHECK_THROWS")
{
    RealVariable x;

    CHECK_THROWS(solve((x^2) == -16));
    CHECK_THROWS(solve((x^2) == -1.0));
    CHECK_THROWS(solve((x^2) == 4-20));
    CHECK_THROWS(solve((x^2) == (x^2)));
    CHECK_THROWS(solve((x^2) + x == -16.0 + x));
    CHECK_THROWS(solve((x^2) + x - 16.0 == -32.0 + x));
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
}

//////////////////12 test need 100//////////////