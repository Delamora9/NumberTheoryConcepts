#include <iostream>
using namespace std;
#include <vector>

/*
Author: Nick Delamora
Date Created: 08/14/18

Number Theory Mathematics Project

Division Algorithm: For any integer n and positive integer b there 
exists unique integers q and r such that n = qb+r and 0 <= r < b.
*/

void printDivisionAlgorithm(vector<vector<int> > vv){
  for(int i = 0; i < vv[0].size(); i++){
    cout << vv[0][i] << " = " << vv[1][i] << "*" << vv[2][i]
         << " + " << vv[3][i] << "\n\n";
  }
}

vector<vector<int> > divisionAlogorithm(int n, int b){
  vector<int> remainders;
  vector<int> quotients;
  vector<int> bees;
  vector<int> nums;
  vector<vector<int> > values;
  int q;
  int r;
  int count = 0;
  
  while(r > 1 || nums.size() == 0){
    nums.push_back(n);
    bees.push_back(b);
    q = 0;
    while((q+1)*b <= n){
      q += 1;
    }
    quotients.push_back(q);
    r = n - (q*b);
    remainders.push_back(r);
    n = b;
    b = r; 
    count += 1;
  }

  cout << count << " step(s)\n";

  values.push_back(nums);
  values.push_back(quotients);
  values.push_back(bees);
  values.push_back(remainders);
  return values;
}


int main() {
  //Parameters
  //If b divides n then the greatest common divisor is b
  //aka vv[0].size == 1 and the gcd is vv[2][0]
  //Otherwise the gcd is the last non-zero remainder
  //aka if vv[3][vv.size-1] == 0 gcd = vv[3][vv.size-2]
  //else gcd = vv[3][vv.size-1]
  int n = 523764;
  int b = 234367;

  if(b > n){
    cout << "Please choose a number n that is larger than b";
  }
  else{
      //Compute values following the division algorithm
  vector<vector<int> > results = divisionAlogorithm(n, b);

  cout << "Starting with n = " << n << " and b = " << b << " we get:\n\n";
  printDivisionAlgorithm(results);
  }

  return 0;  
} 