/* basic_CISD.cpp
 * Last update: Jun 26, 2018 00:56 China Standard Time by fieryd
 * 
 * This file implements the CISD procedure after a SCF job.
 * 
 * Note: Please also note to update the parser and the main function
 *       to allow CISD job assignment.
 */
 
#include "basic_CISD.h"

// The constructor of the job CISD. Matrix elements are evaluated at this stage
CISD::CISD(MatrixXd _C){
	
	this->C = _C;                   // Assign the parameter to the class member
	int nOrbital = C.size(); 	// Get the number of total orbitals
	
	int nDouble;                    // Number of double excitations
        int nSingle;
	int nExcitation = nDouble + nSingle + 1;
	
	CI.resize(nExcitation, nExcitation);
	
	// TODO: fill the CI matrix
	
	// TODO: Diagonize the matrix and assign the result to class members
	
	
	
}





