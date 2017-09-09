/* ***************************************************************
\\ File Name:  Graph.h
// Created By: Nick G. Toth
\\ E-Mail:     ntoth@pdx.edu
// Date:       Setp. 9th, 2017
\\
// Overview: This file contains the declaration for a basic digraph
\\ to be used with the CFSM-Designer. Additionally, this file
// contains the definitions for a vertex and edgelist structs, to
\\ be used in the adjacency list and edge lists. See Graph.cpp for
// Graph implementation details.
\\
// ***************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <string>

typedef unsigned long ulong;

#ifndef nullptr
#define nullptr 0
#endif // nullptr

// Handle potential template-related compile errors.
#ifdef USE_EXPORT_KEYWORD
export
#endif // USE_EXPORT_KEYWORD
// Continues after Graph declaration.


template <typename T> struct Node;


/* ************************************************
\\ Vertex serves as the data wrapper for the
// edgelist in the Graph class. In most cases, the
\\ QVertex class (../QVertex/QVertex.h/cpp) will
// serve as the Vertex's underlying data type. For
\\ instances of this class which do not use QT,
// T=string would be most appropriate.
\\
// ************************************************/
template <typename T>
struct Vertex
{
	// Default vertex constructor.
	Vertex(): data(T()), head(nullptr) {}

	// Initialize a new vertex.
	Vertex(const T & data): data(T(data)),
													head(nullptr) {}

	// Copy the contents of an existing vertex.
	Vertex(const Vertex<T> & vtex_src): data(T(vtex_src.data)),
														 					head(vtex_src.head) {}

	// Compare vertices (by data only).
	inline bool operator==(const Vertex<T> & vtex_cmp) const
	{ if(vtex_cmp.data == data) return true; return false; }

	T data; // Probably QVertex or string.

	// Pointer to the first node in the edgelist.
	std::shared_ptr< struct Node<T> > head;
};


/* ************************************************
\\ The node class is used in the edge lists of
// vertices in the Graph class's adjacency list.
\\ Rather storing using Vertex pointers, Nodes
// store the keys to their associated Vertices in
\\ the adjacency list in the Graph class.
//
\\ ************************************************/
template <typename T>
struct Node
{
	// Default constructor.
	Node(std::string adj = ""): next(nullptr), length(0), chain_length(0), adj_key(adj) { }

	std::shared_ptr< Node<T> > next; // Pointer to the next vertex in the edgelist.	

	unsigned length, // Length between this vertex, and the vertex specified by next.
					 chain_length; // Length of the edge list, starting from this node.

	std::string adj_key; // Key of the adjacent vertex.
};


/* ************************************************
\\ The graph class is a bare-bones digraph for use
// by the CFSM-Designer.
\\
// ************************************************/
template <typename T>
class Graph
{
	public:

		// Initialize a new graph.
		Graph(unsigned vertices): graph(std::unordered_map< std::string, Vertex<T> >(vertices)),
										 					current_size(vertices) { }

		// Copy the contents of an existing graph.
		Graph(const Graph<T> & graph_src): current_size(graph_src.current_size) { }

		~Graph() { }

		// Add a new vertex to the graph.
    int newVertex(const T &, std::string key);

		// Add a new edge between two vertices.
		int newEdge( std::string,
								 std::string,
								 unsigned );

		// Display the edge list for some initial vertex.
		int displayChain(std::string);

		// Returns the data in the specified vertex.
		T get(std::string) const;

	private:

		// Array of vertices.
		std::unordered_map< std::string, Vertex<T> > graph;

		// The size of the graph.
		unsigned current_size;
};


// Manages potential template-related compile errors.
#ifndef USE_EXPORT_KEYWORD
	#ifndef GRAPH_CPP
  #include "Graph.cpp"
	#endif // GRAPH_CPP
#endif // USE_EXPORT_KEYWORD
#endif // GRAPH_H
