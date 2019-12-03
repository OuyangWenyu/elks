#ifndef WIND_H
#define WIND_H

extern void GlobalFunc();

class Wind
{
public:
    Wind();
    ~Wind();

    static void StaticFunc();
    void MemberFunc();
};

#endif
