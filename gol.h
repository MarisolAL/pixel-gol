/*!
 * \file gol.h
 * \brief Game of life functions
 *
 */

#ifndef __GOL_H__
#define __GOL_H__

extern const int LIVE;
extern const int  DEAD;

/**
 * \brief           Populates a 2D array with the values of DEAD and LIVE
 * \note            This function does not return value, it stores it to pointer instead
 * \param[in]       size: Size of the array
 * \param[in]       board: Pointer of the 2D array
 */
void populate_board(int size, int board[][size]);

/**
 * \brief           Iterate the game one time
 * \note            The function does not return value, it stores it to pointer instead
 * \param[in]       size: Size of the array
 * \param[in]       board: Pointer of the 2D array
 * \param[in]       bMoore: When is 1, then uses Moore neighborhoods, Von Neumann when it's 0
 */
void iterate_board(int size, int board[][size], int bMoore);

#endif /*__GOL_H__*/
