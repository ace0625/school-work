//CS202
//Assignment#2
//Hyunchan Kim
//degree.h
//=======================================================================
//This program is about Computer science major curriculum that shows you
//what classes you have to take before getting into CS program and your
//status with your grade and GPA by the classes you have taken so far.
//First, this program reads in the CS curriculum data from a text file
//and analyzes with your classes taken. 
//=======================================================================

//degree class derived by course LLL
//this class manages all classes and GPA
class degree: course_lll
{
	public:
		degree(); //default constructor
		void degree_handler(); //data handling 
		void add_sdata(int a_course_term, sclass* a_sclass);//adding a data by term
};
