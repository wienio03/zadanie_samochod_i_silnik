#include <iostream>
#include <sstream>
#include <string>
struct Samochod;
struct Silnik{
    Samochod* samochod;
    unsigned short* moc_m;
    unsigned short* zuzycie_paliwa_m;
    Silnik(){
    }
    Silnik(unsigned short moc, unsigned short zuzycie_paliwa, Samochod& car){
        moc_m = new unsigned short;
        *moc_m=moc;
        zuzycie_paliwa_m = new unsigned short;
        *zuzycie_paliwa_m=zuzycie_paliwa;
    }
    std::string na_napis_silnik(){
        std::stringstream ss_silnik;
        ss_silnik << "Moc silnika:" << moc_m << "KM" << "\nZuzycie paliwa:" << zuzycie_paliwa_m << "l/100km" << "\n";
        return ss_silnik.str();
    }
    ~Silnik(){
        if(moc_m!=nullptr ){
            delete moc_m;
            moc_m=nullptr;  // tutaj jest problem z moc silnika
        }
        if(zuzycie_paliwa_m!=nullptr){
            delete zuzycie_paliwa_m;
            zuzycie_paliwa_m=nullptr;
        }
        if(samochod!=nullptr) {
            delete samochod;
            samochod=nullptr;
        }
        std::cout << "Zwolniono pamiec (silnik)"<<std::endl;
    }
};
struct Samochod{
    Silnik* silnik;
    std::string marka_m;
    int* rok_produkcji_m;
    Samochod(){

    };
    Samochod(std::string marka, int rok_produkcji, Silnik engine){
        marka_m=marka;
        rok_produkcji_m=new int;
        *rok_produkcji_m=rok_produkcji;
        silnik = new Silnik;
        silnik->moc_m=engine.moc_m;
        silnik->zuzycie_paliwa_m=engine.zuzycie_paliwa_m;
    }
    std::string na_napis_samochod(){
        std::stringstream ss_samochod;
        ss_samochod << "Marka samochodu:" << marka_m << "\nRok produkcji:" << *rok_produkcji_m << "\nMoc silnika:" << *silnik->moc_m << "KM"
                    << "\nZuzycie paliwa:" << *silnik->zuzycie_paliwa_m << "l/100km" << "\n";
        return ss_samochod.str();
    }
    ~Samochod(){
        if(rok_produkcji_m!=nullptr){
        delete rok_produkcji_m;
        rok_produkcji_m=nullptr;
            }
        silnik=nullptr;
        std::cout << "Zwolniono pamiec (samochod i silnik)" << "\n";
    }
};
int main(){
    Samochod samochod_test = Samochod("Opel",1990,Silnik(100,8,samochod_test));
    std::cout << samochod_test.na_napis_samochod() << std::endl;
    return 0;
}