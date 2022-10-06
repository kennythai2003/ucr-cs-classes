#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm> //gcd
using namespace std;


char mapNumToLetter(int num) {
	if (num == 30){
		return ' ';
	}
	else if (num == 31){
		return '"';
	}
	else if (num == 32){
		return '.';
	}
	else if (num == 33){
		return ',';
	}
	else if (num == 34){
		return 39;
	}
	else {
		return num + 61;		
	}
}

int powMod(long long int c, unsigned int d, int n) {
	// (C^d mod(n))
	// Hint: C^d mod n = (C mod n * C^{d-1}) mod n (easy)
	// Hint: Can also implement squaring technique: C^d = (C*C)^(d/2) (harder)

    //c continously holds the base that will be squared and modded by n
    // n is const
    // d is the power that is continously halved till 1
    int m = 1;    
    
    //int counter = 1; for testing purposes
    
    while (d > 0){
      //keep halving D TILL D = 0 

      //test statement (IGNORE)
      // cout << endl << counter << ": " << "beginning: m = " 
      //<< m << " c = "<< c << " d = "<< d << " n = " << n << endl;
        
      //if d is even, we just half d and update the base (c)
        if (d % 2 == 0){
            c = (c * c) % n;
            //2. 2837*2837 % 7663 = 2419 = c
			
			d = d / 2; 
            //2. 2246 / 2 = 1123
        }
        else {
            //LAST ITERATION M IS ANSWER (happens when d = 1)
            
            m = (m * c) % n;
            //accounts for odd exponent and multiples the base to the outside 
            //1. M = 1 * 183 % 7663 = 183
            //last iteration  5092 * 1684  mod n = 31
            
			c = (c * c) % n;
            //1. 16384 % 7663 = 2837 = c (next number to be squared and modded)
            //last iteration: does not matter bc our m is found 
            
			d = d / 2; 
            //1. 4493 / 2 = 2246
            //last iteration 1 / 2 = 0; ->exits loop after done
            
        }
    
      //test statement (IGNORE)
      // cout << counter << ": " << "end: m = " << 
      //m << " c = "<< c << " d = "<< d << " n = " << n << endl;
      //  counter += 1;
    }

    return m;
}

bool isPrime(int num) {
	for (int i = 2; i < sqrt(num); ++i){
		if (num % i == 0){
			return false;
		}
	}
	return true;
} 
// Driver code
int main()
{

	int e,n,m;
	int c;
//  cout << "enter e n" << endl;
	cin >> e >> n;
//  cout << "enter m" << endl;
	cin >> m;
//  cout << e << " " << "n" << "m" << endl; 
	int p, q, phi = 0;

  vector<int> ciphers;
//  cout << "size: " << ciphers.size() << endl;
	for(int i = 0; i < m; ++i) {
//		cout << " enter an int: ";
    cin >> c;
//    cout << endl;
		ciphers.push_back(c);
	}
	//FINDING P & Q
	
	vector<int>primes; //holds the found prime factors of n
	int temp = n;
  
	//prime factorization efficency based off geeksforgeeks square root method
	while (temp % 2 == 0){
        primes.push_back(2);
        temp = temp/2;		
	}
    for (int i = 3; i <= sqrt(temp); i = i + 2){
        // While i divides n, print i and divide n
        while (temp % i == 0) {
            primes.push_back(i);
            temp = temp/i;
        }
    }	
    if (temp > 2){
        primes.push_back(temp);
    }

	p = primes.at(0);
	q = 0;

  	for (int i = 1; i < primes.size(); i++){
   		if (p * primes.at(i) == n){
    		q = primes.at(i);
    	}
 	}	 

  phi = (p - 1) * (q - 1);
   //re
 	bool rsaValidity = true; 
  if (p == q){
		rsaValidity = false;
	}
	if (!isPrime(p)){
		rsaValidity = false;
	}
	if (!isPrime(q)){
		rsaValidity = false;
	}
	if (__gcd(e, phi) != 1){
		rsaValidity = false;
	}

  if (!rsaValidity){
    cout << "Not a valid public key pair." << endl;
    return 0;
  }

  long long int d = 0;
  int cnt = 1;
  while ((phi * cnt + 1) % e != 0){
    //d = (phi * cnt + 1) % e;
    cnt += 1; 
    //cout << endl << "d: " << d <<  " cnt: " << cnt << endl;
  }
  d = (phi * cnt + 1) / e;
  
  cout << p << " " << q << " " << phi << " "<< d <<endl;
  vector<int>cipheredNum; 
  for (int i = 0; i < m; ++i){
    cout << powMod(ciphers.at(i), d, n) << " ";
    cipheredNum.push_back(powMod(ciphers.at(i), d, n));
  }
  cout << endl; 
//  cout << "decrypted number: " << powMod(c, d, n) << endl;
  for (int i = 0; i < m; ++i){
  cout << mapNumToLetter(cipheredNum.at(i));
  }
//  cout << endl; 
  return 0; 
}
 