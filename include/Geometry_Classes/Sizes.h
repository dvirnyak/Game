#ifndef MYCOOLGAME_SIZES_H
#define MYCOOLGAME_SIZES_H

struct Sizes {
    int height = 0;
    int width = 0;
    Sizes(int width, int height);
    Sizes() = default;
    Sizes& operator *=(double k);
    Sizes operator *(double k);
};

#endif //MYCOOLGAME_SIZES_H
