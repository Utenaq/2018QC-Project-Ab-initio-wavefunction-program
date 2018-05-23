### Architecture

1. Programming languages

    C++

    Python as glue

2. The following basic functions & classes need to be implemented.

2.1. The following functions are for PYTHON

        @functions
        IMPLICIT
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
        #           Wavefunction,array of instance of wavefunctionss
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
        @hessian
        frequencies()


2.2. The following classes are for PYTHON
        #classes


        # basic molecule class
        Molecule
        # Bases  :  Object
        # Attribs:

        # Methods:




        # basic wavefunction class
        Wavefunction
        # Bases  :  Object
        # Attribs:

        # Methods:





2.3. The following functions are for C++

[TODO]

2.4. The following classes are for C++

[TODO]
