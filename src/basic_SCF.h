#ifndef _QC_include_basic_SCF_h_ //header guard
#define _QC_include_basic_SCF_h_

#include "../include/molecule.h"

// build the symmetric orthogonalization matrix S^(1/2) by diagnalizing the
// overlap matrix S
Matrix S12(Matrix S);

// initialize Fock matrix with default params (currently just H_{core})
Matrix initialize_guess();
Matrix initialize_guess(Matrix init_guess);

// calculate density matrix
Matrix calc_density_matrix(Matrix fock_matrix);

double calc_energy_elec(Matrix density_matrix, Matrix fock_matrix, Matrix core_hamiltonian);

// if we have little memory, save ERIs as matrix. if we have more, save it as
// 4-dimensional tensor.
Matrix calc_fock_matrix(Matrix core_hamiltonian, Matrix density_matrix, Matrix ERI);
Matrix calc_fock_matrix(Matrix core_hamiltonian, Matrix density_matrix, Tensor ERI);

double test_convergence(double etot_previous, double etot_current);


#endif
