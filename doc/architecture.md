### Architecture

1. Programming languages

    C++

    Python as glue

2. The following basic functions & classes need to be implemented.

2.1. The following functions are for PYTHON

        @functions
        @IMPLICIT
            raise: ParamsError, insufficient params, or type assertion failure
            raise: MaxMemExceeded


        # OPTIONAL, max memory to be used
        set_memory(mem_spec)
        # takes  :  string,      mem_spec: memory specification, like '10 GB'
        # returns:  float64,     memory amount, in absolute number.
        # raises :  ValueError,  unacceptable unit, or any other nonsense.


        # Z matrix interpreter
        create_molecular_with_Z_matrix_string(z_matrix)
        # takes  :  string,      z_matrix: geometry specified by Z-matrix
        # returns:  Molecule,    instance of class Molecule
        # raises :  ValueError,  incorrect format, or any other nonsense


        # evaluates single point energy, prints all information to file/stdout
        energy(method, molecule, restart_file)
        # takes  :  string,      method: method specification, like 'ccsd(t)/aug-cc-pvdz',
        #           Molecule,    molecule: molecule to calculate
        #           FileIO,      restart_file: the file for calculation restart
        # returns:  float64,     energy
        #           Wavefunction,array of instance of wavefunctions
        # raises :

        # options
        set_global_options(options_dict)
        # takes  :  dict,        options_dict: options, like {'reference': 'uhf'}
        # returns:  None
        # raises :


        # OPTIONAL, calculates the Hessian
        hessian(method, molecule)
        # wrappers: frequencies()
        # takes  :  string,      method: method specification, like 'scf/cc-pvdz'
        #           Molecule,    molecule: molecule to calculate
        # returns:  Matrix(float64)
        # raises :


        # OPTIONAL, calculates frequencies
        @frequencies
        hessian()


2.2. The following classes are for PYTHON


        # basic molecule class
        Molecule
        # Bases  :  Object
        # Attribs:  @Cpp_class_Molecule
        # Methods:  @Cpp_class_Molecule

        # basic wavefunction class
        Wavefunction
        # Bases  :  Object
        # Attribs:  @Cpp_class_Wavefunction
        # Methods:  @Cpp_class_Wavefunction


2.3. [TODO] The following functions are for C++

        # Matrix Eigenvalues
        eigen()
        # (just use OpenBLAS)

        # Evaluate
        nuclear_repulsion_energy()
        one_e_integrals()
        two_e_integrals()
        orthogonalization_matrix()
        init_guess()
        SCF_energy()
        Fock()
        density()
        test_convergence()
        MP2_energy()


2.4. [TODO] The following classes are for C++

        class Molecule
        Construct:  natom, total_charge, zvals, geom
                    from_z_matrix, total_charge
                    from_z_matrix (total_charge = 0)
                    from_file, total_charge
                    from_file (total_charge = 0)

        Attribute:  int number_of_atoms;
                    int total_charge;
                    int \*zvals;
                    double \*\*geometry;
                    string point_group;

        Mothods:    // print geometry in plain text
                    void print_geometry();

                    // rotate the molecule with a set of quaternions
                    void rotate(double q1, double q2, double q3, double q4);

                    // translate the molecule with a vector
                    void translate(double x, double y, double z);

                    // measure the bondlength between 2 atoms
                    double bondlength(int atom1, int atom2);

                    // measure the angle between two bond
                    double angle(int atom1, int atom2, int atom3);

                    // measure the torsion (dihedral angle)
                    double torsion(int atom1, int atom2, int atom3, int atom4);

        class Wavefunction
        {
            public:

                //Attribs


        };



3. units: a.u. for all internal units. When output, the unit must be explicitly
appended after the number. For input files, use a.u. for now.

4. Input formats

        v0.1

            Cartesian: (unit: a.u.)
                [Number of atoms]
                [Z value of atom 1] [X of atom 1]   [Y of atom 1]   [Z of atom 1]
                [Z value of atom 2] [X of atom 2]   [Y of atom 2]   [Z of atom 2]
                ...
                [Z value of atom N] [X of atom N]   [Y of atom N]   [Z of atom N]

            Z matrix: (unit: a.u.)
                We just use the standard form of Z matrices

            // Single electron integrals

            S (AO Basis Overlaps)
                1   1   S_{11}
                2   1   S_{21}
                2   2   S_{22}
                3   1   S_{31}
                ...

            T (Kinetic Energy)
                1   1   T_{11}
                2   1   T_{21}
                2   2   T_{22}
                3   1   T_{31}
                ...

            V (N-E attraction integrals)
                1   1   V_{11}
                2   1   V_{21}
                2   2   V_{22}
                3   1   V_{31}
                ...

            // Two electron integrals

            ERI (electron repulsion integrals)
            // Note: the ERIs obey the symmetric rule as
            //   (ij|kl) = (ij|lk) = (ji|kl) = (ji|lk)
            // = (kl|ij) = (lk|ij) = (kl|ji) = (lk|ji)
            // so we only need to store 1/8 of the 4-dimensional tensor
            // Note: When performing calculation, we recommend that the full
            // tensor being constructed in memory to facilitate lookups
                1     1     1     1    (11|11)
                2     1     1     1    (21|11)
                2     2     1     1    (22|11)
                2     1     2     1    (21|21)
                2     2     2     1    (22|21)
                2     2     2     2    (22|22)
                3     3     1     1    (33|11)
                ...


5. Output formats

        v0.1
            S (AO Basis Overlaps)
                1   1   S_{11}
                2   1   S_{21}
                2   2   S_{22}
                3   1   S_{31}
                ...

            T (Kinetic Energy)
                1   1   T_{11}
                2   1   T_{21}
                2   2   T_{22}
                3   1   T_{31}
                ...

            V (N-E attraction integrals)
                1   1   V_{11}
                2   1   V_{21}
                2   2   V_{22}
                3   1   V_{31}
                ...

            // Two electron integrals

            ERI (electron repulsion integrals)
            // Note: the ERIs obey the symmetric rule as
            //   (ij|kl) = (ij|lk) = (ji|kl) = (ji|lk)
            // = (kl|ij) = (lk|ij) = (kl|ji) = (lk|ji)
            // so we only need to store 1/8 of the 4-dimensional tensor
            // Note: When performing calculation, we recommend that the full
            // tensor being constructed in memory to facilitate lookups
                1     1     1     1    (11|11)
                2     1     1     1    (21|11)
                2     2     1     1    (22|11)
                2     1     2     1    (21|21)
                2     2     2     1    (22|21)
                2     2     2     2    (22|22)
                3     3     1     1    (33|11)
                ...

            HF Energy
            molecular orbitals ...
