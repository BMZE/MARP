//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
////O(n) where n is the number of possible movies to watch
//bool SolveCase()
//{
//	int n; cin >> n;
//	if (n == 0)
//		return false;
//
//	vector<pair<int, int>> movies;
//	movies.resize(n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int h; int m; int t;  char c;
//		cin >> h >> c >> m >> t;
//		movies[i].first = h * 60 + m; //time of projection in minutes
//		movies[i].second = t + 10; //duration of movie plus rest time
//	}
//
//	sort(movies.begin(), movies.end());
//
//	int solution = 1;
//
//	int current = 0;
//
//	for (int i = 1; i < n; i++)
//	{
//		if (movies[current].first + movies[current].second <= movies[i].first) //time to watch the movie and get to the next one
//		{
//			current = i;
//			solution++;
//		}
//		else if(movies[current].first + movies[current].second > movies[i].first //current movie ends later than start of the next one 
//			&& movies[current].first + movies[current].second > movies[i].first + movies[i].second) //and ends after the next one ends
//		{
//			current = i;
//		}
//	}
//
//	cout << solution << '\n';
//
//	return true;
//}
//
//int main()
//{
//	while (SolveCase());
//	return 0;
//}