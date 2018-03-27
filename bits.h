#define SetBit(a,b) a=(a|(1<<b))
#define ClearBit(a,b) a=(a&(~(1<<b)))
#define GetBit(a,b) (a&(1<<b))>>b
