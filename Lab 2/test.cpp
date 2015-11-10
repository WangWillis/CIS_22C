#include <iostream>
#include "Money.h"
#include "List.h"

using namespace std;

List<int> makeList(){
	int i = 1;
	List<int> temp(i);
	return temp;
}

// List<Currency*> makeDollar(){
// 	Dollar* d1 = new Dollar(1,1);
// 	List<Currency*> temp(d1);
// 	return temp;
// }

int main(){
	List<int> l1 = makeList();
	// List<Currency*> l2 = makeDollar();
	cout << l1.getHeadData() << endl;
	// l2.getHeadData()->toString();
	// delete l2.getHeadData();
	return 0;
}