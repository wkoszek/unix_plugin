#include "d.h"

struct d dupa1 __attribute__((section("chuj"))) = { 10 };
struct d dupa2 __attribute__((section("chuj"))) = { 20 };
struct d dupa3 __attribute__((section("chuj"))) = { 30 };
