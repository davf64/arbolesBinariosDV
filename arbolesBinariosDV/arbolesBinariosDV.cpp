/*
* Name: Arbol Binario
*
* Author: Diego Alfonso Vega Fernandez
* E-mail: davf64@yahoo.com
*
* Date: 23/05/2021
*
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>


using namespace std;

struct nodo {
	int nro;
	struct nodo* izq, * der;
};
typedef struct nodo* raiz;



/*prototypes*/
raiz crearNodo(const char* db_dir, int x);
void insertar(raiz& arbol, const char* db_dir, int x);
void insertarCache(raiz& arbol, const char* db_dir, int x);
void poblarArbol(raiz& arbol, const char* db_dir);
void verArbol(raiz arbol, int n);

bool busquedaAncestros(raiz arbol, vector<int>& ruta, int n);
bool nodosAncestros(raiz arbol, int n);
int  ancestroComun(raiz arbol, int n1, int n2);
void buscarAncestros(raiz arbol);

static int crearDB(const char* db_dir);
static int crearT(const char* db_dir);
static int insertarT(const char* db_dir, int x);
static int leerT(raiz& arbol, const char* db_dir);
static int limpiarT(raiz& arbol, const char* db_dir);



/*Main Function*/
int main()
{
	int			opcion = 0;

	raiz		arbol = NULL;
	const char* db_dir = "C:\\Users\\Public\\Documents\\binaryTree.db";

	//system("cls");

	crearDB(db_dir);
	crearT(db_dir);

	do {

		system("cls");

		cout << endl;
		cout << "======================================\n";
		cout << "Ingrese Una Opcion: \n";
		cout << "======================================\n\n";
		cout << "(1) Crear/Modificar Arbol Binario\n";
		cout << "(2) Ver Arbol Binario\n";
		cout << "(3) Menor Ancestro\n";
		cout << "(4) Cargar Arbol Binario Almacenado\n";
		cout << "(5) Borrar Arbol Binario Almacenado\n";
		cout << "(6) Salir\n\n";

		cin >> opcion;
		cout << "======================================\n\n";

		switch (opcion) {
		case 1: poblarArbol(arbol, db_dir); cout << endl; system("pause"); break;
		case 2: verArbol(arbol, 0); cout<<endl; system("pause"); break;
		case 3: buscarAncestros(arbol); cout << endl; system("pause"); break;
		case 4: leerT(arbol, db_dir); cout << endl; system("pause"); break;
		case 5: limpiarT(arbol, db_dir); cout << endl; system("pause"); break;
		case 6: cout << "Saliendo." << endl; cout << endl; system("pause"); break;
		default: opcion = 0; break;
		}

	} while (opcion != 6);

	cout << endl << endl;

	// cleanup:
	if (arbol != NULL) delete arbol;
	arbol = NULL;
	return 0;
}


/*Functions*/

raiz crearNodo(const char* db_dir, int x)
{
	raiz	nuevoNodo = new(struct nodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	return nuevoNodo;
}

void insertar(raiz& arbol, const char* db_dir, int x)
{
	if (arbol == NULL) {
		// Se agrega Nodo al arbol:
		arbol = crearNodo(db_dir, x);
		// Se agrega Nodo a la BD:
		insertarT(db_dir, x);
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, db_dir, x);
	else if (x > arbol->nro)
		insertar(arbol->der, db_dir, x);
}

void insertarCache(raiz& arbol, const char* db_dir, int x)
{
	if (arbol == NULL) {
		// Se agrega Nodo al arbol:
		arbol = crearNodo(db_dir, x);
	}
	else if (x < arbol->nro)
		insertarCache(arbol->izq, db_dir, x);
	else if (x > arbol->nro)
		insertarCache(arbol->der, db_dir, x);
}

void poblarArbol(raiz& arbol, const char* db_dir)
{
	int i, n;
	int x;

	cout << "Ingrese el numero de nodos para adicionar al arbol: ";
	cin >> n;
	cout << endl; 

	for (i = 0; i < n; i++)
	{
		cout << " Numero del nodo " << i + 1 << ": ";
		cin >> x;
		insertar(arbol, db_dir, x);
	}

	return;
}


void verArbol(raiz arbol, int n)
{
	int i;

	if (arbol == NULL)
		return;

	verArbol(arbol->der, n + 1);

	for (i = 0; i < n; i++)
		cout << "  ";
	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);

	return;
}

bool busquedaAncestros(raiz arbol, vector<int>& ruta, int n)
{
	if (arbol == NULL)
		return false;

	ruta.push_back(arbol->nro);

	if (arbol->nro == n)
		return true;

	if ((arbol->izq && busquedaAncestros(arbol->izq, ruta, n)) || (arbol->der && busquedaAncestros(arbol->der, ruta, n)))
		return true;

	ruta.pop_back();

	return false;
}

bool nodosAncestros(raiz arbol, int n)
{
	if (arbol == NULL)
		return false;

	if (arbol->nro == n)
		return true;

	if (nodosAncestros(arbol->izq, n) || nodosAncestros(arbol->der, n)) {
		//cout << arbol->nro << " "; // DEBUG
		return true;
	}

	return false;
}

int  ancestroComun(raiz arbol, int n1, int n2)
{
	int i;
	vector<int> ruta1, ruta2;

	if (!busquedaAncestros(arbol, ruta1, n1) || !busquedaAncestros(arbol, ruta2, n2))
		return -1; // No existe el numero.

	for (i = 0; i < ruta1.size() && i < ruta2.size(); i++) {
		if (ruta1[i] != ruta2[i])
			break;
	}

	return ruta1[i - 1];
}

void buscarAncestros(raiz arbol)
{
	int n1, n2;
	bool ancestros;

	cout << "Ingrese primer numero: ";
	cin >> n1;
	ancestros = nodosAncestros(arbol, n1);
	if (ancestros == false) {
		cout << n1 << " No encontrado!\n\n";
		return;
	}

	cout << "Ingrese segundo numero: ";
	cin >> n2;
	ancestros = nodosAncestros(arbol, n2);
	if (ancestros == false) {
		cout << n2 << " No encontrado!\n\n";
		return;
	}

	cout << "El menor ancestro comun es: " << ancestroComun(arbol, n1, n2) << endl;

	return;
}

static int crearDB(const char* db_dir)
{
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open(db_dir, &DB);

	sqlite3_close(DB);

	return 0;
}


static int crearT(const char* db_dir)
{
	sqlite3* DB;
	int exit = 0;
	char* errMsg;

	string sql = "CREATE TABLE IF NOT EXISTS BINARY_TREE_T("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"VALUE	INT NOT NULL);";

	try {
		exit = sqlite3_open(db_dir, &DB);

		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);

		if (exit != SQLITE_OK) {
			cerr << "Error creando la tabla." << endl;
			sqlite3_free(errMsg);
		}

		sqlite3_close(DB);
	}
	catch (const exception& exc) {
		cerr << exc.what();
	}

	return 0;
}

static int insertarT(const char* db_dir, int x)
{
	sqlite3* DB;
	int exit = 0;
	char* errMsg;

	string sql = "INSERT INTO BINARY_TREE_T (VALUE) VALUES (";
	sql += to_string(x);
	sql += ");";

	exit = sqlite3_open(db_dir, &DB);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);

	if (exit != SQLITE_OK) {
		cerr << "Error insertando en la tabla." << endl;
		sqlite3_free(errMsg);
	}

	sqlite3_close(DB);
	return 0;
}

static int leerT(raiz& arbol, const char* db_dir)
{
	sqlite3* DB;
	int exit = 0;
	char* errMsg;
	const char* data = "";

	sqlite3_stmt* stmt;

	string sql = "SELECT VALUE FROM BINARY_TREE_T";


	// Se limpia el arbol en memoria
	if (arbol != NULL) delete arbol;
	arbol = NULL;

	exit = sqlite3_open(db_dir, &DB);

	sqlite3_prepare_v2(DB, "SELECT ID, VALUE FROM BINARY_TREE_T", -1, &stmt, 0);
	int a, b;

	cout << "Leyendo datos de la BD." << endl; // DEBUG
	while (sqlite3_step(stmt) != SQLITE_DONE) {

		//sqlite3_step(stmt);
		a = sqlite3_column_int(stmt, 0);
		b = sqlite3_column_int(stmt, 1);

		//cout << "ID: " << a << " VALUE: " << b << endl; // DEBUG
		cout << b << endl; // DEBUG

		// Se insertan los datos de la tabla a memoria
		insertarCache(arbol, db_dir, b);

	};

	sqlite3_close(DB);

	return 0;
}

static int limpiarT(raiz& arbol, const char* db_dir)
{
	sqlite3* DB;
	int exit = 0;
	char* errMsg;

	string sql = "DELETE FROM BINARY_TREE_T;";

	exit = sqlite3_open(db_dir, &DB);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &errMsg);

	if (exit != SQLITE_OK) {
		cerr << "Error limpiando la tabla." << endl;
		sqlite3_free(errMsg);
	}

	sqlite3_close(DB);

	// Se limpia el arbol en memoria
	if (arbol != NULL) delete arbol;
	arbol = NULL;

	return 0;
}

