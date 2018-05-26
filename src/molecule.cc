#include "../include/molecule.h"

void print_geometry(){

}

void rotate(double q1, double q2, double q3, double q4){

}

void translate(double x, double y, double z){

}

double bondlength(int atom1, int atom2){

}

double angle(int atom1, int atom2, int atom3){

}

double torsion(int atom1, int atom2, int atom3, int atom4){

}


Molecule::Molecule(int natom, int q, int *z, int **geom) {

}

Molecule(const char *z_matrix, int q) {

}

Molecule(const char *z_matrix) {

}

Molecule::Molecule(const char *filename, int q) {

}

Molecule::Molecule(const char *filename) {

}

Molecule::~Molecule()
{
    // free everything

    delete[] zvals;

    for(int i=0; i < number_of_atoms; i++){
        delete[] geometry[i];
    }

    delete[] geometry;
}
