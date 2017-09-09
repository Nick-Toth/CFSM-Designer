/* ***************************************************************
\\ File Name:  Graph.cpp
// Created By: Nick G. Toth
\\ E-Mail:     ntoth@pdx.edu
// Date:       Sept. 9th, 2017
\\
// Overview: This file contains the Graph class implementation.
\\ The Graph's primary purpose is modeling data in the CFSM-
// Designer. See Graph.h for the Graph's underlying structures
\\ (Vertex and Node).
//
\\ ***************************************************************/

#ifndef GRAPH_CPP
#define GRAPH_CPP
#endif

#include "Graph.h"

#ifdef USE_EXPORT_KEYWORD
export
#endif // USE_EXPORT_KEYWORD



/* ************************************************
\\ Create and insert a new vertex into the
// adjacency list.
\\
// ************************************************/
template <typename T>
int Graph<T> :: newVertex( const T & data,
			   std::string key)
{
	// If the specified key is already in use, return error code -1.
	if(graph.find(key) != graph.end()) return -1;

	// Set the next open graph vertex to data.
	graph[key].data = data;

	// Return current number of vertices.
	return current_size++;
}


/* ************************************************
\\ Add the vertex specified by to_key to the edge
// list of the vertex specified by from_key.
\\
// ************************************************/
template <typename T>
int Graph<T> :: newEdge( std::string from_key,
			 std::string to_key,
			 unsigned length )
{
	// Stores the length of the edgelist in
	// the vertex given by from_vtex to return.
	int edge_len = 0;

	// Temporary node for traversing the edge list of from_vtex
	std::shared_ptr< Node<T> > edge = graph[from_key].head;

	// If to_vtex is already in from_vtex's
	// edge list, report error code edge_len.
	if(edge_len < 0) return edge_len;

	// Create, initialize a new Node.
	edge = std::shared_ptr< Node<T> >(new Node<T>);
	edge->next = graph[from_key].head;

	// Set new node's chain length to the
	// current head's chain length + 1.
	if(graph[from_key].head) edge->chain_length = graph[from_key].head->chain_length + 1;
	else edge->chain_length = 1;

	edge->adj_key = to_key;
	
	// Store the new edge at the head of from_vtex's edge list.
	graph[from_key].head = edge;

	// Return the new length of the edge list.
	return ++edge_len;
}


/* ************************************************
\\ Displays the edge list for some specific vertex.
//
\\ ************************************************/
template <typename T>
int Graph<T> :: displayChain(std::string vtex)
{
	// If the specified vertex is invalid, return error code -1.
	if(graph.find(vtex) == graph.end()) return -1;

	// Temporary node for traversing the edge list of from_vtex
	std::shared_ptr< Node<T> > edge = graph[vtex].head;

	// Loop control for traversing the edge list.
	bool display_complete = edge == nullptr;

	// Display the starting vertex's data.
	std::cout << "\n\t    " << graph[vtex].data << " => " << std::flush;

	// Display the data in all vertices in the edgelist of vtex.
	while(!display_complete)
	{
		// If the current node contains a valid key..
		if(graph.find(edge->adj_key) != graph.end())
			// Display the current data.
			std::cout << graph[edge->adj_key].data << ' ' << std::flush;

		// Update the current edge list vertex pointer.
		edge = edge->next;
		// Exit if the edge list has been displayed.
		display_complete = edge == nullptr;
	}

	// Display whitespace.
	std::cout << std::endl;

	return 0;
}


/* ************************************************
\\ Return a copy of the data stored in the graph
// at a specific vertex.
\\
// ************************************************/
template <typename T>
T Graph<T> :: get(std::string key) const
{
	// If the specified key is invalid return error code -1.
	if(graph.find(key) == graph.end()) return -1;

	// Return the data at the specified vtex.
	return T(graph[key].data);
}
