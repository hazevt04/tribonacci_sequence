// C++ File for main

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

std::vector<int> tribonacci( std::vector<int> signature, int n ) {
   std::vector<int> result;
   int index_max = ( n < signature.size() ) ? n : signature.size();
   for( int index = 0; index < index_max; ++index ) {
      result.push_back( signature[index] );
   } 
   for( int index = 3; index < n; ++index ) {
      result.push_back( result[index-3] + result[index-2] + result[index-1] );
   } 
   return result;
}


std::vector<int> tribonacci2( std::vector<int> signature, int n ) {
   std::vector<int> result;
   int index_max = ( n < signature.size() ) ? n : signature.size();
   for( int index = 0; index < index_max; ++index ) {
      result.push_back( signature[index] );
   } 
   for( int index = 3; index < n; ++index ) {
      result.push_back( result[index-3] + result[index-2] + result[index-1] );
   } 
   return result;
}


int main( int argc, char* argv[] ) {

   std::vector<std::tuple<std::vector<int>, int>> tests{
         {{1, 1, 1}, 10},
         {{0, 0, 1}, 10},
         {{0, 1, 1}, 10},
         {{1, 0, 0}, 10},
         {{1, 2, 3}, 10},
         {{1, 2, 3}, 2},
         {{1, 2, 3}, 0}
   };
   
   //std::vector<std::tuple<int, std::tuple<int, int, int>>> tests;
   //tests.push_back( std::make_tuple(10, {1, 1, 1}));
      
   
   int i = 0;
   for( auto test : tests ) {
      std::cout << "Test " << i << ":\n"; 
      //std::cout << "For loop: Test " << std::get<0>(test) << " field 1 is " << std::get<1>(test) << "\n"; 

      std::vector<int> signature = std::get<0>(test);

      std::cout << "\tSignature = ["; 
      for ( auto val: signature ) {
         std::cout << " " << val; 
      }
      std::cout << " ]\n";
      
      int num_vals = std::get<1>(test);
      std::cout << "\tNum Values = " << num_vals << "\n"; 
      std::vector<int> result = tribonacci( signature, num_vals );

      std::cout << "\tResult = ["; 
      for ( auto val : result ) {
         std::cout << " " << val; 
      }
      std::cout << " ]\n\n"; 
      ++i;
   }
   return 0;
}

