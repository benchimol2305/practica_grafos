#include<iostream>
#include<cstring>
#include<limits>

using namespace std; 

struct Usuario
{
    char nombre [50];
    int edad;
    int numeAmigos;
    int capacidad;
    int* amigos;
};

struct RedSocial
{
    int numUsuarios;
    int capacidad;
    Usuario* usuarios;
};

RedSocial* crearRedSocial()
{
    RedSocial* rs= new RedSocial;
    rs->numUsuarios=0;
    rs->capacidad=2;
    rs->usuarios= new Usuario[rs->capacidad];
    return rs;
}

void redimensionarUsuarios(RedSocial* rs){
    int nuevaCapacidad= rs->capacidad*2;
    Usuario* nuevosUsuarios= new Usuario[nuevaCapacidad];

    for (int i = 0; i < rs->numUsuarios; i++)
    {
        nuevosUsuarios[i]= rs->usuarios[i];
    }
    delete[] rs->usuarios;
    rs->usuarios= nuevosUsuarios;
    rs->capacidad= nuevaCapacidad;

    cout<< "la red social se agrando a una capacidad de:" << nuevaCapacidad << " usuarios\n";

    
}

int buscarUsuario(RedSocial* rs, const char* nombre){
    for(int i=0; i<rs->numUsuarios; i++){
        if(strcmp(rs->usuarios[i].nombre, nombre)==0){
            return i;
        }
    }
    return -1;
}
