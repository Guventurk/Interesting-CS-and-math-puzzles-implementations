/*
this program is written to solve towers of hanoi problem using recursion.

we have three disks: A B and C
allowed to move one disk at a time and never transfer a larger one into a smaller.
*/

#include <iostream>
#include <stack>

template <typename T>
void print_stack(std::stack<T>& a) {
	if (!a.size())
		return;
	T x = a.top();
	a.pop();
	std::cout << x << ' ';
	print_stack(a);
	a.push(x);
}

void tower_of_hanoi(int num_disks, std::stack<int>& A, std::stack<int>& B, std::stack<int>& C) {
	if (!num_disks)
		return;
	else if (num_disks == 1) {
		B.push(A.top());
		A.pop();
	}
	else {
		tower_of_hanoi(num_disks - 1, A, C, B);
		B.push(A.top());
		A.pop();
		tower_of_hanoi(num_disks - 1, C, B, A);
	}
}

template<typename T>
void display(std::stack<T>& a) {
	std::cout << "content of a stack: ";
	print_stack(A);
	std::cout << std::endl;
}

int main() {
	int disk_number;
	std::cout << " Enter the number of disks: ";
	std::cin >> disk_number;
	
	std::stack<int> A, B, C; // A source, B destination and C auxiliary bars.
	for (int i{ disk_number }; i > 0; i--) {
		A.push(i);
	}

	display(A);
	display(B);

	tower_of_hanoi(disk_number, A, B, C);
	
	display(A);
	display(B);

	std::cin.get();
	return 0;
}
