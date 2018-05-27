#ifndef _QC_include_basic_CCSD_h_ //header guard
#define _QC_include_basic_CCSD_h_

#include "../include/molecule.h"

Tensor<4> spatial_to_spin_orbital_integrals(Matrix nmo);

Matrix calc_spin_orbital_fock_matrix(Tensor<4> spin_orbital_integrals);

Tensor<2> initialize_T1(Tensor<4> spin_orbital_integrals);
Tensor<4> initialize_T2(Tensor<4> spin_orbital_integrals);


Tensor<4> calc_effective_doubles(Tensor<4> spin_orbital_integrals);

Tensor<2> calc_F_intermediate(Tensor<4> spin_orbital_integrals);
Tensor<4> calc_W_intermediate(Tensor<4> spin_orbital_integrals);


Tensor<2> calc_T1(Tensor<2> T1, Tensor<4> T2, Tensor<4> tau, Tensor<2> F, Tensor<4> spin_orbital_integrals);

Tensor<4> calc_T2(Tensor<2> T1, Tensor<4> T2, Tensor<4> tau, Tensor<2> F, Tensor<4> W, Tensor<4> spin_orbital_integrals);

double calc_CC_corr_energy(Tensor<2> T1, Tensor<4> T2, Tensor<4> spin_orbital_integrals);

// at end of each iteration, test if convergence is achived
bool test_convergence_Delta(double e_previous, double e_current);
// bool test_convergence_RMS(Tensor<2> T1, Tensor<4> T2);

// if convergence achived, stop the iteration and print output
// if in verbose mode, print information regardless of convergence or not
void print_output(bool convergence, int verbosity);

// if the iteration process have exceeded the max iteration limit, then stop
// and print failure message
void print_failure(string reason);

#endif //header guard
