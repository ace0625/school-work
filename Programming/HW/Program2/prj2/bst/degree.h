class snode: public sclass
{
	public:
		snode(); // snode constructor
		snode(sclass* a_sclass);
		snode(char* a_course_type, int a_course_code, int a_course_term, char a_course_grade);
		~snode(); // snode destructor
		snode *& go_next(); // LLL snode move to left
		bool if_next();
		void display();
		int retrieve(const char* course_type, int course_code);
	
	protected:
		snode* next;
};

// LLL objects
class degree: public snode
{
	public:
		degree(); // LLL constructor
		~degree(); // LLL destructor
		int load_courses(char course_file_name[]);
		void add(sclass* a_sclass); // add data at front of LLL
		void add_course(char* a_course_type, int a_course_code, int a_course_term, char a_course_grade);
		void remove(const char* course_type, const int course_code); // remove index of data ( in deal datas)
		void display_all(); // display data of LLL
		void display_all(snode* head); // display data of LLL
		int remove_all();
		int remove_all(snode * & head);
		bool find(const char* a_course_type, const int a_course_code);

	protected:
		snode* head;
};
