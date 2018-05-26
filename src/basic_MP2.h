#ifndef _QC_include_basic_MP2_h_ //header guard
#define _QC_include_basic_MP2_h_

#include <string>

#include "../include/molecule.h"

int verbosity;

// read 2 electron integrals from file
Matrix integrals_preprocess_ERI(const char *ERI_filename);

// read the MO coefficients and MO energies from SCF calculation
Matrix read_MO_coefficients(const char *MO_coefficients_filename);
double *read_MO_energies(const char *MO_energies_filename);

// transform 2 electron integrals to MO basis with Noddy algorithm
// Note: By symmetry, we can calculate only part of it, the total time
// complexity should be N^5. If we compute all of it, it's N^8
Matrix calc_ERI_MO(Matrix ERI, Matrix MO_coefficients);

// calculate the MP2 energy
double calc_MP2_energy(Matrix ERI_MO, double *MO_energies);

void print_output(int verbosity);

#endif // header guard
