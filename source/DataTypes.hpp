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

// basic data types
typedef unsigned int uint;
typedef unsigned char byte;
typedef unsigned long ulong;

typedef std::vector< std::vector<double> > Matrix;
typedef std::vector< std::vector<uint> > AdjacencyMatrix;
typedef std::vector<std::string> Strings;

typedef std::vector<bool> BoolVec;

struct FreqPair
{
	FreqPair(): f1(0), f2(0) {}
	FreqPair(const BoolVec& _split, double _f1, double _f2): split(_split), f1(_f1), f2(_f2) {}

	BoolVec split;
	double f1;
	double f2;
};