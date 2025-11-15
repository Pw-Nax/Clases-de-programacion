#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>    // Para numeric_limits
#include <algorithm> // Para sort
#include <stdexcept> // Para invalid_argument
#include <iomanip>   // Para setprecision
#include <cctype>    // Para toupper, isdigit, isalpha

using namespace std;

// --- ESTRUCTURAS ---
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Candidato {
    string dni;
    string nombre;
    string apellido;
    char sexo;
    string partidoPolitico;
    Fecha fechaNacimiento;
    int votos = 0; // Se restaura el inicializador ' = 0 '
};

struct Votante {
    string dni;
    string nombre;
    char sexo;
    Fecha fechaNacimiento;
    string votoPorDNI; // DNI del candidato o "NULO"
};

// --- VARIABLES GLOBALES ---
vector<Candidato> listaCandidatos;
vector<Votante> listaVotantes;

// --- PROTOTIPOS DE FUNCIONES ---
bool esDNIValido(const string &str);
bool esNombreValido(const string &str);
bool validarFecha(const Fecha &fecha);
int calcularEdad(const Fecha &fecha);
void cargarCandidatos();
void cargarVotantes();
void menu();

// Prototipos Opciones Menu
void mostrarCandidatos();
void buscarCandidato();
void crearArchivoTerceraEdad();
void crearArchivoGanador();
void buscarVotante();
void crearArchivoVotosNulos();
void ordenarYMostrarCandidatos();

// (NUEVOS) Prototipos Opciones Avanzadas
void analisisVotoPorGenero();
void analisisVotoPorEdad();
void busquedaPorPartido();
void reporteParticipacion();


// --- FUNCION PRINCIPAL ---
int main() {
    cargarCandidatos();
    cargarVotantes();
    menu();
    return 0;
}

// --- FUNCIONES DE VALIDACIÓN ---

// Valida DNI (de 7 a 9 digitos)
bool esDNIValido(const string &str) {
    if (str.length() < 7 || str.length() > 9) // Modificado
        return false;
    
    // Bucle for C++11 (range-based)
    for (char c : str) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// Valida nombres y apellidos (permite letras y espacios)
bool esNombreValido(const string &str) {
    if (str.empty()) return false;
    
    // Bucle for C++11 (range-based)
    for (char c : str) {
        // Permite letras (mayúsculas y minúsculas) y espacios
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool validarFecha(const Fecha &fecha) {
    // Año base (1900) y año actual (2025)
    if (fecha.anio < 1900 || fecha.anio > 2025) // Actualizado al año actual
        return false;
    if (fecha.mes < 1 || fecha.mes > 12)
        return false;
    if (fecha.dia < 1 || fecha.dia > 31)
        return false;

    // Verificar días máximos por mes
    if (fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11) {
        if (fecha.dia > 30)
            return false;
    }
    if (fecha.mes == 2) {
        bool esBisiesto = (fecha.anio % 4 == 0 && (fecha.anio % 100 != 0 || fecha.anio % 400 == 0));
        if (esBisiesto && fecha.dia > 29)
            return false;
        if (!esBisiesto && fecha.dia > 28)
            return false;
    }
    return true;
}

int calcularEdad(const Fecha &fecha) {
    time_t t = time(nullptr); // C++11: nullptr restaurado
    tm *tiempo_local = localtime(&t);

    int anio_actual = tiempo_local->tm_year + 1900;
    int mes_actual = tiempo_local->tm_mon + 1;
    int dia_actual = tiempo_local->tm_mday;

    int edad = anio_actual - fecha.anio;
    if (mes_actual < fecha.mes || (mes_actual == fecha.mes && dia_actual < fecha.dia)) {
        edad--;
    }
    return edad;
}

// --- FUNCIONES DE CARGA DE DATOS ---

void cargarCandidatos() {
    Candidato nuevoCandidato;
    int contador = 1;

    while (true) {
        cout << "\n--- Cargando datos del candidato " << contador << " ---\n";

        // Ingreso del DNI
        while (true) {
            try {
                cout << "Ingrese DNI (7-9 digitos) (o 'FIN' para terminar): ";
                cin >> nuevoCandidato.dni;
                if (nuevoCandidato.dni == "FIN")
                    return;
                if (!esDNIValido(nuevoCandidato.dni))
                    throw invalid_argument("DNI invalido (debe tener entre 7 y 9 digitos numericos)");
                
                // Verificar DNI repetido (Bucle C++11)
                bool dni_repetido = false;
                for (const auto& cand : listaCandidatos) {
                    if (cand.dni == nuevoCandidato.dni) {
                        dni_repetido = true;
                        break;
                    }
                }
                if (dni_repetido)
                    throw invalid_argument("DNI repetido");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer ANTES de getline

        // Ingreso del nombre
        while (true) {
            try {
                cout << "Ingrese nombre: ";
                getline(cin, nuevoCandidato.nombre); // Usar getline para nombres compuestos
                if (!esNombreValido(nuevoCandidato.nombre))
                    throw invalid_argument("Nombre invalido (solo letras y espacios)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }

        // Ingreso del apellido
        while (true) {
            try {
                cout << "Ingrese apellido: ";
                getline(cin, nuevoCandidato.apellido); // Usar getline
                if (!esNombreValido(nuevoCandidato.apellido))
                    throw invalid_argument("Apellido invalido (solo letras y espacios)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }

        // Ingreso del sexo
        while (true) {
            try {
                cout << "Ingrese sexo (M/F): ";
                cin >> nuevoCandidato.sexo;
                nuevoCandidato.sexo = toupper(nuevoCandidato.sexo); // Convertir a mayúscula
                if (nuevoCandidato.sexo != 'M' && nuevoCandidato.sexo != 'F')
                    throw invalid_argument("Sexo invalido (solo M o F)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer ANTES de getline

        // Ingreso del partido politico
        cout << "Ingrese partido politico: ";
        getline(cin, nuevoCandidato.partidoPolitico);

        // Ingreso de la fecha de nacimiento
        while (true) {
            try {
                cout << "Ingrese fecha de nacimiento (dia mes anio): ";
                cin >> nuevoCandidato.fechaNacimiento.dia >> nuevoCandidato.fechaNacimiento.mes >> nuevoCandidato.fechaNacimiento.anio;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Formato de fecha incorrecto.");
                }

                if (!validarFecha(nuevoCandidato.fechaNacimiento))
                    throw invalid_argument("Fecha invalida (fuera de rango o inexistente)");
                
                int edad = calcularEdad(nuevoCandidato.fechaNacimiento);
                if (edad < 18)
                    throw invalid_argument("El candidato debe ser mayor de edad (18 anios)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }

        listaCandidatos.push_back(nuevoCandidato);
        contador++;
    }
}

void cargarVotantes() {
    Votante nuevoVotante;
    int contador = 1;

    // No se puede cargar votantes si no hay candidatos
    if (listaCandidatos.empty()) {
        cout << "\nError: Debe cargar candidatos antes de cargar votantes.\n";
        return;
    }

    while (true) {
        cout << "\n--- Cargando datos del votante " << contador << " ---\n";

        // Ingreso del DNI
        while (true) {
            try {
                cout << "Ingrese DNI (7-9 digitos) (o 'FIN' para terminar): ";
                cin >> nuevoVotante.dni;
                if (nuevoVotante.dni == "FIN")
                    return;
                if (!esDNIValido(nuevoVotante.dni))
                    throw invalid_argument("DNI invalido (debe tener entre 7 y 9 digitos numericos)");
                
                // Verificar DNI repetido (Bucle C++11)
                bool dni_repetido = false;
                for (const auto& vot : listaVotantes) {
                    if (vot.dni == nuevoVotante.dni) {
                        dni_repetido = true;
                        break;
                    }
                }
                if (dni_repetido)
                    throw invalid_argument("DNI repetido (este votante ya ha votado)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer ANTES de getline

        // Ingreso del nombre
        while (true) {
            try {
                cout << "Ingrese nombre: ";
                getline(cin, nuevoVotante.nombre); // Usar getline
                if (!esNombreValido(nuevoVotante.nombre))
                    throw invalid_argument("Nombre invalido (solo letras y espacios)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }

        // Ingreso del sexo
        while (true) {
            try {
                cout << "Ingrese sexo (M/F): ";
                cin >> nuevoVotante.sexo;
                nuevoVotante.sexo = toupper(nuevoVotante.sexo); // Convertir a mayúscula
                if (nuevoVotante.sexo != 'M' && nuevoVotante.sexo != 'F')
                    throw invalid_argument("Sexo invalido (solo M o F)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        // Ingreso de la fecha de nacimiento
        while (true) {
            try {
                cout << "Ingrese fecha de nacimiento (dia mes anio): ";
                cin >> nuevoVotante.fechaNacimiento.dia >> nuevoVotante.fechaNacimiento.mes >> nuevoVotante.fechaNacimiento.anio;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Formato de fecha incorrecto.");
                }

                if (!validarFecha(nuevoVotante.fechaNacimiento))
                    throw invalid_argument("Fecha invalida (fuera de rango o inexistente)");
                
                int edad = calcularEdad(nuevoVotante.fechaNacimiento);
                if (edad < 18) // La consigna no especifica edad mínima para votar, pero es lógico.
                    throw invalid_argument("El votante debe ser mayor de edad (18 anios)");
                break;
            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }

        // Ingreso del voto por Opción
        while (true) {
            try {
                cout << "\n--- Opciones de Voto ---\n";
                // Usar bucle C++11 (con contador manual)
                int indice = 1;
                for (const auto& candidato : listaCandidatos) {
                    cout << indice << ". " << candidato.nombre << " " << candidato.apellido 
                         << " (" << candidato.partidoPolitico << ")\n";
                    indice++;
                }
                cout << "0. Voto NULO\n";
                cout << "--------------------------\n";
                
                int opcionVoto;
                cout << "Seleccione su opcion (0-" << listaCandidatos.size() << "): ";
                cin >> opcionVoto;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Entrada invalida. Debe ingresar un numero.");
                }

                // Logica if-else if (como se pidio)
                if (opcionVoto == 0) {
                    nuevoVotante.votoPorDNI = "NULO";
                    break; // Voto valido
                } else if (opcionVoto > 0 && opcionVoto <= static_cast<int>(listaCandidatos.size())) {
                    // static_cast<int> es buena practica para comparar int con size_t
                    nuevoVotante.votoPorDNI = listaCandidatos[opcionVoto - 1].dni; // -1 por el indice
                    break; // Voto valido
                } else {
                    // Opcion invalida
                    throw invalid_argument("Opcion invalida. El numero no esta en la lista.");
                }

            } catch (exception &e) {
                cerr << "Error: " << e.what() << ". Intente nuevamente.\n";
            }
        }


        listaVotantes.push_back(nuevoVotante);

        // Incrementar voto al candidato correspondiente si el voto no es nulo
        if (nuevoVotante.votoPorDNI != "NULO") {
            // Bucle C++11
            for (auto &candidato : listaCandidatos) { 
                if (candidato.dni == nuevoVotante.votoPorDNI) {
                    candidato.votos++;
                    break;
                }
            }
        }
        contador++;
    }
}


// --- FUNCIONES DEL MENÚ ---

// (OPCION 1 ACTUALIZADA CON GRÁFICO ASCII)
void mostrarCandidatos() {
    cout << "\n--- Resultados Electorales ---\n";
    int totalVotosPositivos = 0;
    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        totalVotosPositivos += candidato.votos;
    }
    
    int votosNulos = 0;
    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        if (votante.votoPorDNI == "NULO") {
            votosNulos++;
        }
    }

    int totalVotosEmitidos = totalVotosPositivos + votosNulos;
    if (totalVotosEmitidos == 0) {
        cout << "Aun no se han registrado votos.\n";
        return;
    }

    const int ANCHO_BARRA = 25; // Ancho máximo de la barra

    // Mostrar candidatos (Bucle C++11)
    for (const auto &candidato : listaCandidatos) {
        double porcentaje = (static_cast<double>(candidato.votos) / totalVotosEmitidos) * 100;
        int barraActual = static_cast<int>(porcentaje / 100.0 * ANCHO_BARRA);
        
        cout << candidato.partidoPolitico << " (" << fixed << setprecision(1) << porcentaje << "%): "
             << "[" << string(barraActual, '=') 
             << string(ANCHO_BARRA - barraActual, ' ') << "]"
             << " (" << candidato.votos << " votos)\n";
    }
    
    // Mostrar Nulos
    double porcentajeNulos = (static_cast<double>(votosNulos) / totalVotosEmitidos) * 100;
    int barraNulos = static_cast<int>(porcentajeNulos / 100.0 * ANCHO_BARRA);
    
    cout << "Nulos/Blancos (" << fixed << setprecision(1) << porcentajeNulos << "%): "
         << "[" << string(barraNulos, '=') 
         << string(ANCHO_BARRA - barraNulos, ' ') << "]"
         << " (" << votosNulos << " votos)\n";

    cout << "--------------------------------------------\n"
         << "Total Votos Emitidos: " << totalVotosEmitidos << "\n";
}

// (OPCION 2)
void buscarCandidato() {
    string dniBuscado;
    cout << "Ingrese el DNI del candidato a buscar: ";
    cin >> dniBuscado;

    bool encontrado = false;
    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        if (candidato.dni == dniBuscado) {
            encontrado = true;
            int votosHombres = 0;
            int votosMujeres = 0;

            // Recorrer votantes para contar (Bucle C++11)
            for (const auto &votante : listaVotantes) {
                if (votante.votoPorDNI == dniBuscado) {
                    if (votante.sexo == 'M') {
                        votosHombres++;
                    } else if (votante.sexo == 'F') {
                        votosMujeres++;
                    }
                }
            }

            cout << "\n--- Informacion del Candidato ---\n";
            cout << "Nombre: " << candidato.nombre << " " << candidato.apellido << "\n";
            cout << "Partido: " << candidato.partidoPolitico << "\n";
            cout << "Total de Votos: " << candidato.votos << "\n";
            cout << "Votos de Hombres: " << votosHombres << "\n";
            cout << "Votos de Mujeres: " << votosMujeres << "\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "Error: No se encontro ningun candidato con ese DNI.\n";
    }
}

// (OPCION 3)
void crearArchivoTerceraEdad() {
    ofstream archivo("terceraedad.txt"); // Nombre segun consigna
    if (!archivo.is_open()) {
        cerr << "Error critico: No se pudo crear el archivo 'terceraedad.txt'\n";
        return;
    }

    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        int edad = calcularEdad(votante.fechaNacimiento);
        if (edad >= 70) { // Logica corregida: 70 o mas
            // Formato corregido: Nombre y DNI
            archivo << "Nombre: " << votante.nombre << " - DNI: " << votante.dni << "\n";
        }
    }
    archivo.close();
    cout << "Archivo 'terceraedad.txt' generado correctamente.\n";
}

// (OPCION 4)
void crearArchivoGanador() {
    ofstream archivo("ganador.txt");
    if (!archivo.is_open()) {
        cerr << "Error critico: No se pudo crear el archivo 'ganador.txt'\n";
        return;
    }

    int maxVotos = -1; // Usar -1 por si no hay votos

    // Primera pasada: encontrar el maximo de votos (Bucle C++11)
    for (const auto &candidato : listaCandidatos) {
        if (candidato.votos > maxVotos) {
            maxVotos = candidato.votos;
        }
    }

    if (maxVotos <= 0) {
        cout << "No hay votos, no se puede declarar un ganador.\n";
        archivo << "No hubo votos suficientes para declarar un ganador.\n";
        archivo.close();
        return;
    }

    // Segunda pasada: escribir a todos los que tengan el maximo (maneja empates)
    archivo << "--- Ganador(es) de la Eleccion ---\n";
    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        if (candidato.votos == maxVotos) {
            archivo << "Nombre: " << candidato.nombre << " " << candidato.apellido 
                    << " - DNI: " << candidato.dni 
                    << " - Votos: " << candidato.votos << "\n";
        }
    }
    archivo.close();
    cout << "Archivo 'ganador.txt' generado correctamente.\n";
}

// (OPCION 5)
void buscarVotante() {
    string dniBuscado;
    cout << "Ingrese el DNI del votante a buscar: ";
    cin >> dniBuscado;

    bool votanteEncontrado = false;
    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        if (votante.dni == dniBuscado) {
            votanteEncontrado = true;
            int edad = calcularEdad(votante.fechaNacimiento);
            
            cout << "\n--- Informacion del Votante ---\n";
            cout << "Votante: " << votante.nombre << "\n";
            cout << "Edad: " << edad << " anios\n";

            if (votante.votoPorDNI == "NULO") {
                cout << "Voto: NULO\n";
            } else {
                // Buscar el nombre del candidato
                string nombreCandidato = "Candidato no encontrado (Error de datos)";
                // Bucle C++11
                for (const auto &candidato : listaCandidatos) {
                    if (candidato.dni == votante.votoPorDNI) {
                        nombreCandidato = candidato.nombre + " " + candidato.apellido;
                        break;
                    }
                }
                cout << "Voto por: " << nombreCandidato << "\n";
            }
            break;
        }
    }
    if (!votanteEncontrado) {
        cout << "Error: No se encontro ningun votante con ese DNI.\n";
    }
}

// (OPCION 6)
void crearArchivoVotosNulos() {
    ofstream archivo("nulos.txt");
    if (!archivo.is_open()) {
        cerr << "Error critico: No se pudo crear el archivo 'nulos.txt'\n";
        return;
    }

    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        if (votante.votoPorDNI == "NULO") {
            // La consigna solo pide DNI, pero anadir nombre es mas util
            archivo << "DNI: " << votante.dni << " - Nombre: " << votante.nombre << "\n";
        }
    }
    archivo.close();
    cout << "Archivo 'nulos.txt' generado correctamente.\n";
}

// (OPCION 7)
void ordenarYMostrarCandidatos() {
    // Copiar el vector para no modificar el orden original de listaCandidatos
    vector<Candidato> candidatosOrdenados = listaCandidatos;

    // Ordenar la copia (de mayor a menor) usando una lambda de C++11
    sort(candidatosOrdenados.begin(), candidatosOrdenados.end(), [](const Candidato &a, const Candidato &b) {
        return a.votos > b.votos;
    });

    cout << "\n--- Candidatos Ordenados por Votos (Mayor a Menor) ---\n";
    // Bucle C++11
    for (const auto &candidato : candidatosOrdenados) {
        cout << "Votos: " << candidato.votos
             << " | Nombre: " << candidato.nombre << " " << candidato.apellido
             << " | DNI: " << candidato.dni << "\n";
    }
}

// --- (NUEVAS FUNCIONES DE ANÁLISIS) ---

// (NUEVA OPCION 8)
void analisisVotoPorGenero() {
    cout << "\n--- Analisis de Voto por Genero ---\n";
    
    int totalHombresVotantes = 0;
    int totalMujeresVotantes = 0;
    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        if (votante.sexo == 'M') totalHombresVotantes++;
        if (votante.sexo == 'F') totalMujeresVotantes++;
    }

    if (listaVotantes.empty() || (totalHombresVotantes == 0 && totalMujeresVotantes == 0)) {
        cout << "No hay suficientes datos de votantes para generar un analisis.\n";
        return;
    }

    cout << fixed << setprecision(1);

    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        int votosHombres = 0;
        int votosMujeres = 0;
        // Bucle C++11
        for (const auto &votante : listaVotantes) {
            if (votante.votoPorDNI == candidato.dni) {
                if (votante.sexo == 'M') votosHombres++;
                if (votante.sexo == 'F') votosMujeres++;
            }
        }

        cout << "\nCandidato: " << candidato.nombre << " " << candidato.apellido << "\n";
        
        // Ejemplo 1: "El Candidato X obtuvo el 60% de sus votos de mujeres."
        if (candidato.votos > 0) {
            double porcMujeres = (static_cast<double>(votosMujeres) / candidato.votos) * 100.0;
            double porcHombres = (static_cast<double>(votosHombres) / candidato.votos) * 100.0;
            cout << "  - De sus " << candidato.votos << " votos: " << porcHombres << "% fueron hombres y " << porcMujeres << "% mujeres.\n";
        } else {
            cout << "  - No recibio votos.\n";
        }

        // Ejemplo 2: "Del total de mujeres, el 35% votó al Candidato X."
        if (totalMujeresVotantes > 0) {
            double porcDelTotalMujeres = (static_cast<double>(votosMujeres) / totalMujeresVotantes) * 100.0;
            cout << "  - Recibio el " << porcDelTotalMujeres << "% del total de votos de mujeres.\n";
        }
        if (totalHombresVotantes > 0) {
            double porcDelTotalHombres = (static_cast<double>(votosHombres) / totalHombresVotantes) * 100.0;
            cout << "  - Recibio el " << porcDelTotalHombres << "% del total de votos de hombres.\n";
        }
    }
}

// (NUEVA OPCION 9)
void analisisVotoPorEdad() {
    cout << "\n--- Analisis de Voto por Rango de Edad ---\n";

    if (listaVotantes.empty()) {
        cout << "No hay votantes registrados para analizar.\n";
        return;
    }

    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        int votosJovenes = 0;  // 18-30
        int votosAdultos = 0;  // 31-60
        int votosMayores = 0;  // 61+

        // Bucle C++11
        for (const auto &votante : listaVotantes) {
            if (votante.votoPorDNI == candidato.dni) {
                int edad = calcularEdad(votante.fechaNacimiento);
                if (edad >= 18 && edad <= 30) {
                    votosJovenes++;
                } else if (edad >= 31 && edad <= 60) {
                    votosAdultos++;
                } else if (edad > 60) { // Es 61+
                    votosMayores++;
                }
            }
        }
        
        cout << "\nCandidato: " << candidato.nombre << " " << candidato.apellido << " (Total: " << candidato.votos << " votos)\n";
        cout << "  - Votos 18-30 anios: " << votosJovenes << "\n";
        cout << "  - Votos 31-60 anios: " << votosAdultos << "\n";
        cout << "  - Votos 61+ anios:   " << votosMayores << "\n";
    }
}

// (NUEVA OPCION 10)
void busquedaPorPartido() {
    string partidoBuscado;
    cout << "Ingrese el nombre del Partido Politico a buscar: ";
    
    // Limpiar el buffer de 'cin' antes de usar 'getline'
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    getline(cin, partidoBuscado);

    cout << "\n--- Resultados para el Partido: " << partidoBuscado << " ---\n";
    bool encontrado = false;

    // Bucle C++11
    for (const auto &candidato : listaCandidatos) {
        // Comparación simple (puedes hacerla insensible a mayúsculas si quieres)
        if (candidato.partidoPolitico == partidoBuscado) {
            cout << "Candidato: " << candidato.nombre << " " << candidato.apellido << "\n"
                 << "  - DNI: " << candidato.dni << "\n"
                 << "  - Votos Obtenidos: " << candidato.votos << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron candidatos para ese partido politico.\n";
    }
}

// (NUEVA OPCION 11)
void reporteParticipacion() {
    cout << "\n--- Reporte de Participacion ---\n";
    
    int totalVotantes = listaVotantes.size();
    if (totalVotantes == 0) {
        cout << "No se han registrado votantes.\n";
        return;
    }

    int hombres = 0;
    int mujeres = 0;
    int nulos = 0;

    // Bucle C++11
    for (const auto &votante : listaVotantes) {
        if (votante.sexo == 'M') hombres++;
        if (votante.sexo == 'F') mujeres++;
        if (votante.votoPorDNI == "NULO") nulos++;
    }

    cout << "Total de Votos Emitidos: " << totalVotantes << "\n";
    cout << "---------------------------\n";
    cout << "Desglose por Sexo:\n";
    cout << "  - Hombres: " << hombres << "\n";
    cout << "  - Mujeres:   " << mujeres << "\n";
    cout << "---------------------------\n";
    cout << "Total de Votos Nulos: " << nulos << "\n";
}


// --- FUNCIÓN DE MENÚ (ACTUALIZADA) ---

void menu() {
    int opcion;
    do {
        cout << "\n========= MENU DE ELECCIONES =========\n";
        cout << "--- Reportes Basicos ---\n";
        cout << "1. Mostrar candidatos y porcentaje de votos (Grafico)\n";
        cout << "2. Buscar candidato por DNI (conteo por sexo)\n";
        cout << "3. Crear archivo 'terceraedad.txt' (votantes >= 70 anios)\n";
        cout << "4. Crear archivo 'ganador.txt'\n";
        cout << "5. Buscar votante por DNI (mostrar su voto)\n";
        cout << "6. Crear archivo 'nulos.txt'\n";
        cout << "7. Ordenar y mostrar candidatos por cantidad de votos\n";
        cout << "\n--- Analisis Avanzado ---\n";
        cout << "8. Analisis de Voto por Genero\n";
        cout << "9. Analisis de Voto por Rango de Edad\n";
        cout << "10. Buscar Candidatos por Partido Politico\n";
        cout << "11. Reporte de Participacion General\n";
        cout << "\n0. Salir\n";
        cout << "======================================\n";
        cout << "Seleccione una opcion: ";
        
        cin >> opcion;

        if (cin.fail()) {
            cerr << "Error: Opcion invalida. Debe ingresar un numero.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1; // Forzar a que el bucle continue
            continue;
        }

        // Bloque if-else if actualizado
        if (opcion == 1) {
            mostrarCandidatos();
        } else if (opcion == 2) {
            buscarCandidato();
        } else if (opcion == 3) {
            crearArchivoTerceraEdad();
        } else if (opcion == 4) {
            crearArchivoGanador();
        } else if (opcion == 5) {
            buscarVotante();
        } else if (opcion == 6) {
            crearArchivoVotosNulos();
        } else if (opcion == 7) {
            ordenarYMostrarCandidatos();
        } else if (opcion == 8) { // NUEVO
            analisisVotoPorGenero();
        } else if (opcion == 9) { // NUEVO
            analisisVotoPorEdad();
        } else if (opcion == 10) { // NUEVO
            busquedaPorPartido();
        } else if (opcion == 11) { // NUEVO
            reporteParticipacion();
        }
         else if (opcion == 0) {
            cout << "Saliendo del programa...\n";
        } else {
            cout << "Opcion invalida, intente nuevamente.\n";
        }

    } while (opcion != 0);
}
