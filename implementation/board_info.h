#ifndef BOARD_INFO_H
#define BOARD_INFO_H

#ifndef BOARD_SIZE
#define BOARD_SIZE 11
#endif

typedef unsigned int uint;

namespace Hex {

const uint kBoardSize = BOARD_SIZE;
const uint kBoardSizeAligned = kBoardSize + 2;

}

#endif /* BOARD_INFO_H */
