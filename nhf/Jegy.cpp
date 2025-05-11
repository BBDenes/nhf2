#include "jegy.h"
#include <iomanip>
#include <ctime>

int Jegy::getId() { return id; }
void Jegy::kiir(std::ostream& os) {  
   time_t now = time(0);  
   struct tm datetime;  
   localtime_s(&datetime, &now); // Correct usage of localtime_s  

   os << "╔════════════════════════════════════════════╗\n";  
   os << "║                 VONATJEGY                  ║\n";  
   os << "╠════════════════════════════════════════════╣\n";  
   os << "║ Jegyazonosito :  #" << std::setw(32) << std::left << id << "║\n";  
   os << "║ Ar            :  " << std::setw(33) << std::left << (std::to_string(ar) + " Ft") << "║\n";  
   os << "║ Jaratszam     :  " << std::setw(33) << std::left << jaratszam << "║\n";  
   os << "║ Datum         :  " << std::setw(32) << std::left  << (std::to_string(1900 + datetime.tm_year) + "-" + std::to_string(datetime.tm_mon + 1) + "-" + std::to_string(datetime.tm_mday) + " " + std::to_string(datetime.tm_hour) + ":" + std::to_string(datetime.tm_min))  << "║\n";  
   os << "╚════════════════════════════════════════════╝\n";  
}

int Helyjegy::getHely() { return szek; }
int Helyjegy::getKocsi() { return kocsiszam; }

void Helyjegy::kiir(std::ostream& os){
    Jegy::kiir(os);
    os << "╔════════════════════════════════════════════╗\n";
    os << "║                 HELYJEGY                   ║\n";
    os << "╠════════════════════════════════════════════╣\n";
    os << "║ Nev :  #" << std::setw(32) << std::left << nev << "║\n";
    os << "║ Honnan            :  " << std::setw(33) << std::left << honnan.getNev() << honnan.getIndulas() << "║\n";
    os << "║ Hova     :  " << std::setw(33) << std::left << hova.getNev() << hova.getErkezes() << "║\n";
    os << "║ Kocsi     :  " << std::setw(33) << std::left << kocsiszam << "║\n";
    os << "║ Szek     :  " << std::setw(33) << std::left << szek << "║\n";
    os << "╚════════════════════════════════════════════╝\n";
}