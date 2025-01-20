#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("oldfront");
	list.push_back("oldback");

	//EXPECT_TRUE(checkListContent(&list, {"oldfront", "oldback"}));

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");
  cout << "HELLOOOEOEOEOEOEOEEOO" << endl;
	//EXPECT_TRUE(checkListContent(&list, {"newfront", "oldback"}));

	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");
  cout << "HIIIIIYYIYYYIIIIII" << endl;
  list.get(0);
  list.get(1);

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront", "newfront"}));

	// now, the original head should get deleted
	list.pop_back();

	//EXPECT_TRUE(checkListContent(&list, {"cloudfront"}));

	list.pop_front();

	//EXPECT_TRUE(checkListContent(&list, {}));

	list.push_front("newback");
  cout << "HEYYYYYYYEYEYEEYYEYYYYY" << endl;
	//EXPECT_TRUE(checkListContent(&list, {"newback"}));

  list.clear();

/*
  dat.push_back("XYZ?");
  dat.pop_back();
  dat.push_front("Def");
  dat.pop_front();
  dat.push_back("Ghi");
  dat.push_front("Jkl");

  dat.push_back("Mno");
  dat.push_front("Qrs");
  cout << dat.get(0) << " " << dat.get(6) << " " << dat.get(13) << endl;
  dat.pop_back();
  dat.pop_front();
  cout << "Front: " << dat.front() << endl;
  cout << "Back: " << dat.back() << endl;
  */
  return 0;
}
