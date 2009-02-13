////////////////////////////////////////////////////////////////
/*! \file 
 *  \brief Declares class NewtonFitterGSL
 *
 * Author: Benno List
 * Last update: $Date: 2008-11-24 11:01:01 $
 *          by: $Author: beckmann $
 * $Date: 2008-11-24 11:01:01 $
 * $Author: beckmann $
 *
 * \b Changelog:
 * - 25.9.08 BL: Added some documentation
 *
 * \b CVS Log messages:
 * - $Log: not supported by cvs2svn $
 * - Revision 1.1  2008/10/16 08:13:36  blist
 * - New versions of OPALfitter and Newtonfitter using GSL
 * -
 * - Revision 1.3  2008/09/26 07:30:53  blist
 * - Added documentation,
 * - removed bug in Newtonfitter (could not handle fixed parameters correctly)
 *
 */ 

#ifndef __NEWTONFITTERGSL_H
#define __NEWTONFITTERGSL_H

#include "BaseFitter.h"

#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_permutation.h>
#include <gsl/gsl_eigen.h>

// Class NewtonFitterGSL
/// A kinematic fitter using the Newton-Raphson method to solve the equations

class NewtonFitterGSL : public BaseFitter {
  public:
    /// Constructor
    NewtonFitterGSL();
    /// Virtual destructor
    virtual ~NewtonFitterGSL();
    
    /// The fit method, returns  the fit probability
    virtual double fit();
    
    /// Get the error code of the last fit: 0=OK, 1=failed
    virtual int getError() const;
    
    /// Get the fit probability of the last fit
    virtual double getProbability() const;
    /// Get the chi**2 of the last fit
    virtual double getChi2() const;
    /// Get the number of degrees of freedom of the last fit
    virtual int    getDoF() const;
    /// Get the number of iterations of the last fit
    virtual int  getIterations() const;

    /// Get the number of hard constraints of the last fit
    virtual int    getNcon() const;
    
    /// Get the number of soft constraints of the last fit
    virtual int    getNsoft() const;
    
    /// Get the number of all parameters of the last fit
    virtual int    getNpar() const;
    
    /// Get the number of unmeasured parameters of the last fit
    virtual int    getNunm() const;

    /// Initialize the fitter
    virtual bool initialize();
  
  protected:
    /// Calculate the chi2
    virtual double calcChi2();
    
    /// Calculate the vector dx to update the parameters; returns fail code, 0=OK
    int calcDx () const;
    
    /// Calculate the vector dx to update the parameters; returns fail code, 0=OK
    int calcDxSVD () const;
    
    /// Print a Matrix M and a vector y of dimension idim
    void printMy (double M[], double y[], int idim);
    
    enum {NPARMAX=50, NCONMAX=10, NUNMMAX=10};
    
    int npar;      ///< total number of parameters
    int ncon;      ///< total number of hard constraints
    int nsoft;     ///< total number of soft constraints
    int nunm;      ///< total number of unmeasured parameters
    int ierr;      ///< Error status
    int nit;       ///< Number of iterations

    double fitprob;   ///< fit probability
    double chi2;      ///< final chi2
    
    static void ini_gsl_permutation (gsl_permutation *&p, unsigned int size);
    static void ini_gsl_vector (gsl_vector *&v, int unsigned size);
    static void ini_gsl_matrix (gsl_matrix *&m, int unsigned size1, unsigned int size2);
    
    static void debug_print (gsl_matrix *m, const char *name);
    static void debug_print (gsl_vector *v, const char *name);

  private:
    gsl_vector *x;
    gsl_vector *dx;
    gsl_vector *y;
    gsl_vector *perr;
    gsl_vector *v1;
    gsl_vector *v2;
    gsl_vector *Meval;
  
    gsl_matrix *M;
    gsl_matrix *M1;
    gsl_matrix *Mevec;

    gsl_permutation *permM;
    gsl_eigen_symmv_workspace *ws; 
    unsigned int wsdim;
    unsigned int idim;
};

#endif // __NEWTONFITTERGSL_H