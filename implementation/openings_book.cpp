# include "board.h"
# include "openings_book.h"
# include <vector>

namespace Hex {

	const float OpeningsBook::opening_wins_rate[] = {
			5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5.,
			5., 0.497312, 0.497312, 0.533602, 0.509409, 0.500672, 0.527554, 0.551075, 0.53629, 0.569892, 0.563844, 0.5975, 5.,
			5., 0.50672, 0.532258, 0.52957, 0.52621, 0.552505, 0.558379, 0.59272, 0.588276, 0.589474, 0.628365, 0.589792, 5.,
			5., 0.545956, 0.545287, 0.568646, 0.555246, 0.577674, 0.610851, 0.575843, 0.621368, 0.623927, 0.613971, 0.560976, 5.,
			5., 0.530747, 0.543033, 0.591195, 0.591195, 0.610703, 0.612802, 0.633403, 0.609902, 0.611672, 0.603122, 0.521405, 5.,
			5., 0.498399, 0.574786, 0.566845, 0.59164, 0.626609, 0.631974, 0.618093, 0.606325, 0.586507, 0.587595, 0.510337, 5.,
			5., 0.533333, 0.567277, 0.576216, 0.589577, 0.606094, 0.586507, 0.606094, 0.589577, 0.576216, 0.567277, 0.533333, 5.,
			5., 0.510337, 0.587595, 0.586507, 0.606325, 0.618093, 0.631974, 0.626609, 0.59164, 0.566845, 0.574786, 0.498399, 5.,
			5., 0.521405, 0.603122, 0.611672, 0.609902, 0.633403, 0.612802, 0.610703, 0.591195, 0.591195, 0.543033, 0.530747, 5.,
			5., 0.560976, 0.613971, 0.623927, 0.621368, 0.575843, 0.610851, 0.577674, 0.555246, 0.568646, 0.545287, 0.545956, 5.,
			5., 0.589792, 0.628365, 0.589474, 0.588276, 0.59272, 0.558379, 0.552505, 0.52621, 0.52957, 0.532258, 0.50672, 5.,
			5., 0.5975, 0.563844, 0.569892, 0.53629, 0.551075, 0.527554, 0.500672, 0.509409, 0.533602, 0.497312, 0.497312, 5.,
			5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5., 5.,
	};

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
