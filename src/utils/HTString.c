#include "HTString.h"

void HTStringAlloc(HTStringRef self) {

}

void HTStringDealloc(HTStringRef self) {
    HTMemFree(self->impl->characters);
}
