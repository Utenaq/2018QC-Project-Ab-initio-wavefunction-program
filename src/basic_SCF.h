#ifndef _QC_include_basic_SCF_h_ //header guard
#define _QC_include_basic_SCF_h_

#include <string>

#include "../include/molecule.h"

int max_iter;
int max_memory;

// read single electron integrals from files
Matrix integrals_preprocess_S(const char *S_filename);
Matrix integrals_preprocess_T(const char *T_filename);
Matrix integrals_preprocess_V(const char *V_filename);

// read 2 electron integrals from file
Matrix integrals_preprocess_ERI(const char *ERI_filename);

// read initial guess, if any
Matrix read_initial_guess(const char *initial_guess_filename);

// build the symmetric orthogonalization matrix S^(1/2) by diagnalizing the
// overlap matrix S
Matrix calc_S_ortho(Matrix S);

// initialize Fock matrix with default params (currently just H_{core})
Matrix initialize_guess();
Matrix initialize_guess(Matrix init_guess);

// calculate density matrix
Matrix calc_density_matrix(Matrix fock_matrix, Matrix core_hamiltonian, Matrix S_ortho);

double calc_energy_elec(Matrix density_matrix, Matrix fock_matrix, Matrix core_hamiltonian);

// if we have little memory, save ERIs as matrix. if we have more, save it as
// 4-dimensional tensor.
Matrix calc_fock_matrix(Matrix core_hamiltonian, Matrix density_matrix, Matrix ERI);
Matrix calc_fock_matrix(Matrix core_hamiltonian, Matrix density_matrix, Tensor ERI);

// at end of each iteration, test if convergence is achived
bool test_convergence(double etot_previous, double etot_current);

// if convergence achived, stop the iteration and print output
// if in verbose mode, print information regardless of convergence or not
void print_output(bool convergence, bool verbosity);

// if the iteration process have exceeded the max iteration limit, then stop
// and print failure message
void print_failure(string reason);

#endif // header guard
