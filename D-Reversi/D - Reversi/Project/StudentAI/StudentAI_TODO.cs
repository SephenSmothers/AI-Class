using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.IO.Pipes;
using FullSailAFI.GamePlaying.CoreAI;
using static FullSailAFI.GamePlaying.CoreAI.Node;
using System.Runtime.CompilerServices;

namespace FullSailAFI.GamePlaying
{
    public class StudentAI : Behavior
    {
        TreeVisLib treeVisLib;  // lib functions to communicate with TreeVisualization
       // bool visualizationFlag = true;
         bool visualizationFlag = false;  // turn this on to use tree visualization (which you will have to implement via the TreeVisLib API)
        // WARNING: Will hang program if the TreeVisualization project is not loaded!

        public StudentAI()
        {
            if (visualizationFlag == true)
            {
                if (treeVisLib == null)  // should always be null, but just in case
                    treeVisLib = TreeVisLib.getTreeVisLib();  // WARNING: Creation of this object will hang if the TreeVisualization project is not loaded!
            }
        }

        //
        // This function starts the look ahead process to find the best move
        // for this player color.
        //
        public ComputerMove Run(int _nextColor, Board _board, int _lookAheadDepth)
        {
           // treeVisLib.StartVisualization();
           // treeVisLib.StartRoot((Node.Player)_nextColor);
            ComputerMove nextMove = GetBestMove(_nextColor, _board, _lookAheadDepth);
           // treeVisLib.FinishRoot(nextMove.row, nextMove.col, nextMove.rank);
           // treeVisLib.FinishVisualization();

            return nextMove;
        }

        //
        // This function uses look ahead to evaluate all valid moves for a
        // given player color and returns the best move it can find. This
        // method will only be called if there is at least one valid move
        // for the player of the designated color.
        //
        private ComputerMove GetBestMove(int color, Board board, int depth)
        {
            //TODO: the lab
            ComputerMove bestMove = null;
            Board newBoard = new Board();
            List<ComputerMove> allMoves = new List<ComputerMove>();

            //  int colorPlayer = 0;

            //if (color == 1)
            //{
            //    colorPlayer = 1;
            //}


            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (board.IsValidMove(color, i, j))
                    {
                        ComputerMove tempMove = new ComputerMove(i, j);
                        allMoves.Add(tempMove);
                    }
                }
            }

            foreach (ComputerMove move in allMoves)
            {
                newBoard.Copy(board);
                newBoard.MakeMove(color, move.row, move.col);
                // treeVisLib.StartMove((Node.MinMax)colorPlayer ,(Node.Player)colorPlayer, move.row, move.col);



                if (newBoard.IsTerminalState() || depth == 0)
                {
                    move.rank = Evaluate(newBoard);
                }
                else
                {
                    ComputerMove tempMove2 = GetBestMove(GetNextPlayer(color, board), newBoard, depth - 1);
                    if (tempMove2 != null)
                        move.rank = tempMove2.rank;
                    else
                        Console.WriteLine("tempMove2 was null");
                }

                if (bestMove == null || move.rank > bestMove.rank && color == 1)
                {
                    bestMove = move;
                }

                if (bestMove == null || move.rank < bestMove.rank && color == -1)
                {
                    bestMove = move;
                }

                //  treeVisLib.FinishMove(bestMove.rank);
            }
            return bestMove;
        }


        #region Recommended Helper Functions

        private int Evaluate(Board _board)
        {
            int rank = 0;


            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (i != 0 && i != 7)
                    {
                        if (j != 0 && j != 7)
                        {
                            rank = rank + _board[i, j];
                        }
                        else
                        {
                            rank = rank + _board[i, j] * 10;
                        }
                    }
                    else
                    {
                        if (j != 0 && j != 7)
                        {
                            rank = rank + _board[i, j] * 10;
                        }
                        else
                        {
                            rank = rank + _board[i, j] * 100;
                        }
                    }
                }
            }


            if (_board.IsTerminalState())
            {
                if (_board.Score > 0)               
                    rank += 10000;             
                else if (_board.Score < 0)               
                    rank -= 10000;          
            }

            return rank;

            //TODO: determine score based on position of pieces
           // return ExampleAI.MinimaxAFI.EvaluateTest(_board); // TEST WITH THIS FIRST, THEN IMPLEMENT YOUR OWN EVALUATE
        }

        int GetNextPlayer(int player, Board gameState)
        {
            if (gameState.HasAnyValidMove(-player))
                return -player;
            else
                return player;
        }


        #endregion

    }
}
