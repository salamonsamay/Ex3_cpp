#include <stdexcept>
#include "solver.hpp"
#include <math.h>

namespace solver
{

    //get an equation as RealVariable object, calc it and return the result as a double 
    const double solve(RealVariable v)
    {
        double a = v.getA(), b = v.getB(), c = v.getC();
        if(a==0 && b==0 && v.getStart()==true){   //there is no 'x'  throw exception
            throw std::overflow_error("There is no real solution");}
        if(v.getStart()==false) return -c;   //'x' coefficient is 1
        if(a==0 && b!=0) return (-c)/b;     //'x' coefficient is not '1' or '0'
        if((b * b - 4.0 * a * c) < 0){throw std::overflow_error("There is no real solution");}//neg sqrt
        return 0.5 * ((sqrt(b * b - 4.0 * a * c)) - b) / a;
    }


    //RealVariable + RealVariable
    const RealVariable operator+ (const RealVariable& v1, const RealVariable& v2) 
    {
        if(v1.start==false && v2.start==false){return RealVariable(0, 2, 0, true);} //x1&&x2 - first use
        if(v1.start==false && v2.start==true){return RealVariable(v2.A, v2.B+1, v2.C, true);}  //x1 - first use
        if(v1.start==true && v2.start==false){return RealVariable(v1.A, v1.B+1, v1.C, true);}  //x2 - first use
        return RealVariable(v1.A+v2.A, v1.B+v2.B, v1.C+v2.C, true);
    }

    //double + RealVariable
    const RealVariable operator+ (const double& c, const RealVariable& v)
    {
        if(v.start==false){return RealVariable(0, 1, c, true);}  //first use with the 'x'
        return RealVariable(v.A, v.B, c + v.C, true);
    }

    //RealVariable + double
    const RealVariable operator+ (const RealVariable& v, const double& c)
    {
        if(v.start==false){return RealVariable(0, 1, c, true);}  //first use with the 'x'
        return RealVariable(v.A, v.B, v.C + c, true);
    }

    //RealVariable - RealVariable
    const RealVariable operator-(const RealVariable& v1, const RealVariable& v2) 
    {
        if(v1.start==false && v2.start==false){return RealVariable(0,0,0,true);}   //first use for x1 && x2
        if(v1.start==false && v2.start==true){return RealVariable(v2.A,v2.B-1,v2.C,true);}  //for x1
        if(v1.start==true && v2.start==false){return RealVariable(v1.A,v1.B-1,v1.C,true);} //for x2
        return RealVariable(v1.A-v2.A,v1.B-v2.B,v1.C-v2.C,true);
    }

    //double - RealVariable
    const RealVariable operator- (const double& c, const RealVariable& v)
    {
        if(v.start==false){return RealVariable(0,1,c,true);}  // 'x' - first use
        return RealVariable(-v.A, -v.B, c - v.C, true);
    }

    //RealVariable - double
    const RealVariable operator- (const RealVariable& v, const double& c)
    {
        if(v.start==false){return RealVariable(0,1,-c,true);}  //'x' - first use
        return RealVariable(v.A, v.B, v.C - c, true);
    }

    //double * RealVariable
    const RealVariable operator* (const double& b, const RealVariable& v)
    {
        if(b==0) return RealVariable(0,0,0,true);   //0*x - reboot 'x'
        if(v.start==false){return RealVariable(0,b,0,true);}  //'x' - first use
        return RealVariable(b*v.A, b*v.B, b*v.C, true);
    }

    //RealVariable * double
    const RealVariable operator* (const RealVariable& v, const double& b)
    {
        if(b==0) return RealVariable(0,0,0,true);    //0*x - reboot 'x'
        if(v.start==false){return RealVariable(0,b,0,true);}   //'x' - first use
        return RealVariable(b*v.A, b*v.B, b*v.C, true);
    }

    //RealVariable / double
    const RealVariable operator/ (const RealVariable& v, const double& b)
    {
        if(b==0) throw std::overflow_error("cant div with zero");   // x/0 - illegal
        if(v.start==false){return RealVariable(0,1/b,0,true);}   //'x' - first use
        return RealVariable(v.A/b, v.B/b, v.C/b, true);
    }

    //RealVariable == RealVariable
    const RealVariable operator== (const RealVariable& v1, const RealVariable& v2)
    {
        if(v1.start==false && v2.start==false){return RealVariable(0,0,0,true);}    //x1&&x2 - first use 
        if(v1.start==false && v2.start==true){return RealVariable(v2.A,v2.B-1,v2.C,true);}   //x1 - first use
        if(v1.start==true && v2.start==false){return RealVariable(v1.A,v1.B-1,v1.C,true);}   //x2 - first use
        return RealVariable(v1.A-v2.A, v1.B-v2.B, v1.C-v2.C, true);
    }

    //RealVariable == double
    const RealVariable operator== (const RealVariable& v, const double& c)
    {
        if(v.start==false){return RealVariable(0,1,-c,true);}   //'x' - first use
        return RealVariable(v.A, v.B, v.C - c, true);
    }

    //double == RealVariable
    const RealVariable operator== (const double& c, const RealVariable& v)
    {
        if(v.start==false){return RealVariable(0,1,-c,true);}   //'x' - first use
        return RealVariable(v.A, v.B, v.C - c, true);
    }

    //RealVariable^double
    RealVariable operator^ (const RealVariable& v, const double& c)
    {
        if(c>2) throw std::overflow_error("exp bigger then 2");    //x^i, i>2  throw exception 
        if(c==0) return RealVariable(0,0,1,true);                   //x^0
        if(c==1 && v.start==false) return RealVariable(0,1,0,true);      
        if(c==1 && v.start==true) return RealVariable(v.A,v.B,v.C,true);
        if(v.start==false){return RealVariable(1,0,0,true);}        //'x' - first use
        return RealVariable(pow(v.A,2), 2*v.B, pow(v.C,2), true);
    }



////////////////////////////////////ComplexVariable///////////////////////////////////////////



    //get an equation as ComplexVariable object, calc it and return the result as a complex number 
    const std::complex<double> solve(ComplexVariable v)
    {
        double a = v.getA(), b = v.getB(), c = v.getC();
        if(a==0 && b==0 && v.getStart()==true){   //there is no 'y'  throw exception
            throw std::overflow_error("There 'y' solution");}
        if(v.getStart()==false) return complex<double>(-c,0);
        if((b==1 && a==0)|| (b<0 && a==0))    //y=c || b*y= c (b is neg)
            return complex<double>(-c+v.getComplex().real(),-v.getComplex().imag());
        if(b==0 && a!=0)          //a different from '0'
        {
            if(-c<0){return complex<double>(0,sqrt(c/a));} // change 'c' to pos for sqrt method 
            else return complex<double>(sqrt(-c/a));    
        } 
        if(b!=0 && a==0) return complex<double>(-c/b);    //b different from '0'
        if(b!=0 && a!=0)         //a and b not '0'
        {   
            if((-c/b) < 0)return complex<double>(0,sqrt(c/b));  
            else {return complex<double>(sqrt(-c/b));}
        } 
        throw std::overflow_error("Exception!!! not valid");
    }

////////////////////////////////////////////////////////////////////////////////////////
    //ComplexVariable + ComplexVariable
    const ComplexVariable operator+(const ComplexVariable& v1, const ComplexVariable& v2)  
    {
        if(v1.start==false && v2.start==false){
            return ComplexVariable(0,2,0,v1.comp.real()+v2.comp.real()
                                ,v1.comp.imag()+v2.comp.imag(),true);}
        if(v1.start==true && v2.start==false){
            return ComplexVariable(v1.A, v1.B+1, v1.C,v1.comp.real()+v2.comp.real()
                                ,v1.comp.imag()+v2.comp.imag(),true);}
        if(v1.start==false && v2.start==true){
            return ComplexVariable(v2.A,v2.B + 1, v2.C,v1.comp.real()+v2.comp.real()
                                ,v1.comp.imag()+v2.comp.imag(),true);}
        return ComplexVariable(v1.A+v2.A,v1.B+v2.B,v1.C+v2.C,v1.comp.real()+v2.comp.real()
                                ,v1.comp.imag()+v2.comp.imag(),true);
    }

    //double + ComplexVariable
    const ComplexVariable operator+ (const double& c, const ComplexVariable& v)
    {
        if(v.start==false){
            return ComplexVariable(v.A,v.B+1,c+v.C,v.comp.real(), v.comp.imag(),true);}
        return ComplexVariable(v.A, v.B, c + v.C,v.comp.real(),v.comp.imag(),true);
    }

    //ComplexVariable + double
    const ComplexVariable operator+ (const ComplexVariable& v, const double& c)
    {
        if(v.start==false){
            return ComplexVariable(v.A, v.B + 1,v.C + c,v.comp.real(),v.comp.imag(),true);}
        return ComplexVariable(v.A, v.B, v.C + c,v.comp.real(),v.comp.imag(),true);
    }

    //ComplexVariable + complex
    const ComplexVariable operator+ (const ComplexVariable& v, std::complex<double> _complex)
    {
        if(v.start==false){
            return ComplexVariable(v.A,v.B + 1,v.C,v.comp.real()+_complex.real()
                            ,v.comp.imag()+_complex.imag(),true);}
        return ComplexVariable(v.A,v.B,v.C,v.comp.real()+_complex.real()
                            ,v.comp.imag()+_complex.imag(),true);
    }

    //complex + ComplexVariable
    const ComplexVariable operator+ (std::complex<double> _complex, const ComplexVariable& v)
    {
        if(v.start==false){
            return ComplexVariable(v.A,v.B + 1,v.C,_complex.real()+v.comp.real()
                                ,_complex.imag()+v.comp.imag(),true);}
        return ComplexVariable(v.A,v.B,v.C,_complex.real()+v.comp.real()
                                ,_complex.imag()+v.comp.imag(),true);
    }

    //complex + double
    const std::complex<double> operator+ (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real() + c, _complex.imag());
    }

    //double + ComplexVariable
    const std::complex<double> operator+ (const double& c, std::complex<double> _complex)
    {
        return std::complex<double>(c + _complex.real(), _complex.imag());
    }

    //ComplexVariable - ComplexVariable
    const ComplexVariable operator- (const ComplexVariable& v1, const ComplexVariable& v2) 
    {
        if(v1.start==false && v2.start==false){
            return ComplexVariable(0,0,0,v1.comp.real()+v2.comp.real()
                            ,v1.comp.imag()+v2.comp.imag(),true);}
        if(v1.start==true && v2.start==false){
            return ComplexVariable(v1.A, v1.B - 1,v1.C,v1.comp.real()-v2.comp.real()
                            ,v1.comp.imag()-v2.comp.imag(),true);}
        if(v1.start==false && v2.start==true){
            return ComplexVariable(v2.A,v2.B - 1, v2.C,v1.comp.real()-v2.comp.real()
                            ,v1.comp.imag()-v2.comp.imag(),true);}
        return ComplexVariable(v1.A-v2.A,v1.B-v2.B,v1.C-v2.C,v1.comp.real()-v2.comp.real()
                            ,v1.comp.imag()-v2.comp.imag(),true);
    }

    //complex - ComplexVariable
    const ComplexVariable operator- (const double& c, const ComplexVariable& v)
    {
        if(v.start==false){
            return ComplexVariable(v.A, 1, v.C-c,v.comp.real(),v.comp.imag(),true);}
        return ComplexVariable(v.A, v.B, v.C-c,v.comp.real(),v.comp.imag(),true);
    }

    //ComplexVariable - double
    const ComplexVariable operator- (const ComplexVariable& v, const double& c)
    {
        if(v.start==false){
            return ComplexVariable(v.A, 1, v.C - c,v.comp.real(),v.comp.imag(),true);}
        return ComplexVariable(v.A, v.B, v.C - c, v.comp.real(),v.comp.imag(),true);
    }

    //ComplexVariable - complex
    const ComplexVariable operator- (const ComplexVariable& v, std::complex<double> _complex) 
    {
        if(v.start==false){
            return ComplexVariable(v.A, 1,v.C,v.comp.real()-_complex.real()
                                ,v.comp.imag()-_complex.imag(),true);}
        return ComplexVariable(v.A,v.B,v.C,v.comp.real()-_complex.real()
                                ,v.comp.imag()-_complex.imag(),true);
    }

    //complex + double
    const std::complex<double> operator- (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real() - c, _complex.imag());
    }

    //double - complex
    const std::complex<double> operator- (const double& c, std::complex<double> _complex)
    {
        return std::complex<double>(_complex.real() - c, _complex.imag());
    }

    //ComplexVariable / double
    const ComplexVariable operator/ (const ComplexVariable& v, const double& b)
    {
        if(v.start==false){
            return ComplexVariable(v.A, 1/(b), v.C, v.comp.real(),v.comp.imag(),true);}
        return ComplexVariable(v.A/(b), v.B/(b), v.C/(b),v.comp.real(),v.comp.imag(),true);
    }

    //double * ComplexVariable
    const ComplexVariable operator* (const double& b, const ComplexVariable& v)
    {
        if(b==0) return ComplexVariable(0, 0, 0, 0, 0, true);   //0*x - reboot 'y
        if(v.start==false){
            return ComplexVariable(0, b, 0, 0, 0, true);}
        return ComplexVariable(b*v.A,b*v.B, b*v.C,v.comp.real(),v.comp.imag(),true);
    }

    //ComplexVariable * double
    const ComplexVariable operator* (const ComplexVariable& v, const double& b)
    {
        if(b==0) return ComplexVariable(0, 0, 0, 0, 0, true);   //0*x - reboot 'y
        if(v.start==false){
            return ComplexVariable(0, b, 0, 0, 0, true);}
        return ComplexVariable(b*v.A,b*v.B, b*v.C,v.comp.real(),v.comp.imag(),true);
    }

    //complex * double
    const std::complex<double> operator* (std::complex<double> _complex, const double& c)
    {
        return std::complex<double>(_complex.real()*c, _complex.imag()*c);
    }

    //ComplexVariable * ComplexVariable
    const ComplexVariable operator* (const ComplexVariable& v1, const ComplexVariable& v2) 
    {
        return ComplexVariable(v1.A*v1.A,v1.B*v2.B,v1.C+v2.C,v1.comp.real()*v2.comp.real()
                            ,v1.comp.imag()*v2.comp.imag(),true);
    }

    //ComplexVariable == ComplexVariable
    const ComplexVariable operator== (const ComplexVariable& v1, const ComplexVariable& v2)
    {
        if(v1.start==false && v2.start==false){
            return ComplexVariable(0,0,0,v1.comp.real()-v2.comp.real()
                        ,v1.comp.imag()-v2.comp.imag(),true);}
        if(v1.start==true && v2.start==false){
            return ComplexVariable(v1.A, v1.B-1, v1.C,v1.comp.real()-v2.comp.real()
                        ,v1.comp.imag()-v2.comp.imag(),true);}
        if(v1.start==false && v2.start==true){
            return ComplexVariable(v2.A,v2.B-1, v2.C,v2.comp.real()-v1.comp.real()
                        ,v2.comp.imag()-v1.comp.imag(),true);}
        return ComplexVariable(v1.A-v2.A,v1.B-v2.B,v1.C-v2.C,v1.comp.real()-v2.comp.real()
                        ,v1.comp.imag()-v2.comp.imag(),true);
    }

    //ComplexVariable == double
    const ComplexVariable operator== (const ComplexVariable& v,const double& c)
    {
        if(v.start==false){
            return ComplexVariable(v.A,1,v.C-c,v.comp.real(),v.comp.imag(),true);}
        return ComplexVariable(v.A, v.B, v.C-c,v.comp.real(),v.comp.imag(),true);
    }        

    //ComplexVariable^double
    ComplexVariable operator^ (const ComplexVariable& v, const double& a)
    {
        if(a>2 || a==0) throw std::overflow_error("exp bigger then 2 or exp is zero");
        if(a==1) return ComplexVariable(0,1,0,v.comp.real(),v.comp.imag(),true);
        return ComplexVariable(v.A+1, v.B, v.C,v.comp.real(),v.comp.imag(),true);
    }

}