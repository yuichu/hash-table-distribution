#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemPallet.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int sku) {
  unsigned int hashValue;
  hashValue = sku / 100000;
	return hashValue;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int sku) {
   unsigned int hashValue;
   hashValue = sku % 100000;
   hashValue = hashValue / 10000;
	return hashValue;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int sku) {
   unsigned int hashValue;
   hashValue = sku % 10000;
   hashValue = hashValue / 1000;
	return hashValue;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int sku) {
   unsigned int hashValue;
   hashValue = sku % 1000;
   hashValue = hashValue / 100;
	return hashValue;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int sku) {
    unsigned int hashValue;
    hashValue = sku % 100;
    hashValue = hashValue / 10;
	return hashValue;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int sku) {
    unsigned int hashValue;
    hashValue = sku % 10;
	return hashValue;
}

// Constructor for struct Item
Item::Item(string itemName, unsigned int sku):itemName_(itemName), sku_(sku)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemPallet::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemName;
    unsigned int sku;
    while (myfile >> itemName >> sku) {
			if (itemName.size() > 0)
      	addItem(itemName, sku);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemPallet::addItem(string itemName, unsigned int sku) {
  hT1[itemName, sku];
  hT2[itemName, sku];
  hT3[itemName, sku];
  hT4[itemName, sku];
  hT5[itemName, sku];
  hT6[itemName, sku];
}

bool ItemPallet::removeItem(unsigned int sku) {
  hT1.erase(sku);
  hT2.erase(sku);
  hT3.erase(sku);
  hT4.erase(sku);
  hT5.erase(sku);
  hT6.erase(sku);
  return true;
}

  
// Pseudocode:
// for i=0 to 9 do
//   if number in bucket is less than minimum number do
//     minimum = number in bucket at position i
//   if number in bucket is greater than maximum number do
//     maximum = number in bucket at position i
// balance = maximum - minimum
// hashTableNumber = the hash table at which lowest balance is calculated
unsigned int ItemPallet::bestHashing() {
  unsigned int min = 0;
  unsigned int max = 0;
  unsigned int balance = 0;
  unsigned int hashTableNumber = 0;

  //hT1
  min = hT1.bucket_size(0);
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT1.bucket_size(i) < min)
    {
      min = hT1.bucket_size(i);
    }
    if (hT1.bucket_size(i) > max)
    {
      max = hT1.bucket_size(i);
    }
  }
  balance = max - min;
  hashTableNumber = 1;

  //hT2
  min = hT2.bucket_size(0);
  max = 0;
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT2.bucket_size(i) < min)
    {
      min = hT2.bucket_size(i);
    }
    if (hT2.bucket_size(i) > max)
    {
      max = hT2.bucket_size(i);
    }
  }

  if (balance > max-min)
  {
    balance = max-min;
    hashTableNumber = 2;
  }

  //hT3
  min = hT3.bucket_size(0);
  max = 0;
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT3.bucket_size(i) < min)
    {
      min = hT3.bucket_size(i);
    }
    if (hT3.bucket_size(i) > max)
    {
      max = hT3.bucket_size(i);
    }
  }

  if (balance > max-min)
  {
    balance = max-min;
    hashTableNumber = 3;
  }

  //hT4
  min = hT4.bucket_size(0);
  max = 0;
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT4.bucket_size(i) < min)
    {
      min = hT4.bucket_size(i);
    }
    if (hT4.bucket_size(i) > max)
    {
      max = hT4.bucket_size(i);
    }
  }
  
  if (balance > max-min)
  {
    balance = max-min;
    hashTableNumber = 4;
  }

  //hT5
  min = hT5.bucket_size(0);
  max = 0;
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT5.bucket_size(i) < min)
    {
      min = hT5.bucket_size(i);
    }
    if (hT5.bucket_size(i) > max)
    {
      max = hT5.bucket_size(i);
    }
  }
  
  if (balance > max-min)
  {
    balance = max-min;
    hashTableNumber = 5;
  }

  //hT6
  min = hT6.bucket_size(0);
  max = 0;
  for (unsigned i=0; i<10; ++i) 
  {
    if (hT6.bucket_size(i) < min)
    {
      min = hT6.bucket_size(i);
    }
    if (hT6.bucket_size(i) > max)
    {
      max = hT6.bucket_size(i);
    }  
  }

  if (balance > max-min)
  {
    balance = max-min;
    hashTableNumber = 6;
  }
  
    return hashTableNumber;
}

// ALREADY COMPLETED
size_t ItemPallet::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) )
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}