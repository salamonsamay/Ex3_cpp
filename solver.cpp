#include <stdexcept>
#include <iostream>
#include "solver.hpp"

using namespace std;
using namespace solver;

////////////////////////////////////RealVariable space///////////////////////////////////////
const RealVariable operator+ (const double& num, const RealVariable& realVar)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator+ (const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator- (const double& num, const RealVariable& realVar)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator- (const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator* (const double& num, const RealVariable& realVar)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator* (const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator/ (const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

const RealVariable operator== (const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

RealVariable operator^(const RealVariable& realVar, const double& num)
{
    return RealVariable(realVar.getVarA());
}

ostream& operator<< (ostream& os, const RealVariable&)
{
    return os;
}
//double operator() (const RealVariable& realVar);
//double operator()();


//////////////////////////////////////////////end RealVariable space////////////////////////////////////


const double solve(RealVariable realVariable)
{
    return realVariable.getVarA();
}

const std::complex<double> solve(ComplexVariable c)
{
    return c.getComplex();
}


////////////////////////////////////ComplexVariable space///////////////////////////////////////

const ComplexVariable operator+ (const double& num, const ComplexVariable& compVar)
{
    return ComplexVariable();
}

const ComplexVariable operator+ (const ComplexVariable& compVar, const double& num)
{
    return ComplexVariable();
}

const ComplexVariable operator+ (const ComplexVariable& compVar1, std::complex<double> c)
{
    return ComplexVariable();
}

const ComplexVariable operator+ (std::complex<double> c, ComplexVariable& compVar1)
{
    return ComplexVariable();
}

const ComplexVariable operator- (const double& num, const ComplexVariable& compVar)
{
    return ComplexVariable();
}

const ComplexVariable operator- (const ComplexVariable& compVar, const double& num)
{
    return ComplexVariable();
}

const ComplexVariable operator/ (const ComplexVariable& compVar, const double& num)
{
    return ComplexVariable();
}

const ComplexVariable operator* (const double& num, const ComplexVariable& compVar)
{
    return ComplexVariable();
}

const ComplexVariable operator* (const ComplexVariable& compVar, const double& num)
{
    return ComplexVariable();
}

const ComplexVariable operator== (const ComplexVariable& compVar,const double& num)
{
    return ComplexVariable();
}       

ComplexVariable operator^ (const ComplexVariable& compVar, const double& num)
{
    return ComplexVariable();
}

ostream& operator<< (ostream& os, const ComplexVariable& compVar)
{
    return os;
}
