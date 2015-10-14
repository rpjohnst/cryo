#include "schema.h"

#include "sprite.h"
#include "schema_decl.h"

#include <stdio.h>
#include <stddef.h>

int main(void) {
	struct sprite sprite = {
		.name = { .string = "player_spr", .length = 10 },
		.texture = NULL,
		.origin = { .x = 0, .y = 0 },
		.bounding_box_type = 0,
		.bounding_box = { .x = 0, .y = 0, .w = 24, .h = 24 },
	};

	struct schema *schema = &sprite_schema;
	void *resource = &sprite;

	printf("(struct %s){\n", schema->name);
	for (size_t i = 0; i < schema->num_fields; i++) {
		printf("\t.%s = ", schema->names[i]);

		void *field = (char*)resource + schema->offsets[i];
		switch (sprite_schema.types[i]) {
		case INT: printf("%ld", *(int64_t*)field); break;
		case UINT: printf("%lu", *(uint64_t*)field); break;

		case STRING: {
			struct string *string = field;
			printf("\"%.*s\"", (int)string->length, string->string);
			break;
		}

		case POINT: {
			struct point *point = field;
			printf("{ .x = %ld, .y = %ld }", point->x, point->y);
			break;
		}

		case RECT: {
			struct rect *rect = field;
			printf(
				"{ .x = %ld, .y = %ld, .w = %ld, .h = %ld }",
				rect->x, rect->y, rect->w, rect->h
			);
			break;
		}

		default: {
			char *bytes = field;
			printf("[ ");
			for (size_t j = 0; j < schema->sizes[i]; j++)
				printf("%02x ", bytes[j]);
			printf("]");
			break;
		}
		}

		printf(",\n");
	}
	printf("}\n");
}
