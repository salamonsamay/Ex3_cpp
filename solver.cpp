#include <stdexcept>
#include "solver.hpp"
#include <math.h>

namespace solver
{
    //solve for RealVariable
    const double solve(RealVariable v)
    {
        double a = v.getA(), b = v.getB(), c = v.getC(), ans;
        if(a == 0 && b == 0){throw std::overflow_error("There is no real solution");}
        else if((b * b - 4.0 * a * c) < 0){throw std::overflow_error("There is no real solution");}
        else if(a == 0){ans = (-c)/b;}
        else{ans = 0.5 * ((sqrt(b * b - 4.0 * a * c)) - b) / a;}
        return ans;
    }



    ///////////////////////////Operators of RealVariable////////////////////////////
    const RealVariable operator+ (const RealVariable& v1, const RealVariable& v2) 
    {
        if(v2.getA()==0 && v2.getB()==0 && v2.getC()==0 && v1.getA()==0 && v1.getB()==0 && v1.getC()==0){
            return RealVariable(0,2,0);}
        if(v2.getA() == 0 && v2.getB() == 0 && v2.getC()==0){
            //cout<<v1.getA()<<" "<<v1.getB() + 1<<" "<<v1.getC()<<endl;
            return RealVariable(v1.getA(), v1.getB() + 1, v1.getC());}
        if(v1.getA() == 0 && v1.getB() == 0 && v1.getC()==0){
            return RealVariable(v2.getA(),v2.getB() + 1, v2.getC());}
        return RealVariable(v1.getA()+v2.getA(),v1.getB()+v2.getB(),v1.getC()+v2.getC());
    }

    const RealVariable operator+ (const double& c, const RealVariable& v)
    {
        if(v.getB() == 0 && v.getC()==0){
            return RealVariable(v.getA(), v.getB() + 1,c + v.getC());}
        return RealVariable(v.getA(), v.getB(),c + v.getC());
    }

    const RealVariable operator+ (const RealVariable& v, const double& c)
    {
        if(v.getB() == 0 && v.getC()==0){
            return RealVariable(v.getA(), 1, v.getC() + c);}
        return RealVariable(v.getA(), v.getB(), v.getC() + c);
    }

    const RealVariable operator-(const RealVariable& v1, const RealVariable& v2) 
    {
        if(v2.getA()==0 && v2.getB()==0 && v2.getC()==0 && v1.getA()==0 && v1.getB()==0 && v1.getC()==0){
            return RealVariable(0,0,0);}
        if(v2.getA()==0 && v2.getB()==0 && v2.getC()==0){
            return RealVariable(v1.getA(), v1.getB() - 1, v1.getC());}
        if(v1.getA()==0 && v1.getB()==0 && v1.getC()==0){
            return RealVariable(v2.getA(),v2.getB() - 1, v2.getC());}
        return RealVariable(v1.getA()-v2.getA(),v1.getB()-v2.getB(),v1.getC()-v2.getC());
    }

    const RealVariable operator- (const double& c, const RealVariable& v)
    {
        if(v.getB()==0 && v.getC()==0){
            return RealVariable(v.getA(), 1, c - v.getC());}
        return RealVariable(v.getA(), v.getB(),c - v.getC());
    }

    const RealVariable operator- (const RealVariable& v, const double& c)
    {
        if(v.getB()==0 && v.getC()==0){
            return RealVariable(v.getA(), 1,v.getC() - c);}
        return RealVariable(v.getA(), v.getB(),v.getC() - c);
    }

    const RealVariable operator* (const double& b, const RealVariable& v)
    {
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
            return RealVariable(v.getA(), b + v.getB(), v.getC());}
        return RealVariable(b*v.getA(), b*v.getB(), b*v.getC());
    }

    const RealVariable operator* (const RealVariable& v, const double& b)
    {
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
            return RealVariable(v.getA(), v.getB() + b, v.getC());}
        return RealVariable(b*v.getA(),b*v.getB(), b*v.getC());
    }

    const RealVariable operator/ (const RealVariable& v, const double& c)
    {
        return RealVariable(v.getA(), v.getB()/(c), v.getC());
    }

    const RealVariable operator== (const RealVariable& v1, const RealVariable& v2)
    {
        if(v2.getA()==0 && v2.getB()==0 && v2.getC()==0 && v1.getA()==0 && v1.getB()==0 && v1.getC()==0){
            return RealVariable(0,0,0);}
        if(v2.getA()==0 && v2.getB()==0 && v2.getC()==0){
            return RealVariable(v1.getA(), v1.getB() - 1, v1.getC());}
        if(v1.getA()==0 && v1.getB()==0 && v1.getC()==0){
            return RealVariable(v2.getA(),v2.getB() - 1, v2.getC());}
        return RealVariable(v1.getA()-v2.getA(),v1.getB()-v2.getB(),v1.getC()-v2.getC());
    }

    const RealVariable operator== (const RealVariable& v, const double& c)
    {
        if(v.getA()==0 && v.getB()==0){
            return RealVariable(v.getA(), 1, v.getC() - c);}
        return RealVariable(v.getA(), v.getB(), v.getC() - c);
    }

    const RealVariable operator== (const double& c, const RealVariable& v)
    {
        if(v.getA()==0 && v.getB()==0){
            return RealVariable(v.getA(), 1, v.getC() - c);}
        return RealVariable(v.getA(), v.getB(), v.getC() - c);
    }

    RealVariable operator^(const RealVariable& v, const double& c)
    {
        if(c>2) throw std::overflow_error("exp bigger then 2");
        return RealVariable(1, v.getB(), v.getC());
    }

    ostream& operator<< (ostream& os, const RealVariable&)
    {
        return os;
    }




    ///////////////////////////Operators of ComplexVariable////////////////////////////

    //solve for ComplexVariable
    const std::complex<double> solve(ComplexVariable c)
    {
        return c.getComplex();
    }




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