#include"Station.h"
namespace w2{
    class Stations {
        string filename;
        Station* stationlist;
        int NoOfStations;
        
    public:
        Stations(char* file) {
            filename = file;
            
            char deliminator;
            string tempstationname;         
            string dumb;
            int s, a;                       
            fstream f;
            f.open(filename, ios::in);
            if(f.is_open()){
                f >> NoOfStations;
               
                stationlist = new Station[NoOfStations];
                for (int i = 0; i < NoOfStations; i++) {
                    getline(f, dumb);
                    getline(f, tempstationname, ';');
                    f >> s;
                    f >> a;
                    stationlist[i].set(tempstationname, s, a);
                }
                
            }
            f.close();
            
        }
        void update()const {
            
        }
        void Stations::report()
        {
            cout << "Passes in Stock :";
            cout << "Student Adult \n";
            cout << "--------------------------------\n";

            for (int i = 0; i <NoOfStations ; i++)
            {
                cout.setf(ios::left);
                cout.width(15);
                cout << stationlist[i].getName();
                cout.unsetf(ios::left);
                cout.width(10);
                cout << stationlist[i].inStock(student);
                cout.width(6);
                cout << stationlist[i].inStock(adult) << endl;
            }
        }

        void Stations::restock()
        {
            int a_rec, s_rec;

            cout << "Passes Added :\n";
            cout << "-----------------\n";

            for (int i = 0; i < NoOfStations; i++)
            {
                cout << stationlist[i].getName() << endl;
                cout << " Student Passes Added : ";
                cin >> s_rec;
                stationlist[i].update(student, s_rec);
                cout << " Adult   Passes Added : ";
                cin >> a_rec;
                stationlist[i].update(adult, a_rec);
            }

            cout << endl;
        }

        void Stations::update()
        {
            int A_Sold, S_Sold;
            cout << "Passes Sold : \n" << "-------------\n";
            int i = 0;

            for (i = 0; i<NoOfStations; i++)
            {
                cout << stationlist[i].getName() << endl << " Student Passes Sold : ";
                cin >> S_Sold;
                stationlist[i].update(student, S_Sold * -1);
                cout << " Adult   Passes Sold : ";
                cin >> A_Sold;
                stationlist[i].update(adult, A_Sold * -1);
            }

            cout << endl;
        }


        ~Stations() {
            fstream f;
            f.open(filename, ios::out);
            if (f.is_open()) {
                f << NoOfStations << ";" << endl;
                for (int i = 0; i < NoOfStations; i++) {
                    f << stationlist[i].getName() << "; " << stationlist[i].inStock(student) << " " << stationlist[i].inStock(adult) << endl;
                }
                f.close();
                delete[] stationlist;

            }
        }


    };
}
