#ifndef HEX_BOARD_H_
#define HEX_BOARD_H_

#include <string>
#include "fast_sample.h"
#include "hash_board.h"

typedef unsigned int uint;

namespace Hex {

//const uint kBoardSize = 11;
//const uint kBoardSizeAligned = 13;	// kBoardSize + 2

// -----------------------------------------------------------------------------

class Rand {
public:
	static void init (uint seed) { _seed = seed; }
	static uint next_rand() {
		uint lo = 16807 * (_seed & 0xffff);
		uint hi = 16807 * (_seed >> 16);
		lo += (hi & 0x7fff) << 16;
		lo += hi >> 15;
		return _seed = (lo & 0x7FFFFFFF) + (lo >> 31);
	}
	static uint next_rand(uint n) {
	  return ((next_rand() & 0xffff) * n) >> 16;
	}
private:
	static uint _seed;
};

// -----------------------------------------------------------------------------

class Player {
 public:
  static Player First();
  static Player Second();
  static Player None();
  static Player OfString (std::string);

  Player Opponent() const;

  bool operator== (const Player&) const;
  bool operator!= (const Player&) const;

  uint GetVal();

  std::string ToString() const;

  static bool ValidPlayer(const std::string& player);

 private:
  Player();
  Player(uint val);

 private:
  uint _val;
};

// -----------------------------------------------------------------------------

class Location {
 public:
  static Location OfCoords (std::string);
  static Location Swap ();
  Location (uint pos);
  Location (uint x, uint y);
  uint GetPos() const;

  inline uint GetX() const { return _pos % kBoardSizeAligned; }
  inline uint GetY() const { return _pos / kBoardSizeAligned; }

  std::string ToCoords() const;
  bool operator==(Location loc) const;
  bool operator!=(Location loc) const;
  static bool ValidLocation(const std::string& location);
  static bool ValidLocation(uint x, uint y);
  static bool ValidPosition(uint pos);
  static void ToCoords(uint pos, uint& x, uint& y);
  bool IsSwap() const;

 private:
  Location();
  static uint ToTablePos(uint x, uint y);

 private:
  static const uint swap_code = kBoardSizeAligned*kBoardSizeAligned;
  uint _pos;
};

// -----------------------------------------------------------------------------

class Move {
 public:
  Move (const Player&, const Location&);
  Location GetLocation() const;
  Player GetPlayer() const;

 private:
  Move();

 private:
  Player _player;
  Location _location;
};

// -----------------------------------------------------------------------------

class Board {
 public:
  const static Board Empty();

  typedef unsigned short* ushort_ptr;

  Board();
  Player CurrentPlayer() const;
  Move RandomLegalMove (const Player&) const;
  void PlayLegal (const Move&);
  bool IsFull() const;
  Player Winner() const;
  void Load (const Board&);
  uint MovesLeft() const;
  void GetPossiblePositions(ushort_ptr& locations);
  std::string ToAsciiArt(Location last_move) const;
  bool IsValidMove(const Move& move);
  bool IsEmpty() const;
  bool IsSwapPossible() const;

  // some gui useful functions
  Player nowWinner() const;
  Player getBoardAt(uint, uint) const;
  void fillWith(const Player&);

 private:
  void MakeUnion(uint pos);
  uint MakeUnion(uint pos1, uint pos2);
  uint Find(uint pos);
  uint ConstFind(uint pos) const;

 private:
  static const uint table_size;
  static const uint guarded_board_size;
  short _board[kBoardSizeAligned * kBoardSizeAligned];
  unsigned short _fast_field_map[kBoardSizeAligned * kBoardSizeAligned];
  unsigned short _reverse_fast_field_map[kBoardSizeAligned * kBoardSizeAligned];
  uint _moves_left;
  Player _current;
  FastSample _red_sample, _blue_sample;
  HashBoard _hash_board;
};

// -----------------------------------------------------------------------------

} // namespace Hex

#undef TREE_BALANCING

#endif
