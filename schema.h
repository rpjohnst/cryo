#include <stdint.h>
#include <stddef.h>

struct string {
	char *string;
	size_t length;
};

struct point {
	int64_t x;
	int64_t y;
};

struct rect {
	int64_t x;
	int64_t y;
	int64_t w;
	int64_t h;
};

enum type {
	UNKNOWN,
	INT,
	UINT,
	STRING,
	POINT,
	RECT,
};

#define TYPE_OF(type) _Generic((type){0}, \
	default: UNKNOWN, \
	int64_t: INT, \
	uint64_t: UINT, \
	struct string: STRING, \
	struct point: POINT, \
	struct rect: RECT \
)

struct schema {
	const char *name;

	size_t num_fields;
	const char **names;
	enum type *types;
	size_t *offsets;
	size_t *sizes;
};
