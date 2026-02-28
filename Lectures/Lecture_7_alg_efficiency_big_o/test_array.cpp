/** @file test_array.cpp
 * @author G. Zhou
 */

#define CATCH_CONFIG_MAIN

#include "ArrayBagInt.hpp"
#include "catch.hpp"

TEST_CASE("Test remove method", "[ArrayBagInt]")
{
  ArrayBagInt bag;
  REQUIRE(bag.isEmpty());
  for (int i = 0; i < 100; i++)
  {
    bag.add(i * i - 24 * i + 100); // just add 100 items, some of which are duplicates
                                   // 100, 77, 56, etc.
  }
  REQUIRE(bag.getCurrentSize() == 100);

  // test remove method
  REQUIRE(bag.remove(100)); // remove an item
  REQUIRE(bag.getCurrentSize() == 99);

  // test remove2 method
  REQUIRE(bag.remove2(77)); // remove an item
  REQUIRE(bag.getCurrentSize() == 98);
}

TEST_CASE("Test clear method", "[ArrayBagInt]")
{
  ArrayBagInt bag;
  REQUIRE(bag.isEmpty());

  // test clear method
  for (int i = 0; i < 100; i++)
  {
    bag.add(i * i - 24 * i + 100); // just add 100 items, some of which are duplicates
                                   // 100, 77, 56, etc.
  }
  REQUIRE(bag.getCurrentSize() == 100);
  bag.clear();
  REQUIRE(bag.isEmpty());

  // test clear2 method
  for (int i = 0; i < 100; i++)
  {
    bag.add(i * i - 24 * i + 100);
  }
  REQUIRE(bag.getCurrentSize() == 100);
  bag.clear2();
  REQUIRE(bag.isEmpty());

  // test clear3 method
  for (int i = 0; i < 100; i++)
  {
    bag.add(i * i - 24 * i + 100);
  }
  REQUIRE(bag.getCurrentSize() == 100);
  bag.clear3();
  REQUIRE(bag.isEmpty());

  // test clear4 method
  for (int i = 0; i < 100; i++)
  {
    bag.add(i * i - 24 * i + 100);
  }
  REQUIRE(bag.getCurrentSize() == 100);
  bag.clear4();
  REQUIRE(bag.isEmpty());
}

TEST_CASE("Test remove/clear with timestamp", "[ArrayBagInt]")
{
  ArrayBagInt bag;

  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  REQUIRE(bag.getCurrentSize() == 100000);
  clock_t start = clock();
  bag.remove(500 * 500); // remove an item in the middle
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "remove() time used: " << seconds << " seconds" << std::endl;

  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  start = clock();
  bag.remove2(500 * 500 + 24 * 500 + 100); // remove an item in the middle
  end = clock();
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "remove2() time used: " << seconds << " seconds" << std::endl;

  bag.clear();
  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  start = clock();
  bag.clear();
  end = clock();
  REQUIRE(bag.isEmpty());
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "clear() time used: " << seconds << " seconds" << std::endl;

  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  start = clock();
  bag.clear2();
  end = clock();
  REQUIRE(bag.isEmpty());
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "clear2() time used: " << seconds << " seconds" << std::endl;

  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  start = clock();
  bag.clear3();
  end = clock();
  REQUIRE(bag.isEmpty());
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "clear3() time used: " << seconds << " seconds" << std::endl;

  for (int i = 0; i < 100000; i++)
  {
    bag.add(i * i);
  }
  start = clock();
  bag.clear4();
  end = clock();
  REQUIRE(bag.isEmpty());
  seconds = (double)(end - start) / CLOCKS_PER_SEC;
  std::cout << "clear4() time used: " << seconds << " seconds" << std::endl;

  // TODO:
  // How would you continue to write more test cases for clear4() method to prove
  // Hint: decrease or increase the size of the bag by a factor
}

TEST_CASE("Test clear4() with timestamp n = 10", "[ArrayBagInt]")
{
  ArrayBagInt bag10;

  for (int i = 0; i < 2; i++){
    bag10.add(i);
  }

  clock_t start = clock();
  bag10.clear4();
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  REQUIRE(bag10.isEmpty());
  std::cout << "clear4() time used when n = 10: " << seconds << " seconds" << std::endl;

}
TEST_CASE("Test clear4() with timestamp n = 100", "[ArrayBagInt]")
{
  ArrayBagInt bag100;

  for (int i = 0; i < 100; i++)
  {
    bag100.add(i);
  }

  clock_t start = clock();
  bag100.clear4();
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  REQUIRE(bag100.isEmpty());
  std::cout << "clear4() time used when n = 100: " << seconds << " seconds" << std::endl;
}

TEST_CASE("Test clear4() with timestamp n = 1000", "[ArrayBagInt]")
{
  ArrayBagInt bag1000;

  for (int i = 0; i < 1000; i++)
  {
    bag1000.add(i);
  }

  clock_t start = clock();
  bag1000.clear4();
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  REQUIRE(bag1000.isEmpty());
  std::cout << "clear4() time used when n = 1000: " << seconds << " seconds" << std::endl;
}

TEST_CASE("Test clear4() with timestamp n = 10000", "[ArrayBagInt]")
{
  ArrayBagInt bag10000;

  for (int i = 0; i < 10000; i++)
  {
    bag10000.add(i);
  }

  clock_t start = clock();
  bag10000.clear4();
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  REQUIRE(bag10000.isEmpty());
  std::cout << "clear4() time used when n = 10000: " << seconds << " seconds" << std::endl;
}

TEST_CASE("Test clear4() with timestamp n = 100000", "[ArrayBagInt]")
{
  ArrayBagInt bag100000;

  for (int i = 0; i < 100000; i++)
  {
    bag100000.add(i);
  }

  clock_t start = clock();
  bag100000.clear4();
  clock_t end = clock();
  double seconds = (double)(end - start) / CLOCKS_PER_SEC;
  REQUIRE(bag100000.isEmpty());
  std::cout << "clear4() time used when n = 100000: " << seconds << " seconds" << std::endl;
}

//when the magnitude of n increases by a factor of 10, the time used for clear4() 
//increases by a factor of 100, which indicates that the time complexity of 
//clear4() is O(n^2).