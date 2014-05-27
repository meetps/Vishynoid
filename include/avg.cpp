#include<iostream>
using namespace std;
int main(int argc, char* argv[]) {
	long long sum = 0;
	/*for(int i=1; i<argc; i++){
	 cout<<(int)*argv[i]-'0'<<endl;
	 sum+=(int)*argv[i]-'0';
	 }*/
	int temp;
	float c = 0;
	while (cin >> temp) {
		sum += temp;
		c++;
	}
	//float avg = sum / (argc-1);
	float avg = sum / c;
	cout << "Average: " << avg << endl;
	return avg;
}
