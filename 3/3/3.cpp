#include <iostream>
#include <vector>

using namespace std;

void Dijkstra(vector<vector<int>> graph, int n, vector<int>& res,int k)
{
	vector<bool> visited(n, false);
	vector<int> dist(n, INT_MAX);

	dist[k] = 0;

	for (int i = 0; i < n; i++)
	{
		int min = INT_MAX;
		int u = -1;

		for (int j = 0; j < n; j++)
		{
			if (visited[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
				break;
			}
		}

		if (u < -1)
			break;
		else
			visited[u] = true;

		int newDist;

		for (int j = 0; j < n; j++)
		{
			if (graph[u][j] == 0 || visited[j] == true)
				continue;

			newDist = dist[u] + graph[u][j];

			if (dist[j] > newDist)
				dist[j] = newDist;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (dist[i] < res[i])
			res[i] = dist[i];
	}
}

bool Includes(vector<int> array, int key)
{
	for (int i = 0; i < array.size(); i++)
	{
		if (key == array[i])
			return true;
	}

	return false;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<vector<int>> graph(n, vector<int>(n));
	vector<int> key(k);
	vector<int> res(n,INT_MAX);

	for (int i = 0; i < k; i++)
	{
		int value;
		cin >> value;
		key[i] = value - 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	

	for (int i = 0; i < k; i++)
	{
		Dijkstra(graph, n, res, key[i]);
	}

	int summ = 0;

	for (int i = 0; i < n; i++)
	{
		if (Includes(key, i))
			continue;
		else
			summ += res[i];
	}
	
	cout << summ;
}