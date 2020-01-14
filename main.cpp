#include <iostream>
#include <vector>
#include "Instance.h"
#include "Client.h"
#include "Solution.h"
#include "Solveur.h"
using namespace std;
void afficher(vector<Client>& clients){
    for (int i=0; i<clients.size();i++){
        cout<<clients[i]<<endl;
        //cout<<"("<<clients[i].numero<<","<<clients[i].demande<<")"<<endl;
    };
};
int main(){
/////////////////////////
//// test Instance
/////////////////////////
    cout<<" TEST Instance "<<endl;
    Instance instance;
    instance.read_file("./test2.data");
     //instance.read_file("./instance/Vrp-Set-P/P/P-n19-k2.vrp");
    //instance.read_file("./instance/Vrp-Set-P/P/P-n22-k8.vrp");
    instance.afficher();

////////////////////////////////////
///// test Solveur  MTZ
////////////////////////////////
    cout<<" TEST Solveur "<<endl;
    Solveur solver;
    solver.set_instance( & instance);
    bool flag;
    solver.set_method("plne_MTZ");
    flag = solver.solve();
    cout<<"\n********************main \n \n \n"<<endl;
    if (flag){
       solver.psolution->affichage();
    };

////////////////////////////////////
///// test Solveur  Branch and cut
////////////////////////////////
    // cout<<" TEST Solveur "<<endl;
    // Solveur solver;
    // solver.set_instance( & instance);
    // bool flag;
    // solver.set_method("plne_branch_and_cut");
    // flag = solver.solve();
    // cout<<"\n********************main \n \n \n"<<endl;
    // if (flag){
    //    solver.psolution->affichage();
    // };

    return 0;
};