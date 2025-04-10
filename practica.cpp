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

void registrarUsuario(RedSocial* rs){
    if(rs->numUsuarios >= rs->capacidad){
        redimensionarUsuarios(rs);

    }
    Usuario nuevo;
    cout<< "ingrese nombre del usuario: ";
    cin.getline(nuevo.nombre, 50);

    cout<< "ingrese la edad del usuario: ";
    cin>> nuevo.edad;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    nuevo.numeAmigos=0;
    nuevo.capacidad=1;
    nuevo.amigos= new int[1];
    rs->usuarios[rs->numUsuarios]= nuevo;
    rs->numUsuarios++;

    cout<< " el usuario se registro de manera correcta /n";
    
}

void redimensionarAmigos(Usuario* usuario) {
    int nuevaCapacidad = usuario->capacidad * 2;
    int* nuevosAmigos = new int[nuevaCapacidad];
    
   
    for (int i = 0; i < usuario->numeAmigos; i++) {
        nuevosAmigos[i] = usuario->amigos[i];
    }
    
    delete[] usuario->amigos;
    usuario->amigos = nuevosAmigos;
    usuario->capacidad = nuevaCapacidad;
}

void agregarAmistad(RedSocial* rs) {
    char nombre1[50], nombre2[50];
    
    cout<<"Ingrese nombre del primer usuario: ";
    cin.getline(nombre1, 50);
    
    cout<<"Ingrese nombre del segundo usuario: ";
    cin.getline(nombre2, 50);
    
    int idx1=buscarUsuario(rs, nombre1);
    int idx2=buscarUsuario(rs, nombre2);
    
    if(idx1==-1||idx2==-1){
        cout<<"Error: Uno o ambos usuarios no existen\n";
        return;
    }
    for (int i = 0; i < rs->usuarios[idx1].numeAmigos; i++) {
        if (rs->usuarios[idx1].amigos[i] == idx2) {
            cout << "Estos usuarios ya son amigos\n";
            return;
        }
    }

    if (rs->usuarios[idx1].numeAmigos>=rs->usuarios[idx1].capacidad){
        redimensionarAmigos(&rs->usuarios[idx1]);
    }
    rs->usuarios[idx1].amigos[rs->usuarios[idx1].numeAmigos++]=idx2;

    if (rs->usuarios[idx2].numeAmigos >= rs->usuarios[idx2].capacidad){
        redimensionarAmigos(&rs->usuarios[idx2]);
    }
    rs->usuarios[idx2].amigos[rs->usuarios[idx2].numeAmigos++]=idx1;
    
    cout <<"Amistad agregada exitosamente!\n";
}