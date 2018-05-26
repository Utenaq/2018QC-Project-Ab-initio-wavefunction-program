#include <string>

class Molecule
{
    public:

        // Attribs
        int number_of_atoms;
        int total_charge;
        int *zvals;
        double **geometry;
        string point_group;

        // Methods
        void print_geometry();
        void rotate(double q1, double q2, double q3, double q4);
        void translate(double x, double y, double z);
        double bondlength(int atom1, int atom2);
        double angle(int atom1, int atom2, int atom3);
        double torsion(int atom1, int atom2, int atom3, int atom4);

        // Constructor, Destructor
        Molecule(int natom, int q, int *z, int **geom);
        ~Molecule();
};
