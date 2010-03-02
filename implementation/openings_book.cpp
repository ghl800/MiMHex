# include "board.h"
# include "openings_book.h"
# include <vector>
# include <iostream>
# include <fstream>

namespace Hex {

	float * OpeningsBook::opening_wins_rate = new float[kBoardSizeAligned*kBoardSizeAligned];

	std::string OpeningsBook::book_file = "../openings_book/openings_book.txt";

	void OpeningsBook::SetBookFile(std::string filename) {
		book_file = filename;
	}

	void OpeningsBook::ReadBookFromFile() {
		std::ifstream fin;
		fin.open(book_file.c_str());

		if (fin.fail())
			std::cerr << "Reading openings book from file '" << book_file << "' failed.\n";

		for (uint i=0; i<kBoardSizeAligned*kBoardSizeAligned; i++)
			fin >> opening_wins_rate[i];

		fin.close();
	}

	inline float abs (const float x) {
		return x>0 ? x : -x;
	}

	Location OpeningsBook::GetOpening (float tolerance) {
		float best_error = 1.;
		uint best_opening = 0;

		std::vector<uint> possible_openings;
		for (uint i=0; i<kBoardSizeAligned*kBoardSizeAligned; i++) {
			if (opening_wins_rate[i] == not_on_board)
				continue;

			float error = abs(opening_wins_rate[i]-best_wins_rate);
			if (error <= tolerance)
				possible_openings.push_back(i);
			if (error < best_error) {
				best_error = error;
				best_opening = i;
			}
		}

		if (possible_openings.size() == 0)
			return Location(best_opening);
		else {
			uint rand = Rand::next_rand(possible_openings.size());
			return Location(possible_openings[rand]);
		}
	}

	bool OpeningsBook::ShouldSwap (const Location& opening) {
		return (opening_wins_rate[opening.GetPos()] > .5);
	}
}
