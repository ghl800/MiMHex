#ifndef OPENINGS_BOOK_H_
#define OPENINGS_BOOK_H_

# include "board.h"

namespace Hex {

	class OpeningsBook {
	public:
		static Location GetOpening (float);
		static bool ShouldSwap (const Location&);
	private:
		const static float opening_wins_rate[kBoardSizeAligned*kBoardSizeAligned];
		const static float best_wins_rate = .5;
		const static float not_on_board = 5.;
	};

}

#endif
