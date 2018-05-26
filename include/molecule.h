#ifndef _QC_include_molecule_h_ //header guard
#define _QC_include_molecule_h_

#include <string>

typedef struct Tpoint{
	double x,y,z;
} Point;

class Molecule
{
    public:

        // Attribs
        int number_of_atoms;
        int total_charge;
        int *zvals;
        Point *geometry;
        string point_group;

        // Methods
        void print_geometry();
        void rotate(double q1, double q2, double q3, double q4);
        void translate(double x, double y, double z);
        double bondlength(int atom1, int atom2);
        double angle(int atom1, int atom2, int atom3);
        double torsion(int atom1, int atom2, int atom3, int atom4);

        // Constructor, Destructor
        // Overloading Molecule
        Molecule(int natom, int q, int *z, Point* geom);
        Molecule(const char *z_matrix, int q);
        Molecule(const char *z_matrix);
        Molecule(const char *cartesian_filename, int q);
        Molecule(const char *cartesian_filename);
        ~Molecule();
};

#endif //header guard
