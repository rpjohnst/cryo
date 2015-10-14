#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)

struct NAME {
#define FIELD(type, name) type name;
	FIELDS
#undef FIELD
};

extern struct schema CAT(NAME, _schema);

#undef NAME
#undef FIELDS
#undef CAT_
#undef CAT
