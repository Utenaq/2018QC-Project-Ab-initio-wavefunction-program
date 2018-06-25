#ifndef __header_CISD
#define __header_CISD


// The following lines are copied from src/basic_SCF.h
// Please add any necessary headers
#include "Eigen/Dense"
#include <unsupported/Eigen/CXX11/Tensor>

#include "basic_Const.h"
#include "basic_Tools.h"
#include "basic_Global.h"
#include "basic_Parser.h"
#include "basic_Integral.h"

using namespace std;
using namespace Eigen;

class CISD{
	
private:
	
	MatrixXd C;
	MatrixXd CI;    // This is the CI matrix to diagonize
	
	MatrixXd EigenSpace;
	VectorXd EigenValues;
	
	// Construct a CISD job from a C Matrix
	CISD(MatrixXd _C);
	
	// This returns the result of a CISD job
	MatrixXd getEigenSpace(){return this->EigenSpace;}
	VectorXd getEigenValues(){return this->EigenValues;}
	
};



#endif //header protecter