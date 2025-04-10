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
