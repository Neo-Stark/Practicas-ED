#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <fstream>

#define log_2(valor) log((valor)) / log(2)

void QuienEsQuien::copiar(const QuienEsQuien &quienEsQuien)
{
	this->personajes = quienEsQuien.personajes;
	this->atributos = quienEsQuien.atributos;
	this->tablero = quienEsQuien.tablero;
	this->arbol = quienEsQuien.arbol;
	this->jugada_actual = quienEsQuien.jugada_actual;
}

QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien)
{
	copiar(quienEsQuien);
}

QuienEsQuien &QuienEsQuien::operator=(const QuienEsQuien &quienEsQuien)
{
	if (this != &quienEsQuien)
	{
		this->limpiar();
		copiar(quienEsQuien);
	}
	return *this;
}
QuienEsQuien::~QuienEsQuien()
{
	this->limpiar();
}

void QuienEsQuien::limpiar()
{
	personajes.clear();
	atributos.clear();
	for (auto v_it = tablero.begin(); v_it != tablero.end(); ++v_it)
	{
		v_it->clear();
	}
	tablero.clear();
	arbol.clear();
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &s)
{
	if (!s.empty())
	{
		out << '[';
		std::copy(s.begin(), s.end(), std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &v)
{
	if (!v.empty())
	{
		out << '[';
		std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
		out << "\b\b]";
	}
	return out;
}

void QuienEsQuien::mostrar_estructuras_leidas()
{
	cout << "personajes: " << (this->personajes) << endl;
	cout << "atributos:  " << (this->atributos) << endl;
	cout << "tablero:    " << endl;
	cout << (*this);
}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original, string cadena_a_eliminar)
{
	string linea(cadena_original);

	while (linea.find_first_of(cadena_a_eliminar) != std::string::npos)
	{
		linea.erase(linea.find_first_of(cadena_a_eliminar), cadena_a_eliminar.length());
	}

	return linea;
}

istream &operator>>(istream &is, QuienEsQuien &quienEsQuien)
{
	quienEsQuien.limpiar();

	if (is.good())
	{
		string linea;
		getline(is, linea, '\n');

		linea = limpiar_string(linea, "\r");

		while (linea.find('\t') != string::npos)
		{
			string atributo = linea.substr(0, linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
			linea = linea.erase(0, linea.find('\t') + 1);
		}

		assert(linea == "Nombre personaje");
	}

	while (is.good())
	{
		string linea;
		getline(is, linea, '\n');
		linea = limpiar_string(linea, "\r");

		//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
		if (linea != "")
		{
			;
			vector<bool> atributos_personaje;

			int indice_atributo = 0;
			while (linea.find('\t') != string::npos)
			{
				string valor = linea.substr(0, linea.find('\t'));

				assert(valor == "0" || valor == "1");

				bool valor_atributo = valor == "1";

				atributos_personaje.push_back(valor_atributo);

				linea = linea.erase(0, linea.find('\t') + 1);
				indice_atributo++;
			}

			string nombre_personaje = linea;

			quienEsQuien.personajes.push_back(nombre_personaje);
			quienEsQuien.tablero.push_back(atributos_personaje);
		}
	}

	return is;
}

ostream &operator<<(ostream &os, const QuienEsQuien &quienEsQuien)
{

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for (vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		 it_atributos != quienEsQuien.atributos.end();
		 it_atributos++)
	{

		os << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada l�nea y al final ponemos el nombre del personaje.
	for (int indice_personaje = 0; indice_personaje < quienEsQuien.personajes.size(); indice_personaje++)
	{
		for (int indice_atributo = 0; indice_atributo < quienEsQuien.atributos.size(); indice_atributo++)
		{

			os << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un n�mero a un vector de bool que corresponde 
  *        con su representaci�n en binario con un numero de digitos
  *        fijo.
  *
  * @param n N�mero a convertir en binario.
  * @param digitos N�mero de d�gitos de la representaci�n binaria.
  *
  * @return Vector de booleanos con la representaci�n en binario de @e n 
  *      con el n�mero de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos)
{
	vector<bool> ret;
	while (n)
	{
		if (n & 1)
		{
			ret.push_back(true);
		}
		else
		{
			ret.push_back(false);
		}
		n >>= 1;
	}

	while (ret.size() < digitos)
	{
		ret.push_back(false);
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

void QuienEsQuien::crear_arbol()
{

	vector<int> atrib_usados;
	set<int> personajes_levantados;

	for (int i = 0; i < personajes.size(); i++)
		personajes_levantados.insert(i);

	// Se crea la raiz con el mejor atributo.
	int indice = calcular_mejor_atributo(atrib_usados, personajes_levantados);
	atrib_usados.push_back(indice);

	Pregunta preguntaRoot = crear_pregunta(indice, personajes_levantados);

	arbol = bintree<Pregunta>(preguntaRoot);

	// Crea el resto de nodos con el resto de atributos.
	crear_arbol(arbol.root(), atrib_usados, personajes_levantados);
}

void QuienEsQuien::crear_arbol(const bintree<Pregunta>::node &nodoP, vector<int> atrib_usados, set<int> personajes_levantados)
{

	int indice = calcular_mejor_atributo(atrib_usados, personajes_levantados);
	if (indice != -1)
	{
		int ultima_preg = atrib_usados.back();
		atrib_usados.push_back(indice);

		set<int> per_izq = tumba_personajes(personajes_levantados, ultima_preg, true);
		set<int> per_der = tumba_personajes(personajes_levantados, ultima_preg, false);

		Pregunta pregunta_izq = crear_pregunta(indice, per_izq);
		arbol.insert_left(nodoP, pregunta_izq);
		if (per_izq.size() != 1)
			crear_arbol(nodoP.left(), atrib_usados, per_izq);

		Pregunta pregunta_der = crear_pregunta(indice, per_der);
		arbol.insert_right(nodoP, pregunta_der);
		if (per_der.size() != 1)
			crear_arbol(nodoP.right(), atrib_usados, per_der);
	}
}

Pregunta QuienEsQuien::crear_pregunta(int indice, set<int> personajes_levantados)
{
	assert(indice != -1);
	Pregunta pregunta;
	int num_personajes = personajes_levantados.size();
	if (num_personajes != 1)
	{
		string atributo = atributos[indice];
		pregunta = Pregunta(atributo, num_personajes);
	}
	else
	{
		string atributo = personajes[(*personajes_levantados.begin())];
		pregunta = Pregunta(atributo, num_personajes);
	}

	return pregunta;
}

set<int> QuienEsQuien::tumba_personajes(set<int> personajes_levantados, int indice, bool rama)
{
	for (auto it = tablero.begin(); it != tablero.end(); it++)
	{
		if (!(*it)[indice] && rama)
			personajes_levantados.erase(it - tablero.begin());
		else if ((*it)[indice] && !rama)
			personajes_levantados.erase(it - tablero.begin());
	}
	return personajes_levantados;
}

void QuienEsQuien::iniciar_juego()
{
	string otra_partida = "SI";
	while (otra_partida.compare("SI") == 0)
	{
		this->jugada_actual = this->arbol.root();
		while ((*jugada_actual).es_pregunta())
		{
			string respuesta = "";
			cout << "¿" << (*jugada_actual).obtener_pregunta() << "?" << endl;
			respuesta = responder();

			if (respuesta.compare("SI") == 0)
				this->jugada_actual = this->jugada_actual.left();
			else
				this->jugada_actual = this->jugada_actual.right();

			cout << "Personajes restantes: " << informacion_jugada(jugada_actual) << endl;
			cout << "Preguntas formuladas: " << preguntas_formuladas(jugada_actual) << endl;
		}

		cout << "¡Ya lo sé! tu personaje es " << (*jugada_actual).obtener_personaje() << endl;
		cout << "=========================¿Otra partida?=========================" << endl;
		otra_partida = responder();
	}
}

string QuienEsQuien::responder()
{
	string respuesta = "";
	while ((respuesta.find("SI") == string::npos) && (respuesta.find("NO") == string::npos))
	{
		cout << "\tRespuesta(SI/NO): ";
		cin >> respuesta;
		if (respuesta.find("si") != string::npos)
			respuesta.replace(0, 2, "SI");
		else if (respuesta.find("no") != string::npos)
			respuesta.replace(0, 2, "NO");
		else
			cout << "Introduce una respuesta valida: SI o NO" << endl;
	}
	return respuesta;
}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual)
{
	set<string> personajes_levantados;
	bintree<Pregunta> sub_arbol;
	sub_arbol.assign_subtree(this->arbol, jugada_actual);

	for (bintree<Pregunta>::preorder_iterator it = sub_arbol.begin_preorder(); it != sub_arbol.end_preorder(); ++it)
		if ((*it).es_personaje())
			personajes_levantados.insert((*it).obtener_personaje());

	return personajes_levantados;
}

void escribir_esquema_arbol(ostream &ss,
							const bintree<Pregunta> &a,
							bintree<Pregunta>::node n,
							string &pre)
{
	if (n.null())
	{
		ss << pre << "-- x" << endl;
	}
	else
	{
		ss << pre << "-- " << (*n) << endl;
		if (!n.right().null() || !n.left().null())
		{ // Si no es una hoja
			pre += "   |";
			escribir_esquema_arbol(ss, a, n.right(), pre);
			pre.replace(pre.size() - 4, 4, "    ");
			escribir_esquema_arbol(ss, a, n.left(), pre);
			pre.erase(pre.size() - 4, 4);
		}
	}
}

void QuienEsQuien::escribir_arbol_completo() const
{
	string pre = "";
	static string pruebaSalida = "pruebaSalida0";
	static int cont = 0;
	std::ofstream ofs(pruebaSalida, std::ofstream::out);
	// Cambiar "cout" por "ofs" para guardar arbol en un fichero
	escribir_esquema_arbol(cout, this->arbol, this->arbol.root(), pre);
	cont++;
	pruebaSalida.replace(pruebaSalida.end() - 1, pruebaSalida.begin() + 1, to_string(cont));
	ofs.close();
}

float QuienEsQuien::profundidad_promedio_hojas()
{
	vector<int> alturas;
	double media;
	bintree<Pregunta>::preorder_iterator mi_iter;

	for (mi_iter = arbol.begin_preorder(); mi_iter != arbol.end_preorder();
		 ++mi_iter)
	{

		if ((*mi_iter).es_personaje())
		{
			bintree<Pregunta>::node nodo_actual = mi_iter.nodo();
			int nivel = 0;


			while (!nodo_actual.null())
			{
				nivel++;
				nodo_actual = nodo_actual.parent();
			}

			alturas.push_back(nivel);
		}
	}

	media = accumulate(alturas.begin(), alturas.end(), 0.0);
	media /= alturas.size();

	return media;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max)
{
	int tam = max - min;
	return ((rand() % tam) + min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes)
{
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes) / log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petici�n para generar " << numero_de_personajes << " personajes ";
	cout << "con " << numero_de_atributos << " atributos" << endl;
	cout << "Paso 1: generar " << pow(2, numero_de_atributos) << " personajes" << endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for (int indice_personaje = 0; indice_personaje < pow(2, numero_de_atributos); indice_personaje++)
	{
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje, numero_de_atributos);
		string nombre_personaje = "Personaje_" + to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for (int indice_atributo = 0; indice_atributo < numero_de_atributos; indice_atributo++)
	{
		string nombre_atributo = "Atr_" + to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar " << (pow(2, numero_de_atributos) - numero_de_personajes) << " personajes" << endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while (personajes.size() > numero_de_personajes)
	{
		int personaje_a_eliminar = generaEntero(0, personajes.size());

		personajes.erase(personajes.begin() + personaje_a_eliminar);
		tablero.erase(tablero.begin() + personaje_a_eliminar);
	}
}

inline bool es_hoja(const bintree<Pregunta>::node &nodo)
{
	return nodo.right().null() && nodo.left().null();
}

void QuienEsQuien::eliminar_nodos_redundantes()
{
	this->arbol = eliminar_nodos_redundantes(arbol.root());
}

bintree<Pregunta> QuienEsQuien::eliminar_nodos_redundantes(const bintree<Pregunta>::node &nodo)
{
	if (es_hoja(nodo))
		return bintree<Pregunta>(*nodo);

	bintree<Pregunta> resultado;

	bool usarIzq = !nodo.left().null() && (*nodo.left()).obtener_num_personajes() > 0;
	bool usarDer = !nodo.right().null() && (*nodo.right()).obtener_num_personajes() > 0;

	if (!usarIzq)
	{
		auto subArbol = eliminar_nodos_redundantes(nodo.right());
		resultado.assign_subtree(subArbol, subArbol.root());
	}
	else if (!usarDer)
	{
		auto subArbol = eliminar_nodos_redundantes(nodo.left());
		resultado.assign_subtree(subArbol, subArbol.root());
	}
	else
	{
		auto subArbol1 = eliminar_nodos_redundantes(nodo.left());
		auto subArbol2 = eliminar_nodos_redundantes(nodo.right());
		resultado = bintree<Pregunta>(*nodo);
		resultado.insert_left(resultado.root(), subArbol1);
		resultado.insert_right(resultado.root(), subArbol2);
	}

	return resultado;
}

pair<int, int> QuienEsQuien::calcular_valores_atributo(int atributo, set<int> personajes_levantados) const
{
	pair<int, int> valores;

	for (auto it = tablero.begin(); it != tablero.end(); it++)
	{
		if (personajes_levantados.find(it - tablero.begin()) != personajes_levantados.end())
		{
			if ((*it)[atributo])
				valores.first++;
			else
				valores.second++;
		}
	}

	return valores;
}

double QuienEsQuien::calcular_entropia(pair<int, int> valores)
{
	int total = valores.first + valores.second;
	double valor_si = (double)valores.first / total;
	double valor_no = (double)valores.second / total;

	if (valor_si != 0)
		valor_si = -(valor_si)*log_2(valor_si);

	if (valor_no != 0)
		valor_no = -(valor_no)*log_2(valor_no);

	return abs((valor_si - valor_no));
}

int QuienEsQuien::calcular_mejor_atributo(vector<int> &atrib_usados, set<int> personajes_levantados)
{
	double entropia = INFINITY;
	pair<int, int> valores;
	int atributo = -1;

	for (int i = 0; i < atributos.size(); i++)
	{
		if (std::find(atrib_usados.begin(), atrib_usados.end(), i) == atrib_usados.end())
		{
			valores = calcular_valores_atributo(i, personajes_levantados);

			double e = calcular_entropia(valores);

			if (e < entropia)
			{
				entropia = e;
				atributo = i;
			}
		}
	}
	return atributo;
}

set<string> QuienEsQuien::preguntas_formuladas(bintree<Pregunta>::node jugada)
{
	set<string> preguntas;

	while (!jugada.parent().null())
	{
		string cadena((*jugada.parent()).obtener_pregunta());

		if (jugada.parent().left() == jugada)
			cadena += " - si";
		else
			cadena += " - no";

		preguntas.insert(cadena);
		jugada = jugada.parent();
	}

	return preguntas;
}
