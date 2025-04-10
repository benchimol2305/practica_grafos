Bienvenido al repositorio oficial de nuestra practica

Esta practica consiste en una red social super sencilla, implementada en C++ usando el concepto de grafos dinámicos. La idea básica es representar cada usuario como un nodo y cada amistad como una conexión (o arista) entre esos nodos.

Empecemos con la instalacion Partiendo de ya tener Visual Studio Code instalado, con un compilador como MinGW. Desde la terminal de Visual Studio Code

Clona el repositorio usando: git clone https://github.com/benchimol2305/practica_grafos.git

Una vez clonado el repositorio, para ubicarte en la carpeta, usa el siguiente comando desde la terminal: cd proyecto

Una vez ubicado en la carpeta, compilar el archivo usando en la terminal: g++ Controlador.cpp -o Controlador

Una vez compilador ejecutar con el siguiente comando: ./Controlador

El programa te presentará un menú interactivo donde podrás:

  -Registrar nuevos usuarios.
  
  -Agregar amistad entre usuarios.
  
  -Mostrar todos los usuarios con sus amistades.
  
  -Salir y liberar la memoria de la red.

Explicacion del programa:

El código está dividido en varias partes

Usuario: Cada usuario tiene un nombre, edad, y además un arreglo dinámico llamado amigos en el que se van guardando los índices de otros usuarios con los que tiene amistad. También se guarda el número de amigos actuales

RedSocial: Esta estructura representa la red completa. Tiene un arreglo dinámico de usuarios y lleva el conteo del número de usuarios que hay

Crear la Red Social: La función crearRedSocial() inicializa la red creando un arreglo para dos usuarios por defecto. 

Redimensionar Usuarios: Cuando el arreglo de usuarios se llena, la función redimensionarUsuarios() dobla su capacidad. Se copia cada elemento del antiguo arreglo al nuevo y se libera la memoria anterior.

Registrar Usuario: La función registrarUsuario() se encarga de pedir los datos (nombre y edad) de un nuevo usuario, inicializar su lista de amigos (con capacidad 1) y guardarlo en el array principal. Punto importante: Si ya no hay espacio, se llama a la función de redimensionar.

Buscar Usuario: buscarUsuario() recorre el arreglo para encontrar un usuario por su nombre y devuelve su índice. Si no se encuentra, devuelve -1.

Agregar Amistad: Esta función permite conectar dos usuarios. Primero busca los índices de ambos usuarios; luego, verifica que no sean ya amigos, y si uno de sus arreglos de amigos está lleno, lo redimensiona con la función redimensionarAmigos(). Finalmente, se registra la amistad de forma bidireccional (es decir, cada usuario se agrega en la lista de amigos del otro).

Mostrar la Red Social: mostrarRedSocial() imprime todos los usuarios junto a su información y la lista de amigos, mostrando los nombres de los amigos conectados.

Liberar Memoria: destruirRedSocial() se asegura de liberar toda la memoria dinámica utilizada, tanto la de los usuarios como la de cada lista de amigos, para evitar fugas de memoria.

¿Cómo se relaciona todo esto con la implementación de grafos?

Nodos (vértices): Cada Usuario es un nodo en nuestro grafo. Contiene toda la información personal y, lo más importante, la lista de amigos.

Aristas: La conexión entre dos usuarios (amistad) se guarda en el arreglos amigos de cada usuario. Como las amistades son bidireccionales (si A es amigo de B, entonces B es amigo de A), cada conexión se guarda en ambos nodos. Esto crea un grafo no dirigido.

Listas de Adyacencia: En vez de usar una matriz de adyacencia, se utilizan arreglos dinámicos para cada usuario. Cada vez que se agrega un amigo, se añade el índice del usuario amigo a esta lista. Si el arreglo se queda sin espacio, se dobla su tamaño dinámicamente.

Dinamicidad: Tanto en el arreglo de usuarios como en cada lista de amigos, el manejo dinámico permite que el grafo se expanda conforme se agregan más datos. Las funciones redimensionarUsuarios() y redimensionarAmigos() se encargan de esto, simulando el crecimiento on the fly del grafo a medida que la red social crece.

Las contribuciones son bienvenidas 😃 Sigue estos pasos para contribuir

Haz un fork del proyecto. (Click en el boton Fork en la pagina original del repositorio)

Crea una nueva rama usando: git checkout -b "nombre de la rama"

Realiza los cambios necesarios y haz un commit. (git commit -m "Comentario"

Sube los cambios. (git push -u origin "Nombre de la rama que creaste"

Crea un pull request. (Es como una solicitud formal que le envías al dueño del proyecto)

Contacto

Luis Chirinos - Email - luisemilio2006@gmail.com

Eldi Rangel - Email - eldi456.rangel@gmail.com

Cesar Benchimol - Cesarbenchimoldavila@gmail.com
