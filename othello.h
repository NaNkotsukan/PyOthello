#pragma once
#include <iostream>
#include <vector>
#include<pybind11/pybind11.h>
#include<pybind11\numpy.h>
using namespace std;
namespace py = pybind11;

class othello
{
public:
	othello();
	~othello();
	//bool next[64] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//char board[8][8] = { { 1,1,1,1,1,1,1,1 },{ -1,-1,-1,-1,-1,-1,-1,-1 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,1,-1,0,0,0 },{ 0,0,0,-1,1,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 } };
	auto solve(int,py::array_t<char>);
	auto select(int);
	void show();
	//void put(int,int);
	//auto putable();

	
private:
				char board[8][8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
				int now = 1;
				char nextBord[40][8][8];
				char num = 0;
};

othello::othello()
{
				memcpy(nextBord[0], board,64);
				//nextBord[1]=board;
				//char board[8][8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,1,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
				//char board[8][8] = { { 1,1,1,1,1,1,1,1 },{ -1,-1,-1,-1,-1,-1,-1,-1 }, { 0,0,0,0,0,0,0,0 }, { 0,0,0,1,-1,0,0,0 }, { 0,0,0,-1,1,0,0,0 }, { 0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,0,0 }, { 0,0,0,0,0,0,0,0 }};
	//now = 1;
}

othello::~othello()
{
								
}

void othello::show() {
	cout << " ‚O‚P‚Q‚R‚S‚T‚U‚V"<<endl;
	//char t[8] = { '‚O','‚P','‚Q','‚R','‚S','‚T','‚U','‚V' };
	for (int i = 0; i < 8; ++i) {
		cout << i;
		////cout << i+1 - 0x30 + 0x824f;
		//printf("%s", i + 1 - 0x30 + 0x824f);
		for (int j = 0; j < 8; ++j) {
			//cout << board[i][j]<<endl;
			cout << (board[i][j] == 0 ? "@" : board[i][j] == 1 ? "ü" : "œ");
		}
		cout << endl;
	}
}

//
//void othello::put(int x,int y) {
// 
//	bool p = false;
//	for (char i = y + 1; i < 8; ++i)
//	{
//		if (p && (board[i][x] == now)) {
//			for (char j = y ; j < i; ++j)
//			{
//				board[j][x] = now;
//			}
//			p = false;
//			break;
//		}
//
//		if (board[i][x] == -now) {
//			p = true;
//		}
//		else
//		{	
//			p = false;
//			break;
//		}
//	}
//	for (char i = x + 1; i < 8; ++i)
//	{
//		if (p && (board[y][i] == now)) {
//			for (char j = x ; j < i; ++j)
//			{
//				board[y][j] = now;
//			}
//			p = false;
//			break;
//		}
//		if (board[y][i] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = y - 1; i >= 0; --i)
//	{
//		if (p && (board[i][x] == now)) {
//			for (char j = y; i < j; --j)
//			{
//				board[j][x] = now;
//			}
//			p = false;
//			break;
//		}
//		if (board[i][x] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = x - 1; i >= 0; --i)
//	{
//		if (p && (board[y][i] == now)) {
//			for (char j = x; i < j; --j)
//			{
//				board[y][j] = now;
//			}
//			p = false;
//			break;
//		}
//		if (board[y][i] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = y + 1, ii = x + 1; i < 8 && ii < 8; ++ii, ++i)
//	{
//		if (p && (board[i][ii] == now)) {
//			for (char j = y, jj = x; j < i; ++j, ++jj)
//			{
//				board[j][jj] = now;
//			}
//			p = false;
//			break;
//		}
//
//		if (board[i][ii] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = y - 1, ii = x + 1; i >= 0 && ii < 8; ++ii,--i)
//	{
//		if (p && (board[i][ii] == now)) {
//			for (char j = y , jj = x; jj < ii; --j , ++jj)
//			{
//				board[j][jj] = now;
//			}
//			p = false;
//			break;
//		}
//
//		if (board[i][ii] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = y + 1, ii = x - 1; i < 8 && ii >= 0; --ii, ++i)
//	{
//		if (p && (board[i][ii] == now)) {
//			for (char j = y, jj = x; j < i; ++j, --jj)
//			{
//				board[j][jj] = now;
//			}
//			p = false;
//			break;
//		}
//
//		if (board[i][ii] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	for (char i = y - 1, ii = x - 1; i >= 0 && ii >= 0; --ii, --i)
//	{
//		if (p && (board[i][ii] == now)) {
//			for (char j = y, jj = x; j > i; --j, --jj)
//			{
//				board[j][jj] = now;
//			}
//			p = false;
//			break;
//		}
//
//		if (board[i][ii] == -now) {
//			p = true;
//		}
//		else
//		{
//			p = false;
//			break;
//		}
//	}
//	
//	now = -now;
//}

auto othello::select(int x) {
				py::list result;
				if (x >= num) { result.append(2);return result; }
				bool round2 = false;
				//char board[8][8];
				memcpy(board, nextBord[x], 64);
				bool p;
restart:
				now = -now;
				num=0;
				bool change = 0;
				memcpy(nextBord[num],board,64);
				for (char y = 0; y < 8; ++y) {
								for (char x = 0; x < 8; ++x) {
												if (board[y][x]) { continue; }
												p = false;
												for (char i = y + 1; i < 8; ++i)
												{
																if (p && (board[i][x] == now)) {
																				for (char j = y; j < i; ++j)
																				{
																								nextBord[num][j][x] = now;
																								change = 1;
																				}
																				break;
																}

																if (board[i][x] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = x + 1; i < 8; ++i)
												{
																if (p && (board[y][i] == now)) {
																				for (char j = x; j < i; ++j)
																				{
																								nextBord[num][y][j] = now;
																								change = 1;
																				}
																				break;
																}
																if (board[y][i] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1; i >= 0; --i)
												{
																if (p && (board[i][x] == now)) {
																				for (char j = y; i < j; --j)
																				{
																								nextBord[num][j][x] = now;
																								change = 1;
																				}
																				break;
																}
																if (board[i][x] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = x - 1; i >= 0; --i)
												{
																if (p && (board[y][i] == now)) {
																				for (char j = x; i < j; --j)
																				{
																								nextBord[num][y][j] = now;
																								change = 1;
																				}
																				break;
																}
																if (board[y][i] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y + 1, ii = x + 1; i < 8 && ii < 8; ++ii, ++i)
												{
																if (p && (board[i][ii] == now)) {
																				for (char j = y, jj = x; j < i; ++j, ++jj)
																				{
																								nextBord[num][j][jj] = now;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1, ii = x + 1; i >= 0 && ii < 8; ++ii, --i)
												{
																if (p && (board[i][ii] == now)) {
																				for (char j = y, jj = x; jj < ii; --j, ++jj)
																				{
																								nextBord[num][j][jj] = now;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y + 1, ii = x - 1; i < 8 && ii >= 0; --ii, ++i)
												{
																if (p && (board[i][ii] == now)) {
																				for (char j = y, jj = x; j < i; ++j, --jj)
																				{
																								nextBord[num][j][jj] = now;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1, ii = x - 1; i >= 0 && ii >= 0; --ii, --i)
												{
																if (p && (board[i][ii] == now)) {
																				for (char j = y, jj = x; j > i; --j, --jj)
																				{
																								nextBord[num][j][jj] = now;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -now) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												if (change) {
																++num;
																memcpy(nextBord[num], board, 64);
																change = 0;
												}
								}
				}
				//--num;
				
				if(round2) {
								result.append(0);
								char a = 0;
								char *p = (char*)&board;
								for (int i = 0;i < 64;++i, ++p) {
												a += *p;
								}
								result.append(a / 64.0);
				}
				else if (num) {
								auto nb = py::array_t<char>(64 * num);
								char* ptr = (char*)nb.request().ptr;
								memcpy(ptr, &nextBord, 64 * num);
								result.append(now);
								result.append(nb);
				}
				else
				{
								round2 = true;
								goto restart;
				}
				return result;
}

auto othello::solve(int color, py::array_t<char> input) {
				//if (x>num) { return 999; }
				bool round1 = true;
				//char board[8][8];
				memcpy(board, input.request().ptr, 64);
				bool p;
restart:
				char col = color;
				num = 0;
				bool change = 0;
				memcpy(nextBord[num], board, 64);
				for (char y = 0; y < 8; ++y) {
								for (char x = 0; x < 8; ++x) {
												if (board[y][x]) { continue; }
												p = false;
												for (char i = y + 1; i < 8; ++i)
												{
																if (p && (board[i][x] == col)) {
																				for (char j = y; j < i; ++j)
																				{
																								nextBord[num][j][x] = col;
																								change = 1;
																				}
																				break;
																}

																if (board[i][x] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = x + 1; i < 8; ++i)
												{
																if (p && (board[y][i] == col)) {
																				for (char j = x; j < i; ++j)
																				{
																								nextBord[num][y][j] = col;
																								change = 1;
																				}
																				break;
																}
																if (board[y][i] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1; i >= 0; --i)
												{
																if (p && (board[i][x] == col)) {
																				for (char j = y; i < j; --j)
																				{
																								nextBord[num][j][x] = col;
																								change = 1;
																				}
																				break;
																}
																if (board[i][x] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = x - 1; i >= 0; --i)
												{
																if (p && (board[y][i] == col)) {
																				for (char j = x; i < j; --j)
																				{
																								nextBord[num][y][j] = col;
																								change = 1;
																				}
																				break;
																}
																if (board[y][i] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y + 1, ii = x + 1; i < 8 && ii < 8; ++ii, ++i)
												{
																if (p && (board[i][ii] == col)) {
																				for (char j = y, jj = x; j < i; ++j, ++jj)
																				{
																								nextBord[num][j][jj] = col;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1, ii = x + 1; i >= 0 && ii < 8; ++ii, --i)
												{
																if (p && (board[i][ii] == col)) {
																				for (char j = y, jj = x; jj < ii; --j, ++jj)
																				{
																								nextBord[num][j][jj] = col;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y + 1, ii = x - 1; i < 8 && ii >= 0; --ii, ++i)
												{
																if (p && (board[i][ii] == col)) {
																				for (char j = y, jj = x; j < i; ++j, --jj)
																				{
																								nextBord[num][j][jj] = col;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												p = false;
												for (char i = y - 1, ii = x - 1; i >= 0 && ii >= 0; --ii, --i)
												{
																if (p && (board[i][ii] == col)) {
																				for (char j = y, jj = x; j > i; --j, --jj)
																				{
																								nextBord[num][j][jj] = col;
																								change = 1;
																				}
																				break;
																}

																if (board[i][ii] == -col) {
																				p = true;
																}
																else
																{
																				break;
																}
												}
												if (change) {
																++num;
																memcpy(nextBord[num], board, 64);
																change = 0;
												}
								}
				}
				//--num;
				py::list result;

				if (num) {
								auto nb = py::array_t<char>(64 * num);
								char* ptr = (char*)nb.request().ptr;
								memcpy(ptr, &nextBord, 64 * num);
								result.append(now);
								result.append(nb);
				}
				else if (!round1) { 
								result.append(0); 

				}
				else
				{
								col = -col;
								goto restart;
				}
				return result;
}


//auto othello::putable() {
//				char nextHand[8][8] = { 0 };
//				//char nextboard[8][8] = {0};
//				bool p = false;
//				for (char y = 0; y < 8; ++y) {
//								for (char x = 0; x < 8; ++x) {
//												if (!board[y][x]) {
//																for (char i = y + 1; i < 8; ++i)
//																	{
//																					if (p && (board[i][x] == now)) {
//																									goto end;
//																					}
//
//																					if (board[i][x] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = x + 1; i < 8; ++i)
//																	{
//																					if (p && (board[y][i] == now)) {
//																									goto end;
//																					}
//																					if (board[y][i] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = y - 1; i >= 0; --i)
//																	{
//																					if (p && (board[i][x] == now)) {
//																									goto end;
//																					}
//																					if (board[i][x] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = x - 1; i >= 0; --i)
//																	{
//																					if (p && (board[y][i] == now)) {
//																									goto end;
//																					}
//																					if (board[y][i] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = y + 1, ii = x + 1; i < 8 && ii < 8; ++ii, ++i)
//																	{
//																					if (p && (board[i][ii] == now)) {
//																									goto end;
//																					}
//
//																					if (board[i][ii] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = y - 1, ii = x + 1; i >= 0 && ii < 8; ++ii, --i)
//																	{
//																					if (p && (board[i][ii] == now)) {
//																									goto end;
//																					}
//
//																					if (board[i][ii] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																				}
//																	}										
//																for (char i = y + 1, ii = x - 1; i < 8 && ii >= 0; --ii, ++i)
//																	{
//																					if (p && (board[i][ii] == now)) {
//																									goto end;
//																					}
//
//																					if (board[i][ii] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																for (char i = y - 1, ii = x - 1; i >= 0 && ii >= 0; --ii, --i)
//																	{
//																					if (p && (board[i][ii] == now)) {
//																									goto end;
//																					}
//
//																					if (board[i][ii] == -now) {
//																									p = true;
//																					}
//																					else
//																					{
//																									p = false;
//																									break;
//																					}
//																	}
//																end:nextHand[y][x] = 1;
//												}
//								}
//								return nextHand ;
//				}
//}
