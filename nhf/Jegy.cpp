#include "memtrace.h"
#include "jegy.h"
#include <iomanip>
#include <ctime>

int Jegy::getId() { return id; }
void Jegy::kiir(std::ostream& os) const {  
   time_t now = time(0);  
   struct tm datetime;  
    #ifdef _WIN32
       localtime_s(&datetime, &now);
    #else
       localtime_r(&now, &datetime);
    #endif

   os << "**********************************************\n";  
   os << "*                 VONATJEGY                  *\n";  
   os << "**********************************************\n";  
   os << "* Jegyazonosito :  #" << std::setw(25) << std::setfill(' ') << std::left << id << "*\n";
   os << "* Ar            :  " << std::setw(26) << std::setfill(' ') << std::left << (std::to_string(ar) + " Ft") << "*\n";
   os << "* Jaratszam     :  " << std::setw(26)<< std::setfill(' ') << std::left << jaratszam << "*\n";
   os << "* Datum         :  " << std::setw(26) << std::setfill(' ') << std::left << (std::to_string(1900 + datetime.tm_year) + "-" + std::to_string(datetime.tm_mon + 1) + "-" + std::to_string(datetime.tm_mday) + " " + std::to_string(datetime.tm_hour) + ":" + std::to_string(datetime.tm_min)) << "*\n";
   os << "**********************************************\n";  
}

int Helyjegy::getHely() const { return szek; }
int Helyjegy::getKocsi() const { return kocsiszam; }

void Helyjegy::kiir(std::ostream& os) const{
    Jegy::kiir(os);
    os << "**********************************************\n";
    os << "*                 HELYJEGY                   *\n";
    os << "**********************************************\n";
    os << "* Nev   :  " << std::setw(34) << std::setfill(' ') << std::left << nev << "*\n";
    os << "* Honnan:  " << std::setw(29) << std::setfill(' ') << std::left << honnan.getNev() << honnan.getIndulas() << "*\n";
    os << "* Hova  :  " << std::setw(29) << std::setfill(' ') << std::left << hova.getNev() << hova.getErkezes() << "*\n";
    os << "* Kocsi :  " << std::setw(34) << std::setfill(' ') << std::left << kocsiszam << "*\n";
    os << "* Szek  :  " << std::setw(34) << std::setfill(' ') << std::left << szek << "*\n";
    os << "**********************************************\n" << std::endl;
}