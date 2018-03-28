#include <stdio.h>
#include <map>
#include <set>
#include <cmath>

using namespace std;

struct Point{
	double x;
	double y;
};


double getMinDistance(double x, double y, set<int> used, int idLast, double dis, map<int,Point> unused, int n){
	if(n==1)
		return 0;

	if(used.size()==n-1)
		return dis + sqrt(pow(x-unused[idLast].x, 2) + pow(y-unused[idLast].y, 2));

	double minDistance = 1000000000000000000;

	for(map<int,Point>::iterator it=unused.begin(); it!=unused.end(); ++it){
		if (used.find(it->first)==used.end()&&it->first!=idLast){
			used.insert(it->first);

			double distanceNext = sqrt(pow(x-it->second.x, 2) + pow(y-it->second.y, 2));
			double distance = getMinDistance(it->second.x, it->second.y, used, idLast, dis+distanceNext, unused, n);

			if(distance<minDistance)
				minDistance = distance;

			used.erase(it->first);
		}
	}

	return minDistance;
}


int main(){
	int N, id, first, last;
	double xi, yi;
	
	scanf("%d", &N);

	map<int,Point> points;

	for (int n = 0; n < N; ++n){
		scanf("%d %lf %lf", &id, &xi, &yi);
		Point cur = {xi, yi};
		points.insert(pair<int,Point>(id, cur));
	}
	
	scanf("%d %d", &first, &last);

	set<int> used;
	used.insert(first);
	printf("%0.2lf\n", getMinDistance(points[first].x, points[first].y, used, last, 0, points, N));

	return 0;
}