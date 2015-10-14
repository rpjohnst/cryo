#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)

#define STR_(a) #a
#define STR(a) STR_(a)

struct schema CAT(NAME, _schema) = {
	.name = STR(NAME),

	.num_fields = (
#define FIELD(type, name) 1 +
		FIELDS
#undef FIELD
	0),

	.names = (const char *[]){
#define FIELD(type, name) #name,
		FIELDS
#undef FIELD
	},

	.types = (enum type[]){
#define FIELD(type, name) TYPE_OF(type),
		FIELDS
#undef FIELD
	},

	.offsets = (size_t[]){
#define FIELD(type, name) offsetof(struct NAME, name),
		FIELDS
#undef FIELD
	},

	.sizes = (size_t[]) {
#define FIELD(type, name) sizeof(type),
		FIELDS
#undef FIELD
	},
};

#undef NAME
#undef FIELDS
#undef CAT_
#undef CAT
