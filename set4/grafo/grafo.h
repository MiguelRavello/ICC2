#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Grafo{
protected:
    map<int, vector<int> > m_outgoing;
public:
    Grafo(const vector<int> &inicio, const vector<int> &fin);
    int numOutgoing(const int nodeID) const;
    const vector<int> &adjacent(const int nodeID) const;
};


#endif
