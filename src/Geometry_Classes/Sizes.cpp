#include <Sizes.h>

Sizes::Sizes(int width, int height) : height(height), width(width) {
}

Sizes& Sizes::operator *=(double k) {
    height *= k;
    width *= k;
}

Sizes Sizes::operator *(double k) {
    Sizes copy = *this;
    copy *= k;
    return copy;
}