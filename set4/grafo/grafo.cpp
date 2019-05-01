#include"grafo.h"

Grafo::Grafo(const vector<int> &inicio, const vector<int> &fin){
    if(inicio.size()!=fin.size()){
        throw invalid_argument("inicio/fin no tienen la misma longitud");
    }
    for(int i=0;i<inicio.size();i++){
        int start=inicio[i];
        int end=fin[i];
        m_outgoing[start].push_back(end);
        m_outgoing[end];
    }
}

const vector<int> &Grafo::adjacent(const int nodeID) const{
    map<int, vector<int> >::const_iterator it=m_outgoing.find(nodeID);
    if(it==m_outgoing.end())
        throw invalid_argument("No existe tal nodo");
    return it->second;
}

int Grafo::numOutgoing(const int nodeID) const{
    return adjacent(nodeID).size();
}
