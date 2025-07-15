#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fill;
using std::string;

using std::ios;

int N, C;
int UF[2001];

int Find(int _i)
{
    if (UF[_i] < 0) return _i;
    return UF[_i] = Find(UF[_i]);
}

int Union(int _i1, int _i2)
{
    _i1 = Find(_i1);
    _i2 = Find(_i2);
    if (_i1 == _i2) return false;
    UF[_i2] = _i1;
    return true;
}

struct Edge
{
    int m_iU, m_iV, m_iW;
    Edge() : Edge(-1, -1, 0) {}
    Edge(int _iU, int _iV, int _iW) : m_iU(_iU), m_iV(_iV), m_iW(_iW) {}
    bool operator <(const Edge& _Other)const { return m_iW < _Other.m_iW; }
};

struct Node
{
    int m_iX, m_iY;
};

int main()
{
    cin >> N >> C;

    vector<Node> Nodes(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Nodes[i].m_iX >> Nodes[i].m_iY;
    }

    vector<Edge> Edges;

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int iWeight = (Nodes[i].m_iX - Nodes[j].m_iX) * (Nodes[i].m_iX - Nodes[j].m_iX)
                + (Nodes[i].m_iY - Nodes[j].m_iY) * (Nodes[i].m_iY - Nodes[j].m_iY);
            if (iWeight >= C)
            {
                Edges.push_back(Edge(i, j, iWeight));
            }
        }
    }

    sort(Edges.begin(), Edges.end());

    fill(UF, UF + N, -1);

    int iResult = 0;
    int iCount = 0;

    for (int i = 0; i < Edges.size(); ++i)
    {
        if (Union(Edges[i].m_iU, Edges[i].m_iV))
        {
            iResult += Edges[i].m_iW;

            if (++iCount == N - 1)
                break;
        }
    }

    if (iCount < N - 1)
    {
        iResult = -1;
    }

    cout << iResult;

    return 0;
}