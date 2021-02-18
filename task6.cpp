#include <iostream>
#include <cmath>

void RabinKarp(std::string str, std::string pat)
{
    long long pat_value = 0;
    long long tmp = 0;

    for (auto ix = 0; ix < pat.size(); ++ix)
    {
        pat_value += ((pat[ix] - 96) * (pow(10, pat.size() - ix - 1)));
    }

    for (auto ix = 0; ix < pat.size(); ++ix)
    {
        tmp += ((str[ix] - 96) * (pow(10, pat.size() - ix - 1)));
    }

    //pat_value %= 10^32;

    for (auto jx = 1; jx < str.size() - 1; ++jx)
    {

        tmp -= ((str[jx - 1] - 96) * (pow(10, pat.size() - 1)));
        tmp *= 10;
        tmp += (str[jx + 1] - 96);

        if (tmp == pat_value)
            std::cout << "Pattern found at index " << jx - 1 << std::endl;
    }
}

int main()
{
    std::string str = "barev";
    std::string pattern = "rev";
    RabinKarep(str, pattern);
}