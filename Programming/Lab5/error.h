struct NULL_STRING {
	char * astring;
};

struct INVALID_PAY {
	float invalid_rate;
};

void set_pay_rate(float rate) throw(INVALID_PAY);

struct TOO_MANY {
	char extra;
};
