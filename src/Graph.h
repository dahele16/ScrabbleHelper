#ifndef GRAPH_H   
#define GRAPH_H
#include <List>
#include <String>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include"Palabra.h"

class Graph {
private:
    std::unordered_map<std::string, std::list<Palabra>> nodes; 

public:
    Graph();
    Graph (std::list <Palabra> palabras);
    std::list <Palabra> getPalabras();
    void setPalabras(std::list <Palabra> palabras);
    void addEdge (Palabra p1, Palabra p2); 
    void addVertex(std::string palabra);
    std::unordered_map <std::string, std::list <Palabra>>* getNodesRef();
    void addConnections();
    bool hayConexion(std::string pal1, std::string pal2);
    std::string imprimirPalabras();
    void addVertices(std::list<Palabra>* listaPalabras);
    void sinComodin(std::string letras);
    void bfs(Palabra start);
    std::unordered_map<char, int> countChars(std::string str);
    bool esPermutacion(std::string text,  std::string pattern);
    void imprimirConexiones(std::list<Palabra> listaPalabras);
};
#include "Graph.cpp"
#endif