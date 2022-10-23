#include <iostream>
#include "filtr_ip_lib.h"

using namespace std;

int main()
{
    IpAddrPool ip_pool;
    string line;
    while (getline(cin, line))
    {
        auto v = split(line, '\t');
        ip_pool.insert(v[0]);
    }

    ip_pool.print_all(cout);
    ip_pool.print_all(cout, 1);
    ip_pool.print_all(cout, 46, 70);
    ip_pool.print_any(cout, 46);

    return 0;
}
