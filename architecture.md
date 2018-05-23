### Architecture

1. Programming languages

    C++

    Python as glue

2. The following basic functions & classes need to be implemented.


        # max memory to be used
        # takes  : string, memory specification, like '10 GB'
        # returns: null
        QC.set_memory(string mem_spec)

        # Z matrix interpreter
        # takes  : string, geometry specified by Z-matrix, like """
        O
        H 1 0.96
        H 1 0.96 2 104.5
        """
        # returns: Geometry
        QC.geometry(string geometry)

        # evaluates energy, prints all information to file/stdout
        # takes  :  string, method specification, like 'ccsd(t)/aug-cc-pvdz',
                    Geometry
        # returns: float64
        QC.energy(method, geometry)
    
        # options
        # takes  : dict, other options
        # returns: null
        QC.set_options({'reference': 'uhf'})
    
        # OPTIONAL, calculates the Hessian
        # takes  : string, method specification, like 'scf/cc-pvdz'
        # returns: Array(float64)
        QC.frequency(method='method', etc.)
