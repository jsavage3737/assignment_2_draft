#include "game.h"

using namespace std;
using namespace hw2;

void game::initializeGame(){
  cout << "Welcome to the game of life!" << endl << endl;
  while (true){
    // display options
    cout << "Which ruleset would you like to use?" << endl;
    cout << "1) Standard" << endl;
    cout << "2) Mirror" << endl;
    cout << "3) Donut" << endl;

    // get input
    cin >> inputc;
    cout << endl;

    // check validity of input and create game accordingly
    if (inputc=='1'){board = board_normal(); break;}
    else if (inputc=='2'){board = board_mirror(); break;}
    else if (inputc=='3'){board = board_torus(); break;}
    else{cout << "invalid input - try again" << endl << endl;}
  }

  // generating board
  while(true){
    cout << "Would you like to start with a random configuration or read from a file? (R/F)" << endl;
    cin >> inputc;

    // determining valid input and proceeding acordingly
    if (inputc=='R'||inputc=='r'){

      // prompting for valid density input
      while (true){
        cout << "Please enter a \"density\" value between 0 and 1: ";
        cin >> inputf;

        // determining if input is valid and storing in class member
        if (inputf>0.0 && inputf<1.0){
          board.setDensity(inputf);
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
        if(rows>0){board.setRows(rows);break;}

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
       if(rows>0){board.setColumns(columns);break;}

       // handling invalid input
       else{
         cout << "invalid input - try again" << endl;
         cin.clear(); // clearing input buffer
         cin.ignore(55, '\n');
       }
     }

     board.generate_from_input();
     break;
    }

    // if reading from file
    else if (inputc=='F'||inputc=='f'){
      board.generate_from_file();
      break;
    }
    else{cout<< "invalid input = try again" << endl << endl;}
  }

  // determining whether user wants enter mode or brief pause mode
  while (true){
    cout << "Would you like to run with a pause"
  }

  board.printBoard();
}
