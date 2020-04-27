cmake_minimum_required(VERSION 3.15)
project(Poker)

set(CMAKE_CXX_STANDARD 14)

add_executable(Poker main.cpp PlayerType.h Card.cpp Card.h Bet.cpp Bet.h Game.cpp Game.h Hand.cpp Hand.h BetHistory.cpp BetHistory.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AlphaPlayer.cpp AlphaPlayer.h BetaPlayer.cpp BetaPlayer.h GammaPlayer.cpp GammaPlayer.h)