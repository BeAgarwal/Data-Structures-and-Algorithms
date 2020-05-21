/*Code is written by Shubham Agarwal. Feel free to contribute.*/

/*  Execute it with C++17.
	vector,	list,	map, pair, forward_list, set, unordered_set, queue, deque, stack
*/

#include<bits/stdc++.h>
using namespace std;

bool fun(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("inputf.in", "r", stdin);
// 	freopen("outputf.in", "w", stdout);
// #endif

	vector<int> v = {12, 1, 5, 34, 53};

	vector<int> v2[5]; //Arrays of vector with size 5

	v.push_back(31);	//Pushing more element in vector
	v.push_back(31);	//Time complexity of push_back is O(1)
	v.push_back(31);
	v.push_back(39);

	for (int i = 0; i < v.size(); i++)	//Printing vector
		cout << v[i] << " ";	//12 1 5 34 53 31 31 31 39
	cout << endl;

	sort(v.begin(), v.end());	//Sort in ascending order
	//This sort function is in algorithm library

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " "; //1 5 12 31 31 31 34 39 53

	cout << endl;

	if (binary_search(v.begin(), v.end(), 53))	//Searching 53 in the vector
		cout <<  "Present" << endl;				//It uses O(log N) time complexity
	//This binary_search function is in algorithm library


	vector<int>::iterator lb = lower_bound(v.begin(), v.end(), 31);	//>=
	auto ub = upper_bound(v.begin(), v.end(), 31);	//>
	cout << "LB: " << *lb << " UB: " << *ub << endl;	//LB: 31 UB: 34
	cout << ub - lb << endl;	//3

	sort(v.begin(), v.end(), fun);	//Sort in descending order. It takes O(Nlog N) time complexity
	//we can use greater<int>() instead of fun function

	vector<int>::iterator it;		//This is how we can print vector using iterators
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}//53 39 34 31 31 31 12 5 1
	cout << endl;

	for (int x : v) {	//This enhanced for loop can also be used to print vector
		cout << x << " ";
	}//53 39 34 31 31 31 12 5 1
	cout << endl;


	set<int> s;	//Set internally maintains the ascending sequence
	//Set is implemented as a balanced tree structure
	s.insert(1);	//Each operation of set takes O(log N) time
	s.insert(5);
	s.insert(3);

	for (int x : s) {
		cout << x << " ";
	}	//1 3 5
	cout << endl;

	unordered_set<int> s2;	//Unordered_set is a set in which key can be stored in any order
	//unordered_set is implemented using a hash table where keys are hashed into indices of a hash table so the insertion is always randomized
	s2.insert(1);	//The time complexity of unordered_set operations is O(1)
	s2.insert(5);
	s2.insert(2);
	s2.insert(6);
	s2.erase(6);

	for (int x : s2) {
		cout << x << " ";
	}	//2 1 5
	cout << endl;

	//find returns end iterator if key is not found, else it returns iterator to that key
	if (s2.find(5) == s2.end()) {
		cout << "not found" << endl;
	} else {
		cout << "found" << endl;
	}

	//LIST
	list<int> l;	//Its doubly linked list
	//If we want singly linked list, then we have to use forward_list
	l.push_back(100);
	l.push_back(17);
	l.push_back(34);
	l.push_back(55);
	for (int i = 1; i <= 10; i++) {
		l.push_back(i * 3);
	}


	list<int>::iterator itr;
	for (itr = l.begin(); itr != l.end(); itr++) {
		cout << *itr << " ";
	} cout << endl;
	//100 17 34 55 3 6 9 12 15 18 21 24 27 30

	cout << "Front: " << l.front() << endl;	//100 Front at list
	cout << "Back: " << l.back() << endl;	//30 Back at list
	l.pop_front();	//Deleting front
	l.pop_back();	//Deleting back
	l.reverse();	//Reverse the list
	l.sort();	//Sort the list
	//3 6 9 12 15 17 18 21 24 27 34 55


	for (itr = l.begin(); itr != l.end(); itr++) {
		cout << *itr << " ";	//3 6 9 12 15 17 18 21 24 27 34 55
	} cout << endl;


	//FORWARD LIST
	forward_list<int> fl;	//Singly Linked List
	fl.assign({2, 3, 4});
	fl.push_front(1);
	fl.push_front(0);
	fl.pop_front();		//delete the first element
	fl.insert_after(fl.begin(), {5, 6, 7});	//insert after any particular element
	fl.remove(5);	//remove the particular element

	for (int &a : fl)
		cout << a << " ";	//1 6 7 2 3 4
	cout << endl;

	//STACK
	stack<int> stk;
	for (int i = 10; i <= 100; i += 10) {
		stk.push(i);
	}
	cout << stk.size() << endl;	//10
	while (!stk.empty()) {
		cout << stk.top() << " ";	//100 90 80 70 60 50 40 30 20 10
		stk.pop();
	} cout << endl;

	//QUEUE
	queue<int> q;
	for (int i = 10; i <= 100; i += 10) {
		q.push(i);
	}
	cout << q.size() << endl;	//10
	cout << q.front() << endl;	//10
	cout << q.back() << endl;	//100
	while (!q.empty())
	{
		cout << q.front() << " ";	//10 20 30 40 50 60 70 80 90 100
		q.pop();
	}
	cout << endl;

	//DEQUE
	deque<int> dq;
	dq.push_back(10);	//10
	dq.push_front(30);	//30 10
	dq.push_back(40);	//30 10 40
	dq.push_front(20);	//20 30 10 40
	dq.push_back(50);	//20 30 10 40 50
	dq.push_front(70);	//70 20 30 10 40 50
	dq.push_back(80);	//70 20 30 10 40 50 80
	dq.push_front(90);	//90 70 20 30 10 40 50 80

	deque <int> :: iterator itrr;
	for (itrr = dq.begin(); itrr != dq.end(); ++itrr)
		cout << *itrr << " ";	//90 70 20 30 10 40 50 80
	cout << endl;

	cout << dq.size() << endl;	//8
	cout << dq.max_size() << endl;	//2305843009213693951
	cout << dq.front() << endl;	//90
	cout << dq.back() << endl;	//80
	cout << dq.at(5) << endl;	//40
	dq.pop_front();
	dq.pop_back();

	deque <int> :: iterator itrr1;
	for (itrr1 = dq.begin(); itrr1 != dq.end(); ++itrr1)
		cout << *itrr1 << " ";	//70 20 30 10 40 50
	cout << endl;

	//MAP
	map<int, int> M;	//key value
	M[1] = 100;
	M[2] = 200;
	M[3] = 150;

	map<char, int> M1;
	string str = "shubham agarwal";	//4
	for (char c : str) {
		M1[c]++;
	}
	cout << M1['a'] << endl;

	map<int, int> map1;

	// insert elements in random order
	map1.insert(pair<int, int>(1, 40));
	map1.insert(pair<int, int>(2, 30));
	map1.insert(pair<int, int>(3, 60));
	map1.insert(pair<int, int>(4, 20));
	map1.insert(pair<int, int>(5, 50));
	map1.insert(pair<int, int>(6, 50));
	map1.insert(pair<int, int>(7, 10));

	// printing map map1
	map<int, int>::iterator itrr2;
	for (itrr2 = map1.begin(); itrr2 != map1.end(); ++itrr2) {
		cout << '\t' << itrr2->first
		     << '\t' << itrr2->second << '\n';
	}
	/*	1	40
		2	30
		3	60
		4	20
		5	50
		6	50
		7	10
	*/
	cout << endl;

	//PAIR
	set<pair<int, int> > Set;
	Set.insert({2, 5});
	Set.insert({10, 20});
	Set.insert({100, 250});

	return 0;
}



/*OUTPUT
12 1 5 34 53 31 31 31 39 
1 5 12 31 31 31 34 39 53 
Present
LB: 31 UB: 34
3
53 39 34 31 31 31 12 5 1 
53 39 34 31 31 31 12 5 1 
1 3 5 
2 1 5 
found
100 17 34 55 3 6 9 12 15 18 21 24 27 30 
Front: 100
Back: 30
3 6 9 12 15 17 18 21 24 27 34 55 
1 6 7 2 3 4 
10
100 90 80 70 60 50 40 30 20 10 
10
10
100
10 20 30 40 50 60 70 80 90 100 
90 70 20 30 10 40 50 80 
8
2305843009213693951
90
80
40
70 20 30 10 40 50 
4
	1	40
	2	30
	3	60
	4	20
	5	50
	6	50
	7	10

*/
