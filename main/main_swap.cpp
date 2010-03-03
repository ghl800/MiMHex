#define INSERT_ASSERTIONS

#include "board.h"
#include "board.cpp"
#include "playout.cpp"
#include "gtp.cpp"
#include "mcts_node.cpp"
#include "mcts_tree.cpp"
#include "game.cpp"
#include "protocol.h"
#include "protocol.cpp"
#include "params.cpp"
#include "openings_book.cpp"
#include "fast_sample.cpp"
#include "hash_board.cpp"
#include "pattern_data.cpp"

#include <iostream>
#include <cstdlib>
#include <boost/lexical_cast.hpp>

int main() {
	Hex::Game game;
	game.SetPlayoutsPerMove(50000);

	uint first_pos = Hex::kBoardSizeAligned;
	uint last_pos = Hex::kBoardSizeAligned*(Hex::kBoardSizeAligned-1);

	for (uint p=first_pos; p<=last_pos; p++) {
		uint x, y;
		Hex::Location::ToCoords(p, x, y);

		if (x==0 || x==Hex::kBoardSizeAligned-1 || x+y>Hex::kBoardSize+1)
			continue;

		game.ClearBoard();
		game.Play(Hex::Move(Hex::Player::First(), Hex::Location(p)));
		Hex::Player player = Hex::Player::Second();

		while (!game.IsFinished()) {
			Hex::Move move = game.GenMoveNoSwap(player);
			game.Play(move);
			player = player.Opponent();
		}

		if (game.Winner() == Hex::Player::First())
			std::cout << p << '\t' << 1 << std::endl;
		else
			std::cout << p << '\t' << 0 << std::endl;
		std::cout.flush();
	}

	return 0;
}
