struct abc {
  int N ;
  int M ;
  int S ;
};

struct Node {
 double val;
 Node* next;
};


/* program definition, no union or typdef definitions needed */
program RDBPROG { /* could manage multiple servers */
	version RDBVERS {
                double GETLOAD() = 1;
		double FINDMAX_GPU(abc) = 2;
		double UPDATE_LST(Node) = 3;
	} = 1;
} = 0x20000001;  /* program number ranges established by ONC */
