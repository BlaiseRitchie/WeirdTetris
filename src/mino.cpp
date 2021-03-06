#include "mino.hpp"

#include <chrono>
#include <random>


Mino::Mino() : rot(0) {
	int seed = (int)std::chrono::system_clock::now().time_since_epoch().count();
	
	std::mt19937 r(seed);
	type = abs(int(r() % (Mino::numPieces + 6) - 6));
}

Mino::Mino(int type) : type(type), rot(0) {
}

Mino::Mino(Mino const &m) : type(m.type), rot(m.rot) {
}

Mino &Mino::operator=(Mino const &m) {
	this->type = m.type;
	this->rot = m.rot;
	return *this;
}

void Mino::rotClock() {
	rot = ((rot + 1) % 4);
}

void Mino::rotCounterClock() {
	rot--;
	if(rot == -1)
		rot = 3;
}

const int *Mino::getArray() {
	return minos[this->type][rot];
}

int Mino::startOffset() {
	return stoffset[this->type];
}

const int Mino::minos[Mino::numPieces][4][16] = {
	{ // 0
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			2, 2, 2, 2
		},
		{
			0, 0, 0, 2,
			0, 0, 0, 2,
			0, 0, 0, 2,
			0, 0, 0, 2
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 0,
			2, 2, 2, 2
		},
		{
			2, 0, 0, 0,
			2, 0, 0, 0,
			2, 0, 0, 0,
			2, 0, 0, 0
		}
	},

	{ // 1
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 3, 3,
			0, 3, 3, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 3, 0,
			0, 0, 3, 3,
			0, 0, 0, 3
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 3, 3, 0,
			3, 3, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 3, 0, 0,
			0, 3, 3, 0,
			0, 0, 3, 0
		}
	},

	{ // 2
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 4, 4, 0,
			0, 0, 4, 4
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 4,
			0, 0, 4, 4,
			0, 0, 4, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			4, 4, 0, 0,
			0, 4, 4, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 4, 0,
			0, 4, 4, 0,
			0, 4, 0, 0
		}
	},

	{ // 3
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 5, 0, 0,
			0, 5, 5, 5
		},
		{
			0, 0, 0, 0,
			0, 0, 5, 5,
			0, 0, 5, 0,
			0, 0, 5, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 5, 5, 5,
			0, 0, 0, 5
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 5,
			0, 0, 0, 5,
			0, 0, 5, 5
		}
	},

	{ // 4
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 6,
			0, 6, 6, 6
		},
		{
			0, 0, 0, 0,
			0, 0, 6, 0,
			0, 0, 6, 0,
			0, 0, 6, 6
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 6, 6, 6,
			0, 6, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 6, 6,
			0, 0, 0, 6,
			0, 0, 0, 6
		},
	},

	{ // 5
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 7, 7
		}
	},

	{ // 6
		{
			0, 0, 0, 0,
			0, 0, 8, 0,
			0, 8, 8, 8,
			0, 0, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 8, 0,
			0, 0, 8, 8,
			0, 0, 8, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 8, 8, 8,
			0, 0, 8, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 8, 0,
			0, 8, 8, 0,
			0, 0, 8, 0
		}
	},

	{ // 7
		{
			0, 0, 0, 0,
			0, 5, 0, 0,
			0, 0, 0, 0,
			0, 5, 5, 5
		},
		{
			0, 0, 0, 0,
			0, 5, 0, 5,
			0, 5, 0, 0,
			0, 5, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 5, 5, 5,
			0, 0, 0, 0,
			0, 0, 0, 5
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 5,
			0, 0, 0, 5,
			0, 5, 0, 5
		}
	},

	{ // 8
		{
			0, 0, 0, 0,
			0, 0, 0, 6,
			0, 0, 0, 0,
			0, 6, 6, 6
		},
		{
			0, 0, 0, 0,
			0, 6, 0, 0,
			0, 6, 0, 0,
			0, 6, 0, 6
		},
		{
			0, 0, 0, 0,
			0, 6, 6, 6,
			0, 0, 0, 0,
			0, 6, 0, 0
		},
		{
			0, 0, 0, 0,
			0, 6, 0, 6,
			0, 0, 0, 6,
			0, 0, 0, 6
		},
	},

	{ // 9
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			5, 0, 0, 0,
			5, 0, 5, 5
		},
		{
			0, 0, 5, 5,
			0, 0, 0, 0,
			0, 0, 5, 0,
			0, 0, 5, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			5, 5, 0, 5,
			0, 0, 0, 5
		},
		{
			0, 0, 0, 5,
			0, 0, 0, 5,
			0, 0, 0, 0,
			0, 0, 5, 5
		}
	},

	{ // 10
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 0, 6,
			6, 6, 0, 6
		},
		{
			0, 0, 6, 0,
			0, 0, 6, 0,
			0, 0, 0, 0,
			0, 0, 6, 6
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			6, 0, 6, 6,
			6, 0, 0, 0
		},
		{
			0, 0, 6, 6,
			0, 0, 0, 0,
			0, 0, 0, 6,
			0, 0, 0, 6
		},
	},

	{ // 11
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 7, 0, 7,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 7,
			0, 0, 7, 0,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 7, 7, 0,
			0, 7, 0, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 0, 7,
			0, 0, 7, 0
		}
	},

	{ // 12
		{
			0, 0, 0, 0,
			0, 0, 7, 0,
			0, 0, 0, 7,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 7, 0, 7,
			0, 7, 7, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 7, 0,
			0, 0, 0, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 7, 0, 7
		}
	},

	{ // 13
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 7, 0, 7,
			0, 7, 0, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 0, 0,
			0, 0, 7, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			0, 7, 0, 7,
			0, 7, 0, 7
		},
		{
			0, 0, 0, 0,
			0, 0, 7, 7,
			0, 0, 0, 0,
			0, 0, 7, 7
		}
	},

	{ // 14
		{
			0, 0, 0, 0,
			0, 0, 3, 3,
			0, 0, 0, 0,
			0, 3, 3, 0
		},
		{
			0, 0, 0, 0,
			0, 3, 0, 0,
			0, 3, 0, 3,
			0, 0, 0, 3
		},
		{
			0, 0, 0, 0,
			0, 3, 3, 0,
			0, 0, 0, 0,
			3, 3, 0, 0
		},
		{
			0, 0, 0, 0,
			3, 0, 0, 0,
			3, 0, 3, 0,
			0, 0, 3, 0
		}
	},

	{ // 15
		{
			0, 0, 0, 0,
			0, 4, 4, 0,
			0, 0, 0, 0,
			0, 0, 4, 4
		},
		{
			0, 0, 0, 0,
			0, 0, 0, 4,
			0, 4, 0, 4,
			0, 4, 0, 0
		},
		{
			0, 0, 0, 0,
			4, 4, 0, 0,
			0, 0, 0, 0,
			0, 4, 4, 0
		},
		{
			0, 0, 0, 0,
			0, 0, 4, 0,
			4, 0, 4, 0,
			4, 0, 0, 0
		}
	},

};

const int Mino::stoffset[Mino::numPieces] = {-3, -3, -3, -3, -3, -3, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3};