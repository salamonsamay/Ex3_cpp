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
            return RealVariable(v1.getA(), v1.getB() + 1, v1.getC());}
        if(v1.getA() == 0 && v1.getB() == 0 && v1.getC()==0){
            return RealVariable(v2.getA(),v2.getB() + 1, v2.getC());}
        return RealVariable(v1.getA()+v2.getA(),v1.getB()+v2.getB(),v1.getC()+v2.getC());
    }

    const RealVariable operator+ (const double& c, const RealVariable& v)
    {
        if(v.getA()==0 && v.getB() == 0 && v.getC()==0){
            return RealVariable(v.getA(), v.getB() + 1,c + v.getC());}
        return RealVariable(v.getA(), v.getB(),c + v.getC());
    }

    const RealVariable operator+ (const RealVariable& v, const double& c)
    {
        if(v.getA()==0 && v.getB() == 0 && v.getC()==0){
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
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
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

    const RealVariable operator/ (const RealVariable& v, const double& b)
    {
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
            return RealVariable(v.getA(), 1/(b), v.getC());}
        return RealVariable(v.getA()/(b), v.getB()/(b), v.getC()/(b));
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
    const std::complex<double> solve(ComplexVariable v)
    {
        if((v.getB()==1 && v.getA()==0)|| (v.getB()<0 && v.getA()==0))
            return complex<double>(v.getC()+v.getComplex().real(),-v.getComplex().imag());
        if(v.getB()==0 && v.getA()!=0)
        {
            if(-v.getC()<0){return complex<double>(0,sqrt(v.getC()));}
            else return complex<double>(sqrt(-v.getC()));
        } 
        if(v.getB()!=0 && v.getA()==0) return complex<double>(-v.getC()/v.getB());
        if(v.getB()!=0 && v.getA()!=0)
        {
            if((-v.getC()/v.getB()) < 0)return complex<double>(0,sqrt(-v.getC()/v.getB()));
            else return complex<double>(sqrt(-v.getC()/v.getB()));
        } 
        throw std::overflow_error("Exception!!! not valid");
    }


    const ComplexVariable operator+(const ComplexVariable& v1, const ComplexVariable& v2)  
    {
        if(v2.A==0 && v2.B==0 && v2.C==0 && v1.A==0 && v1.B==0 && v1.C==0){
            return ComplexVariable(0,2,0,v1.comp.real()+v2.comp.real(),v1.comp.imag()+v2.comp.imag());}
        if(v2.A == 0 && v2.B == 0 && v2.C==0){
            return ComplexVariable(v1.A, v1.B+1, v1.C,v1.comp.real()+v2.comp.real(),v1.comp.imag()+v2.comp.imag());}
        if(v1.A == 0 && v1.B == 0 && v1.C==0){
            return ComplexVariable(v2.A,v2.B + 1, v2.C,v1.comp.real()+v2.comp.real(),v1.comp.imag()+v2.comp.imag());}
        return ComplexVariable(v1.A+v2.A,v1.B+v2.B,v1.C+v2.C,v1.comp.real()+v2.comp.real(),v1.comp.imag()+v2.comp.imag());
    }


    const ComplexVariable operator+ (const double& c, const ComplexVariable& v)
    {
        if(v.A==0 && v.B == 0 && v.C==0){
            return ComplexVariable(v.A,v.B+1,c+v.C,v.comp.real(), v.comp.imag());}
        return ComplexVariable(v.A, v.B, c + v.C,v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator+ (const ComplexVariable& v, const double& c)
    {
        if(v.A==0 && v.B == 0 && v.C==0){
            return ComplexVariable(v.A, v.B + 1,v.C + c,v.comp.real(),v.comp.imag());}
        return ComplexVariable(v.A, v.B, v.C + c,v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator+ (const ComplexVariable& v, std::complex<double> _complex)
    {
        if(v.A==0 && v.B == 0 && v.C==0){
            cout<<"real = "<<v.comp.real()+_complex.real()<<endl;
            cout<<"img = "<<v.comp.imag() + _complex.imag()<<endl;
            cout<<"a = "<<v.A<<"   b1 = "<<v.B<<"   c = "<<v.C<<endl;
            return ComplexVariable(v.A,v.B + 1,v.C,v.comp.real()+_complex.real(),v.comp.imag()+_complex.imag());}
        return ComplexVariable(v.A,v.B,v.C,v.comp.real()+_complex.real(),v.comp.imag()+_complex.imag());
    }


    const ComplexVariable operator+ (std::complex<double> _complex, const ComplexVariable& v)
    {
        if(v.A==0 && v.B == 0 && v.C==0){
            return ComplexVariable(v.A,v.B + 1,v.C,_complex.real()+v.comp.real(),_complex.imag()+v.comp.imag());}
        return ComplexVariable(v.A,v.B,v.C,_complex.real()+v.comp.real(),_complex.imag()+v.comp.imag());
    }


    const std::complex<double> operator+ (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real() + c, _complex.imag());
    }


    const std::complex<double> operator+ (const double& c, std::complex<double> _complex)
    {
        return std::complex<double>(c + _complex.real(), _complex.imag());
    }


    const ComplexVariable operator- (const ComplexVariable& v1, const ComplexVariable& v2) 
    {
        if(v2.A==0 && v2.B==0 && v2.C==0 && v1.A==0 && v1.B==0 && v1.C==0){
            return ComplexVariable(0,0,0,v1.comp.real()+v2.comp.real(),v1.comp.imag()+v2.comp.imag());}
        if(v2.A==0 && v2.B==0 && v2.C==0){
            return ComplexVariable(v1.A, v1.B - 1,v1.C,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());}
        if(v1.A==0 && v1.B==0 && v1.C==0){
            return ComplexVariable(v2.A,v2.B - 1, v2.C,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());}
        return ComplexVariable(v1.A-v2.A,v1.B-v2.B,v1.C-v2.C,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());
    }


    const ComplexVariable operator- (const double& c, const ComplexVariable& v)
    {
        if(v.getB()==0 && v.getC()==0){
            return ComplexVariable(v.A, 1, v.C-c,v.comp.real(),v.comp.imag());}
        return ComplexVariable(v.A, v.B, v.C-c,v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator- (const ComplexVariable& v, const double& c)
    {
        if(v.getB()==0 && v.getC()==0){
            return ComplexVariable(v.A, 1, v.C - c,v.comp.real(),v.comp.imag());}
        return ComplexVariable(v.A, v.B, v.C - c, v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator- (const ComplexVariable& v, std::complex<double> _complex) 
    {
        if(v.A==0 && v.B == 0 && v.C==0){
            return ComplexVariable(v.A, 1,v.C,v.comp.real()-_complex.real(),v.comp.imag()-_complex.imag());}
        return ComplexVariable(v.A,v.B,v.C,v.comp.real()-_complex.real(),v.comp.imag()-_complex.imag());
    }


    const std::complex<double> operator- (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real() - c, _complex.imag());
    }


    const std::complex<double> operator- (const double& c, std::complex<double> _complex)
    {
        return std::complex<double>(_complex.real() - c, _complex.imag());
    }


    const ComplexVariable operator/ (const ComplexVariable& v, const double& b)
    {
        if(v.A==0 && v.B==0 && v.C==0){
            return ComplexVariable(v.A, 1/(b), v.C, v.comp.real(),v.comp.imag());}
        return ComplexVariable(v.A/(b), v.B/(b), v.C/(b),v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator* (const double& b, const ComplexVariable& v)
    {
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
            ComplexVariable a(v.getA(), v.getB() + b, v.getC(),v.comp.real(),v.comp.imag());
            cout<<"a = "<<a.A<<"  b = "<<a.B<<"  c = "<<a.C<<endl;
            return ComplexVariable(v.getA(), v.getB() + b, v.getC(),v.comp.real(),v.comp.imag());}
        return ComplexVariable(b*v.getA(),b*v.getB(), b*v.getC(),v.comp.real(),v.comp.imag());
    }


    const ComplexVariable operator* (const ComplexVariable& v, const double& b)
    {
        if(v.getA()==0 && v.getB()==0 && v.getC()==0){
            return ComplexVariable(v.getA(), v.getB() + b, v.getC(),v.comp.real(),v.comp.imag());}
        return ComplexVariable(b*v.getA(),b*v.getB(), b*v.getC(),v.comp.real(),v.comp.imag());
    }


    const std::complex<double> operator* (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real()*c, _complex.imag()*c);
    }


    const ComplexVariable operator* (const ComplexVariable& v1, const ComplexVariable& v2) 
    {
        return ComplexVariable(v1.A*v1.A,v1.B*v2.B,v1.C+v2.C,v1.comp.real()*v2.comp.real(),v1.comp.imag()*v2.comp.imag());
    }


    const ComplexVariable operator== (const ComplexVariable& v1, const ComplexVariable& v2)
    {
        if(v2.A==0 && v2.B==0 && v2.C==0 && v1.A==0 && v1.B==0 && v1.C==0){
            return ComplexVariable(0,0,0,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());}
        if(v2.A==0 && v2.B==0 && v2.C==0){
            return ComplexVariable(v1.A, v1.B-1, v1.C,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());}
        if(v1.A==0 && v1.B==0 && v1.C==0){
            return ComplexVariable(v2.A,v2.B-1, v2.C,v2.comp.real()-v1.comp.real(),v2.comp.imag()-v1.comp.imag());}
        return ComplexVariable(v1.A-v2.A,v1.B-v2.B,v1.C-v2.C,v1.comp.real()-v2.comp.real(),v1.comp.imag()-v2.comp.imag());
    }


    const ComplexVariable operator== (const ComplexVariable& v,const double& c)
    {
        if(v.A==0 && v.B==0){
            return ComplexVariable(v.A,1,v.C-c,v.comp.real(),v.comp.imag());}
        return ComplexVariable(v.A, v.B, v.C-c,v.comp.real(),v.comp.imag());
    }        


    ComplexVariable operator^ (const ComplexVariable& v, const double& a)
    {
        if(a>2 || a==0) throw std::overflow_error("exp bigger then 2 or exp is zero");
        if(a==1) return ComplexVariable(0,1,0);
        return ComplexVariable(v.A+1, v.B, v.C,v.comp.real(),v.comp.imag());
    }


    ostream& operator<< (ostream& os, const ComplexVariable& compVar)
    {
        return os;
    }
}