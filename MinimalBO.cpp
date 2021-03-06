#include "pch.h"
#include <iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <cassert>
#include <windows.h>
#include <time.h>

using namespace std;

struct Point {
	int x;
	int y;
};

int main()
{
	int n;
	cout << "Enter the number of points: ";
	cin >> n;
	vector<Point> p;
	
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		p.push_back(Point{ x,y });
	}
	
	sort(p.begin(), p.end(), [](const Point &left, const Point &right) 
	{
		if (left.y != right.y) {
			return left.y < right.y;
		}
		return left.x < right.x;
	});
	p.erase(unique(p.begin(), p.end(), [](const Point &left, const Point &right) {
		return left.x == right.x && left.y == right.y; }), p.end());
	n = (int)p.size();
	if (n == 1) 
	{
		cout << "Only one point:" << p[0].x << p[0].y<< endl;
		return 0;
	}
	double dx = -1;
	double dy = 0;
	int cur = 0;
	vector<Point> perim;
	cout << "True points:" << endl;
	while (true) 
	{
		cout << p[cur].x << " " << p[cur].y << endl;
		perim.push_back(p[cur]);
		int next = -1;
		double bestcos = -2;
		for (int i = 0; i < n; i++) 
		{
			if (i != cur) 
			{
				int ndx = p[i].x - p[cur].x;
				int ndy = p[i].y - p[cur].y;
				double cos = (dx*ndx + dy * ndy) / sqrt(ndx*ndx + ndy * ndy);
				if (cos > bestcos)
				{
					next = i;
					bestcos = cos;
				}
			}
		}
		assert(bestcos != -2);
		dx = p[next].x - p[cur].x;
		dy = p[next].y - p[cur].y;
		double len = sqrt(dx*dx + dy * dy);
		dx /= len;
		dy /= len;
		cur = next;
		if (cur == 0)
		{
			break;
		}
	}
	
}


