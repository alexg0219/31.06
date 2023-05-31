#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,s,v;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> s >> v;
			graph[i][j] = s / v;
		}
			

	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);

	dist[0] = 0;

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

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] > max)
			max = dist[i];
	}

	cout << max;
}