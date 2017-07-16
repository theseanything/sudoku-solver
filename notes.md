main.cpp:20:13: error: array size expression must have integral or enumeration type, not 'typename __lazy_enable_if<is_arithmetic<int>::value && is_arithmetic<int>::value, __promote<int, int> >::type'
      (aka 'double')
    board = new int[pow(boardSize,2)];


    Grid(){
      boardSize = 9;
      board = new int[pow(boardSize,2)];
    }

  -----

    main.cpp:47:12: warning: address of stack memory associated with local variable 'column' returned [-Wreturn-stack-address]
        return column;

      int** getColumn(int pos){
        int* column[boardSize];
        for(int i = 0; i < boardSize; i++){
          int offset = (pos - 1);
          column[i] = &board[(i * boardSize) + offset];
        }
        return column;
      }

    ------

      ➔ ./main
    0 5 6 9 0 7 4 0 0
    0 8 1 0 4 0 0 0 0
    0 0 0 0 1 5 0 9 0
    0 0 0 0 0 3 8 5 7
    8 4 0 0 6 0 0 2 3
    7 3 9 2 0 0 0 0 0
    0 6 0 5 8 0 0 0 0
    0 0 0 0 7 0 3 6 0
    0 0 8 3 0 6 5 7 0
    Hello, world
    main(70359,0x7fffc3dc83c0) malloc: *** error for object 0x7fff5fb064e0: pointer being freed was not allocated
    *** set a breakpoint in malloc_error_break to debug
    [1]    70359 abort      ./main

    public:
      Grid(){
        boardSize = 9;
        int numberOfPositions = pow(boardSize,2);
        board = new int[numberOfPositions];
      }

      Grid(int size){
        boardSize = size;
        int numberOfPositions = pow(boardSize,2);
        board = new int[numberOfPositions];
      }

      Grid(int startNums[], int size){
        boardSize = size;
        board = startNums;
      }

      ~Grid(){
        delete [] board;
      }

    Due to calling the third consructor which assigns board to a stack - not a dynamic.
    Have to use the heap.


    ---
    itorators the GetRow issues - why should I need to make a new array. Be nice to have a row iterator.
    
