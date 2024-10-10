Scrabble Helper
Overview

Scrabble Helper is a command-line application designed to assist players of the game Scrabble by providing functionalities like word search, scoring, and generating valid word combinations. It leverages efficient data structures and algorithms to process the game’s dictionary and interact with the user via textual commands.
Features

The application offers several key features to support Scrabble gameplay:

    Game Configuration
        Initialize Dictionary: Loads a dictionary from a diccionario.txt file and validates the words, ensuring no invalid symbols are included.
        Initialize Reverse Dictionary: Similar to the standard initialization, but stores words in reverse (from right to left) for specific use cases.
        Word Scoring: Calculates the score of a given word based on Scrabble's point system, ensuring the word exists in the dictionary and contains valid characters.

    Word Search
        Prefix Search: Finds all valid words that start with a given prefix by traversing a tree of letters built from the dictionary.
        Suffix Search: Similar to prefix search, but searches for words ending with a given suffix.

    Letter Combinations
        Word Graph: Creates a graph where each node is a word, and words are connected if they differ by only one letter.
        Generate Valid Words: Given a set of letters (including an optional wildcard ?), generates all valid Scrabble words that can be formed.

    Interactive Commands:
        $ inicializar diccionario.txt: Initializes the dictionary from the provided file.
        $ iniciar_inverso diccionario.txt: Initializes the reverse dictionary.
        $ puntaje <palabra>: Returns the score of the given word.
        $ iniciar_arbol diccionario.txt: Initializes a tree structure for word search.
        $ palabras_por_prefijo <prefijo>: Lists words that start with the given prefix.
        $ palabras_por_sufijo <sufijo>: Lists words that end with the given suffix.
        $ grafo_de_palabras: Builds a word graph from the dictionary.
        $ posibles_palabras <letras>: Generates all possible words from the given letters.
