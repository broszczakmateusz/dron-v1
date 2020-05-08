#include "SMacierz.cpp"
#include "rozmiar.h"


template class SMacierz<double, ROZMIAR>;
template std::istream& operator >> (std::istream & Strm, SMacierz<double, ROZMIAR> &Mac);
template std::ostream& operator << (std::ostream & Strm, const SMacierz<double, ROZMIAR> & Mac);
