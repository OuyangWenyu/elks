#include "wind.h"

int main()
{
    Wind::StaticFunc();
    Wind w;
    w.MemberFunc();

    GlobalFunc();
    return 1;
}
