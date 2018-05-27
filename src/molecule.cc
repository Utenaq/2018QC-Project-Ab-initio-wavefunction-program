#include "../include/molecule.h"
#include "../include/qcmath.h"

void print_geometry(){

}

void rotate(double q1, double q2, double q3, double q4){

}

void translate(double x, double y, double z){

}

double bondlength(int atom1, int atom2){
	
	return (geometry[atom1] - geometry[atom2]).modulus();

}

double angle(int atom1, int atom2, int atom3){
	
	Point _v = geometry[atom1] - geometry[atom2];
	Point _u = geometry[atom2] - geometry[atom3];
	
	return acos((_v*_u)/(_v.modulus()*_u.modulus()))*180/PI;
	
}

double torsion(int atom1, int atom2, int atom3, int atom4){

}


Molecule::Molecule(int natom, int q, int *z, Point* geom) {
	
	this->number_of_atoms = natom;
	this->total_charge = q;
	this->zvals = z;
	this->geometry = geom;
	
}

Molecule::Molecule(const char *z_matrix, int q) {

}

Molecule::Molecule(const char *z_matrix) {

}

// Load a molecule with give charge
Molecule::Molecule(const char *cartesian_filename, int q) {
		
	if (q < 0){
		// variable check: otherwise you can raise an error
	}
	total_charge = abs(q);
	
	FILE* fHandle = fopen(cartesian_filename, "r");
	if (fHandle == NULL){
		// or throw an exception 
		fprintf(stderr, "Cannot open input file.\n");
	}
	
	fscanf(fHandle, "%d", &(number_of_atoms));
	
	geometry = new Point[number_of_atoms];
	zvals = new int[number_of_atoms];
	
	for(int i = 0; i < number_of_atoms; ++i)
		fscanf(fHandle, "%d %lf %lf %lf", zvals+i, &(geometry[i].x), &(geometry[i].y), &(geometry[i].z));
	
	fclose(fHandle);
	
}

Molecule::Molecule(const char *cartesian_filename) {
	
	FILE* fHandle = fopen(cartesian_filename, "r");
	if (fHandle == NULL){
		// or throw an exception 
		fprintf(stderr, "Cannot open input file.\n");
	}
	
	fscanf(fHandle, "%d", &(number_of_atoms));
	
	geometry = new Point[number_of_atoms];
	zvals = new int[number_of_atoms];
	
	for(int i = 0; i < number_of_atoms; ++i)
		fscanf(fHandle, "%d %lf %lf %lf", zvals+i, &(geometry[i].x), &(geometry[i].y), &(geometry[i].z));
	
	fclose(fHandle);

}

Molecule::~Molecule()
{
    // free everything

    delete[] zvals;

    for(int i = 0; i < number_of_atoms; i++){
        delete[] geometry[i];
    }

    delete[] geometry;
}
