#define NAME sprite

#define FIELDS \
	FIELD(struct string, name) \
	FIELD(struct texture *, texture) \
	FIELD(struct point, origin) \
	FIELD(uint64_t, bounding_box_type) \
	FIELD(struct rect, bounding_box)
