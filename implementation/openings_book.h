#ifndef OPENINGS_BOOK_H_
#define OPENINGS_BOOK_H_

# include "board.h"

namespace Hex {

	class OpeningsBook {
	public:
		static Location GetOpening (float);
		static bool ShouldSwap (const Location&);
		static void SetBookFile (std::string);
		static void ReadBookFromFile ();

	private:
		const static float best_wins_rate = .5;
		static std::string book_file;
		const static float not_on_board = 5.;
		static float * opening_wins_rate;
	};

}

#endif
