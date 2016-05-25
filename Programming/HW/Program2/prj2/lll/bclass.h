class bclass
{
	public:
		bclass();
		bclass(bclass* a_bclass);
		bclass(char* a_course_type, int a_course_code, char* a_course_name, int a_course_credit);
		void display_bclass();
	protected:
		char* course_type; // ex) CS, COMM
		int course_code; // ex) 163, 202
		char* course_name; // Data Structure
		int course_credit; // 4
		char grade; // A, B, C, D, F
		int gpa;
		int eff_flag; // 1 - CS, 0 - NON CS
};
