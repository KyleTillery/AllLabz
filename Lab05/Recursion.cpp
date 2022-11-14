#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1



int FactorialByRecursion::CalculateFactorial(int num) 
{

	int answer = 1;

	if (num > 1)
	{
		return num * CalculateFactorial(num-1);
	}
	else{
		return 1;
	}
	
	return answer;

}


int FactorialByStack::CalculateFactorial(int num) {

	stack<int> stack;
	stack.push(1);
	for(int i = 2; i <= num; i++)
	{
		stack.push(stack.top() * i);
	}

	return stack.top();
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	stack<int> rStack;
	stack<int> cStack;

	int fill = 0,row = 0;

	rStack.push(row);
	cStack.push(col);

	m_board[row][col]=1;
	row++;
	
	while (fill < 7)
	{
		if(!CheckSafeQueens(chessBoard, row, col))
		{
			fill++;
			rStack.push(row);
			cStack.push(col);
			m_board[row][col] = 1;
			row++;
			col = 0;
		}
		else
		{
			col++;
			if (col > 7)
			{
				
				row = rStack.top();
				col = cStack.top();
				rStack.pop();
				cStack.pop();
				
				m_board[row][col] = 0;
				col++;
				fill--;
				
			}
		}
		

	}
	return true;
	


}


bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{

    for (int i = 0; i < 8; i++)
    {
        if (m_board[row][i] || m_board[i][col]) {return true;}
    }

    for (int r = row, c = col; r < 8 && c >=0; r++,c--)
    {
        if (m_board[r][c]) {return true;}
    }

    for (int r = row, c = col; r < 8 && c < 8; r++,c++)
    {
        if (m_board[r][c]) {return true;}
    }

    for (int r = row, c = col; r >= 0 && c >= 0; r--,c--)
    {
        if (m_board[r][c]) {return true;}
    }

    for (int r = row, c = col; r >= 0 && c < 8; r--,c++)
    {
        if (m_board[r][c]) {return true;}
    }

    return false;

}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal;
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;
	try
	{
		resourceThatNeedsToBeCleanedup = new MyFakeClass();
		SimpleExceptionMethod(i);
	}
	catch(MyException1 e){
		retVal = "I got Exception 1";
	}
	catch(MyException2 e){
		retVal = "I got Exception 2";
	}
	catch(MyException3 e){
		retVal = "I got Exception 3";
	}

	if (retVal == "")
		return "I did not get an Exception";
	
	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
char const* MyException3::what() const throw() {
	return "MyException3";
}
// TODO make a MyException3::what
