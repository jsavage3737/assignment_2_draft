#include "game.h"
#include <unistd.h>
#include <fstream>

using namespace std;
using namespace hw2;

void game::initializeGame(){
  board newBoard;
  default_board = newBoard;
  cout << "Welcome to the game of life!" << endl << endl;
  while (true){
    // display options
    cout << "Which ruleset would you like to use?" << endl;
    cout << "1) Standard" << endl;
    cout << "2) Mirror" << endl;
    cout << "3) Donut" << endl;

    // get input
    cin >> inputc;

    // check validity of input and create game accordingly
    if (inputc=='1'){
      board_normal newBoard1;
      board1 = newBoard1;
      board_type=1; break;}
    else if (inputc=='2'){
      board_mirror newBoard2;
      board2 = newBoard2;
      board_type=2; break;}
    else if (inputc=='3'){
      board_torus newBoard3;
      board3 = newBoard3;
      board_type=3; break;}
    else{cout << "invalid input - try again" << endl << endl;}
  }
  // generating default_board
  while(true){
    cout << "Would you like to input configuration or read from a file? (I/F): ";
    cin >> inputc;

    // determining valid input and proceeding acordingly
    if (inputc=='I'||inputc=='i'){

      // prompting for valid density input
      while (true){
        cout << "Please enter a \"density\" value between 0 and 1: ";
        cin >> inputf;

        // determining if input is valid and storing in class member
        if (inputf>0.0 && inputf<1.0){
          if (board_type==1){board1.setDensity(inputf);}
          else if (board_type==2){board2.setDensity(inputf);}
          else if (board_type==3){board3.setDensity(inputf);}
          break;
        }

        // handling invalid input
        else{
          cout << "invalid input - try again" << endl;
          cin.clear(); // clearing input buffer
          cin.ignore(55, '\n');
        }
      }
       // getting input for number of rows
      while(true){
        cout << "Enter desired number of rows: ";
        cin >> rows;
        if(rows>0){
          if (board_type==1){board1.setRows(rows);break;}
          else if (board_type==2){board2.setRows(rows);break;}
          else if (board_type==3){board3.setRows(rows);break;}
        }
        // handling invalid input
        else{
          cout << "invalid input - try again" << endl;
          cin.clear(); // clearing input buffer
          cin.ignore(55, '\n');
        }
      }

      // getting input for number of columns
     while(true){
       cout << "Enter desired number of columns: ";
       cin >> columns;
       if(columns>0){
         if (board_type==1){board1.setColumns(columns); break;}
         else if (board_type==2){board2.setColumns(columns); break;}
         else if (board_type==3){board3.setColumns(columns); break;}
       }

       // handling invalid input
       else{
         cout << "invalid input - try again" << endl;
         cin.clear(); // clearing input buffer
         cin.ignore(55, '\n');
       }
     }

     if (board_type==1){board1.generate_from_input();}
     else if (board_type==2){board2.generate_from_input();}
     else if (board_type==3){board3.generate_from_input();}
     break;
    }

    // if reading from file
    else if (inputc=='F'||inputc=='f'){
      if (board_type==1){board1.generate_from_file();}
      else if (board_type==2){board2.generate_from_file();}
      else if (board_type==3){board3.generate_from_file();}
      break;
    }
    else{cout<< "invalid input = try again" << endl << endl;}
  }

  // determining whether user wants enter mode or brief pause mode
  while (true){

    cout << "Would you like to:" << endl;
    cout << "1) Run with a pause" << endl;
    cout << "2) Space bar" << endl;
    cout << "3) Output to file" << endl;
    cin >> inputi;
    cout << endl;

    // acting if input is valid
    if (inputi==1){output_mode=1;break;}
    else if (inputi==2){output_mode=2;break;}
    else if (inputi==3){
      // setting output mode to 3
      output_mode=3;
      string filename;

      // getting desired file to output
      cout << "Enter file to output to: ";
      cin>>filename;

      if (board_type==1){board1.setOutputFilename(filename);}
      else if (board_type==2){board2.setOutputFilename(filename);}
      else if (board_type==3){board3.setOutputFilename(filename);}

      break;
    }


    // clearing buffer if invalid
    else{
      cout << "invalid input - try again" << endl;
      cin.clear(); // clearing input buffer
      cin.ignore(55, '\n');
    }
  }

  if (board_type==1){board1.printBoard();}
  else if (board_type==2){board2.printBoard();}
  else if (board_type==3){board3.printBoard();}
  // transferring data from parent board to correct child board
  //initializeBoard(board_type);
}

// running a full simulation
void game::runGame(){
  board1.setOutputFilename("out.txt");
  cout << "Starting game..."<<endl;
  while(true){
    // update board values
    handleUpdateBoard();

    // see if board is still running;
    if (board_type==1){if(!board1.getRunning()){break;}}
    else if (board_type==2){if(!board2.getRunning()){break;}}
    else if (board_type==3){if(!board3.getRunning()){break;}}

    // if not outputting to file
  }
}

// applying update board to correct board
void game::handleUpdateBoard(){
  // updating normal board
  if(board_type==1){
    board1.update_board();

    // pause if user chose to run with pause
    if(output_mode==1){
      board1.printBoard();
      sleep(2);
    }

    // wait until space if user chose to run with space
    if(output_mode==2){
      board1.printBoard();
      cout << "Press enter to continue"<<endl;
      cin.clear(); // incase buffer still active
      cin.get(); // waiting until spacebar
    }

    // saving board layout to file if user chose to save to file
    if(output_mode==3){
      board1.printBoardToFile();
    }
  }
  // updating mirror board
  else if(board_type==2){
    board2.update_board();

    // pause if user chose to run with pause
    if(output_mode==1){
      board2.printBoard();
      sleep(2);
    }

    // wait until space if user chose to run with space
    if(output_mode==2){
      board2.printBoard();
      cout << "Press enter to continue"<<endl;
      cin.clear(); // incase buffer still active
      cin.get(); // waiting until spacebar
    }

    // saving board layout to file if user chose to save to file
    if(output_mode==3){
      board2.printBoardToFile();
    }
  }

  // updating torus board
  else if(board_type==3){
    board3.update_board();

    // pause if user chose to run with pause
    if(output_mode==1){
      board3.printBoard();
      sleep(2);
    }

    // wait until space if user chose to run with space
    if(output_mode==2){
      board3.printBoard();
      cout << "Press enter to continue"<<endl;
      cin.clear(); // incase buffer still active
      cin.get(); // waiting until spacebar
    }

    // saving board layout to file if user chose to save to file
    if(output_mode==3){
      board3.printBoardToFile();
    }
  }
}
