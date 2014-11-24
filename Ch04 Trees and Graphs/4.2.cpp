/*
 * 4.2.cpp
 *
 * Given a directed graph, design an algorithm to find out whether there is a route between two nodes
 *
 * SOLUTION
 * - DFS returns route
 * - BFS would be complicated to return route
 *
 *  Created on: Nov 19, 2014
 *      Author: Milan Fan
 */


#include <iostream>
#include <stack>
using namespace std;

#define MAX_NODE	10

struct GraphNode {
	bool isVisited;		// node visited
	int adjCount;		// # of adjacent nodes
	int adjVisited;		// # of visited adjacent nodes
	int *adj;			// adjacent nodes
	GraphNode() : isVisited(false), adjCount(0), adjVisited(0), adj(new int[MAX_NODE]) {};
};

GraphNode g[MAX_NODE];	// 0 ~ MAX_NODE-1

void init()
{
	for (int i = 0; i < MAX_NODE; i++) {
		g[i].isVisited = false;
		g[i].adjVisited = 0;
	}
}

stack<int> DFS(int ori, int dst)
{
	stack<int> ret;

	ret.push(ori);
	g[ori].isVisited = true;
	while (!ret.empty()) {
		int n = ret.top();
		if (n == dst) return ret;
		if (g[n].adjVisited < g[n].adjCount) {
			ret.push(g[n].adj[g[n].adjVisited]);
			g[g[n].adj[g[n].adjVisited]].isVisited = true;
			g[n].adjVisited++;
		} else {
			ret.pop();
		}
	}

	return ret;
}

int main()
{
	int a[][2] = { {1, 5}, {3, 5}, {5, 2}, {5, 4} };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		g[a[i][0]].adj[g[a[i][0]].adjCount] = a[i][1];
		g[a[i][0]].adjCount++;
	}

	while (true) {
		int ori, dst;
		stack<int> ret;
		cin >> ori;
		if (ori < 0 ||  ori >= MAX_NODE) break;
		cin >> dst;
		if (dst < 0 ||  dst >= MAX_NODE) break;
		ret = DFS(ori, dst);
		cout << ori << " to " << dst << ": ";
		if (!ret.empty()) {
			stack<int> s;
			while (!ret.empty()) {
				s.push(ret.top());
				ret.pop();
			}
			cout << s.top();
			s.pop();
			while (!s.empty()) {
				cout << " -> " << s.top();
				s.pop();
			}
			cout << endl;
		} else
			cout << "Not connected" << endl;
		init();
	}
	cout << "End" << endl;

	return 0;
}
