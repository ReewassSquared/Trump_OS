#include <system.h>
#include <string.h>

typedef struct __attribute__((packed)) _node_int32_t
{
	int32_t val;
	struct node_int32_t *next;
} node_int32_t;

typedef struct __attribute__((packed)) _node_uint32_t
{
	uint32_t val;
	struct node_uint32_t *next;
} node_uint32_t;

typedef struct __attribute__((packed)) _node_int16_t
{
	int16_t val;
	struct node_int16_t *next;
} node_int16_t;

typedef struct __attribute__((packed)) _node_uint16_t
{
	uint16_t val;
	struct node_uint16_t *next;
} node_uint16_t;

typedef struct __attribute__((packed)) _node_int8_t
{
	int8_t val;
	struct node_int8_t *next;
} node_int8_t;

typedef struct __attribute__((packed)) _node_uint8_t
{
	uint8_t val;
	struct node_uint8_t *next;
} node_uint8_t;

typedef struct __attribute__((packed)) _node_bool
{
	bool val;
	struct node_bool *next;
} node_bool;

typedef struct __attribute__((packed)) _node_char
{
	char val;
	struct node_char *next;
} node_char;

typedef struct __attribute__((packed)) _node_string
{
	string val;
	struct node_string *next;
} node_string;

class list_int32_t
{
private:
	node_int32_t head;
public:
	void add(int32_t vl)
	{
		node_int32_t ;
		
	}
};
