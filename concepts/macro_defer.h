#define EMPTY()
#define DEFER(name) name EMPTY()
#define OBSTRUCT(x) x DEFER(EMPTY)()

#define EVAL(x)  EVAL1(EVAL1(EVAL1(x)) )

#define EVAL1(x) EVAL2(EVAL2(EVAL2(x)))
#define EVAL2(x) EVAL3(EVAL3(EVAL3(x)))
#define EVAL3(x) EVAL4(EVAL4(EVAL4(x)))
#define EVAL4(x) EVAL5(EVAL5(EVAL5(x)))
#define EVAL5(x) x
