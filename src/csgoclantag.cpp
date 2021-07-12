#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
	เขียน C++ ไม่เป็น โปรเกรมนี้เเย่มากอย่าทําตาม 
*/

int main() {
	int x , n , u , z;
	cout << "How many Group ?";
	cin >> x;
	int array[0 + x]= {};
	for (int i = 0; i < x; i++){
		n = i + 1;
		cout << n << ". Group id :";
		cin >> array[i];
		cout << array[i] << endl;
	}

	ofstream config;
	config.open("clantag.cfg");
	config << "alias clanwdnm clanwdnm1" << "\"" << endl; 

	/*
		เขียนไฟล์ config ท่อนบน
		*/

	for (int i = 0; i != x; ++i) {
		u = i + 1;
		config << "alias clanwdnm" << u << "\"cl_clanid " << array[i] <<";alias clanwdnm clanwdnm"<< u + 1 << "\""  << endl;}
    cout << u;

    /*
		เขียนไฟล์ config ท่อนล่าง
		*/
	
    for (int z = x - 1; z != -1; --z) {
    	++u;
		config << "alias clanwdnm" << u << "\"cl_clanid " << array[z] <<";alias clanwdnm clanwdnm"<< u + 1 << "\""  << endl;}

    /*
    		เขียนไฟล์ config ปิดท้าย
		*/
    config << "alias clanwdnm" << u << "\"cl_clanid " << array[0] <<";alias clanwdnm clanwdnm1"<<"\""  << endl;
    config << "bind w " << "\"+forward;clanwdnm\""  << endl;
	config << "bind a " << "\"+moveleft;clanwdnm\""  << endl;
	config << "bind s " << "\"+back;clanwdnm\""  << endl;
	config << "bind d " << "\"+moveright;clanwdnm\""  << endl;
    config.close();

    cout << flush;
    cout << endl;
    cout << "Done";
	return 0;}
