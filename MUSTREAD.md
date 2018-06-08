# everyone should know  
* everyone should read the basic_Global.h file, where defines all class our modeling needs.  
* the original point.h molecule.h (mainly contributed by Da Teng), I suggest to merge them in the basic_Global.h 
file (though most of the function we don't used in SCF calculation).    
* the saving of integration, if anyone interested about it, he can write it.  
* the general integral function I have completed some, but V & ERI integration is not completed, they are all 
under annonation block. @Zhi Zi, I think you can do better.   
* there still some problem as discribed below. It seems we need to judge the degenerate? or may need DIIS, and 
certainly the open shell RHF is in need.    


# compile
in ./ directory, by command `make`, or in this child directory ./src type `make`. The excutable file will be 
generated in the ./src directory. Note your computer should be LINUX platform because the default compiler is g++.  
  
# usage
* \[ main -h \], help information
* \[ main -d \], to calculate HeH+ example by default.
* \[ main -f *.gjf\], read from a file with the Gauss09's format (or with .hif[^format] format, it's similiar 
with the .gjf format).  
[^format]: this file-format is called Heisenberg Input file .hif, which is similiar to Gauss's <>.gjf file, but 
'%' just stand for an annotation. Similiar, its output file is called Heisenberg output file type (.hof).  
  
# tests and problems
the closed shell of s type Hatree-Fock calculation is fine. But it can not treat with open shell RHF equation 
now or UHF equation. Later will add them.  
	    
		
		// you can run the following command under ./src
		
		/*
		list of commands of some test examples
		
		| commands                          | what the procedure does                                       |
		|-----------------------------------|---------------------------------------------------------------|
		| ./main -h					        | get help information                                          |
		| ./main -d                         | run HeH+ default test. (see details in ../test/HeH.gjf)       |
		| ./main -f ../test/HeH.gjf         | run HeH+ test. (see details in ../test/HeH.gjf)               |
		| ./main -f ../test/H2.gjf          | run H2 test. (see details in ../test/H2.gjf)                  |
		| ./main -f ../test/H.gjf           | run H test. (see details in ../test/H.gjf)                    |
		| ./main -f ../test/H4_D4.gjf       | run H4 with D4 symmetry (see details in ../test/H4_D4.gjf)    |
		| ./main -f ../test/H4_nosym.gif    | run H4 without symmetry (see details in ../test/H4_nosym.gjf) |
		
		
		list of results
			    
		|test   |result                     | remarks                                                       |  
		|-------|---------------------------|---------------------------------------------------------------|  
		| H2    | consistent with Gauss     | closed-shell RHF works well                                   |  
		| HeH+  | consistent with Gauss     | closed-shell RHF works well                                   |  
		| H     | incorrect                 | open-shell RHF / UHF needed[^a]                                |  
		| CH4   | (no result)               | integration fucntion of s-p/p-p type is needed                |  
		| H4    | incorrect                 | open shell & degenerate problem[^b]                            |  
		
		
		[^a]: the test of H, is not correct.(though we not we just diagonize the H matrix to obtain the correct 
		result, but the RHF equation of closed shell is not fit to treat it. It's need open-shell RHF SCF method.)  
		[^b]: the test of H4, has convergence problem with oscillation ! It is not a reason to need DIIS, but a 
		degenerate problem.(or to say, there are degenerate orbitals in the molecule (H4) ! So the occupation of 
		orbitals should be treat more carefully! P.S., according to Jahn-Teller theorem, non-linear molecule of 
		some symmetry must be degenerate, this means the H4 molecule of D4 symmetry must be openshell and 
		degenegrate!). If we distory D4 symmetry to calculate H4 again, we will find it meets convergence!  
		
		*/ 


  
# files structure
## new structure  
new structure with few files, mainly contains six files, and move them a copy to tyro directory now. From them,
 it's easy to understand how does this procedure work!  
#### basic_Const.h
just as the old file structure.  
* basic math and physics constants, mainly a copy from Pysi4 with little modification.  
* \[static const char*\] _elements\_label_  
* \[static const char*\] _elements\_mass_  

#### basic_Tools.h
just as the old file structure, mainly process the strings.  
>>
* _tempalate \<class T\> int getArrayLen(T& array)_  
* _string& trim(string &s)_ 
* _string& replace\_recursive(string& str, const string& old\_value, const string& new\_value)_  
* _string& replace\_distinct(string& str, const string& old\_value, const string& new\_value)_  
  
  
#### basic_Global.h
all modeling class of the program are put into this file:  
here defines:
* class Point  
> __with members__  
>>
_string name_  
_double x_  
_double y_  
_double z_  
  
  
> __with methods__  
>>
_double norm()_  
_double norm2()_  
_Point ref\_Point(Point& A)_  
_double ref\_norm(Point A)_  
_double ref\_norm2(Point A)_  
_friend double dist\_AB(Point A, Point B)_  
_friend double dist\_AB2(Point A, Point B)_  
  
  
> __with operators__  
>>
_+_  
_-_  
_*_  
_*_  
_<<_  
  
  
* class Orbital: inherit from Point  
> __extra members__  
>>
_int L_  
_int M_  
_int N_  
_double alpha_  
  
  
> __extra methods__  
>>
_int set\_Alpha(double aa)_  
_int set\_LMN(int ll,int mm, int nn)_  
_int set\_XYZ(double xx, double yy, double zz)_  
_int set\_XYZ(Point P)_  
_Point& get\_Point()_  
_int get\_LMN(int& ll,int& mm, int& nn)_  
_int get\_XYZ(double& xx, double& yy, double& zz)_  
_int conv\_AUnit()_  
_double normGTO()_  
_double normGTO( double a)_  
  
  
> __with operators__  
  
* class Orbital_cgto: inherit from Orbital  
> __extra members__  
>>
_int cn_  
the number of (Gauss) Orbital in this contracted GTO.  
_int* coeffs_  
list of coefficients.  
_int* alphas_  
list of exponents.(to be abandoned)  
_Orbital* gtos_  
list of Orbital objects.  
  
  
> __extra/overload methods__  
>>
_int set\_Cgto(int num)_  
_int get\_CA(int idx, double& cc, double& aa)_  
_int set\_LMN(int ll,int mm, int nn)_  
_int set\_XYZ(double xx, double yy, double zz)_  
_int set\_XYZ(Point P)_  
_int conv\_AUnit()_  
_int get\_BohrL()_  
_double normGTO(int k)_  
  
  
> __with operators__  

* class Atom: inherit from Point  
> __extra members__  
>>
_int znum_   
z-number of the atom.  
_double mass_  
the mass of atom (1mol C12 = 12g).  
_int perd_  
_int fmly_  
_int indx_  
_int frag_  
_int ncgto_  
_Orbital\_cgto* cgto_  
  
  
> __with methods__  
>>
_Point& get\_Point()_
_int get\_Point(Point& P)_  
_int read\_Atom(string line)_  
_int link\_Info(string my__name)_  
_int set\_Basis(string my__bname, int mysplit, int mynumcs[], int myidxcs[])_  
_int set\_Basisspace(int split, int numcs[], int idxcs[])_  
_int read\_Basis( fstream& input)_  
_int conv\_AUnit()_  
  
  
> __with operators__  
>>
_<<_  
  
  

* class Molecule: inherit from Atom  
> __extra members__  
>>
_int Natom_  
_int iatom_  
_Atom* atoms_  
  
  
> __extra methods__  
(none)  
> __with operators__  
(none)  
* class System: inherit from Molecule  
> __extra members__  
>>
_int Nmol_  
_int imol_  
_Molecule moles_  
_string Bname_  
_int Nbasis_  
_int split_  
_int* numcs_  
_int* idxcs_  
_int* idmap_  
  
  
> __extra/overload methods__  
>>
_int set\_Natom(int num)_  
_int read\_Atom(string line)_  
_int set\_Basis(string my\_bname)_  
_int set\_Map()_  
_Orbital\_cgto& OrbC(int &idx)_  
_int count\_Znum()_  
_int conv\_AUnit()_  
_int solve\_Top(string line)_  
  
  
> __with operators__  
>>
_<<_  
_\[\]_  
  
  
#### illustration of basic_Global.h
			    
			#################################################################################  
			#                                                                               #  
			#       [ note: ----- inherit, ===== list, =-=-= inherit & list ]               #  
			#                                                                               #  
			#       Point ----- Orbital =-=-= Orbital_cgto                                  #  
			#          '                     //                                             #  
			#               '               //                                              #  
			#                    '         //                                               #  
			#                         ' Atom  =-=-=-=-= Molecule =-=-=-= System             #  
			#                                                                               #  
			#################################################################################  
	    
  
#### basic_Parser.h
a parser of reading input file.  
* HTask class:  
> __with members__  
_string Hiffile_  
location and name of input file.  
_string Logfile_  
location and name of output file.  
_int Maxmem_  
max memory to be used (not used for now).  
_string Job_  
type of job (now only support sp; scan, opt, freq, qm/mm are not supported now).  
_string Method_  
type of method (now only support closed-shell RHF SCF; 
open-shell RHF, UHF, DFT, MP2, CISD, CCSD are not supported now).  
_string Basis_  
type of basis, such as 6-31g (should be lowercase! later will add a convector).  
_string Title_ 
title, optional.    
_int Charge_  
charge of system.  
_int Smulti_  
spin-multiplicity of system.  
_System Sys_  
object of system.  
_int Natom_  
total atoms of system.  
_int Nelec_
total electrons of system.  
_int Nbasis_
total (contracted) orbital of system.  
  
> __with methods__  
_int set\_IO(string Hiffile, string logfile)_  
setup input file and ouput file.  
_int set\_Job(string job, string method, string basis)_  
setup job, methed and basis for the task.  
_int read\_Predo()_  
pre-read the input file and determine the atom number of the system.  
_int read\_Task()_  
read each line of input file, and do analyzation.  
_int Taskparser(string term)_  
a function analyize a line-string, is the job parser!  

> __with overload operator__  
_<<_  

#### basic_Integral.h  
the integration function. new type of s-p/p-p integration method add in the annotation block (the V & ERI of
them are still not compleled. next only list the completed functions:)  
> __with function__  
_double integral\_S(Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2)_  
_double integral\_ERI(  Orbital\_cgto& cgto1, Orbital\_cgto& cgto2, Orbital\_cgto& cgto3, Orbital\_cgto& cgto4)_  
_double integral\_T(  Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2)_  
_double integral\_V( 	Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2, Atom& P )_  
_double integral\_S\_sstype(Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2)_  
_double integral\_ERI\_sstype(  Orbital\_cgto& cgto1, Orbital\_cgto& cgto2, Orbital\_cgto& cgto3, Orbital\_cgto& cgto4)_  
_double integral\_T\_sstype(  Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2)_  
_double integral\_V\_sstype( 	Orbital\_cgto& cgto1,  Orbital\_cgto& cgto2, Atom& P )_  

#### basic_SCF.h
the self-consistent field iteration procedure.  
* class SCFer  
> __with members__  
_ofstream report_   
_HTask* tasklink_  
_System* SYSlink_  
_string Scf\_name_  
_int nsz_  
_int nocc_  
_double threshold_  
_MatrixXd 	eigen\_S_  
_MatrixXd 	eigen\_H_  
_MatrixXd	eigen\_G_  
_MatrixXd	eigen\_J_  
_MatrixXd	eigen\_K_  
_Tensor4D	eigen\_ERI_  
_MatrixXd	eigen\_F_  
_MatrixXd 	eigen\_C_  
_MatrixXd 	eigen\_P_  
_MatrixXd	eigen\_X_  
_MatrixXd	eigen\_Y_  
_MatrixXd	eigen\_Fp_  
_MatrixXd	eigen\_Cp_  
_bool		do\_loop_  
_VectorXd	eigen\_E_  
_double		E_  
_double		E\_old_  
_MatrixXd	eigen\_P\_old_  
_int* 		list_  
> __with methods__  
_int set\_Threshold(double myeps)_  
_int set\_Space(HTask& HT)_  
allocate the matrix size.  
_int calc\_SHERI(System &SYS, MatrixXd &S, MatrixXd &H, Tensor4D &G)_  
calculate the H, S, ERI integrations.  
_int guess\_P()_  
guess P (density matrix) by a pre-SCF using H as F (Fock Matrix) directly.  
_int calc\_XY()_  
calculate the transform matrix, X=S^(-1/2), Y=S^(1/2).  
_int calc\_Fock()_  
calculate Fock matrix from H, ERI and P (density) matrix. By the way, calculate F'=X`*F*X .  
_int calc\_Cprim()_  
calculate the solution of F'C'= e C' .   
_int tr\_Cprim2C()_  
from C' calculate C, by C=X*C' .  
_int calc\_PE()_  
from C, calculate P, then from P and eigenvalues of F' calculate E (and add nuclues exclusion energy!).  
_int check\_Loop(int cnt)_  
check if it is consistent with itself. (SCF)  
_int report\_SCF()_  
print the SCF information.  
_double get\_NE()_  
calculate nuclues exclusion energy.  
_double m\_Diff(MatrixXd &M, MatrixXd &N)_  
give a kind of norm of matrix. (the elements with max absolution).  
_int loop\_SCF()_  
control total SCF cycles.  
  
# the process of the procedure
1. _main_ read the arguments, pass to Parser(or Task object).  
2. Parser preread the file, determine how many atoms it contains. And pass to creat object.  
3. Parser read file, initialize task and system parameters.  
4. Parser deals with the modeling of basis, Creating System/Atom object, and initializing basis with coefficients 
and exponents.  
5. Pass Task to SCFer, SCFer creat the array space.  
6. Do integration of S, H, ERI integration.  
7. Geuss a density matrix P (just use H to from a P).
8. calculate Fock matrix and Fock'.
9. calculate Coefficient Matrix C'.
10. transfer C' to C.
11. calculate density matrix P and Energy E.
12. Judge whether converge of E or P, otherwise back to calculation Fock matrix again using new P.
  
  
# Acknowledgement 
to Prof. W.J. Liu,  and my teammates in the Quantum Chemistry class.  


