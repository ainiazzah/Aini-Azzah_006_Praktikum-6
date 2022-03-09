#include <bits/stdc++.h>
using namespace std;

struct QNode {
	int data;
	QNode* link;
	QNode(int d)
	{
		data = d;
		link = NULL;
	}
};

struct Queue {
	QNode *front, *back;
	Queue()
	{
		front = back = NULL;
	}
	void enQueue(int x)
	{
		// Membuat Node Baru
		QNode* temp = new QNode(x);
		
		// Jika antrian kosong
		// node baru adalah depan dan belakang
		if (back == NULL)
		{
			front = back = temp;
			return;
		}\
		
		// Tambah node baru
		// di akhir antrian dan ganti antrian belakang
		back -> link = temp;
		back = temp;
	}

	// Function untuk menghapus
	// key dari antrian yang diberikan
	void deQueue()
	{
		// Jika queue kosong, return NULL.
		if (front == NULL)
		return;
		
		// Simpan antrian awal
		// pindah antrian awal
		QNode* temp = front;
		front = front->link;

		// jika antrian awal null
		// ganti antrian belakang dengan null
		if (front == NULL)
		back = NULL;
		
		delete (temp);
	}
};

// Inti Program
int main()
{

	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front\t: " << (q.front) -> data << endl;
	cout << "Queue Back\t: " << (q.back) -> data;
}
