#include <stdexcept>
#include "solver.hpp"

namespace solver
{
    //solve for RealVariable
    const double solve(RealVariable realVariable)
    {
        return realVariable.getVarA();
    }

    //solve for ComplexVariable
    const std::complex<double> solve(ComplexVariable c)
    {
        return c.getComplex();
    } 

    ///////////////////////////Operators of RealVariable////////////////////////////
    const RealVariable operator+(const RealVariable& other, const RealVariable& other1) 
    {
        return other;
    }

    const RealVariable operator+ (const double& num, const RealVariable& realVar)
    {
        return RealVariable(realVar.getVarA());
    }

    const RealVariable operator+ (const RealVariable& realVar, const double& num)
    {
        return RealVariable(realVar.getVarA());
    }    

    const RealVariable operator-(const RealVariable& other, const RealVariable& other1) 
    {
        return other;
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

    const RealVariable operator== (const RealVariable& other, const RealVariable& other1)
    {
        return other;
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

    ///////////////////////////Operators of ComplexVariable////////////////////////////

    const ComplexVariable operator+(const ComplexVariable& other, const ComplexVariable& other1)  
    {
        return other;
    }

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

    const std::complex<double> operator+ (std::complex<double> c, const double& num)
    {
        return c;
    }

    const std::complex<double> operator+ (const double& num, std::complex<double> c)
    {
        return c;
    }

    const ComplexVariable operator- (const ComplexVariable& other, const ComplexVariable& other1) 
    {
        return other;
    }

    const ComplexVariable operator- (const double& num, const ComplexVariable& compVar)
    {
        return ComplexVariable();
    }

    const ComplexVariable operator- (const ComplexVariable& compVar, const double& num)
    {
        return ComplexVariable();
    }

    const ComplexVariable operator- (const ComplexVariable& other, std::complex<double> c) 
    {
        return other;
    }


    const std::complex<double> operator- (std::complex<double> c, const double& num)
    {
        return c;
    }

    const std::complex<double> operator- (const double& num, std::complex<double> c)
    {
        return c;
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

    const std::complex<double> operator* (std::complex<double> c, const double& num)
    {
        return c;
    }

    const ComplexVariable operator* (const ComplexVariable&, const ComplexVariable&)
    {
        return ComplexVariable();

    }

    const ComplexVariable operator== (const ComplexVariable& other, const ComplexVariable& other1)
    {
        return other;
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
}