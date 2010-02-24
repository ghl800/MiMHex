#include "game.h"
#include "board.h"
#include "mcts_tree.h"
#include "conditional_assert.h"

namespace Hex {

Game::Game() : empty_board(Board::Empty()), last_move(0) {
	ClearBoard();
}

void Game::ClearBoard() {
	current_board.Load(empty_board);
	tree.Reset();
}

void Game::Play(const Move& move) {
	ASSERT(current_board.IsValidMove(move));
	current_board.PlayLegal(move);
	last_move = move.GetLocation();
}

Move Game::GenMove(Player player) {
	ASSERT(!current_board.IsFull());
	return tree.BestMove(player, current_board);
}

void Game::SetMaxUTCTreeDepth(uint depth) {
	tree.SetMaxDepth(depth);
}

void Game::PrintBoard(std::string& board) {
	board = current_board.ToAsciiArt(last_move);
}

void Game::SetPlayoutsPerMove(uint playouts) {
	tree.SetPlayoutsPerMove(playouts);
}

void Game::PrintTree(std::string& ascii_tree, uint children) {
	ascii_tree = tree.ToAsciiArt(children);
}

bool Game::IsValidMove(const Move& move) {
	return current_board.IsValidMove(move);
}

bool Game::IsFinished() {
	// TODO better check
	return current_board.IsFull();
}

Player Game::getBoardAt(uint x, uint y) const {
    return current_board.getBoardAt(x, y);
}

Player Game::nowWinner() const {
    return current_board.nowWinner();
}

Player Game::CurrentPlayer() const {
    if (current_board.IsFull())
        return Player::None();
    return current_board.CurrentPlayer();
}

Location Game::LastMove() const {
    return last_move;
}

} // namespace Hex
