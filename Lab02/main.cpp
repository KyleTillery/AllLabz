// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class TowersOfHannoiGame
{
public:
	TowersOfHannoiGame() : m_GameEnded(false)
	{

	}

	bool IsGameEnded() {
		std::string str1,str2;
		std::string check[4] = {"4", "3", "2", "1"};
		int x = 4;
		for(int i = 0; i < 4; i++)
		{
			if (gamearray3[i] == "4")
			{
				if (gamearray3[i+1] == "3")
				{
					if (gamearray3[i+2] == "2")
					{
						if (gamearray3[i+3] == "1")
						{
							return true;
						}
					}
				}
			}
				
			
		}
		return false;
		
		
	}

	void PrintTowers()
	{
		std::string str1, str2, str3;
		for(int i = 0; i < 4; i++)
		{
			if(i != 3)
			{
				str1 = str1 + gamearray1[i] + " ";
				str2 = str2 + gamearray2[i] + " ";
				str3 = str3 + gamearray3[i] + " ";
			}
			else
			{
				str1 = str1 + gamearray1[i];
				str2 = str2 + gamearray2[i];
				str3 = str3 + gamearray3[i];
			}
		}
		cout << "Tower 1: " << str1 <<endl;
		cout << "Tower 2: " << str2 <<endl;
		cout << "Tower 3: " << str3 <<endl;
		
	}
	int size (std::string disk){
		bool good = true;
		int i = 0;
		while (good == true){
			if (disk == "1"){
				if (gamearray1[i] != ""){
					i++;
				}else{
					good = false;
				}
			}else if (disk == "2"){
				if (gamearray2[i] != ""){
					i++;
				}else{
					good = false;						}
			}else {
				if (gamearray3[i] != ""){
					i++;
				}else{
					good = false;
				}
			}
		}
		return i;
	}
	bool push(int disk,int to,int size,std::string diskn,int from,int sizep){
		if (to == 1){
			if (gamearray1[size-1] > diskn || size == 0)
			{
				gamearray1[size] = diskn;
				return true;
			}
			else
			{
				std::cout << "larger disk can't be added\n";
				if (from == 2)
					gamearray2[sizep-1] = diskn;
				else
					gamearray3[sizep-1] = diskn;
				return false;
			}
		}else if (to == 2){
			if (gamearray2[size-1] > diskn || size == 0)
			{
				gamearray2[size] = diskn;
				return true;
			}
			else
			{
				std::cout << "larger disk can't be added\n";
				if (from == 1)
					gamearray1[sizep-1] = diskn;
				else
					gamearray3[sizep-1] = diskn;
				return false;
			}
		}else {
			if (gamearray3[size-1] > diskn || size == 0)
			{
				gamearray3[size] = diskn;
				return true;
			}
			else
			{
				std::cout << "larger disk can't be added\n";
				if (from == 1)
					gamearray1[sizep-1] = diskn;
				else
					gamearray2[sizep-1] = diskn;
				return false;
			}
		}
	}
	bool pop(int disk,int from,int size,std::string diskn, int to){
		if (from == 1){
			if (gamearray1[size-1] == diskn){
				gamearray1[size-1] = "";
				return true;
			}
		}else if (from == 2){
			if (gamearray2[size-1] == diskn ){
				gamearray2[size-1] = "";
				return true;
			}
		}else if (from ==3) {
			if (gamearray3[size-1] == diskn){
				gamearray3[size-1] = "";
				return true;
			}
		}else
		{
			return false;
		}
	}
protected:
	std::string gamearray1[4] = {"4","3","2","1"};
	std::string gamearray2[4];
	std::string gamearray3[4];

private:
	bool m_GameEnded;

};


int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHannoiGame game;

	bool receivedEndToken = false;
	int size;
	bool end;
	bool poppy;
	bool pushy;

	std::ofstream outfile ("temp.txt");

	while (!receivedEndToken && end == false)
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				outfile << output[0] << "," << output[1] << "," << output[2] << endl;

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId == 0 || fromId == 0 || toId == 0)
				{
					receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;
				
		
				int sizep;
				sizep = game.size(from);
				size = game.size(from);
				poppy = game.pop(diskId,fromId,size,disk,toId);
				game.pop(diskId,fromId,size,disk,toId);
				if(poppy == true)
				{
					size = game.size(to);
					game.push(diskId,toId,size,disk, fromId,sizep);
				}
				else
				{
					cout << "Pick value from top\n";
				}
				//}
				

				end = game.IsGameEnded();
				if (end == true)
				{
					cout << "YOU WIN" << endl;
					abort;
				}

				
				

			}
		}
		


	}
	outfile.close();

    return 0;
}