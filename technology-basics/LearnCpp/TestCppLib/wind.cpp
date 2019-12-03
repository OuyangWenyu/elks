#include "wind.h"
#include <iostream>

void GlobalFunc()
{
    std::cout << "GlobalFunc test!" << std::endl;
}

Wind::Wind()
{

}

Wind::~Wind()
{

}

void Wind::StaticFunc()
{
    std::cout << "StaticFunc test!" << std::endl;
}

void Wind::MemberFunc()
{
    std::cout << "MemberFunc test!" << std::endl;
}
