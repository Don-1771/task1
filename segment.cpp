#include <iostream>
#include <fstream>
#include <vector>
//---------------------------------------------------------------------------------------------
struct Point
{
   Point(int x, int y): x{x}, y{y} {}
   int x;
   int y;

   Point()
   {
      x = 0;
      y = 0;
   }
};
//---------------------------------------------------------------------------------------------
void From_file(std::vector<Point>& points) {
   std::ifstream fin("data.txt", std::ifstream::in);
   while (!fin.eof())

   {
      int N;
      fin >> N;
      points.resize(N);
      while (!fin.eof()) {
         int x, y;
         int i = 0;
         while (fin >> x >> y)
         {
            points.at(i) = Point{ x, y };
            ++i;
         }
      }

   }
   fin.close();
}

//---------------------------------------------------------------------------------------------
int Count_point(std::vector<Point>& points) {
   int count_point = 0;
   int l, r;
   for (int i = 0; i < points.size(); ++i) {
      l = points.at(i).x;
      r = points.at(i).y;
      count_point++;

      int j = i + 1;

      while (j < points.size()) {


         int l_j = points.at(j).x;
         int r_j = points.at(j).y;

         if ((l_j < l && r_j > r) || l_j == l || r_j ==r ) {
            points.erase(points.begin() + j);

         }

         if (l_j > l && l_j < r) {
            l = l_j;               
            points.erase(points.begin() + j);

         }

         if (r_j > l && r_j < r) {
            r = r_j;               
            points.erase(points.begin() + j);

         }        
         ++j;
      }
      points.erase(points.begin() + i);
   }
   return count_point;
}
//---------------------------------------------------------------------------------------------
int main()
{  
   std::vector<Point> points(1);
   int count_point = 0;

   From_file(points);
   count_point = Count_point(points);
   std::cout << count_point << std::endl;
      
}