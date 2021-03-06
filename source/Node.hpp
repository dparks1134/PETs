//=======================================================================
// Author: Donovan Parks
//
// Copyright 2013 Donovan Parks (donovan.parks@gmail.com)
//
// This file is part of PETs.
//
// PETs is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// PETs is distributed in the hope that it will be useful, bu
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with PETs. If not, see <http://www.gnu.org/licenses/>.
//=======================================================================

#pragma once

#include "Precompiled.hpp"

class Node
{
public:
	static const double NO_DISTANCE;

public:
	Node(const std::string& name = "");
	Node(const Node &rhs);
	Node& operator=(const Node &rhs);
	  
	std::string name() const	{	return m_name; }
	void name(const std::string& name)	{	m_name = name; }
   
	double distanceToParent() const { return m_distanceToParent; }
	void distanceToParent(double distance) { m_distanceToParent = distance; }

	Node* parent() const  { return m_parent; }
	void parent(Node* parent) { m_parent = parent; }
	void removeParent() { m_parent = NULL; }
	    
	bool isRoot() const { return m_parent == NULL; }
	bool isLeaf() const  { return m_children.empty(); }
 
	uint numberOfChildren() const { return m_children.size(); }
	Node* child(uint pos) const { return m_children[pos]; }
	const std::vector<Node*>& children() const { return m_children; }
	void addChild(Node* node);
	void removeChildren() { m_children.clear(); }
	void removeChild(uint pos);
	void removeChild(Node* node);
	
	std::vector<Node*> leaves();
	Strings leafNames();
	std::vector<Node*> nodes() { return breadthFirstOrder(); }
	std::vector<Node*> breadthFirstOrder();

	bool isProcessed() const { return m_bProcessed; }
	void setProcessed(bool bProcessed) { m_bProcessed = bProcessed; }

private:
	void leaves(Node* node, std::vector<Node*>& leafVector);
	void leafNames(Node* node, Strings& leafVector);

private:
	std::string m_name;
  
	Node* m_parent;
	double m_distanceToParent; 

	std::vector<Node*> m_children;

	bool m_bProcessed;
};