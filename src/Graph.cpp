#include "Graph.h"



Graph::Graph(){}
void Graph::addEdge (Palabra p1, Palabra p2){
    nodes[p1.stringPalabra()].push_back(p2);
    nodes[p2.stringPalabra()].push_back(p1);
}
void Graph::addVertex(std::string palabra){
    nodes[palabra];
}

void Graph::addVertices(std::list<Palabra>* listaPalabras){
    for(auto it = listaPalabras->begin(); it != listaPalabras->end(); ++it){
        addVertex(it->stringPalabra());
    }
}

std::unordered_map<std::string, std::list<Palabra>>* Graph::getNodesRef(){
    return &nodes;
}

void Graph::addConnections(){
    for (auto it1 = nodes.begin(); it1 != nodes.end(); ++it1) {
        for (auto it2 = std::next(it1); it2 != nodes.end(); ++it2) { 
            if (hayConexion(it1->first, it2->first)) {
                Palabra p2(it2->first);
                Palabra p1(it1->first);
                p2.setPuntaje(p2.calcularPuntaje());
                p1.setPuntaje(p1.calcularPuntaje());
                it1->second.push_back(p2);
                it2->second.push_back(p1); // Since the graph is undirected
            }
        }
    }
}


bool Graph::hayConexion(std::string pal1, std::string pal2){
    int contador = 0;
    std::string mayor = std::max(pal1, pal2);
    if(abs(pal1.length() - pal2.length()) > 1){
        return false;
    }
    else{
        for (int i = 0; i < mayor.length(); i++){
            if(pal1[i] != pal2[i]){
                contador++;
            }
        }
        if(contador == 1){
            return true;
        }else{
            return false;
        }
    }
}

void Graph::sinComodin(std::string letras){
    for (auto it1 = nodes.begin(); it1 != nodes.end(); ++it1){
        std::string palabraPrueba = it1->first;
        if(letras.length() >= it1->first.length()){
            if(esPermutacion(letras, it1->first)){
                Palabra p(it1->first);
                p.setPuntaje(p.calcularPuntaje());
                if(letras.find('?') != -1){
                    std::list<Palabra> palabras = it1->second;
                    imprimirConexiones(palabras);
                }
                std::cout<<p.stringPalabra()<<": "<<"Puntaje: "<<p.getPuntaje()<<std::endl;
            }
        }
    }
}

void Graph::imprimirConexiones(std::list<Palabra> listaPalabras){
    for (auto it = listaPalabras.begin(); it != listaPalabras.end(); ++it){
        std::cout<<it->stringPalabra()<<": "<<"Puntaje: "<<it->getPuntaje()<<std::endl;
    }
}

std::unordered_map<char, int> Graph::countChars(std::string str) {
    std::unordered_map<char, int> charCount;
    for (char ch : str) {
        charCount[ch]++;
    }
    return charCount;
}

// Función para verificar si todos los caracteres de 'pattern' están en 'text'
/*bool Graph::esPermutacion(const std::string text, const std::string pattern) {
    std::unordered_map<char, int> textCount = countChars(text);
    std::unordered_map<char, int> patternCount = countChars(pattern);
    for (const auto p : patternCount) {
        char ch = p.first;
        int count = p.second;

        if (textCount[ch] < count) {
            return false;
        }
    }
    return true;
}*/


bool Graph::esPermutacion(std::string text, std::string pattern) {
    if (pattern.find('?') == std::string::npos) {
        // No wildcard, use the existing logic
        std::unordered_map<char, int> textCount = countChars(text);
        std::unordered_map<char, int> patternCount = countChars(pattern);

        for (const auto& p : patternCount) {
            char ch = p.first;
            int count = p.second;

            if (textCount[ch] < count) {
                return false;
            }
        }
        return true;
    }

    // Wildcard handling
    if (pattern.length() == text.length()) {
        // Case where '?' can replace any single character in pattern
        for (size_t i = 0; i < pattern.length(); ++i) {
            if (pattern[i] != '?' && pattern[i] != text[i]) {
                return false;
            }
        }
        return true;
    }

    if (pattern.length() == text.length() - 1) {
        // Case where text is longer by one character
        size_t mismatchCount = 0;
        size_t j = 0; // index for pattern

        for (size_t i = 0; i < text.length(); ++i) {
            if (j < pattern.length() && (pattern[j] == '?' || pattern[j] == text[i])) {
                j++;
            } else {
                mismatchCount++;
                if (mismatchCount > 1) {
                    return false;
                }
            }
        }
        return mismatchCount <= 1;
    }

    return false;
}


