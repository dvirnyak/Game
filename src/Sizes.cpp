#include <Sizes.h>

Sizes::Sizes(int height, int width) : height(height), width(width) {
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